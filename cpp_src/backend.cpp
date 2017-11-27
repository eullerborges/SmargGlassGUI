#include "backend.h"
#include "Protocol_MTs.h"
#include "cpp_src/crc.h"
#include "cpp_src/utils.h"
#include <QTimer>
#include <stdint.h>

#define DELETE_SET_NULL(x) if(x) {delete(x); x = NULL;}

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
    autosendFileConfig = NULL;
    autosendTimer = NULL;
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
    if (autosendTimer) {
        delete autosendTimer;
        autosendTimer = NULL;
    }
    if(error == "Device is not open"){
        serialClosed();
    }
    else if(error != "No error"){
        qDebug() << "Serial error: " << error;
        serialClosed();
        emit newMsgDialog("Erro na serial", QString(error));
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
    //qDebug() << "Packet sent: " << string_to_hex(encoded_out).c_str();
    _serial.write(encoded_out.c_str(), encoded_out.size());

}

/**
 * @brief Slot para envio de uma nova configuração de um LED
 * @param ledNumber Número do led a ser modificado
 * @param redValue Valor da componente vermelha
 * @param greenValue Valor da componente verde
 * @param blueValue Valor da componente azul
 */
void Backend::sendNewLedConfig(int ledNumber, int redValue, int greenValue, int blueValue,
                               float period, float workcycle, int blinks){
    //qDebug() << "Sending new LED config for LED " << ledNumber << ", colors " << redValue << " " << greenValue << " " << blueValue;
    LedsValues ledValues;
    ledValues.set_commandid(20);
    LedRgb *led = ledValues.add_leds();  // Adicionando um led
    led->set_number((LedNumber)ledNumber); // Número
    // Setando componentes
    led->set_red(colorComponentToLedStrength(redValue));
    led->set_green(colorComponentToLedStrength(greenValue));
    led->set_blue(colorComponentToLedStrength(blueValue));
    if (period){
        LedBlink *blinkValue = new LedBlink;
        blinkValue->set_enable(true);
        blinkValue->set_timeon((period*1000)*workcycle);
        blinkValue->set_timeoff((period*1000)*(1-workcycle));
        blinkValue->set_numblinks(blinks);
        led->set_allocated_blink(blinkValue);
    }
    else{
        LedBlink *blinkValue = new LedBlink;
        blinkValue->set_enable(false);
        led->set_allocated_blink(blinkValue);
    }
    qDebug() << "LED" << ledNumber << ", colors " << led->red() << " " << led->green() << " " << led->blue();
    qDebug() << "Period: " << period << " WC: " << workcycle << " Blinks: " << blinks;

    // Enviando via serial
    _encodeAndSendCommand(MSG_SET_LEDS_VALUE, ledValues.SerializeAsString());
}

/**
 * @brief Envio pedido de atualização para o óculos
 *
 * O pedido é enviado com o fim de atualizar a interface no início do
 * programa. são pedidos status de todos os 20 LEDs.
 */
void Backend::requestUpdate(){
    GetLedsStatus getLedsStatus;
    getLedsStatus.set_commandid(10);
    for(int i=0; i < NUM_LEDS; i++){
        LedStatusRequest *led = getLedsStatus.add_leds();
        led->set_number((LedNumber)i);
    }
    _encodeAndSendCommand(MSG_REQUEST_LEDS_STATUS, getLedsStatus.SerializeAsString());
}

/**
 * @brief Carrega um arquivo de configuração dos LEDs.
 *
 * Carrega o arquivo com um comando FileConfig codificado, que permit enviar
 * configurações dos LEDs previamente codificadas em um arquivo. Se a configuração de
 * envio periódico foi habilitada, configura o timer apropriado para realizar o envio
 * temporizado.
 *
 * @param fileName nome do arquivo
 */
void Backend::loadFile(QString fileName){
    qDebug() << "File selected: " << fileName;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        qDebug() << "Cannot open file!";
        return;
    }
    QByteArray fileData = file.read(file.size());
    qDebug() << "File size: " << file.size();
    qDebug() << "File len: " << fileData.length();
//    std::string str = string_to_hex(fileData.toStdString());
//    qDebug() << "StrLen: " << str.length();
//    qDebug() << string_to_hex(fileData.toStdString()).data();
    FileConfig *fileConfig = new FileConfig();
    if (!fileConfig->ParseFromString(fileData.toStdString())) {
        qDebug() << "Error parsing file!";
        return;
    }
    LedsValues *ledValues = fileConfig->mutable_repledsvalues(0);
    qDebug() << "LED: " << ledValues->leds(0).number() << " R:" << ledValues->leds(0).red() <<
                " G:" << ledValues->leds(0).green() << " B:" << ledValues->leds(0).blue();
    _encodeAndSendCommand(MSG_SET_LEDS_VALUE, ledValues->SerializeAsString());
    // Apagando timer se tiver sido previamente instanciado.
    if (autosendTimer) DELETE_SET_NULL(autosendTimer);
    // Se há configuração para envio periódico, guardar dados.
    if (fileConfig->has_timingconfig()){
        qDebug() << "Timing Config!";
        if (autosendFileConfig) DELETE_SET_NULL(autosendFileConfig);
        qDebug() << "0";
        autosendFileConfig = fileConfig;
        qDebug() << "Timer Period: " << fileConfig->timingconfig().period();
        autosendPeriod = fileConfig->timingconfig().period();
        // O timer começa a enviar a partir do segundo índice
        autosendCurIndex = 1;
        // Criando o timer
        autosendTimer = new QTimer(this);
        // Configurando o callback do timer
        connect(autosendTimer, &QTimer::timeout, this, &Backend::autosendLedsConfig);
        autosendTimer->start(autosendPeriod); // Iniciando o timer
    }
    else{
        DELETE_SET_NULL(fileConfig);
    }
}

/**
 * @brief Envia configuração previamente codificada em arquivo para os LEDs
 *
 * Este é o callback do timer responsável por enviar a configuração codificada
 * em um arquivo carregado via interface gráfica.
 */
void Backend::autosendLedsConfig() {
    autosendCurIndex %= autosendFileConfig->repledsvalues_size();
    LedsValues *ledValues = autosendFileConfig->mutable_repledsvalues(autosendCurIndex++);
    _encodeAndSendCommand(MSG_SET_LEDS_VALUE, ledValues->SerializeAsString());
}
