#include "window.h"

Window::Window()
{
    setWindowTitle(tr("QPatiner 学习"));

    m_label = new QLabel(this);

    // 加载图片路径
    m_pixmap.load(":/images/leetCode.png");

    m_label->setPixmap(m_pixmap);

    auto width = m_pixmap.width();
    auto height = m_pixmap.height();
    m_label->resize(width, height);

}
