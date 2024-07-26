#ifndef MODELLO_H
#define MODELLO_H

#include "CollezioneSensori.h"
#include "SensoreCreator.h"
#include "Sensore.h"
#include <string>
#include <vector>

// Modello:
// --> CollezioneSensori
// ID: [0 1 2 3 4 5 6 7 8 9 10] --> rimuovo ID 4 -->  [0 1 2 3 5 6 7 8 9 10]

// Modello: [0 1 2 3 5 6 7 8 9 10]: massimo degli ID = 10 --> inserisco un nuovo sensore: [0 1 2 3 5 6 7 8 9 10 11] 

class Model {
private:

    //puntatore alla collezione di sensori, che contiene una collezione sensori
    CollezioneSensori *collezioneSensori;

public:

    /**
     * @brief Model:                 costruisce la collezione di sensori
     */
    Model();

     /**
     * @brief addNewSensore:            aggiunge alla collezione e fa creare ad una classe apposita un sensore sulla base dei parametri in ingresso
     * @param Type:                     tipo del sensore da creare
     * @param Name:                     nome del sensore da creare
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
     * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - se il range di valori per la temperatura, alcalinità, acidità, ossigeno, co2, umidità non è corretto (basta una delle seguenti condizioni)-
     */

    void addNewSensore(const std::string &Type, unsigned int ID, const std::string &Nome, unsigned int Precisione, double MinValidTemperatura, double MaxValidTemperatura, 
        int MinValidAlcalinità, int MaxValidAlcalinità, int MinValidAcidità, int MaxValidAcidità, 
        int MinValidOssigeno, int MaxValidOssigeno, int MinValidCO2, int MaxValidCO2,
        int MinValidUmidità, int MaxValidUmidità, int MinValidPH, int MaxValidPH) const;

     /**
     * @brief insertNewSensore:         inserisce alla collezione e fa creare ad una classe apposita un sensore sulla base dei parametri in ingresso
     * @param Type:                     tipo del sensore da inserire
     * @param Name:                     nome del sensore da inserire
     * @param ID:                       ID del sensore da inserire
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
     * @param posizione                 posizione dalla quale inserire il sensore
     * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - se il range di valori per la temperatura, alcalinità, acidità, ossigeno, co2, umidità non è corretto-
     */

    void insertNewSensore(const std::string &Type, unsigned int ID, const std::string &Nome, unsigned int Precisione, double MinValidTeMperatura, double MaxValidTeMperatura, 
        int MinValidAlcalinità, int MaxValidAlcalinità, int MinValidAcidità, int MaxValidAcidità, 
        int MinValidOssigeno, int MaxValidOssigeno, int MinValidCO2, int MaxValidCO2,
        int MinValidUMidità, int MaxValidUMidità, int MinValidPH, int MaxValidPH, unsigned int posizione);
    
    /**
     * @brief setSensore:               setter per un sensore
     * @param Posizione                 posizione del sensore da settare
     * @param Name:                     nome del sensore da settare
     * @param ID:                       ID del sensore da settare
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
     * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - se il range di valori per la temperatura, alcalinità, acidità, ossigeno, co2, umidità non è corretto (basta una delle seguenti condizioni)-
     */

    void setSensore(unsigned int Posizione, const std::string &Nome, unsigned int Precisione, double minValidTemperatura, double maxValidTemperatura, 
        int minValidAlcalinità, int maxValidAlcalinità, int minValidAcidità, int maxValidAcidità, 
        int minValidOssigeno, int maxValidOssigeno, int minValidCO2, int maxValidCO2,
        int minValidUmidità, int maxValidUmidità, int minValidPH, int maxValidPH) const;

     /**
     * @brief removeSensore:           rimuove il sensore richiesto dalla collezione di sensori
     * @param posizione:               posizione del sensore da rimuovere
     * @throw std::out_of_range:       se la posizione passata non è valida ossia maggiore della dimensione della collezione di sensori
     */
    void removeSensore(unsigned int posizione) const;

     /**
     * @brief getSensore:           ritorna il puntatore ad un sensore della collezione di sensori
     * @param posizione:            posizione da cui ottenere il puntatore ad un sensore della collezione di sensori
     * @throw std::out_of_range:    se la posizione passata non è valida ossia maggiore della dimensione della collezione di sensori
     * @return Sensore *:           puntatore ad un sensore dalla collezione di sensori
     */
    Sensore *getSensore(unsigned int posizione) const;

     /**
     * @brief getSensori:                   restituisce il puntatore alla collezione di puntatori ai sensori
     * @return std::vector<Sensore *>*:      puntatore alla collezione di puntatori ai sensori 
     */
    const std::vector<Sensore *>* getSensori() const;

     /**
     * @brief ggetSize:          restituisce il numero di sensori presenti nella collezione di sensori
     * @return unsigned int:     numero di sensori presenti nella collezione di sensori 
     */
    unsigned int getSize() const;

     /**
     * @brief isEmpty:                  ritorna un booleano che indica se la collezione di sensori ha almeno un sensore
     * @return bool:                    indica se la collezione di sensori ha almeno un sensore
     */
    bool isEmpty() const;

     /**
     * @brief removeSensori:                 svuota la collezione di sensori
     */
    void removeSensori() const;

     /**
     * @brief Model:           costruttore di copia profonda
     * @param model:           modello da cui copiare la collezione di sensori 
     */
    Model(const Model &model);

     /**
     * @brief operator=:              operatore di assegnazione ridefinito
     * @param model:                  modello da cui copiare la collezione di sensori
     * @return Model&:                riferimento al modello appena modificato
     */
    Model &operator=(const Model &model);

     /**
     * @brief ~Model:                 distruttore profondo
     */
    ~Model();
};

#endif // MODELLO_H