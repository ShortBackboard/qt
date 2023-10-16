#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QString>
#include <QDebug>

class Message : public QObject
{
    Q_OBJECT

    // getter : author
    // setter : setAuthor

    // author property 的 NOTIFY 信号是 authorChanged ,它使用了 Q_PROPERTY() 宏调用来指定。
    // 这意味着无论何时该信号被发射，就像使用 Message::setAuthor() 使得 author 发生变化一样
    // 都会通知 QML 引擎更新任何与 author property 的绑定,
    // 从而依次地,引擎将会再次调用 Message::author() 更新 text property 。

    Q_PROPERTY(QString author READ author WRITE setAuthor
                   NOTIFY authorChanged)

public:
    void setAuthor(const QString &a)
    {
        if(a != m_author)
        {
            m_author = a;

            // 发送信号
            emit authorChanged();
        }
    }

    QString author() const
    {
        return m_author;
    }

signals:
    void authorChanged();

private:
    QString m_author = "init";
};

#endif // MESSAGE_H

