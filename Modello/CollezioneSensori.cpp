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

void CollezioneSensori::setSensore(unsigned int Posizione,  const std::string &Tipo, const std::string &Nome, unsigned int Precisione,
    double MinValidTemperatura, double MaxValidTemperatura, 
    int MinValidFirstVector, int MaxValidFirstVector, int MinValidSecondVector, int MaxValidSecondVector) {
    
    if (Posizione >= sensori.size()) {
        throw std::out_of_range("Posizione non valida");
    }

    if(Nome == "" || Precisione > 100 || MinValidTemperatura > MaxValidTemperatura
        || MinValidFirstVector > MaxValidFirstVector || MinValidSecondVector > MaxValidSecondVector ) {
        throw std::invalid_argument("Parametri di modifica non validi");
    }

    Sensore* sensore = sensori[Posizione];

    sensore->setNome(Nome);
    sensore->setPrecisione(Precisione);
    sensore->setMinValidTemperatura(MinValidTemperatura);
    sensore->setMaxValidTemperatura(MaxValidTemperatura);

    if(Tipo == "Acqua"){

        SensoreAcqua* sensoreAcqua = dynamic_cast<SensoreAcqua*>(sensore);
        sensoreAcqua->setMinValidAlcalinità(MinValidFirstVector);
        sensoreAcqua->setMaxValidAlcalinità(MaxValidFirstVector);
        sensoreAcqua->setMinValidAcidità(MinValidSecondVector);
        sensoreAcqua->setMaxValidAcidità(MaxValidSecondVector);

    } else if(Tipo == "Aria"){

        SensoreAria* sensoreAria = dynamic_cast<SensoreAria*>(sensore);
        sensoreAria->setMinValidCO2(MinValidFirstVector);
        sensoreAria->setMaxValidCO2(MaxValidFirstVector);
        sensoreAria->setMinValidOssigeno(MinValidSecondVector);
        sensoreAria->setMaxValidOssigeno(MaxValidSecondVector);

    } else if(Tipo == "Suolo"){

        SensoreSuolo* sensoreSuolo = dynamic_cast<SensoreSuolo*>(sensore);
        sensoreSuolo->setMinValidPH(MinValidFirstVector);
        sensoreSuolo->setMaxValidPH(MaxValidFirstVector);
        sensoreSuolo->setMinValidUmidità(MinValidSecondVector);
        sensoreSuolo->setMaxValidUmidità(MaxValidSecondVector);

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
