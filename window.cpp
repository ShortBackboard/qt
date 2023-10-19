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

#include <QFont> // 字体属性


Window::Window()
{
    setWindowTitle(tr("QPatiner 学习"));
}



// 绘画
void Window::paintEvent(QPaintEvent *event)
{
    // 绘制路径(多个绘制元素的集合，可以复用)

    /*
     * 如果要绘制一个复杂的图形，可以使用QPainterPath类，
     * 并使用QPainter::drawPath()进行绘制。
     * QPainterPath类为绘制操作提供了一个容器，可以用来创建图形并且重复使用。
     *
     * 一个绘图路径就是由多个矩形，椭圆，线条或者曲线等组成的对象。
     * 一个路径可以是封闭的，如果矩形和椭圆；也可以是非封闭的，如线条和曲线。
    */

    QPainter painter(this);
    QPainterPath path;
    path.moveTo(50, 250);
    path.lineTo(50, 230);       // 类似的函数还有arcTo(), cubicTo(), quadTo()
    path.cubicTo(QPointF(105, 40), QPointF(115, 80), QPointF(120, 60)); // 绘制三次贝塞尔曲线(使用quadTo()绘制二次贝塞尔曲线)
    path.lineTo(130, 130);
    path.addEllipse(QPoint(130,130), 30, 30);       // 向路径中添加一个圆,与之类似的函数还有addPath(),addRect(),addRegion(),addText(),addPolygon()

    painter.setPen(Qt::darkYellow);
    painter.drawPath(path);		// 路径构建完成后使用drawPath()将路径绘制出来

    // 平移坐标系统
    path.translate(200,0);
    painter.setPen(Qt::darkBlue);
    painter.drawPath(path);


}































