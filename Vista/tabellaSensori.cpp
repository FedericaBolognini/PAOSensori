#include <tabellaSensori.h>

TabellaSensori::TabellaSensori(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(10, 5, 10, 5);

    addFindSection(mainLayout);
    addTable(mainLayout);

    // Creazione layout bottoni
    bottomButtonLayout = new QHBoxLayout;

    // Aggiunta bottoni
    addButtons(bottomButtonLayout);

    // Aggiunta layout bottoni al layout di sinistra
    mainLayout->addLayout(bottomButtonLayout);

    setupConnections();

    setLayout(mainLayout);
}

TabellaSensori::~TabellaSensori() {}

void TabellaSensori::addFindSection(QVBoxLayout *layout)
{
    searchBar = new QLineEdit(this);
    searchBar->setPlaceholderText("Cerca sensori...");
    searchButton = new QPushButton("Cerca", this);

    layout->addWidget(searchBar);
    layout->addWidget(searchButton);
}

void TabellaSensori::addTable(QVBoxLayout *layout)
{
    tableWidget = new QTableWidget(3, 5, this);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Nome" << "Tipo" << "ID" << "Precisione" << "Qualità");
    // tableWidget->setVerticalHeaderLabels(QStringList()<<"Sensore Acqua"<<"Sensore Aria"<<"Sensore Suolo");//?
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout->addWidget(tableWidget, 0, Qt::AlignBottom);
}

void TabellaSensori::addButtons(QHBoxLayout *layout)
{
    bottomButtonElimina = new QPushButton("Elimina", this);
    bottomButtonElimina->setStyleSheet("background-color:red");

    bottomButtonModifica = new QPushButton("Modifica", this);
    bottomButtonModifica->setStyleSheet("background-color:orange");

    bottomButtonAggiungi = new QPushButton("Aggiungi", this);
    bottomButtonAggiungi->setStyleSheet("background-color:green");

    layout->addWidget(bottomButtonElimina);
    layout->addWidget(bottomButtonModifica);
    layout->addWidget(bottomButtonAggiungi);
    layout->setSpacing(10);
    layout->setContentsMargins(0, 5, 0, 5);
}

void TabellaSensori::setupConnections()
{
    connect(searchButton, SIGNAL(clicked()), this, SLOT(gestisciRichiestaCerca()));
    connect(bottomButtonElimina, SIGNAL(clicked()), this, SLOT(gestisciRichiestaElimina()));
    connect(bottomButtonModifica, SIGNAL(clicked()), this, SLOT(gestisciRichiestaModifica()));
    connect(bottomButtonAggiungi, SIGNAL(clicked()), this, SLOT(gestisciRichiestaAggiungi()));
}
void TabellaSensori::gestisciRichiestaCerca()
{

}
void TabellaSensori::pulisciCampoRicerca()
{
    
}
void TabellaSensori::gestisciRichiestaModifica()
{

}
void TabellaSensori::gestisciRichiestaElimina()
{

}
void TabellaSensori::gestisciRichiestaAggiungi()
{
    try {
        bool ok = false;
        QString type = finestraTipo::getTipo(this, &ok);
        if(ok){
            if(type == "Acqua"){
                dialogValues valori = sensoreAcquaDialog::getValues(this, &ok, add ,nullptr);
            }
            if(type == "Aria"){
                dialogValues valori = sensoreAriaDialog::getValues(this, &ok, add ,nullptr);
            }
            if(type == "Suolo"){
                dialogValues valori = sensoreSuoloDialog::getValues(this, &ok, add ,nullptr);
            }

        }
    } catch (std::runtime_error e) {
        showWarning(e.what());
    }

}
void TabellaSensori::aggiornaTabella()
{

}
void TabellaSensori::evidenziaRigaCercata()
{

}

void TabellaSensori::showWarning(const QString &message)
{
    QMessageBox::warning(this, "Errore", message,QMessageBox::Ok);
}

