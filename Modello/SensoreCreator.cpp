#include "sensorecreator.h"


static Sensore *createSensore(const std::string &Type, unsigned int ID, const std::string &Nome, unsigned int Precisione, double MinValidTemperatura, double MaxValidTemperatura, 
        int MinValidAlcalinità, int MaxValidAlcalinità, int MinValidAcidità, int MaxValidAcidità, 
        int MinValidOssigeno, int MaxValidOssigeno, int MinValidCO2, int MaxValidCO2,
        int MinValidUmidità, int MaxValidUmidità, int MinValidPH, int MaxValidPH){
            if (type == "SensoreAcqua")
                return new SensoreAcqua(Nome, Precisione, ID, MinValidTemperatura, MaxValidTemperatura, MinValidAlcalinità, MaxValidAlcalinità, MinValidAcidità, MaxValidAcidità);
            else if (type == "SensoreAria")
                return new SensoreAria(Nome, Precisione, ID, MinValidTemperatura, MaxValidTemperatura, MinValidCO2, MaxValidCO2, MinValidOssigeno, MaxValidOssigeno);
            else if (type == "SensoreSuolo")
                return new SensoreSuolo(Nome, Precisione, ID, MinValidTemperatura, MaxValidTemperatura, MinValidUmidità, MaxValidUmidità, MinValidPH, MaxValidPH);
            else {
                throw std::invalid_argument("Tipo di sensore non valido");
            }
}

