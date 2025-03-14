#include "SensoreCreator.h"


Sensore *SensoreCreator::createSensore(const std::string &Type, unsigned int ID, const std::string &Nome, unsigned int Precisione, double MinValidTemperatura, double MaxValidTemperatura,
        int MinValidFirstVector, int MaxValidFirstVector, int MinValidSecondVector, int MaxValidSecondVector){
            if (Type == "Acqua")
                return new SensoreAcqua(Nome, Precisione, ID, MinValidTemperatura, MaxValidTemperatura, MinValidFirstVector, MaxValidFirstVector, MinValidSecondVector, MaxValidSecondVector);
            else if (Type == "Aria")
                return new SensoreAria(Nome, Precisione, ID, MinValidTemperatura, MaxValidTemperatura, MinValidFirstVector, MaxValidFirstVector, MinValidSecondVector, MaxValidSecondVector);
            else if (Type == "Suolo")
                return new SensoreSuolo(Nome, Precisione, ID, MinValidTemperatura, MaxValidTemperatura, MinValidFirstVector, MaxValidFirstVector, MinValidSecondVector, MaxValidSecondVector);
            else {
                throw std::invalid_argument("Tipo di sensore non valido");
            }
}

