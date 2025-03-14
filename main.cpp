#include "./Vista/vista.h"
#include "./Modello/Modello.h"
#include "./Controller/controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/assets/metering.png"));

    Model *m = new Model();
    Vista* v = new Vista();
    Controller* c = new Controller();

    c->setModel(m);
    c->setView(v);
    v->setController(c);

    a.setApplicationName("EnviroSense");
    a.setApplicationDisplayName("EnviroSense");

    v->show();
    return a.exec();
}
