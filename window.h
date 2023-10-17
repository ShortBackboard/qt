#ifndef WINDOW_H
#define WINDOW_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include <QtWidgets>
#include <QPainter>
#include <QPainterPath>
#include <QLabel>


class Window : public QWidget
{
    Q_OBJECT

// 构造函数
public:
    Window();

protected:
    // 绘画
    // void paintEvent(QPaintEvent *event) override;

private:
    QLabel *m_label;
    QPen *m_pen;
    QBrush *m_brush;
    QPixmap m_pixmap; // 加载图片，用于渲染和显示
};


#endif // WINDOW_H
