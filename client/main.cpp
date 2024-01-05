#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "custominfomodel.h"
#include <unistd.h>
#include <iostream>
#include <QThread>
#include <QUrl>
#include <QObject>
#include <QQmlComponent>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

     QGuiApplication app(argc, argv);

     QQmlApplicationEngine engine;

     CustomInfoModel customInfoModel;

     engine.rootContext()->setContextProperty("customInfoModel", &customInfoModel);

     const QUrl mainUrl(QStringLiteral("qrc:/main.qml"));

     QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                      &app, [mainUrl](QObject *obj, const QUrl &objUrl) {
         if (!obj && mainUrl == objUrl)
             QCoreApplication::exit(-1);
     }, Qt::QueuedConnection);

     const QUrl loginUrl(QStringLiteral("qrc:/Login.qml"));

     QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                      &app, [loginUrl](QObject *obj, const QUrl &objUrl) {
         if (!obj && loginUrl == objUrl)
             QCoreApplication::exit(-1);
     }, Qt::QueuedConnection);
     engine.load(loginUrl);

    return app.exec();
}


