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

// 绘制图像类
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QBitmap>
#include <QPicture>

#include <QTransform>

#include <QDebug>


Window::Window()
{
    setWindowTitle(tr("QPatiner 学习"));
}



// 绘画
void Window::paintEvent(QPaintEvent *event)
{
    // 绘制图像


    /*
     * Qt提供了4个类来处理图像数据：QImage，QPixmap，QBitmap和QPicture，都是常用的绘图设备。
     *
     * QImage主要用来进行I/O处理，它对I/O处理操作进行了优化，而且也可以用来直接访问和操作像素。
     * QPixmap主要用来在屏幕上显示图像，它对在屏幕上显示图像进行了优化。
     * QBitmap是QPixmap的子类，用来处理颜色深度为1的图像，即只能显示黑白两种颜色。
     * QPicture用来记录并重演QPainter命令。
    */




    // 1.QImage，加载显示一个图片文件，并生成倒影图片文件并保存图片到指定路径
    QPainter painter(this);
    QImage image;
    //480 * 270
    image.load("../qt/images/leetCode.png");
    //qDebug() << image.size() <<image.format() << image.depth();

    painter.drawImage(QPoint(10, 10), image);

    QImage mirror = image.mirrored(); // 图片的倒影文件
    QTransform trans;
    trans.shear(0.2 ,0);

    QImage newImage = mirror.transformed(trans);
    painter.drawImage(QPoint(10, 200), newImage);

    // 保存新文件
    newImage.save("../mirror.png");








}































