/*
 * 注册C++自定义对象和qml集成，获得当前时间功能
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "myDatetime.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // 注册C++自定义对象
    MyDatetime o;
    engine.rootContext()->setContextProperty("ob", &o);

    const QUrl url(u"qrc:/qt/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
