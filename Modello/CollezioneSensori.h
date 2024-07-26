#ifndef COLLEZIONESENSORI_H
#define COLLEZIONESENSORI_H

#include "Sensore.h"
#include "SensoreAcqua.h"
#include "SensoreAria.h"
#include "SensoreSuolo.h"
#include <vector>
#include <string>

class CollezioneSensori {
private:

    //collezione di puntatori a sensori
    std::vector<Sensore *> sensori;

    /**
     * @brief copy:                           costruisce una lista di puntatori a sensori equivalenti a quelli della collezione passata in ingresso
     * @param collezione:                     collezione di sensori da copiare
     * @return std::list<Sensore *>:          collezione di puntatori a sensori equivalenti a quelli della collezione passata in ingresso
     */
    static std::vector<Sensore *> copy(const CollezioneSensori &collezione);

    /**
     * @brief destroy:                        dealloca i sensori della collezione passata in ingresso
     * @param collezione:                     collezione di sensori da deallocare 
     */
    static void destroy(const CollezioneSensori &collezione);

public:

    /**
     * @brief CollezioneSensori         costruisce una collezione di sensori vuoto (senza alcun sensore nella collezione)
     */
    CollezioneSensori() = default;

    /**
     * @brief addSensore:               inserisce il puntatore ad un nuovo sensore nella collezione di sensori
     * @param sensore:                  sensore da aggiungere
     * @throw std::invalid_argument:    se il sensore è nullo
     */
    void addSensore(Sensore *sensore);

        /**
     * @brief insertSensore:            inserisce il puntatore ad un nuovo sensore nella collezione di sensori
     * @param sensore:                  sensore da inserire
     * @param posizione                 posizione del sensore da inserire
     * @throw std::invalid_argument:    se il sensore è nullo 
     * @throw std::out_of_range         la posizione non è valida 
     */
    void insertSensore(Sensore *sensore, unsigned int posizione);

    /**
     * @brief removeSensore:               rimuove il puntatore (e dealloca) il sensore richiesto dalla collezione di sensori
     * @param posizione:                   posizione del sensore da rimuovere
     * @throw std::out_of_range:           se la posizione passata non è valida ossia maggiore della dimensione della collezione
     */
    void removeSensore(unsigned int posizione);

    /**
     * @brief getSensore:            ritorna il puntatore ad un sensore dalla collezione di sensori
     * @param posizione:             posizione da cui ottenere il puntatore ad un sensore dalla collezione di sensori
     * @throw std::out_of_range:     se la posizione passata non è valida ossia maggiore della dimensione della collezione
     * @return Sensore*:             puntatore ad un sensore dalla collezione di sensori
     */
    Sensore *getSensore(unsigned int posizione) const;

    /**
     * @brief getSensori:                 restituisce il puntatore alla collezione di puntatori ai sensori
     * @return std::vector<Sensore *>*:   puntatore alla collezione di puntatori ai sensori
     */
    const std::vector<Sensore *>* getSensori() const;

    /**
     * @brief getSize:           restituisce il numero di sensori presenti nella collezione di sensori 
     * @return unsigned int:     numero di sensori presenti nella collezione di sensori
     */
    unsigned int getSize() const;

    /**
     * @brief isEmpty:                  ritorna un booleano che indica se la collezione di sensori ha almeno un sensore 
     * @return bool:                    indica se la collezione di sensori ha almeno un sensore 
     */
    bool isEmpty() const;

    /**
     * @brief clear:                 svuota la collezione di sensori, deallocandoli
     */
    void clear();

    /**
     * @brief setSensore:              modifica un sensore sulla base dei parametri in ingresso
     * @param Posizione:               posizione del sensore da modificare
     * @param Nome:                    nome del sensore
     * @param Precisione:              precisione del sensore, utilizzato nelle simulazioni
     * @param MinValidTemperatura:     valore minimo dell'intervallo valido di temperatura "salubre"
     * @param MaxValidTemperatura:     valore massimo dell'intervallo valido di temperatura "salubre"
     * @param MinValidAlcalinità:      valore minimo dell'intervallo valido di Alcalinità "ammissibile"
     * @param MaxValidAlcalinità:      valore massimo dell'intervallo valido di Alcalinità "ammissibile"
     * @param MinValidAcidità:         valore minimo dell'intervallo valido di Acidità "ammissibile"
     * @param MaxValidAcidità:         valore massimo dell'intervallo valido di Acidità "ammissibile"
     * @param MinValidOssigeno:        valore minimo dell'intervallo valido di Ossigeno "ammissibile"
     * @param MaxValidOssigeno:        valore massimo dell'intervallo valido di Ossigeno "ammissibile"
     * @param MinValidCO2:             valore minimo dell'intervallo valido di CO2 "ammissibile"
     * @param MaxValidCO2:             valore massimo dell'intervallo valido di CO2 "ammissibile"
     * @param MinValidUmidità:         valore minimo dell'intervallo valido di Umidità "ammissibile"
     * @param MaxValidUmidità:         valore massimo dell'intervallo valido di Umidità "ammissibile"
     * @param MinValidPH:              valore minimo dell'intervallo valido di PH "ammissibile"
     * @param MaxValidPH:              valore massimo dell'intervallo valido di PH "ammissibile"
     * @throw std::invalid_argument    se il nome è vuoto - se la precisione supera il 100% - se il range di valori per temperatura, alcalinità, acidità, ossigeno, co2, umidità non è corretto (basta una delle seguenti condizioni)- e se non è possibile risalire al tipo di vettore dai parametri
     * @throw std::out_of_range        se la posizione eccede la lunghezza del vettore 
     */
    void setSensore(unsigned int Posizione, const std::string &Nome, unsigned int Precisione, double MinValidTemperatura, double MaxValidTemperatura, 
        int MinValidAlcalinità = INT_MIN, int MaxValidAlcalinità = INT_MAX, int MinValidAcidità = INT_MIN, int MaxValidAcidità = INT_MAX, 
        int MinValidOssigeno = INT_MIN, int MaxValidOssigeno = INT_MAX, int MinValidCO2 = INT_MIN, int MaxValidCO2 = INT_MAX,
        int MinValidUmidità = INT_MIN, int MaxValidUmidità = INT_MAX, int MinValidPH = INT_MIN, int MaxValidPH = INT_MAX);

    /**
     * @brief CollezioneSensori:           costruttore di copia profonda
     * @param collezione:                  collezione di sensori da cui copiare la collezione di sensori
     */
    CollezioneSensori(const CollezioneSensori &collezione);

    /**
     * @brief operator=:                    operatore di assegnazione ridefinito
     * @param collezoione:                  collezione di sensori da cui copiare la collezione di sensori
     * @return CollezioneSensori&:          riferimento alla collezione di sensori appena modificata
     */
    CollezioneSensori &operator=(const CollezioneSensori &collezione);

    /**
     * @brief ~CollezioneSensori:                 distruttore profondo
     */
    ~CollezioneSensori();
};

#endif //COLLEZIONESENSORI_H