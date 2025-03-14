#include "vista.h"
#include "../Controller/controller.h"

void Vista::addMenus(QVBoxLayout *mainLayout)
{
    menuBar = new QMenuBar(this);
    file = new QMenu("File", menuBar);
    menuBar->addMenu(file);
    file->addAction(new QAction("Salva", file));
    file->addAction(new QAction("Salva con nome", file));
    file->addAction(new QAction("Ripristina", file));
    file->addAction(new QAction("Chiudi", file));


    connect(file->actions().at(0),SIGNAL(triggered()),this,SIGNAL(save()));
    connect(file->actions().at(1),SIGNAL(triggered()),this,SIGNAL(saveAs()));
    connect(file->actions().at(2),SIGNAL(triggered()),this,SIGNAL(open()));

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

    setupConnections();

    setLayout(mainLayout);
}

void Vista::setupConnections()
{
    connect(leftWidget, SIGNAL(selezioneSensore(Sensore*)), this, SIGNAL(selezioneSensore(Sensore*)));
    connect(leftWidget, SIGNAL(aggiungiSensore(dialogValues)), this, SIGNAL(aggiungiSensore(dialogValues)));
    connect(leftWidget, SIGNAL(modificaSensore(dialogValues, unsigned int)), this, SIGNAL(modificaSensore(dialogValues, unsigned int)));
    connect(leftWidget, SIGNAL(rimuoviSensore(unsigned int)), this, SIGNAL(rimuoviSensore(unsigned int)));
    connect(rightWidget, SIGNAL(simulazioneRichiesta(Sensore* )), this, SIGNAL(simulazioneRichiesta(Sensore*)));
}

void Vista::showWarning(const QString &message)
{
    QMessageBox::warning(this, "Errore", message,QMessageBox::Ok);
}

void Vista::setController(Controller *controller)
{
    this->controller = controller;

    connect(this, SIGNAL(open()), controller, SLOT(open()));
    connect(this, SIGNAL(save()), controller, SLOT(save()));
    connect(this, SIGNAL(saveAs()), controller, SLOT(saveAs()));
    connect(file->actions().at(3),SIGNAL(triggered()),controller,SLOT(closeApp()));
}

void Vista::setSensori(const std::vector<Sensore *>* sensori) const
{
    this->leftWidget->setSensori(sensori);
}

void Vista::checkActiveSensor(const std::vector<Sensore *> *sensori) const
{
    this->rightWidget->checkSensoreAttivo(sensori);
}

void Vista::resetSensoreAttivo() const
{
    this->rightWidget->resetSensoreAttivo();
}

void Vista::aggiornaDati()
{
    leftWidget->aggiornaDati();
    rightWidget->aggiornaDati();
}

Vista::~Vista() {}
