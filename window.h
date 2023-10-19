#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtWidgets>



class Window : public QWidget
{
    Q_OBJECT

// 构造函数
public:
    Window();

protected:
    // QPainter一般在一个部件重绘事件的处理函数paintEvent()中进行绘制操作
    void paintEvent(QPaintEvent *event) override;



};


#endif // WINDOW_H
