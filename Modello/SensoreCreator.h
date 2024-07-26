#ifndef SENSORECREATOR_H
#define SENSORECREATOR_H

#include "Sensore.h"
#include "SensoreAcqua.h"
#include "SensoreAria.h"
#include "SensoreSuolo.h"
#include <stdexcept>
#include <string>
#include <vector>

class SensoreCreator {
public:

    /**
     * @brief createSensore:            crea e ritorna un sensore sulla base dei parametri in ingresso
     * @param Type:                     tipo del sensore
     * @param ID:                       ID del sensore da creare
     * @param Precisione:               precisione del sensore, utilizzato nelle simulazioni
     * @param MinValidTemperatura:      valore minimo dell'intervallo valido di temperatura "salubre"
     * @param MaxValidTemperatura:      valore massimo dell'intervallo valido di temperatura "salubre"
     * @param MinValidAlcalinità:       valore minimo dell'intervallo valido di Alcalinità "ammissibile"
     * @param MaxValidAlcalinità:       valore massimo dell'intervallo valido di Alcalinità "ammissibile"
     * @param MinValidAcidità:          valore minimo dell'intervallo valido di Acidità "ammissibile"
     * @param MaxValidAcidità:          valore massimo dell'intervallo valido di Acidità "ammissibile"
     * @param MinValidOssigeno:         valore minimo dell'intervallo valido di Ossigeno "ammissibile"
     * @param MaxValidOssigeno:         valore massimo dell'intervallo valido di Ossigeno "ammissibile"
     * @param MinValidCO2:              valore minimo dell'intervallo valido di CO2 "ammissibile"
     * @param MaxValidCO2:              valore massimo dell'intervallo valido di CO2 "ammissibile"
     * @param MinValidUmidità:          valore minimo dell'intervallo valido di Umidità "ammissibile"
     * @param MaxValidUmidità:          valore massimo dell'intervallo valido di Umidità "ammissibile"
     * @param MinValidPH:               valore minimo dell'intervallo valido di PH "ammissibile"
     * @param MaxValidPH:               valore massimo dell'intervallo valido di PH "ammissibile"
     * @return Sensore *:               sensore creato sulla base dei parametri in ingresso
     * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - se il range di valori per la temperatura, alcalinità, acidità, ossigeno, co2, umidità non è corretto(basta una delle seguenti condizioni) - se il tipo non è valido
     */

    static Sensore *createSensore(const std::string &Type, unsigned int ID, const std::string &Nome, unsigned int Precisione, double MinValidTemperatura, double MaxValidTemperatura, 
        int MinValidAlcalinità, int MaxValidAlcalinità, int MinValidAcidità, int MaxValidAcidità, 
        int MinValidOssigeno, int MaxValidOssigeno, int MinValidCO2, int MaxValidCO2,
        int MinValidUmidità, int MaxValidUmidità, int MinValidPH, int MaxValidPH);
};

#endif //SENSORECREATOR_H 