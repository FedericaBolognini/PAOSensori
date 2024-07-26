#include "CollezioneSensori.h"
#include <stdexcept>

std::vector<Sensore *> CollezioneSensori::copy(const CollezioneSensori &collezione) {
    std::vector<Sensore *> newSensori;
    for (const auto &sensore : collezione.sensori) {
        newSensori.push_back(sensore->clone());
    }
    return newSensori;
}

void CollezioneSensori::destroy(const CollezioneSensori &collezione) {
    for (auto &sensore : collezione.sensori) {
        delete sensore;
    }
}

void CollezioneSensori::addSensore(Sensore *sensore) {
    if (!sensore) {
        throw std::invalid_argument("Sensore non può essere nullptr");
    }
    sensori.push_back(sensore);
}

void CollezioneSensori::insertSensore(Sensore *sensore, unsigned int posizione) {
    if (!sensore) {
        throw std::invalid_argument("Sensore non può essere nullptr");
    }
    if (posizione > sensori.size()) {
        throw std::out_of_range("Posizione non valida");
    }
    sensori.insert(sensori.begin() + posizione, sensore);
}

void CollezioneSensori::removeSensore(unsigned int posizione) {
    if (posizione >= sensori.size()) {
        throw std::out_of_range("Posizione non valida");
    }
    delete sensori[posizione];
    sensori.erase(sensori.begin() + posizione);
}

Sensore *CollezioneSensori::getSensore(unsigned int posizione) const {
    if (posizione >= sensori.size()) {
        throw std::out_of_range("Posizione non valida");
    }
    return sensori[posizione];
}

const std::vector<Sensore *>* CollezioneSensori::getSensori() const {
    return &sensori;
}

unsigned int CollezioneSensori::getSize() const {
    return sensori.size();
}

bool CollezioneSensori::isEmpty() const {
    return sensori.empty();
}

void CollezioneSensori::clear() {
    for (auto &sensore : sensori) {
        delete sensore;
    }
    sensori.clear();
}

void CollezioneSensori::setSensore(unsigned int Posizione, const std::string &Nome, unsigned int Precisione, 
    double MinValidTemperatura, double MaxValidTemperatura, 
    int MinValidAlcalinità, int MaxValidAlcalinità, int MinValidAcidità, int MaxValidAcidità, 
    int MinValidOssigeno, int MaxValidOssigeno, int MinValidCO2, int MaxValidCO2,
    int MinValidUmidità, int MaxValidUmidità, int MinValidPH, int MaxValidPH) {
    
    if (Posizione >= sensori.size()) {
        throw std::out_of_range("Posizione non valida");
    }

    if(Nome == "" || Precisione > 100 || MinValidTemperatura > MaxValidTemperatura || MinValidAcidità > MaxValidAcidità
    || MinValidAlcalinità > MaxValidAlcalinità || MinValidOssigeno > MaxValidOssigeno || MinValidCO2 > MaxValidCO2
    || MinValidUmidità > MaxValidUmidità || MinValidPH > MaxValidPH) {
        throw std::invalid_argument("Parametri di modifica non validi");
    }

    Sensore* sensore = sensori[Posizione];

    sensore->setNome(Nome);
    sensore->setPrecisione(Precisione);
    sensore->setMinValidTemperatura(MinValidTemperatura);
    sensore->setMaxValidTemperatura(MaxValidTemperatura);

    if(MinValidAcidità != INT_MIN && MaxValidAcidità != INT_MAX
    && MinValidAlcalinità != INT_MIN && MaxValidAlcalinità != INT_MAX){

        SensoreAcqua* sensoreAcqua = dynamic_cast<SensoreAcqua*>(sensore);
        sensoreAcqua->setMinValidAlcalinità(MinValidAlcalinità);
        sensoreAcqua->setMaxValidAlcalinità(MaxValidAlcalinità);
        sensoreAcqua->setMinValidAcidità(MinValidAcidità);
        sensoreAcqua->setMaxValidAcidità(MaxValidAcidità);

    } else if(MinValidCO2 != INT_MIN && MaxValidCO2 != INT_MAX
    && MinValidOssigeno != INT_MIN && MaxValidOssigeno != INT_MAX){

        SensoreAria* sensoreAria = dynamic_cast<SensoreAria*>(sensore);
        sensoreAria->setMinValidCO2(MinValidCO2);
        sensoreAria->setMaxValidCO2(MaxValidCO2);
        sensoreAria->setMinValidOssigeno(MinValidOssigeno);
        sensoreAria->setMaxValidOssigeno(MaxValidOssigeno);

    } else if(MinValidPH != INT_MIN && MaxValidPH != INT_MAX
    && MinValidUmidità != INT_MIN && MaxValidUmidità != INT_MAX){

        SensoreSuolo* sensoreSuolo = dynamic_cast<SensoreSuolo*>(sensore);
        sensoreSuolo->setMinValidPH(MinValidPH);
        sensoreSuolo->setMaxValidPH(MaxValidPH);
        sensoreSuolo->setMinValidUmidità(MinValidUmidità);
        sensoreSuolo->setMaxValidUmidità(MaxValidUmidità);

    } else {
        throw std::invalid_argument("Parametri di modifica non validi");
    }
}

CollezioneSensori::CollezioneSensori(const CollezioneSensori &collezione) : sensori(copy(collezione)) {}

CollezioneSensori &CollezioneSensori::operator=(const CollezioneSensori &collezione) {
    if (this != &collezione) {
        destroy(*this);
        sensori = copy(collezione);
    }
    return *this;
}

CollezioneSensori::~CollezioneSensori() {
    destroy(*this);
}