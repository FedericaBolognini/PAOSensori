#ifndef PLAN_H
#define PLAN_H

#include "Sensore.h"
#include <list>
#include <vector>
#include <string>

class CollezioneSensori {
private:

    //collezione di puntatori ad allenamenti: gli allenamenti sono memorizzati in ordine temporale (invariante per ogni operazione
    //  su questa collezione) e tra di essi non ci possono essere sovrapposizioni; la loro durata deve essere <= 20 ore, il numero
    //  di esercizi compreso tra 1 e 15 e le durate ed i nomi devono essere non nulli.
    std::vector<Sensore *> sensori;

    /**
     * @brief copy:                     costruisce una lista di puntatori ad allenamenti equivalenti a quelli del piano passato in ingresso
     * @param plan:                     piano di allenamenti da cui copiare la collezione di allenamenti
     * @return std::list<Sensore *>:   collezione di puntatori ad allenamenti equivalenti a quelli del piano passato in ingresso
     */
    static std::vector<Sensore *> copy(const CollezioneSensori &collezione);

    /**
     * @brief destroy:                  dealloca gli allenamenti del piano passato in ingresso
     * @param plan:                     piano di allenamenti a cui deallocare la collezione di allenamenti
     */
    static void destroy(const CollezioneSensori &collezione);

public:

    /**
     * @brief Plan:                 costruisce il piano di allenamenti vuoto (senza alcun allenamento nella collezione)
     */
    CollezioneSensori() = default;

    /**
     * @brief insertTraining:           inserisce il puntatore ad un nuovo allenamento nella collezione di allenamenti
     * @param training:                 allenamento da inserire
     * @throw std::invalid_argument:    se l'allenamento non rispetta i vincoli di programma
     */
    void addSensore(Sensore *sensore);

        /**
     * @brief insertTraining:           inserisce il puntatore ad un nuovo allenamento nella collezione di allenamenti
     * @param training:                 allenamento da inserire
     * @param posizione
     * @throw std::invalid_argument:    se l'allenamento non rispetta i vincoli di programma
     */
    void insertSensore(Sensore *sensore, unsigned int posizione);

    /**
     * @brief removeTraining:           rimuove il puntatore (e dealloca) l'allenamento richiesto dalla collezione di allenamenti rispettando i vincoli (sopra)
     * @param pos:                      posizione dell'allenamento da rimuovere
     * @throw std::out_of_range:        se la posizione passata non è valida (minore di 0 o maggiore della dimensione della collezione)
     */
    void removeSensore(unsigned int pos);

    /**
     * @brief getTraining:          ritorna il puntatore ad un allenamento dalla collezione di allenamenti
     * @param position:             posizione da cui ottenere il puntatore ad un allenamento dalla collezione di allenamenti
     * @throw std::out_of_range:    se la posizione passata non è valida (minore di 0 o maggiore della dimensione della collezione)
     * @return Training*:           puntatore ad un allenamneto dalla collezione di allenamenti
     */
    Sensore *getSensore(unsigned int position) const;

    /**
     * @brief getTrainings:                 restituisce il puntatore alla collezione di puntatori agli allenamenti
     * @return std::list<Training *>*:      puntatore alla collezione di puntatori agli allenamenti
     */
    const std::vector<Sensore *>* getSensori() const;

    /**
     * @brief getSize:           restituisce il numero di allenamenti presenti nella collezione di allenamenti
     * @return unsigned int:     numero di allenamenti presenti nella collezione di allenamenti
     */
    unsigned int getSize() const;

    /**
     * @brief isEmpty:                  ritorna un booleano che indica se il piano di allenamenti ha almeno un allenamento
     * @return bool:                    indica se il piano di allenamenti ha almeno un allenamento
     */
    bool isEmpty() const;

    /**
     * @brief clear:                 svuota la collezione di puntatori agli allenamenti, deallocandoli
     */
    void clear();

    /**
     * @brief setTraining:              modifica un allenamento sulla base dei parametri in ingresso
     * @param position:                 posizione dell'allenamento da modificare
     * @param name:                     nome per l'allenamento da modificare
     * @param start:                    data di inizio per l'allenamento da modificare
     * @param distance:                 distanza percorsa per l'allenamento da modificare
     * @param duration:                 durata per l'allenamento da modificare
     * @param exPos:                    eventuale posizione dove modificare la collezione di esercizi di un allenamento di ripetizione
     * @param action:                   eventuale azione da effettuare sulla collezione di esercizi di un allenamento di ripetizione (all'esercizio indicato da exPos)
     * @param exName:                   puntatore ad una collezione di nomi per nuovi esercizi da modificare
     * @param exDuration:               puntatore ad una collezione di durate per nuovi esercizi da modificare
     * @param exRecovery:               puntatore ad una collezione di durate di recupero per nuovi esercizi da modificare
     * @throw std::out_of_range:        se la posizione passata non è valida (minore di 0 o maggiore della dimensione della collezione)
     * @throw std::invalid_argument:    se i dati in ingresso non sono corretti
     */
    void setSensore(unsigned int posizione, const std::string &nome, unsigned int precisione, double minValidTemperatura, double maxValidTemperatura, 
        int minValidAlcalinità, int maxValidAlcalinità, int minValidAcidità, int maxValidAcidità, 
        int minValidOssigeno, int maxValidOssigeno, int minValidCO2, int maxValidCO2,
        int minValidUmidità, int maxValidUmidità, int minValidPH, int maxValidPH);

    /**
     * @brief Plan:           costruttore di copia profonda
     * @param plan:           piano di allenamenti da cui copiare la collezione di allenamenti
     */
    CollezioneSensori(const CollezioneSensori &plan);

    /**
     * @brief operator=:             operatore di assegnazione ridefinito
     * @param plan:                  piano di allenamenti da cui copiare la collezione di allenamenti
     * @return Plan&:                riferimento al piano di allenamenti appena modificato
     */
    CollezioneSensori &operator=(const CollezioneSensori &plan);

    /**
     * @brief ~Plan:                 distruttore profondo
     */
    ~CollezioneSensori();
};

#endif // PLAN_H