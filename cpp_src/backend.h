#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QQuickItem>
#include <QSerialPort>
#include <string>
#include "ProtocolFSM.hpp"
#include "Protocol_Commands.pb.h"
#include "Protocol_Leds.pb.h"

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
private:
    QSerialPort _serial;  //!< Porta serial a ser utilizada
    ProtocolFSM _ptclFSM;  //!< Máquina de estados de tratamento do protocolo
    void _encodeAndSendCommand(int mt, std::string data); //!< Envia pacote na serial

signals:
    void serialOpened(); //!< Indica que a serial foi aberta
    void serialClosed(); //!< Indica que a serial foi fechada
    void ledColorChanged(int number, QColor color);

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
