#ifndef SENSOREARIA_H
#define SENSOREARIA_H

#include <string>
#include <vector>
#include <stdexcept>
#include "Sensore.h"

class SensoreAria: public Sensore
{
private:
    // Valore minimo dell'intervallo valido di CO2 "ammissibile"
    int MinValidCO2;
    // Valore massimo dell'intervallo valido di CO2 "ammissibile"
    int MaxValidCO2;
    // Valore minimo dell'intervallo valido di Ossigeno "ammissibile"
    int MinValidOssigeno;
    // Valore massimo dell'intervallo valido di Ossigeno "ammissibile"
    int MaxValidOssigeno;
    // Vettore contenente i dati di CO2 campionati
    std::vector <int> CO2;
    // Vettore contenente i dati di Ossigeno campionati
    std::vector <int> Ossigeno;

public:
  /**
   * @brief SensoreAria: costruttore di default, inizializza le stringhe con valori
   * vuoti e gli interi/double a zero
   */
  SensoreAria();

  /**
   * @brief SensoreAria: costruttore, costruisce un sensore aria a partire da nome, precisione, ID, valore minimo e massimo della temperatura
   * @param Nome:                     nome del sensore
   * @param Precisione:               precisione del sensore, utilizzato nelle simulazioni
   * @param ID:                       identificativo del sensore
   * @param MinValidTemperatura:      valore minimo dell'intervallo valido di temperatura "salubre"
   * @param MaxValidTemperatura:      valore massimo dell'intervallo valido di temperatura "salubre"
   * @param MinValidCO2:              valore minimo dell'intervallo valido di CO2 "ammissibile"
   * @param MaxValidCO2:              valore massimo dell'intervallo valido di CO2 "ammissibile"
   * @param MinValidOssigeno:         valore minimo dell'intervallo valido di Ossigeno "ammissibile"
   * @param MaxValidOssigeno:         valore massimo dell'intervallo valido di Ossigeno "ammissibile"
   * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - 
   * se il range di valori per la temperatura non è corretto - se il range di valori per CO2 non è corretto - se il range di valori per l'ossigeno non è corretto
   */
 SensoreAria(const std::string &Nome, unsigned int Precisione, unsigned ID, double MinValidTemperatura,
 double MaxValidTemperatura,int MinValidCO2, int MaxValidCO2, int MinValidOssigeno,int MaxValidOssigeno);

 /**
 * @brief getMinValidCO2:    getter per il valore minimo dell'intervallo valido di CO2 "ammissibile"
 */
int getMinValidCO2() const;

 /**
 * @brief getMaxValidCO2:    getter per il valore massimo dell'intervallo valido di CO2 "ammissibile"
 */
 int getMaxValidCO2() const;

 /**
 * @brief getMinValidOssigeno:    getter per il valore minimo dell'intervallo valido di Ossigeno "ammissibile"
 */
 int getMinValidOssigeno() const;

 /**
 * @brief getMaxValidOssigeno:    getter per il valore massimo dell'intervallo valido di Ossigeno "ammissibile"
 */
 int getMaxValidOssigeno() const;

   /**
   * @brief setMinValidCO2:           setter per il valore minimo dell'intervallo valido di CO2 "ammissibile"
   * @param MinValidCO2:              nuovo valore minimo dell'intervallo valido di CO2 "ammissibile" del sensore
   * @throw std::invalid_argument:    se il valore CO2 minimo è superiore al valore CO2 massimo
   */

  void setMinValidCO2(int MinValidCO2);

  /**
   * @brief setMaxValidCO2:          setter per il valore massimo dell'intervallo valido di CO2 "ammissibile"
   * @param MaxValidCO2:             nuovo valore massimo dell'intervallo valido di CO2 "ammissibile" del sensore
   * @throw std::invalid_argument:   se il valore CO2 massimo è superiore al valore CO2 minimo
   */
  void setMaxValidCO2(int MaxValidCO2);

   /**
   * @brief setMinValidOssigeno:           setter per il valore minimo dell'intervallo valido di Ossigeno "ammissibile"
   * @param MinValidOssigeno:              nuovo valore minimo dell'intervallo valido di Ossigeno "ammissibile" del sensore
   * @throw std::invalid_argument:        se il valore di ossigeno minimo è superiore al valore di ossigeno massimo
   */

  void setMinValidOssigeno(int MinValidCOssigeno);

  /**
   * @brief setMaxValidOssigen:        setter per il valore massimo dell'intervallo valido di Ossigeno "ammissibile"
   * @param MaxValidOssigeno:          nuovo valore massimo dell'intervallo valido di Ossigeno "ammissibile" del sensore
   * @throw std::invalid_argument:     se il valore di ossigeno massimo è superiore al valore di ossigeno minimo
   */
  void setMaxValidOssigeno(int MaxValidOssigeno);
  

 /**
 * @brief getCO2Vector:     getter (per riferimento) del vettore di CO2 campionati
 */
 const std::vector<int> &getCO2Vector();

  /**
  * @brief getOssigenoVector:     getter (per riferimento) del vettore dell' Ossigeno campionati
  */
  const std::vector<int> &getOssigenoVector();

   /**
   * @brief addCO2Record:      metodo per aggiungere un dato al vettore di CO2 campionati
   * @param record:            nuovo record da aggiungere al vettore di CO2 campionate
   */
  void addCO2Record(int record);

  /**
   * @brief removeCO2Record:          metodo per rimuovere un dato dal vettore di CO2 campionati
   * @param posizione:                posizione dalla quale rimuovere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void removeCO2Record(unsigned int posizione);

  /**
   * @brief getCO2Record:             metodo per ottenere un dato dal vettore di CO2 campionati
   * @param posizione:                posizione dalla quale ottenere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  int getCO2Record(unsigned int posizione);

  /**
   * @brief insertCO2Record:          metodo per inserire un dato nel vettore di CO2 campionati in una posizione specifica
   * @param posizione:                posizione dalla quale inserire il dato
   * @param record:                   nuovo record da aggiungere al vettore di CO2 campionate
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void insertCO2Record(unsigned int posizione, int record);

  /**
   * @brief updateCO2Record:            update di un valore dell'array del CO2
   * @param posizione:                  posizione della modifica da effettuare
   * @param record:                     valore della modifica
   * @throw std::invalid_argument:      se si vuole modificare un dato in una posizione non esistente!
   */
  void updateCO2Record(unsigned int posizione, int record);

    /**
   * @brief addCO2Record:              metodo per aggiungere un dato vettore dell' ossigeno campionati
   * @param record:                    nuovo record da aggiungere al vettore dell' ossigeno campionati
   */
  void addOssigenoRecord(int record);

  /**
   * @brief removeOssigenoRecord:     metodo per rimuovere un dato dal vettore dell' ossigeno campionati
   * @param posizione:                posizione dalla quale rimuovere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void removeOssigenoRecord(unsigned int posizione);

  /**
   * @brief getOssigenoRecord:        metodo per ottenere un dato dal vettore dell' ossigeno campionati
   * @param posizione:                posizione dalla quale ottenere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  int getOssigenoRecord(unsigned int posizione);

  /**
   * @brief insertOssigenoRecord:     metodo per inserire un dato nel vettore dell' ossigeno campionati in una posizione specifica
   * @param posizione:                posizione dalla quale inserire il dato
   * @param record:                   nuovo record da aggiungere dal vettore dell' ossigeno campionati
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void insertOssigenoRecord(unsigned int posizione, int record);

  /**
   * @brief updateOssigenoRecord:       update di un valore dell'array dell' ossigeno
   * @param posizione:                  posizione della modifica da effettuare
   * @param record:                     valore della modifica
   * @throw std::invalid_argument:      se si vuole modificare un dato in una posizione non esistente!
   */
  void updateOssigenoRecord(unsigned int posizione, int record);

  /**
  * @brief MinCO2:                   restituisce il valore minimo del vettore del CO2 campionati
  * @throw std::length_error         se il vettore del CO2 è vuoto
  */
  int MinCO2() const;

  /**
   * @brief MaxCO2:                  restituisce il valore massimo del vettore del CO2 campionati
   * @throw std::length_error        se il vettore del CO2 è vuoto
   */
  int MaxCO2() const;

  /**
  * @brief MinOssigeno:              restituisce il valore minimo del vettore dell'Ossigeno campionati
  * @throw std::length_error         se il vettore dell' ossigeno è vuoto
  */
  int MinOssigeno() const;

  /**
   * @brief MaxOssigeno:              restituisce il valore massimo del vettore dell'Ossigeno campionati
   * @throw std::length_error        se il vettore dell'ossigeno è vuoto
   */
  int MaxOssigeno() const;

  /**
   * @brief Qualità:                  restituisce un valore in percentuale che indica la qualità dell'ambiente analizzato
   */
  int Qualità() const override;

  /**
   * @brief clone:                    metodo per implementare il clonable pattern per la  gerarchia
   */
  SensoreAria *clone() const override;
};


#endif // SENSOREARIA_H