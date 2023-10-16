#ifndef MYDATETIME_H
#define MYDATETIME_H
#include <QWidget>
#include <QDateTime>

class MyDatetime : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE QDateTime getCurrentDateTime() const {
        return QDateTime::currentDateTime();
    }
};


#endif // MYDATETIME_H
