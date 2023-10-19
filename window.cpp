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
    // 颜色填充规则

    /*
     * 1.Qt::OddEvenFill使用的是奇偶填充规则
     * 如果要判断一个点是否在图形中，那么就可以从该点出发向图形外引一条水平线
     * 如果该水平线与图形的交点的个数为奇数，那么说明该点就在图形中
     * Qt::OddEvenFill是路径填充规则的默认值
     *
     *
     *
     * 2.Qt::WindingFill使用的是非零弯曲规则
     * 如果要判断一个点是否在图形中，那么可以从该点向图形外引一条水平线
     * 如果该水平线与图形的边线相交，且这个边线是顺时针绘制的，就记为1
     * 是逆时针的，就记为-1
     * 将所有这些记录值相加，如果结果不为0，那么就说该点在图形中。
     *
    */

    QPainter painter(this);
    QPainterPath path;
    path.addEllipse(10, 50, 100, 100);
    path.addRect(50, 100,100, 100);
    painter.setBrush(Qt::cyan);
    painter.drawPath(path);

    // 平移坐标系
    painter.translate(180, 0);
    path.setFillRule(Qt::WindingFill); // 使用非零弯曲填充规则，还有一个奇偶填充规则(默认值，Qt::OddEventFill)
    painter.drawPath(path);

}































