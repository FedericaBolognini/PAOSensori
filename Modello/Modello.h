#ifndef MODELLO_H
#define MODELLO_H

#include "CollezioneSensori.h"
#include "SensoreCreator.h"
#include "sensoresimulator.h"
#include "Sensore.h"
#include <string>
#include <vector>

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
     * @param Precisione:               precisione del sensore, utilizzato nelle simulazioni
     * @param MinValidTemperatura:      valore minimo dell'intervallo valido di temperatura "salubre"
     * @param MaxValidTemperatura:      valore massimo dell'intervallo valido di temperatura "salubre"
     * @param MinValidFirstVector:      valore minimo dell'intervallo valido del primo vettore caratteristico del sensore
     * @param MaxValidFirstVector:      valore massimo dell'intervallo valido del primo vettore caratteristico del sensore
     * @param MinValidSecondVector:     valore minimo dell'intervallo valido del secondo vettore caratteristico del sensore
     * @param MaxValidSecondVector:     valore massimo dell'intervallo valido del secondo vettore caratteristico del sensore
     * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - se il range di valori per la temperatura, alcalinità, acidità, ossigeno, co2, umidità non è corretto (basta una delle seguenti condizioni)-
     */

    void addNewSensore(const std::string &Type, const std::string &Nome, unsigned int Precisione, double MinValidTemperatura, double MaxValidTemperatura,
        int MinValidFirstVector, int MaxValidFirstVector, int MinValidSecondVector, int MaxValidSecondVector) const;

    /**
     * @brief addNewSensore:            aggiunge alla collezione un sensore
     * @param sensore:                  sensore da aggiungere alla collezione, aggiornando il suo ID in modo da essere compatibile con la collezione stessa
     */
    void addSensore(Sensore* sensore) const;

     /**
     * @brief insertNewSensore:         inserisce alla collezione e fa creare ad una classe apposita un sensore sulla base dei parametri in ingresso
     * @param Type:                     tipo del sensore da inserire
     * @param Name:                     nome del sensore da inserire
     * @param Precisione:               precisione del sensore, utilizzato nelle simulazioni
     * @param MinValidTemperatura:      valore minimo dell'intervallo valido di temperatura "salubre"
     * @param MaxValidTemperatura:      valore massimo dell'intervallo valido di temperatura "salubre"
     * @param MinValidFirstVector:      valore minimo dell'intervallo valido del primo vettore caratteristico del sensore
     * @param MaxValidFirstVector:      valore massimo dell'intervallo valido del primo vettore caratteristico del sensore
     * @param MinValidSecondVector:     valore minimo dell'intervallo valido del secondo vettore caratteristico del sensore
     * @param MaxValidSecondVector:     valore massimo dell'intervallo valido del secondo vettore caratteristico del sensore
     * @param posizione                 posizione dalla quale inserire il sensore
     * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - se il range di valori per la temperatura, alcalinità, acidità, ossigeno, co2, umidità non è corretto-
     */

    void insertNewSensore(const std::string &Type, const std::string &Nome, unsigned int Precisione, double MinValidTeMperatura, double MaxValidTeMperatura, 
        int MinValidFirstVector, int MaxValidFirstVector, int MinValidSecondVector, int MaxValidSecondVector, unsigned int posizione);
    
    /**
     * @brief setSensore:               setter per un sensore
     * @param Posizione                 posizione del sensore da settare
     * @param Tipo:                     tipo del sensore
     * @param Name:                     nome del sensore da settare
     * @param ID:                       ID del sensore da settare
     * @param Precisione:               precisione del sensore, utilizzato nelle simulazioni
     * @param MinValidTemperatura:      valore minimo dell'intervallo valido di temperatura "salubre"
     * @param MaxValidTemperatura:      valore massimo dell'intervallo valido di temperatura "salubre"
     * @param MinValidFirstVector:      valore minimo dell'intervallo valido del primo vettore caratteristico del sensore
     * @param MaxValidFirstVector:      valore massimo dell'intervallo valido del primo vettore caratteristico del sensore
     * @param MinValidSecondVector:     valore minimo dell'intervallo valido del secondo vettore caratteristico del sensore
     * @param MaxValidSecondVector:     valore massimo dell'intervallo valido del secondo vettore caratteristico del sensore
     * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - se il range di valori per la temperatura, alcalinità, acidità, ossigeno, co2, umidità non è corretto (basta una delle seguenti condizioni)-
     */

    void setSensore(unsigned int Posizione, const std::string &Tipo, const std::string &Nome, unsigned int Precisione, double minValidTemperatura, double maxValidTemperatura,
        int MinValidFirstVector, int MaxValidFirstVector, int MinValidSecondVector, int MaxValidSecondVector) const;

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
     * @brief simulaSensore:                fa partire la simulazione di dati per il sensore desiderato
     * @param sensore:                      sensore per il quale eseguire la simulazione
     */
    void simulaSensore(Sensore* sensore) const;

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
