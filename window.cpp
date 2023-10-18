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

Window::Window()
{
    setWindowTitle(tr("QPatiner 学习"));
}



// 绘画
void Window::paintEvent(QPaintEvent *event)
{
    // 自动调用QPainter的begin()，在析构时调用end()函数
    QPainter painter(this);

    // 1.平移坐标系统，将(100, 0)作为原点
    painter.setPen(QPen(Qt::red ,10));
    painter.drawLine(10, 10, 100, 100);

    // 开启抗锯齿
    // 抗锯齿(Anti-aliased)又称为反锯齿或者反走样，就是对图像的边缘进行平滑处理，使其看起来更加柔和流畅的一种技术
    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(100 ,0);
    painter.drawLine(10, 10, 100, 100);


    // 保存painter的状态
    painter.save();
    // 2.将坐标系统旋转90度
    painter.rotate(90);
    painter.setPen(QPen(Qt::cyan ,10));
    painter.drawLine(QPoint(10,10), QPoint(100, 100));

    // 恢复painter的save()之前的状态(没有rotate()之前)
    painter.restore();


    // 3.缩放变换
    painter.setBrush(Qt::darkGreen);
    painter.drawRect(150, 150, 100, 50);
    painter.save();
    // x缩放，y缩放
    painter.scale(0.5, 0.5);
    painter.setBrush(Qt::yellow);       // 改变画刷填充颜色
    painter.drawRect(150, 150, 100, 50);
    painter.restore();





}































