#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent), vista(nullptr),
                                          modello(nullptr), saved(true), filenameSaved("")
{}

void Controller::setView(Vista *v)
{
    vista = v;
    connect(vista,SIGNAL(simulazioneRichiesta(Sensore*)),this,SLOT(simulazione(Sensore*)));
    connect(vista, SIGNAL(aggiungiSensore(dialogValues)), this, SLOT(add(dialogValues)));
    connect(vista, SIGNAL(modificaSensore(dialogValues, unsigned int)), this, SLOT(set(dialogValues, unsigned int)));
    connect(vista, SIGNAL(rimuoviSensore(unsigned int)), this, SLOT(remove(unsigned int)));

    if(modello && vista){
        this->vista->setSensori(modello->getSensori());
        this->vista->aggiornaDati();
    }
}

void Controller::setModel(Model *m)
{
    modello = m;

    if(modello && vista){
        this->vista->setSensori(modello->getSensori());
        this->vista->aggiornaDati();
    }
}

Controller::~Controller()
{
    delete modello;
    delete vista;
}

void Controller::add(dialogValues dati)
{
    try
    {
        this->modello->addNewSensore(dati.type.toStdString(), dati.name.toStdString(), dati.precisione, dati.minValidTemperatura, dati.maxValidTemperatura, dati.minValidFirstVector, dati.maxValidFirstVector, dati.minValidSecondVector, dati.maxValidSecondVector);
        saved = false;
        this->vista->aggiornaDati();
    }
    catch (std::runtime_error e)
    {
        vista->showWarning(QString::fromStdString(e.what()));
    }
    catch (std::invalid_argument e)
    {
        vista->showWarning(QString::fromStdString(e.what()));
    }
    catch (std::out_of_range e)
    {
        vista->showWarning(QString::fromStdString(e.what()));
    }
}

void Controller::set(dialogValues dati, unsigned int posizione)
{
    try
    {
        this->modello->setSensore(posizione, dati.type.toStdString(), dati.name.toStdString(), dati.precisione, dati.minValidTemperatura, dati.maxValidTemperatura, dati.minValidFirstVector, dati.maxValidFirstVector, dati.minValidSecondVector, dati.maxValidSecondVector);
        saved = false;
        this->vista->aggiornaDati();
    }
    catch (std::runtime_error e)
    {
        vista->showWarning(QString::fromStdString(e.what()));
    }
    catch (std::invalid_argument e)
    {
        vista->showWarning(QString::fromStdString(e.what()));
    }
    catch (std::out_of_range e)
    {
        vista->showWarning(QString::fromStdString(e.what()));
    }
}

void Controller::remove(unsigned int posizione)
{
    try
    {
        this->modello->removeSensore(posizione);
        this->vista->checkActiveSensor(this->modello->getSensori());
        saved = false;
        this->vista->aggiornaDati();
    }
    catch (std::runtime_error e)
    {
        vista->showWarning(QString::fromStdString(e.what()));
    }

    catch (std::invalid_argument e)
    {
        vista->showWarning(QString::fromStdString(e.what()));
    }

    catch (std::out_of_range e)
    {
        vista->showWarning(QString::fromStdString(e.what()));
    }
}

void Controller::save()
{
    try
    {
        if (filenameSaved == "")
            filenameSaved = xmlFileHandler::getWriteFileName(vista);
        QFile file(filenameSaved);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(vista, tr("QXmlStream"),
                                 tr("Cannot write file %1:\n%2.")
                                     .arg(QDir::toNativeSeparators(filenameSaved),
                                          file.errorString()));
            throw std::runtime_error("Errore all'apertura del file!");
        }

        xmlFileHandler::write(&file, *modello->getSensori());

        QMessageBox::information(vista, "Salvataggio", "Salvataggio avvenuto correttamente!");
        saved = true;
    }
    catch (std::runtime_error e)
    {
        if (!saved)
            filenameSaved = "";

        vista->showWarning(e.what());
    }
}

void Controller::saveAs() const
{
    try
    {
        QString fileName = xmlFileHandler::getWriteFileName(vista);
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(vista, tr("QXmlStream"),
                                 tr("Cannot write file %1:\n%2.")
                                     .arg(QDir::toNativeSeparators(fileName),
                                          file.errorString()));
            throw std::runtime_error("Errore all'apertura del file!");
        }

        xmlFileHandler::write(&file, *modello->getSensori());

        QMessageBox::information(vista, "Salvataggio", "Salvataggio avvenuto correttamente!");
    }
    catch (std::runtime_error e)
    {
        vista->showWarning(e.what());
    }
}

void Controller::open()
{
    try
    {
        if (!saved && QMessageBox::information(vista, "Salvataggio", "I dati non sono salvati, salvare?", QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
            save();

        QString fileName = xmlFileHandler::getReadFileName(vista);
        QFile file(fileName);

        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(vista, tr("QXmlStream"),
                                 tr("Cannot read file %1:\n%2.")
                                     .arg(QDir::toNativeSeparators(fileName),
                                          file.errorString()));
            throw std::runtime_error("Errore all'apertura del file!");
        }

        modello->removeSensori();
        vista->resetSensoreAttivo();
        vista->aggiornaDati();

        std::vector<Sensore*> values = xmlFileHandler::read(&file);

        for (auto it : values)
        {
            SensoreAcqua* sensoreAcqua = dynamic_cast<SensoreAcqua*>(it);
            SensoreAria* sensoreAria = dynamic_cast<SensoreAria*>(it);
            SensoreSuolo* sensoreSuolo = dynamic_cast<SensoreSuolo*>(it);

            if(sensoreAcqua){
                modello->addSensore(sensoreAcqua);
            } else if(sensoreAria){
                modello->addSensore(sensoreAria);
            } else if(sensoreSuolo){
                modello->addSensore(sensoreSuolo);
            } else {
                throw std::runtime_error("Il sensore letto non è di tipo noto!");
            }

        }
        saved = true;
        filenameSaved = fileName;

        vista->aggiornaDati();
    }
    catch (std::runtime_error e)
    {
        vista->showWarning(e.what());
    }
}

void Controller::closeApp()
{
    try {
        if(!saved && QMessageBox::information(vista,"Salvataggio", "I dati non sono salvati, salvare?", QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
            save();

        vista->close();
    }
    catch (std::runtime_error e) {
        vista->showWarning(e.what());
    }
}

void Controller::simulazione(Sensore *sensore)
{
    try {
        modello->simulaSensore(sensore);
        saved = false;
        vista->aggiornaDati();
    } catch (std::runtime_error e) {
        vista->showWarning(e.what());
    }

}
