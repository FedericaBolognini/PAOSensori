#include "Modello.h"

Model::Model() : collezioneSensori(new CollezioneSensori()) {}

void Model::addNewSensore(const std::string &Type, const std::string &Nome, unsigned int Precisione,
                          double MinValidTemperatura, double MaxValidTemperatura,
                          int MinValidFirstVector, int MaxValidFirstVector, int MinValidSecondVector, int MaxValidSecondVector) const {
    unsigned int ID = 0;
    const std::vector<Sensore *>*sensori = collezioneSensori->getSensori();
    for (auto it = sensori->begin(); it != sensori->end(); ++it){
        if (ID < (*it)->getID())
        {
            ID = (*it)->getID();
        }
    }
    collezioneSensori->addSensore(SensoreCreator::createSensore(Type, ID + 1, Nome, Precisione, MinValidTemperatura, MaxValidTemperatura,
                                  MinValidFirstVector, MaxValidFirstVector, MinValidSecondVector, MaxValidSecondVector));
}

void Model::addSensore(Sensore *sensore) const
{
    if(sensore){
        collezioneSensori->addSensore(sensore);
    } else {
        throw std::runtime_error("Tentativo di inserimento di un sensore nullo!");
    }

}

void Model::insertNewSensore(const std::string &Type, const std::string &Nome, unsigned int Precisione, 
                             double MinValidTemperatura, double MaxValidTemperatura, 
                             int MinValidFirstVector, int MaxValidFirstVector, int MinValidSecondVector, int MaxValidSecondVector,
                             unsigned int posizione) {
    unsigned int ID = 0;
    const std::vector<Sensore *> *sensori = collezioneSensori->getSensori();
    for (auto it = sensori->begin(); it != sensori->end(); ++it){
        if (ID < (*it)->getID())
        {
            ID = (*it)->getID();
        }
    }
    collezioneSensori->insertSensore(SensoreCreator::createSensore(Type, ID + 1, Nome, Precisione, MinValidTemperatura, MaxValidTemperatura,
                                     MinValidFirstVector, MaxValidFirstVector, MinValidSecondVector, MaxValidSecondVector), posizione);
}

void Model::setSensore(unsigned int Posizione, const std::string &Tipo, const std::string &Nome, unsigned int Precisione,
                       double minValidTemperatura, double maxValidTemperatura,
                       int MinValidFirstVector, int MaxValidFirstVector, int MinValidSecondVector, int MaxValidSecondVector) const {
    collezioneSensori->setSensore(Posizione, Tipo, Nome, Precisione, minValidTemperatura, maxValidTemperatura,
                                  MinValidFirstVector, MaxValidFirstVector, MinValidSecondVector, MaxValidSecondVector);
}

void Model::removeSensore(unsigned int posizione) const {
    collezioneSensori->removeSensore(posizione);
}

Sensore* Model::getSensore(unsigned int posizione) const {
    return collezioneSensori->getSensore(posizione);
}

const std::vector<Sensore*>* Model::getSensori() const {
    return collezioneSensori->getSensori();
}

unsigned int Model::getSize() const {
    return collezioneSensori->getSize();
}

bool Model::isEmpty() const {
    return collezioneSensori->isEmpty();
}

void Model::removeSensori() const {
    collezioneSensori->clear();
}

void Model::simulaSensore(Sensore *sensore) const
{
    SensoreSimulator::simulazioneSensore(sensore);
}

Model::Model(const Model &model) : collezioneSensori(new CollezioneSensori(*model.collezioneSensori)) {}

Model& Model::operator=(const Model &model) {
    if (this != &model) {
        delete collezioneSensori;
        collezioneSensori = new CollezioneSensori(*model.collezioneSensori);
    }
    return *this;
}

Model::~Model() {
    delete collezioneSensori;
}
