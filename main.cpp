#include "vista.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Vista v;
    v.show();
    return a.exec();
}
