/*
 * 使用对象作为参数在Qml信号和Cpp槽函数之间传递
 *
 * 当某个 QML 对象类型作为一个信号参数使用时
   该参数可以使用 var作为类型，在 C++ 端，这个值将会使用 QVariant 类型被接收;
   该参数还可以以 QtObject 作为类型，在 C++ 端，这个值将会使用 QObject类型被接收
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
    QObject::connect(object, SIGNAL(qmlSignal(QObject *)),
                     &myClass, SLOT(cppSlot(QObject *)));

    window->show();

    return app.exec();
}
