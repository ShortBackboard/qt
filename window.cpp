#include "window.h"
#include <QPainter> // 绘画类
#include <QLine> // 线条
#include <QPoint> // 点
#include <QPen> // 画笔
#include <QRectF> // 矩形
#include <QBrush> // 画刷
#include <QColor> // 颜色
#include <QPixmap> // 加载图片
#include <QPointF> // 浮点数的点
#include <QGradient> // 渐变填充
#include <QLinearGradient> // 线性渐变
#include <QRadialGradient> // 径向渐变
#include <QConicalGradient> // 锥形渐变

#include <QTimer> // 定时器

// 初始角度
int angle = 0;

Window::Window()
{
    setWindowTitle(tr("QPatiner 学习"));
    QTimer* timer = new QTimer(this);

    // 连接定时器和绘画的update()
    // update()一次，就会执行一遍paintEvent()
    connect(timer, SIGNAL(timeout()),
            this, SLOT(update()));

    // 1s定时器
    timer->start(1000);

}



// 绘画
void Window::paintEvent(QPaintEvent *event)
{
    // 与定时器结合做一个动画

    // 执行一次，角度加10
    angle += 5;

    if(angle == 360) angle = 0;

    // 取较小值
    int side = qMin(width(), height());

    // 自动调用QPainter的begin()，在析构时调用end()函数
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QTransform transform;

    // 平移坐标系
    transform.translate(width() / 2, height() / 2);

    // 根据部件的大小进行缩放，这样当窗口大小改变时绘制的内容也会跟着改变大小
    // 缩放坐标系
    transform.scale(side/300.0, side/300.0);
    transform.rotate(angle);		// 由于angle在不断变化，所以每次旋转的角度都不同
    painter.setWorldTransform(transform);
    painter.drawEllipse(-120, -120, 240, 240);  // 画钟圆
    painter.drawLine(0, 0, 110, 0);             // 画时针

}































