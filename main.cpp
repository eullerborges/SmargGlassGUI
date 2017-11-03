#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtCore/QDebug>
#include <iostream>
#include "cpp_src/ProtocolFSM.hpp"
#include "cpp_src/backend.h"
#include <QQmlComponent>
#include <QQmlProperty>
#include <QQmlContext>

QT_USE_NAMESPACE

int main(int argc, char *argv[])
{
    qmlRegisterType<Backend>("Backend", 1, 0, "Backend");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    qDebug() << "Starting smart glass application.";


    // Backend da aplicação gráfica
//    Backend backend;
//    engine.rootContext()->setContextProperty("backend", &backend);

//    QObject *rootObject = engine.rootObjects().first();
//    QObject *homePage = rootObject->findChild<QObject*>("homePage");

//    qDebug() << homePage;
//    qDebug() << homePage->property("infoPaneText");

    return app.exec();
}
