/*
 * 使用 Q_PROPERTY() 宏，将自定义的类的数据成员暴露给QML访问，eg:自定义message类并设置set、get函数和信号
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "message.h"



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Message msg;
    engine.rootContext()->setContextProperty("msg", &msg);


    const QUrl url(u"qrc:/qt/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
