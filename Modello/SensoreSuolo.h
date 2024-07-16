#ifndef SENSORESUOLO_H
#define SENSORESUOLO_H

#include <string>
#include <vector>
#include <stdexcept>
#include "Sensore.h"

class SensoreSuolo: public Sensore
{
private:
    // Valore minimo dell'intervallo valido di PH "ammissibile"
    int MinValidPH;
    // Valore massimo dell'intervallo valido di PH "ammissibile"
    int MaxValidPH;
    // Valore minimo dell'intervallo valido di Umidità "ammissibile"
    int MinValidUmidità;
    // Valore massimo dell'intervallo valido di Umidità "ammissibile"
    int MaxValidUmidità;
    // Vettore contenente i dati di PH campionati
    std::vector <int> PH;
    // Vettore contenente i dati di Umidità campionati
    std::vector <int> Umidità;

public:
  /**
   * @brief SensoreSuolo: costruttore di default, inizializza le stringhe con valori
   * vuoti e gli interi/double a zero
   */
  SensoreSuolo();

  /**
   * @brief SensoreSuolo: costruttore, costruisce un sensore Suolo a partire da nome, precisione, ID, valore minimo e massimo della temperatura
   * @param Nome:                     nome del sensore
   * @param Precisione:               precisione del sensore, utilizzato nelle simulazioni
   * @param ID:                       identificativo del sensore
   * @param MinValidTemperatura:      valore minimo dell'intervallo valido di temperatura "salubre"
   * @param MaxValidTemperatura:      valore massimo dell'intervallo valido di temperatura "salubre"
   * @param MinValidPH:              valore minimo dell'intervallo valido di PH "ammissibile"
   * @param MaxValidPH:              valore massimo dell'intervallo valido di PH "ammissibile"
   * @param MinValidUmidità:         valore minimo dell'intervallo valido di Umidità "ammissibile"
   * @param MaxValidUmidità:         valore massimo dell'intervallo valido di Umidità "ammissibile"
   * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - 
   * se il range di valori per la temperatura non è corretto - se il range di valori per PH non è corretto - se il range di valori per l'Umidità non è corretto
   */
 SensoreSuolo(const std::string &Nome, unsigned int Precisione, unsigned int ID, double MinValidTemperatura,
 double MaxValidTemperatura,int MinValidPH, int MaxValidPH, int MinValidUmidità,int MaxValidUmidità);

 /**
 * @brief getMinValidPH:    getter per il valore minimo dell'intervallo valido di PH "ammissibile"
 */
int getMinValidPH() const;

 /**
 * @brief getMaxValidPH:    getter per il valore massimo dell'intervallo valido di PH "ammissibile"
 */
 int getMaxValidPH() const;

 /**
 * @brief getMinValidUmidità:    getter per il valore minimo dell'intervallo valido di Umidità "ammissibile"
 */
 int getMinValidUmidità() const;

 /**
 * @brief getMaxValidUmidità:    getter per il valore massimo dell'intervallo valido di Umidità "ammissibile"
 */
 int getMaxValidUmidità() const;

   /**
   * @brief setMinValidPH:           setter per il valore minimo dell'intervallo valido di PH "ammissibile"
   * @param MinValidPH:              nuovo valore minimo dell'intervallo valido di PH "ammissibile" del sensore
   * @throw std::invalid_argument:    se la temperatura minima è superiore alla temperatura massima
   */

  void setMinValidPH(int MinValidPH);

  /**
   * @brief setMaxValidPH:          setter per il valore massimo dell'intervallo valido di PH "ammissibile"
   * @param MaxValidPH:             nuovo valore massimo dell'intervallo valido di PH "ammissibile" del sensore
   * @throw std::invalid_argument:   se la temperatura massima è inferiore alla temperatura minima
   */
  void setMaxValidPH(int MaxValidPH);

   /**
   * @brief setMinValidUmidità:           setter per il valore minimo dell'intervallo valido di Umidità "ammissibile"
   * @param MinValidUmidità:              nuovo valore minimo dell'intervallo valido di Umidità "ammissibile" del sensore
   * @throw std::invalid_argument:         se la temperatura minima è superiore alla temperatura massima
   */

  void setMinValidUmidità(int MinValidCUmidità);

  /**
   * @brief setMaxValidOssigen:        setter per il valore massimo dell'intervallo valido di Umidità "ammissibile"
   * @param MaxValidUmidità:          nuovo valore massimo dell'intervallo valido di Umidità "ammissibile" del sensore
   * @throw std::invalid_argument:     se la temperatura massima è inferiore alla temperatura minima
   */
  void setMaxValidUmidità(int MaxValidUmidità);

  /**
   * @brief addPHRecord:      metodo per aggiungere un dato al vettore di PH campionati
   * @param record:            nuovo record da aggiungere al vettore di PH campionate
   */
  void addPHRecord(int record);

  /**
   * @brief removePHRecord:          metodo per rimuovere un dato dal vettore di PH campionati
   * @param posizione:                posizione dalla quale rimuovere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void removePHRecord(unsigned int posizione);

  /**
   * @brief getPHRecord:             metodo per ottenere un dato dal vettore di PH campionati
   * @param posizione:                posizione dalla quale ottenere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  int getPHRecord(unsigned int posizione);

  /**
   * @brief insertPHRecord:          metodo per inserire un dato nel vettore di PH campionati in una posizione specifica
   * @param posizione:                posizione dalla quale inserire il dato
   * @param record:                   nuovo record da aggiungere al vettore di PH campionate
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void insertPHRecord(unsigned int posizione, int record);

  /**
   * @brief updatePHRecord:            update di un valore dell'array del PH
   * @param posizione:                  posizione della modifica da effettuare
   * @param record:                     valore della modifica
   * @throw std::invalid_argument:      se si vuole modificare un dato in una posizione non esistente!
   */
  void updatePHRecord(unsigned int posizione, int record);

    /**
   * @brief addPHRecord:              metodo per aggiungere un dato vettore dell' Umidità campionati
   * @param record:                    nuovo record da aggiungere al vettore dell' Umidità campionati
   */
  void addUmiditàRecord(int record);

  /**
   * @brief removeUmiditàRecord:     metodo per rimuovere un dato dal vettore dell' Umidità campionati
   * @param posizione:                posizione dalla quale rimuovere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void removeUmiditàRecord(unsigned int posizione);

  /**
   * @brief getUmiditàRecord:        metodo per ottenere un dato dal vettore dell' Umidità campionati
   * @param posizione:                posizione dalla quale ottenere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  int getUmiditàRecord(unsigned int posizione);

  /**
   * @brief insertUmiditàRecord:     metodo per inserire un dato nel vettore dell' Umidità campionati in una posizione specifica
   * @param posizione:                posizione dalla quale inserire il dato
   * @param record:                   nuovo record da aggiungere dal vettore dell' Umidità campionati
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void insertUmiditàRecord(unsigned int posizione, int record);

  /**
   * @brief updateUmiditàRecord:       update di un valore dell'array dell' Umidità
   * @param posizione:                  posizione della modifica da effettuare
   * @param record:                     valore della modifica
   * @throw std::invalid_argument:      se si vuole modificare un dato in una posizione non esistente!
   */
  void updateUmiditàRecord(unsigned int posizione, int record);
  

 /**
 * @brief getPHVector:     getter (per riferimento) del vettore di PH campionati
 */
 const std::vector<int> &getPHVector();

  /**
  * @brief getUmiditàVector:     getter (per riferimento) del vettore dell' Umidità campionati
  */
  const std::vector<int> &getUmiditàVector();

  /**
  * @brief MinPH:                   restituisce il valore minimo del vettore del PH campionati
  * @throw std::length_error         se il vettore dei PH è vuoto
  */
  int MinPH() const;

  /**
   * @brief MaxPH:                  restituisce il valore massimo del vettore del PH campionati
   * @throw std::length_error        se il vettore dei PH è vuoto
   */
  int MaxPH() const;

  /**
  * @brief MinUmidità:              restituisce il valore minimo del vettore dell'Umidità campionati
  * @throw std::length_error         se il vettore dell'Umidità è vuoto
  */
  int MinUmidità() const;

  /**
   * @brief MaxUmidità:              restituisce il valore massimo del vettore dell'Umidità campionati
   * @throw std::length_error        se il vettore dell'Umidità è vuoto
   */
  int MaxUmidità() const;

  /**
   * @brief Qualità:                  restituisce un valore in percentuale che indica la qualità dell'ambiente analizzato
   */
  int Qualità() const override;

  /**
   * @brief clone:                    metodo per implementare il clonable pattern per la  gerarchia
   */
  virtual SensoreSuolo *clone() const override;

};


#endif // SENSORESUOLO_H