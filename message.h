#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QQuickWindow>

class Message : public QObject
{
    Q_OBJECT

public slots:
    // Cpp槽函数，被Qml信号调用
    void cppSlot(QObject *w)
    {
        qDebug() << "Cpp槽函数被调用: ";
        QQuickWindow *window = qobject_cast<QQuickWindow *>(w);
        qDebug() << "获得传递对象信息";
        qDebug() << "窗口宽度：" << window->width() << "窗口宽度：" << window->height();
    }
};

#endif // MESSAGE_H

