#include "qtcamer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtCamer w;
    w.show();

    return a.exec();
}
