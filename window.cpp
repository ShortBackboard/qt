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

    // 1.绘画线条，使用的画笔默认参数
    QPoint start(0, 0), end(100, 100);
    QLine line(start, end);
    painter.drawLine(line);


    // 2.使用画笔绘画一个圆弧
    // QPen类的构造函数为QPen::QPen(QBrush, Width, PenStyle, PenCapStyle, PenJoinStyle)
    QPen pen(Qt::blue, 3, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen); // 使用画笔
    QRectF rect(100, 200, 200, 60); // (x, y, width, height) width为焦距，
    // 这里使用的角度的数值为实际度数乘以16，在时钟表盘中，0度指向3时的位置。如果角度数值为正，则表示逆时针旋转；角度数值为负，则表示顺时针旋转。整个一圈的数值为5760(360 × 16)。
    int startAngle = 0 * 16;       // 圆弧的起始角度
    int spanAngle = 180 * 16;       // 圆弧的张开角度
    painter.drawArc(rect, startAngle, spanAngle);


    // 重新设置画笔样式
    pen.setColor(Qt::black);
    painter.setPen(pen);


    // 3.使用画刷绘画一个椭圆
    QBrush brush(QColor(0, 255, 0), Qt::Dense5Pattern); // (画刷颜色，画刷样式)
    painter.setBrush(brush); // 重新设置painter实例使用的画刷样式
    painter.drawEllipse(300, 300, 100, 50); // 绘画椭圆


    // 4.绘制四边形
    // 为画刷设置纹理(这样设置后画刷的样式就自动转换为Qt::TexturePattern)
    // 相当于使用该图片进行裁剪
    brush.setTexture(QPixmap("../qt/images/leetCode.png"));
    painter.setBrush(brush);
    static const QPointF points[4] = {
        // 点的顺序
        QPointF(300.0, 100.0),
        QPointF(300.0, 200.0),
        QPointF(500.0, 200.0),
        QPointF(500.0, 100.0)
    };
    painter.drawPolygon(points, 4); //指定各个顶点坐标， 顶点数量


    // 5.使用画刷绘制填充矩形
    painter.fillRect(QRect(320, 120, 120, 30), QBrush(Qt::green));

    // 6.擦除一个矩形区域
    painter.eraseRect(QRect(450, 150, 40, 40));


    // 7.颜色渐变填充

    // 创建一个线性渐变
    QLinearGradient linearGradient(QPoint(0, 200), QPoint(60, 200)); // 颜色段
    linearGradient.setColorAt(0, Qt::yellow);
    linearGradient.setColorAt(0.5, Qt::red);
    linearGradient.setColorAt(1, Qt::green);
    linearGradient.setSpread(QGradient::RepeatSpread);
    painter.setBrush(linearGradient);
    painter.drawRect(0, 400, 100, 50);


    // 创建一个径向渐变
    // 需要指定圆心center和半径radius，这样就可以确定一个圆，然后再指定一个焦点focalPoint。
    QRadialGradient radialGradient(QPointF(100, 100), 100, QPointF(275, 200));
    radialGradient.setColorAt(0, QColor(255, 255, 100, 150));
    radialGradient.setColorAt(1, QColor(0, 0, 0, 50));
    painter.setBrush(radialGradient);
    painter.drawRect(160, 400, 50, 50);


    // 创建一个锥形渐变
    // 需要指定中心点center和一个角度angle(值在0 ~ 360)。
    QConicalGradient conicalGradient(QPointF(350, 190), 60);
    conicalGradient.setColorAt(0.2, Qt::yellow);
    conicalGradient.setColorAt(0.9, Qt::black);
    painter.setBrush(conicalGradient);
    painter.drawEllipse(QPointF(300, 400), 50, 50);


    // 8.使用线性渐变来绘制直线和文字
    // 如果为画笔设置了渐变颜色，那么可以绘制出渐变颜色的线条和轮廓，还可以绘制出渐变颜色的文字
    painter.setPen(QPen(linearGradient, 2));
    painter.drawLine(0, 50, 100, 50); // from to

    painter.drawText(30, 80, tr("Hello Qt!"));


    // 9.抗锯齿绘图
    // 抗锯齿(Anti-aliased)又称为反锯齿或者反走样，就是对图像的边缘进行平滑处理，使其看起来更加柔和流畅的一种技术。






}































