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
     * @param MinValidFirstVector:      valore minimo dell'intervallo valido del primo vettore caratteristico del sensore
     * @param MaxValidFirstVector:      valore massimo dell'intervallo valido del primo vettore caratteristico del sensore
     * @param MinValidSecondVector:     valore minimo dell'intervallo valido del secondo vettore caratteristico del sensore
     * @param MaxValidSecondVector:     valore massimo dell'intervallo valido del secondo vettore caratteristico del sensore
     * @return Sensore *:               sensore creato sulla base dei parametri in ingresso
     * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - se il range di valori per la temperatura, alcalinità, acidità, ossigeno, co2, umidità non è corretto(basta una delle seguenti condizioni) - se il tipo non è valido
     */

    static Sensore *createSensore(const std::string &Type, unsigned int ID, const std::string &Nome, unsigned int Precisione, double MinValidTemperatura, double MaxValidTemperatura, 
        int MinValidFirstVector, int MaxValidFirstVector, int MinValidSecondVector, int MaxValidSecondVector);
};

#endif //SENSORECREATOR_H 
