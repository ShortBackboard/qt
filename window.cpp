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




/*1
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

1*/






    // 2.QPixmap：将图片绘制到指定位置并使用画刷或者文字编辑图片

    /*
     * QPixmap可以作为一个绘图设备将图像显示在屏幕上。QPixmap中的像素在内部由底层的窗口系统进行管理。
     * 因为QPixmap是QPaintDevice的子类，所以QPainter也可以直接在它上面进行绘制。
     *
     * 要想访问像素，只能使用QPainter提供的相应函数，或者将QPixmap转换为QImage。
     * 而与QImage不同的是，QPixmap中的fill()函数可以使用指定的颜色初始化整个pixmap图像。
     *
     * 可以使用toImage()和fromImage()函数在QImage和QPixmap之间进行转换。
     * 通常情况下，QImage类用来加载一个图像文件，随意操纵图像数据，然后将QImage对象转换为QPixmap类型以将结果显示在屏幕上。当然，如果不需要对图像进行操作，那么也可以直接使用QPixmap来加载图像文件。
     *
     * 另外，与QImage不同的是，QPixmap依赖于具体的硬件。
     *
     * QPixmap可以很容易地通过QLabel或QAbstractButton的子类(如QPushButton)显示在屏幕上。
     * QLabel拥有一个pixmap属性，而QAbstractButton拥有一个icon属性。
     * QPixmap可以使用copy()复制图像上的一个区域，还可以使用mask()实现遮罩效果
    */



    QPainter painter(this);
    QPixmap pix;
    pix.load("../qt/images/leetCode.png");

    // 绘制到指定位置
    painter.drawPixmap(100, 0, pix.width(), pix.height(), pix);

    // 对图片进行编辑绘画
    // 画刷
    painter.setBrush(QColor(0, 0, 255, 100));
    painter.drawRect(100, 0, pix.width(), pix.height());

    // 编辑文字
    QRect rect(100, 0, 150, 150);
    painter.drawText(rect, Qt::AlignCenter, tr("文字编辑"));





}































