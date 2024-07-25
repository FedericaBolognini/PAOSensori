#ifndef TRAININGCREATOR_H
#define TRAININGCREATOR_H

#include "Sensore.h"
#include <stdexcept>
#include <string>
#include <vector>

class trainingCreator {
public:

    /**
     * @brief createTraining:           crea e ritorna un allenamento sulla base dei parametri in ingresso
     * @param type:                     tipo dell'allenamento da creare
     * @param name:                     nome dell'allenamento da creare
     * @param start:                    data di inizio dell'allenamento da creare
     * @param distance:                 distanza percorsa durante l'allenamento da creare
     * @param duration:                 durata dell'allenamento da creare
     * @param exName:                   puntatore ad una collezione di nomi per nuovi esercizi da creare
     * @param exDuration:               puntatore ad una collezione di durate per nuovi esercizi da creare
     * @param exRecovery:               puntatore ad una collezione di durate di recupero per nuovi esercizi da creare
     * @throw std::invalid_argument:    se i parametri passati contengono degli errori a livello logico
     * @return Training*:               allenamento creato sulla base dei parametri in ingresso
     */
    static Sensore *createSensore(const std::string &type, unsigned int ID, const std::string &nome, unsigned int precisione, double minValidTemperatura, double maxValidTemperatura, 
        int minValidAlcalinità, int maxValidAlcalinità, int minValidAcidità, int maxValidAcidità, 
        int minValidOssigeno, int maxValidOssigeno, int minValidCO2, int maxValidCO2,
        int minValidUmidità, int maxValidUmidità, int minValidPH, int maxValidPH);
};

#endif // TRAININGCREATOR_H


// Modello:
// --> CollezioneSensori
// ID: [0 1 2 3 4 5 6 7 8 9 10] --> rimuovo ID 4 -->  [0 1 2 3 5 6 7 8 9 10]

// Modello: [0 1 2 3 5 6 7 8 9 10]: massimo degli ID = 10 --> inserisco un nuovo sensore: [0 1 2 3 5 6 7 8 9 10 11] 

