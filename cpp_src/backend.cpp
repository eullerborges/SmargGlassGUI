#include "backend.h"
#include "Protocol_MTs.h"
#include "cpp_src/crc.h"
#include "cpp_src/utils.h"
#include <stdint.h>


/**
 * @brief Construtor da classe
 */
Backend::Backend(QObject *parent) : QObject(parent),
    _ptclFSM(std::bind(&Backend::parseProtocolPacket, this,
                       std::placeholders::_1, std::placeholders::_2))
{

    qDebug("Initializing backend");

    // Connection in Qt5 style
    connect(&_serial, &QSerialPort::readyRead, this, &Backend::readData);
    connect(&_serial, &QSerialPort::errorOccurred, this, &Backend::serialError);
    _serial.setPortName("/dev/pts/11");
    _serial.setBaudRate(QSerialPort::Baud115200);
    _serial.setDataBits(QSerialPort::Data8);
    _serial.setParity(QSerialPort::NoParity);
    _serial.setStopBits(QSerialPort::OneStop);
    _serial.setFlowControl(QSerialPort::NoFlowControl);
    //    if(!_serial.open(QIODevice::ReadWrite)) return;
    //    else serialOpened();
    //    _serial.write("Smart Glass application started!\r\n");
    //    _serial.flush();
    curSerialPort = "/dev/pts/11";
    curBaudrate = "115200";
}

/**
 * @brief Destrutor da classe
 */
Backend::~Backend()
{
    if(_serial.isOpen()) {
        _serial.flush();
        _serial.close();
    }
}

/**
 * @brief Método para tratamento do recebimento de dados na serial.
 */
void Backend::readData(){
    QByteArray data = _serial.readAll();
    for (const char &byte: data) _ptclFSM.parseByte(byte);
    //qDebug() << data;
}

/**
 * @brief Método para tratamento de erros na serial.
 */
void Backend::serialError(){
    QString error = _serial.errorString();
    if(error == "Device is not open"){
        serialClosed();
    }
    else if(error != "No error"){
        qDebug() << "Serial error: " << error;
        serialClosed();
    }
}

/**
 * @brief Slot para tratamento de mudança de parâmetros da serial na interface gráfica.
 * @param serialPortName Nome da porta serial escolhida pelo usuário
 * @param baudrate Baudrate da porta serial
 */
void Backend::serialParamsChanged(QString serialPortName, QString baudrate){
    qDebug() << "C++ Serial params changed!!! Baudrate: " << baudrate << ", serial port: " << serialPortName;
    _serial.close();
    _serial.setPortName(serialPortName);
    _serial.setBaudRate(baudrate.toInt());
    _serial.open(QIODevice::ReadWrite);
    if(_serial.isOpen()){
        curSerialPort = serialPortName;
        curBaudrate = baudrate;
        serialOpened();
        // Requerindo update para atualizar os LEDs da interface
        requestUpdate();
    }
}

/**
 * @brief Tratamento de pacotes do protocolo de comunicação
 * @param int message_type Tipo da mensagem
 * @param std::string data Dados do pacote.
 */
void Backend::parseProtocolPacket(int message_type, std::string data){
    static int count = 0;
    qDebug() << ++count << ")Packet received! MT: " << message_type << " DATA:"  << string_to_hex(data).c_str();
    switch (message_type){
        case MSG_LEDS_STATUS:
        qDebug() << ++count << ")Packet received! MT: " << message_type << " DATA:"  << string_to_hex(data).c_str();
        LedsValues ledValues;
        bool res = ledValues.ParseFromString(data);
        if (!res) {
            qDebug() << "Packet decoding failed for MT " << message_type << " !";
            return;
        }
        qDebug() << "LEDs size: " << ledValues.leds_size();
        for (int i=0; i < ledValues.leds_size(); i++){
            LedRgb led = ledValues.leds(i);
            LedNumber number = led.number();
            double str_red = convertRGB(led.red());
            double str_blue = convertRGB(led.blue());
            double str_green = convertRGB(led.green());
            //qDebug() << "LED " << number << " changed status " << str_red << str_green << str_blue;
            QColor resulting_color = QColor::fromRgb(str_red, str_green, str_blue);
            emit ledColorChanged(number, resulting_color);
        }
        break;
    }
}

/**
 * @brief Encapsula o commando em um pacote do protocolo e envia na serial.
 * @param mt Message type do comando a ser enviado
 * @param data Dados a serem encapsulados e enviados
 */
void Backend::_encodeAndSendCommand(int mt, std::string data){
    Protocol_Packet pckt;
    std::string encoded_out;
    pckt.encode_data(mt, data, &encoded_out);
    qDebug() << "Packet sent: " << string_to_hex(encoded_out).c_str();
    _serial.write(encoded_out.c_str(), encoded_out.size());

}

/**
 * @brief Slot para envio de uma nova configuração de um LED
 * @param ledNumber Número do led a ser modificado
 * @param redValue Valor da componente vermelha
 * @param greenValue Valor da componente verde
 * @param blueValue Valor da componente azul
 */
void Backend::sendNewLedConfig(int ledNumber, int redValue, int greenValue, int blueValue){
    //qDebug() << "Sending new LED config for LED " << ledNumber << ", colors " << redValue << " " << greenValue << " " << blueValue;
    LedsValues ledValues;
    ledValues.set_commandid(20);
    LedRgb *led = ledValues.add_leds();  // Adicionando um led
    led->set_number((LedNumber)ledNumber); // Número
    // Setando componentes
    led->set_red(colorComponentToLedStrength(redValue));
    led->set_green(colorComponentToLedStrength(greenValue));
    led->set_blue(colorComponentToLedStrength(blueValue));
    qDebug() << "LED" << ledNumber << ", colors " << led->red() << " " << led->green() << " " << led->blue();

    // Enviando via serial
    _encodeAndSendCommand(MSG_SET_LEDS_VALUE, ledValues.SerializeAsString());
}

void Backend::requestUpdate(){
    GetLedsStatus getLedsStatus;
    getLedsStatus.set_commandid(10);
    for(int i=0; i < NUM_LEDS; i++){
        LedStatusRequest *led = getLedsStatus.add_leds();
        led->set_number((LedNumber)i);
    }
    _encodeAndSendCommand(MSG_REQUEST_LEDS_STATUS, getLedsStatus.SerializeAsString());
}
