#ifndef COLLEZIONESENSORI_H
#define COLLEZIONESENSORI_H

#include "Sensore.h"
#include "SensoreAcqua.h"
#include "SensoreAria.h"
#include "SensoreSuolo.h"
#include <vector>
#include <string>
#include <climits>

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
     * @param Tipo:                    tipo del sensore
     * @param Nome:                    nome del sensore
     * @param Precisione:              precisione del sensore, utilizzato nelle simulazioni
     * @param MinValidTemperatura:     valore minimo dell'intervallo valido di temperatura "salubre"
     * @param MaxValidTemperatura:     valore massimo dell'intervallo valido di temperatura "salubre"
     * @param MinValidFirstVector:      valore minimo dell'intervallo valido del primo vettore caratteristico del sensore
     * @param MaxValidFirstVector:      valore massimo dell'intervallo valido del primo vettore caratteristico del sensore
     * @param MinValidSecondVector:     valore minimo dell'intervallo valido del secondo vettore caratteristico del sensore
     * @param MaxValidSecondVector:     valore massimo dell'intervallo valido del secondo vettore caratteristico del sensore
     * @throw std::invalid_argument    se il nome è vuoto - se la precisione supera il 100% - se il range di valori per temperatura, alcalinità, acidità, ossigeno, co2, umidità non è corretto (basta una delle seguenti condizioni)- e se non è possibile risalire al tipo di vettore dai parametri
     * @throw std::out_of_range        se la posizione eccede la lunghezza del vettore 
     */
    void setSensore(unsigned int Posizione, const std::string& Tipo, const std::string &Nome, unsigned int Precisione, double MinValidTemperatura, double MaxValidTemperatura,
        int MinValidFirstVector, int MaxValidFirstVector, int MinValidSecondVector, int MaxValidSecondVector);

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
