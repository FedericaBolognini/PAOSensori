#include "vista.h"

void Vista::addMenus(QVBoxLayout *mainLayout)
{
    menuBar = new QMenuBar(this);
    file = new QMenu("File", menuBar);
    menuBar->addMenu(file);
    file->addAction(new QAction("Salva", file));
    file->addAction(new QAction("Ripristina", file));
    file->addAction(new QAction("Chiudi", file));
    mainLayout->addWidget(menuBar);
}

Vista::Vista(QWidget *parent) : QWidget(parent)
{

    // Creazione layout principale
    mainLayout = new QVBoxLayout;

    leftWidget = new TabellaSensori(this);
    rightWidget = new DettagliSensore(this);

    // Aggiunta menù
    addMenus(mainLayout);

    // Creazione layout orizzontale principale
    horizontalmainLayout = new QHBoxLayout;

    // Aggiunta layout sinistro e destro al principale
    horizontalmainLayout->addWidget(leftWidget);
    horizontalmainLayout->addWidget(rightWidget);
    horizontalmainLayout->setStretch(0, 1);
    horizontalmainLayout->setStretch(1, 1);

    mainLayout->addLayout(horizontalmainLayout);
    mainLayout->setSpacing(0);

    setLayout(mainLayout);
}
Vista::~Vista() {};
