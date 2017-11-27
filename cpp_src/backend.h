#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QQuickItem>
#include <QSerialPort>
#include <string>
#include "ProtocolFSM.hpp"
#include "Protocol_Commands.pb.h"
#include "Protocol_Leds.pb.h"
#include "protobuf/fileconfig.pb.h"

#define NUM_LEDS 20

class Backend : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(QString curSerialPort READ curSerialPort);
//    Q_PROPERTY(QString curBaudrate READ curBaudrate);
public:
    explicit Backend(QObject *parent = nullptr);
    ~Backend();
    QString curSerialPort; //!< Nome da porta serial atual
    QString curBaudrate; //!< Baudrate atual
    void parseProtocolPacket(int, std::string); //!< Tratamento de pacotes do protocolo
    void autosendLedsConfig(); //!< Envio automático de configuração setado via arquivo
private:
    QSerialPort _serial;  //!< Porta serial a ser utilizada
    ProtocolFSM _ptclFSM;  //!< Máquina de estados de tratamento do protocolo
    void _encodeAndSendCommand(int mt, std::string data); //!< Envia pacote na serial
    // Relativos à configuração via arquivo
    FileConfig *autosendFileConfig; //!< Configuração periódica carregada via arquivo
    int autosendPeriod; //!< Período configurado no arquivo para envios automatizados do fileLedsConfig.
    QTimer *autosendTimer; //!< Objeto de timer para gerar evento de envio automático
    int autosendCurIndex; //!< Índice atual do autosend.

signals:
    void serialOpened(); //!< Indica que a serial foi aberta
    void serialClosed(); //!< Indica que a serial foi fechada
    void ledColorChanged(int number, QColor color);
    void newMsgDialog(QString title, QString msg); //!< Indica a necessidade de mostrar um texto em um dialog

public slots:
    void readData();
    void serialError();
    void serialParamsChanged(QString baudrateText, QString serialportText);
    void sendNewLedConfig(int ledNumber, int redValue, int greenValue, int blueValue,
                          float period, float workcycle, int blinks);
    void requestUpdate();
    void loadFile(QString fileName);
};

#endif // BACKEND_H
