/*
 * QPainter 学习
*/

#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // nitializes the resources specified by the .qrc file with the specified base name.
    Q_INIT_RESOURCE(drawtest);

    QApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();
}
