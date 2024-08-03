#include "SensoreCreator.h"


Sensore *SensoreCreator::createSensore(const std::string &Type, unsigned int ID, const std::string &Nome, unsigned int Precisione, double MinValidTemperatura, double MaxValidTemperatura, 
        int MinValidAlcalinità, int MaxValidAlcalinità, int MinValidAcidità, int MaxValidAcidità, 
        int MinValidOssigeno, int MaxValidOssigeno, int MinValidCO2, int MaxValidCO2,
        int MinValidUmidità, int MaxValidUmidità, int MinValidPH, int MaxValidPH){
            if (Type == "SensoreAcqua")
                return new SensoreAcqua(Nome, Precisione, ID, MinValidTemperatura, MaxValidTemperatura, MinValidAlcalinità, MaxValidAlcalinità, MinValidAcidità, MaxValidAcidità);
            else if (Type == "SensoreAria")
                return new SensoreAria(Nome, Precisione, ID, MinValidTemperatura, MaxValidTemperatura, MinValidCO2, MaxValidCO2, MinValidOssigeno, MaxValidOssigeno);
            else if (Type == "SensoreSuolo")
                return new SensoreSuolo(Nome, Precisione, ID, MinValidTemperatura, MaxValidTemperatura, MinValidPH, MaxValidPH, MinValidUmidità, MaxValidUmidità);
            else {
                throw std::invalid_argument("Tipo di sensore non valido");
            }
}

