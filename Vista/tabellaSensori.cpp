#include <tabellaSensori.h>

TabellaSensori::TabellaSensori(QWidget *parent) : QWidget(parent)
{

    // SOTTO QUI E' DA TOGLIERE ASSOLUTAMENTE

    Sensore* s1 = new SensoreAcqua("Acqua1", 95, 1, 15.0, 40.0, 850, 950, 220000, 290000);
    Sensore* s2 = new SensoreAria("Aria1", 90, 2, 10.0, 35.0, 300, 500, 19, 21);
    Sensore* s4 = new SensoreSuolo("Suolo1", 90, 2, 10.0, 35.0, 300, 500, 19, 21);
    Sensore* s3 = s1->clone();
    s3->setNome("Acqua2");

    sensori = new std::vector<Sensore*>();
    sensori->push_back(s1);
    sensori->push_back(s2);
    sensori->push_back(s3);
    sensori->push_back(s4);

    // SOPRA QUI E' DA TOGLIERE ASSOLUTAMENTE
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
    tableWidget = new QTableWidget(0, 5, this);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Nome" << "Tipo" << "ID" << "Precisione" << "Qualità");
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

    for(Sensore* sensore: *sensori) {
        int currentRowCount = tableWidget->rowCount();
        tableWidget->insertRow(currentRowCount);

        std::string tipo = typeid(*sensore).name();
        tipo = tipo.substr(9);
        std::string id = std::to_string(sensore->getID());
        std::string precisione = std::to_string(sensore->getPrecisione());
        std::string qualità = std::to_string(sensore->Qualità());

        QTableWidgetItem* nome = new QTableWidgetItem(QString::fromStdString(sensore->getNome()));
        QTableWidgetItem* tipoItem = new QTableWidgetItem(QString::fromStdString(tipo));
        QTableWidgetItem* idItem = new QTableWidgetItem(QString::fromStdString(id));
        QTableWidgetItem* precisioneItem = new QTableWidgetItem(QString::fromStdString(precisione));
        QTableWidgetItem* qualitàItem = new QTableWidgetItem(QString::fromStdString(qualità));

        nome->setTextAlignment(Qt::AlignCenter);
        tipoItem->setTextAlignment(Qt::AlignCenter);
        idItem->setTextAlignment(Qt::AlignCenter);
        precisioneItem->setTextAlignment(Qt::AlignCenter);
        qualitàItem->setTextAlignment(Qt::AlignCenter);

        tableWidget->setItem(currentRowCount, 0, nome);
        tableWidget->setItem(currentRowCount, 1, tipoItem);
        tableWidget->setItem(currentRowCount, 2, idItem);
        tableWidget->setItem(currentRowCount, 3, precisioneItem);
        tableWidget->setItem(currentRowCount, 4, qualitàItem);
    };


    layout->addWidget(tableWidget,0);
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

void TabellaSensori::pulisciTabella()
{
    unsigned int dimensioneTabella = tableWidget->rowCount();
    for(unsigned int i=0; i < dimensioneTabella; i++){
        tableWidget->removeRow(0);
    }
}
void TabellaSensori::gestisciRichiestaCerca()
{
    QString searchText = searchBar->text();
    pulisciTabella();

    if(searchText != ""){
        std::vector<Sensore*> aux;

        for(Sensore* sensore: *sensori){
            std::string tipo = typeid(*sensore).name();
            tipo = tipo.substr(9);

            if(sensore->getNome() == searchText.toStdString() || tipo == searchText.toStdString()){
                aux.push_back(sensore);
            }
        }

        for(Sensore* sensore: aux) {
            int currentRowCount = tableWidget->rowCount();
            tableWidget->insertRow(currentRowCount);

            std::string tipo = typeid(*sensore).name();
            tipo = tipo.substr(9);
            std::string id = std::to_string(sensore->getID());
            std::string precisione = std::to_string(sensore->getPrecisione());
            std::string qualità = std::to_string(sensore->Qualità());

            QTableWidgetItem* nome = new QTableWidgetItem(QString::fromStdString(sensore->getNome()));
            QTableWidgetItem* tipoItem = new QTableWidgetItem(QString::fromStdString(tipo));
            QTableWidgetItem* idItem = new QTableWidgetItem(QString::fromStdString(id));
            QTableWidgetItem* precisioneItem = new QTableWidgetItem(QString::fromStdString(precisione));
            QTableWidgetItem* qualitàItem = new QTableWidgetItem(QString::fromStdString(qualità));

            nome->setTextAlignment(Qt::AlignCenter);
            tipoItem->setTextAlignment(Qt::AlignCenter);
            idItem->setTextAlignment(Qt::AlignCenter);
            precisioneItem->setTextAlignment(Qt::AlignCenter);
            qualitàItem->setTextAlignment(Qt::AlignCenter);

            tableWidget->setItem(currentRowCount, 0, nome);
            tableWidget->setItem(currentRowCount, 1, tipoItem);
            tableWidget->setItem(currentRowCount, 2, idItem);
            tableWidget->setItem(currentRowCount, 3, precisioneItem);
            tableWidget->setItem(currentRowCount, 4, qualitàItem);
        };
    } else {
        for(Sensore* sensore: *sensori) {
            int currentRowCount = tableWidget->rowCount();
            tableWidget->insertRow(currentRowCount);

            std::string tipo = typeid(*sensore).name();
            tipo = tipo.substr(9);
            std::string id = std::to_string(sensore->getID());
            std::string precisione = std::to_string(sensore->getPrecisione());
            std::string qualità = std::to_string(sensore->Qualità());

            QTableWidgetItem* nome = new QTableWidgetItem(QString::fromStdString(sensore->getNome()));
            QTableWidgetItem* tipoItem = new QTableWidgetItem(QString::fromStdString(tipo));
            QTableWidgetItem* idItem = new QTableWidgetItem(QString::fromStdString(id));
            QTableWidgetItem* precisioneItem = new QTableWidgetItem(QString::fromStdString(precisione));
            QTableWidgetItem* qualitàItem = new QTableWidgetItem(QString::fromStdString(qualità));

            nome->setTextAlignment(Qt::AlignCenter);
            tipoItem->setTextAlignment(Qt::AlignCenter);
            idItem->setTextAlignment(Qt::AlignCenter);
            precisioneItem->setTextAlignment(Qt::AlignCenter);
            qualitàItem->setTextAlignment(Qt::AlignCenter);

            tableWidget->setItem(currentRowCount, 0, nome);
            tableWidget->setItem(currentRowCount, 1, tipoItem);
            tableWidget->setItem(currentRowCount, 2, idItem);
            tableWidget->setItem(currentRowCount, 3, precisioneItem);
            tableWidget->setItem(currentRowCount, 4, qualitàItem);
        };
    }



}
void TabellaSensori::pulisciCampoRicerca()
{
    
}
void TabellaSensori::gestisciRichiestaModifica()
{
    try {
        bool ok = false;
        QString selezione = finestraSensore::getSensore(this,sensori,&ok);
        unsigned int posizione = 0;

        if(ok){
            for(unsigned int i=0; i < sensori->size(); i++){
                QString etichettaSensore = QString::fromStdString(std::to_string(sensori->at(i)->getID()) + " - " + sensori->at(i)->getNome());

                if(etichettaSensore == selezione){
                    posizione = i;
                    i = sensori->size();
                }
            }

            std::string tipo = typeid(*sensori->at(posizione)).name();
            tipo = tipo.substr(9);

            if(tipo == "Acqua"){
                dialogValues valori = sensoreAcquaDialog::getValues(this, &ok, set , dynamic_cast<SensoreAcqua*>(sensori->at(posizione)));
                std::cout<<valori.name.toStdString()<<std::endl;
                std::cout<<valori.precisione<<std::endl;
                std::cout<<valori.minValidTemperatura<<std::endl;
                std::cout<<valori.minValidFirstVector<<std::endl;
                std::cout<<valori.minValidSecondVector<<std::endl;
                std::cout<<valori.maxValidTemperatura<<std::endl;
                std::cout<<valori.maxValidFirstVector<<std::endl;
                std::cout<<valori.maxValidSecondVector<<std::endl;
            }

            if(tipo == "Aria"){
                dialogValues valori = sensoreAriaDialog::getValues(this, &ok, set , dynamic_cast<SensoreAria*>(sensori->at(posizione)));
            }

            if(tipo == "Suolo"){
                dialogValues valori = sensoreSuoloDialog::getValues(this, &ok, set , dynamic_cast<SensoreSuolo*>(sensori->at(posizione)));
            }


        }
    } catch (const std::runtime_error& e) {
        showWarning(e.what());
    }
}
void TabellaSensori::gestisciRichiestaElimina()
{
    try {
        bool ok = false;
        QString selezione = finestraSensore::getSensore(this,sensori,&ok);
        unsigned int posizione = 0;

        if(ok){
            for(unsigned int i=0; i < sensori->size(); i++){
                QString etichettaSensore = QString::fromStdString(std::to_string(sensori->at(i)->getID()) + " - " + sensori->at(i)->getNome());

                if(etichettaSensore == selezione){
                    posizione = i;
                    i = sensori->size();
                }
            }
        }
    } catch (const std::runtime_error& e) {
        showWarning(e.what());
    }
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
    } catch (const std::runtime_error& e) {
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

