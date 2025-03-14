#include <tabellaSensori.h>

TabellaSensori::TabellaSensori(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(10, 5, 10, 5);

    sensori = nullptr;

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

    int currentRowCount = tableWidget->rowCount();
    tableWidget->insertRow(currentRowCount);
    layout->addWidget(tableWidget,0);
}

void TabellaSensori::addButtons(QHBoxLayout *layout)
{
    bottomButtonElimina = new QPushButton("Elimina", this);
    bottomButtonElimina->setStyleSheet("background-color:red; color:white; height: 20px; width: 100px;");

    bottomButtonModifica = new QPushButton("Modifica", this);
    bottomButtonModifica->setStyleSheet("background-color:orange; color:white; height: 20px; width: 100px;");

    bottomButtonAggiungi = new QPushButton("Aggiungi", this);
    bottomButtonAggiungi->setStyleSheet("background-color:green; color:white; height: 20px; width: 100px;");

    layout->addWidget(bottomButtonElimina);
    layout->addWidget(bottomButtonModifica);
    layout->addWidget(bottomButtonAggiungi);
    layout->setSpacing(10);
    layout->setContentsMargins(0, 5, 0, 5);
}

void TabellaSensori::setupConnections()
{
    connect(searchButton, SIGNAL(clicked()), this, SLOT(aggiornaDati()));
    connect(bottomButtonElimina, SIGNAL(clicked()), this, SLOT(gestisciRichiestaElimina()));
    connect(bottomButtonModifica, SIGNAL(clicked()), this, SLOT(gestisciRichiestaModifica()));
    connect(bottomButtonAggiungi, SIGNAL(clicked()), this, SLOT(gestisciRichiestaAggiungi()));
    connect(tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(cellDoubleClicked(int, int)));
}

void TabellaSensori::pulisciTabella()
{
    unsigned int dimensioneTabella = tableWidget->rowCount();
    for(unsigned int i=0; i < dimensioneTabella; i++){
        tableWidget->removeRow(0);
    }
}

void TabellaSensori::aggiornaDati()
{
    if(!sensori){
        return;
    }

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

        if(!tableWidget->rowCount()){
            tableWidget->insertRow(0);
        }
    }
}

void TabellaSensori::gestisciRichiestaModifica()
{
    try {
        if(sensori->size()){
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

                dialogValues valori;

                if(tipo == "Acqua"){
                    valori = sensoreAcquaDialog::getValues(this, &ok, set , dynamic_cast<SensoreAcqua*>(sensori->at(posizione)));
                }

                if(tipo == "Aria"){
                    valori = sensoreAriaDialog::getValues(this, &ok, set , dynamic_cast<SensoreAria*>(sensori->at(posizione)));
                }

                if(tipo == "Suolo"){
                    valori = sensoreSuoloDialog::getValues(this, &ok, set , dynamic_cast<SensoreSuolo*>(sensori->at(posizione)));
                }

                emit modificaSensore(valori, posizione);

            }
        } else {
            this->showWarning("Non ci sono sensori da modificare!");
        }
    } catch (const std::runtime_error& e) {
        showWarning(e.what());
    }
}
void TabellaSensori::gestisciRichiestaElimina()
{
    try {
        if(sensori->size()){
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

                emit rimuoviSensore(posizione);
            }
        } else {
            this->showWarning("Non ci sono sensori da eliminare!");
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
            dialogValues valori;
            if(type == "Acqua"){
                valori = sensoreAcquaDialog::getValues(this, &ok, add ,nullptr);
            }
            if(type == "Aria"){
                valori = sensoreAriaDialog::getValues(this, &ok, add ,nullptr);
            }
            if(type == "Suolo"){
                valori = sensoreSuoloDialog::getValues(this, &ok, add ,nullptr);
            }

            emit aggiungiSensore(valori);
        }
    } catch (const std::runtime_error& e) {
        showWarning(e.what());
    }

}

void TabellaSensori::showWarning(const QString &message)
{
    QMessageBox::warning(this, "Errore", message,QMessageBox::Ok);
}

void TabellaSensori::setSensori(const std::vector<Sensore *> *sensori)
{
    this->sensori = sensori;
}

void TabellaSensori::cellDoubleClicked(int iRow, int iColumn)
{
    tableWidget->setRangeSelected(QTableWidgetSelectionRange(iRow, 0, iRow, tableWidget->columnCount() - 1), 1);
    unsigned int idSensore = 0;

    if(tableWidget->item(iRow, 2) != NULL){
        idSensore =  std::stoi(tableWidget->item(iRow, 2)->text().toStdString());
    }

    Sensore* sensoreSelezionato = nullptr;

    if(sensori){
        for(Sensore* sensore: *sensori){
            if(sensore->getID() == idSensore){
                sensoreSelezionato = sensore;
                break;
            }
        }
    }

    if(sensoreSelezionato){
        emit selezioneSensore(sensoreSelezionato);
    }

}
