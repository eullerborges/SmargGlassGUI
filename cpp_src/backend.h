#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QQuickItem>
#include <QSerialPort>
#include <string>
#include "ProtocolFSM.hpp"

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
private:
    QSerialPort _serial;  //!< Porta serial a ser utilizada
    ProtocolFSM *_ptclFSM;  //!< Máquina de estados de tratamento do protocolo

signals:
    void serialOpened(); //!< Indica que a serial foi aberta
    void serialClosed(); //!< Indica que a serial foi fechada

public slots:
    void readData();
    void serialError();
    void serialParamsChanged(QString baudrateText, QString serialportText);
};

#endif // BACKEND_H
