#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QString>
#include <QDebug>

class Message : public QObject
{
    Q_OBJECT

public slots:
    // Cpp槽函数，被Qml信号调用
    void cppSlot(const QString &msg)
    {
        qDebug() << "Cpp槽函数被调用: " << msg;
    }
};

#endif // MESSAGE_H

