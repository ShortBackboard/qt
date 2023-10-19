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
    // 绘制文字
    /*
     * 除了绘制图形以外，还可以使用QPainter::drawText()函数来绘制文字
     * 也可以使用QPainter::setFont来设置绘制文字所使用的字体
     * 使用QPainter::fontInfo()函数可以获取字体信息，它返回QFontInfo类对象。
     * 绘制文字时会默认使用抗锯齿
    */

    QPainter painter(this);
    QRect rect(10.0, 10.0, 400, 400);
    painter.drawRect(rect);

    painter.setPen(Qt::red);

    //  绘制文字所在的矩形盒子，文字在盒子中的对齐方式，要绘制的文字内容，第四个参数一般可省
    // 文字的多个不同的对齐方式可以使用’|'符号连接它们以同时使用
    painter.drawText(rect, Qt::AlignCenter, tr("中心"));
    painter.drawText(rect, Qt::AlignHCenter, tr("垂直居中"));
    painter.drawText(rect, Qt::AlignRight, tr("右上"));


    // 字体族，字体大小(默认12)，字体weight，是否使用斜体
    QFont font("宋体", 15, QFont::Bold, true);
    font.setUnderline(true);	// 下划线
    font.setOverline(true);		// 中划线
    font.setCapitalization(QFont::SmallCaps);	// 字母大写
    font.setLetterSpacing(QFont::AbsoluteSpacing, 10);      // 设置字符间间距
    painter.setFont(font);
    painter.setPen(Qt::green);
    painter.drawText(120, 80, tr("drawText()的另一种重载形式"));

    // 平移和旋转坐标系
    painter.translate(100, 100);
    painter.rotate(90);
    painter.drawText(0, 0, tr("heloQt"));


}































