/*
 * 基础的绘画例子
 *
    Copyright (C) 2016 The Qt Company Ltd.
    SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

    The Basic Drawing example consists of two classes:

    1.RenderArea is a custom widget that renders multiple copies of the currently active shape.
    2.Window is the application's main window displaying a RenderArea widget in addition to several parameter widgets.
*/


#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // nitializes the resources specified by the .qrc file with the specified base name.
    Q_INIT_RESOURCE(basicdrawing);

    QApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();
}
