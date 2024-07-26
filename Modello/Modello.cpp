#include "Modello.h"
#include <stdexcept>

Model::Model() : collezioneSensori(new CollezioneSensori()) {}

void Model::addNewSensore(const std::string &Type, unsigned int ID, const std::string &Nome, unsigned int Precisione, 
                          double MinValidTemperatura, double MaxValidTemperatura, 
                          int MinValidAlcalinità, int MaxValidAlcalinità, int MinValidAcidità, int MaxValidAcidità, 
                          int MinValidOssigeno, int MaxValidOssigeno, int MinValidCO2, int MaxValidCO2,
                          int MinValidUmidità, int MaxValidUmidità, int MinValidPH, int MaxValidPH) const {
    collezioneSensori->addSensore(SensoreCreator::createSensore(Type, ID, Nome, Precisione, MinValidTemperatura, MaxValidTemperatura,
                                  MinValidAlcalinità, MaxValidAlcalinità, MinValidAcidità, MaxValidAcidità,
                                  MinValidOssigeno, MaxValidOssigeno, MinValidCO2, MaxValidCO2,
                                  MinValidUmidità, MaxValidUmidità, MinValidPH, MaxValidPH));
}

void Model::insertNewSensore(const std::string &Type, unsigned int ID, const std::string &Nome, unsigned int Precisione, 
                             double MinValidTemperatura, double MaxValidTemperatura, 
                             int MinValidAlcalinità, int MaxValidAlcalinità, int MinValidAcidità, int MaxValidAcidità, 
                             int MinValidOssigeno, int MaxValidOssigeno, int MinValidCO2, int MaxValidCO2,
                             int MinValidUmidità, int MaxValidUmidità, int MinValidPH, int MaxValidPH, 
                             unsigned int posizione) {
    collezioneSensori->insertSensore(SensoreCreator::createSensore(Type, ID, Nome, Precisione, MinValidTemperatura, MaxValidTemperatura,
                                     MinValidAlcalinità, MaxValidAlcalinità, MinValidAcidità, MaxValidAcidità,
                                     MinValidOssigeno, MaxValidOssigeno, MinValidCO2, MaxValidCO2,
                                     MinValidUmidità, MaxValidUmidità, MinValidPH, MaxValidPH), posizione);
}

void Model::setSensore(unsigned int Posizione, const std::string &Nome, unsigned int Precisione, 
                       double minValidTemperatura, double maxValidTemperatura, 
                       int minValidAlcalinità, int maxValidAlcalinità, int minValidAcidità, int maxValidAcidità, 
                       int minValidOssigeno, int maxValidOssigeno, int minValidCO2, int maxValidCO2,
                       int minValidUmidità, int maxValidUmidità, int minValidPH, int maxValidPH) const {
    collezioneSensori->setSensore(Posizione, Nome, Precisione, minValidTemperatura, maxValidTemperatura,
                                  minValidAlcalinità, maxValidAlcalinità, minValidAcidità, maxValidAcidità,
                                  minValidOssigeno, maxValidOssigeno, minValidCO2, maxValidCO2,
                                  minValidUmidità, maxValidUmidità, minValidPH, maxValidPH);
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