/*
 * 在QML视图中使用基于C++的数据模型
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringList>
#include <QVariant>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QStringList dataList;
    dataList.append("Item 0");
    dataList.append("Item 1");
    dataList.append("Item 2");

    engine.rootContext()->setContextProperty("myModel",
                                 QVariant::fromValue(dataList));

    const QUrl url(u"qrc:/qt/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
