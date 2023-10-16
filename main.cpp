/*
 * 连接Qml信号和Cpp槽函数
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include <QString>
#include <QQuickWindow>
#include "message.h"



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/qt/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);


    QObject *object = *engine.rootObjects().begin();
    // 对象名window可以和Main.qml中的id名window不相同
    QQuickWindow *window = qobject_cast<QQuickWindow *>(object);

    Message myClass;

    // 连接Qml信号和Cpp槽
    QObject::connect(window, SIGNAL(qmlSignal(QString)),
                     &myClass, SLOT(cppSlot(QString)));

    window->show();

    return app.exec();
}
