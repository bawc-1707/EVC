#include "displaywindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DisplayWindow w;
    w.show();
    return a.exec();
}
