#include "backend.h"


Backend::Backend(QObject *parent) : QObject(parent)
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

Backend::~Backend()
{
    if(_serial.isOpen()) {
        _serial.write("Application finished!");
        _serial.flush();
        _serial.close();
    }
}

/**
 * Método para tratamento do recebimento de dados na serial.
 */
void Backend::readData(){
    QByteArray data = _serial.readAll();
    qDebug() << data;
}

/**
 * Método para tratamento de erros na serial.
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
        _serial.write("Smart Glass application started!\r\n");
    }
}
