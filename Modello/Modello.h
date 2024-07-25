#ifndef MODEL_H
#define MODEL_H

#include "CollezioneSensori.h"
#include "Sensore.h"
#include <string>
#include <vector>

class Model {
private:

    //puntatore al piano di allenamenti, che contiene una collezione di allenamenti
    CollezioneSensori *collezioneSensori;

public:

    /**
     * @brief Model:                 costruisce il piano di allenamenti
     */
    Model();

    void addNewSensore(const std::string &type, unsigned int ID, const std::string &nome, unsigned int precisione, double minValidTemperatura, double maxValidTemperatura, 
        int minValidAlcalinità, int maxValidAlcalinità, int minValidAcidità, int maxValidAcidità, 
        int minValidOssigeno, int maxValidOssigeno, int minValidCO2, int maxValidCO2,
        int minValidUmidità, int maxValidUmidità, int minValidPH, int maxValidPH) const;

    void insertNewSensore(const std::string &type, unsigned int ID, const std::string &nome, unsigned int precisione, double minValidTemperatura, double maxValidTemperatura, 
        int minValidAlcalinità, int maxValidAlcalinità, int minValidAcidità, int maxValidAcidità, 
        int minValidOssigeno, int maxValidOssigeno, int minValidCO2, int maxValidCO2,
        int minValidUmidità, int maxValidUmidità, int minValidPH, int maxValidPH, unsigned int posizione);

    /**
     * @brief addNewTraining:           aggiunge al piano e fa creare ad una classe apposita un allenamento sulla base dei parametri in ingresso
     * @param type:                     tipo dell'allenamento da creare
     * @param name:                     nome dell'allenamento da creare
     * @param start:                    data di inizio dell'allenamento da creare
     * @param distance:                 distanza percorsa durante l'allenamento da creare
     * @param duration:                 durata dell'allenamento da creare
     * @param exName:                   puntatore ad una collezione di nomi per nuovi esercizi da creare
     * @param exDuration:               puntatore ad una collezione di durate per nuovi esercizi da creare
     * @param exRecovery:               puntatore ad una collezione di durate di recupero per nuovi esercizi da creare
     * @throw std::invalid_argument:    se i parametri passati contengono degli errori a livello logico
     */
    void setSensore(unsigned int posizione, const std::string &nome, unsigned int precisione, double minValidTemperatura, double maxValidTemperatura, 
        int minValidAlcalinità, int maxValidAlcalinità, int minValidAcidità, int maxValidAcidità, 
        int minValidOssigeno, int maxValidOssigeno, int minValidCO2, int maxValidCO2,
        int minValidUmidità, int maxValidUmidità, int minValidPH, int maxValidPH) const;

    /**
     * @brief removeTraining:           rimuove l'allenamento richiesto dal piano di allenamenti
     * @param pos:                      posizione dell'allenamento da rimuovere
     * @throw std::out_of_range:        se la posizione passata non è valida (minore di 0 o maggiore della dimensione del piano di allenamenti)
     */
    void removeSensore(unsigned int pos) const;

    /**
     * @brief getTraining:          ritorna il puntatore ad un allenamento del piano di allenamenti
     * @param position:             posizione da cui ottenere il puntatore ad un allenamento del piano di allenamenti
     * @throw std::out_of_range:    se la posizione passata non è valida (minore di 0 o maggiore della dimensione del piano di allenamenti)
     * @return Training*:           puntatore ad un allenamneto dal piano di allenamenti
     */
    Sensore *getSensore(unsigned int pos) const;

    /**
     * @brief getTrainings:                 restituisce il puntatore alla collezione di puntatori agli allenamenti
     * @return std::list<Training *>*:      puntatore alla collezione di puntatori agli allenamenti
     */
    const std::vector<Sensore *>* getSensori() const;
    /**
     * @brief getPlanSize:       restituisce il numero di allenamenti presenti nella collezione di allenamenti
     * @return unsigned int:     numero di allenamenti presenti nella collezione di allenamenti
     */
    unsigned int getSize() const;

    /**
     * @brief isEmpty:                  ritorna un booleano che indica se il piano di allenamenti ha almeno un allenamento
     * @return bool:                    indica se il piano di allenamenti ha almeno un allenamento
     */
    bool isEmpty() const;

    /**
     * @brief removeTrainings:                 svuota il piano di allenamenti
     */
    void removeSensori() const;

    /**
     * @brief Model:           costruttore di copia profonda
     * @param model:           modello da cui copiare il piano di allenamenti
     */
    Model(const Model &model);

    /**
     * @brief operator=:              operatore di assegnazione ridefinito
     * @param model:                  modello da cui copiare il piano di allenamenti
     * @return Model&:                riferimento al modello appena modificato
     */
    Model &operator=(const Model &model);

    /**
     * @brief ~Model:                 distruttore profondo
     */
    ~Model();
};

#endif // MODEL_H