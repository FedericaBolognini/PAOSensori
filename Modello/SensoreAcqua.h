#ifndef SENSOREACQUA_H
#define SENSOREACQUA_H

#include "Sensore.h"
#include <string>
#include <vector>
#include <stdexcept>

class SensoreAcqua: public Sensore
{
private:
    // Valore minimo dell'intervallo valido di Alcalinità "ammissibile"
    int MinValidAlcalinità;
    // Valore massimo dell'intervallo valido di Alcalinità "ammissibile"
    int MaxValidAlcalinità;
    // Valore minimo dell'intervallo valido di Acidità "ammissibile"
    int MinValidAcidità;
    // Valore massimo dell'intervallo valido di Acidità "ammissibile"
    int MaxValidAcidità;
    // Vettore contenente i dati di Alcalinità campionati
    std::vector <int> Alcalinità;
    // Vettore contenente i dati di Acidità campionati
    std::vector <int> Acidità;

public:
  /**
   * @brief SensoreAcqua: costruttore di default, inizializza le stringhe con valori
   * vuoti e gli interi/double a zero
   */
  SensoreAcqua();

  /**
   * @brief SensoreAcqua: costruttore, costruisce un sensore acqua a partire da nome, precisione, ID, valore minimo e massimo della temperatura
   * @param Nome:                     nome del sensore
   * @param Precisione:               precisione del sensore, utilizzato nelle simulazioni
   * @param ID:                       identificativo del sensore
   * @param MinValidTemperatura:      valore minimo dell'intervallo valido di temperatura "salubre"
   * @param MaxValidTemperatura:      valore massimo dell'intervallo valido di temperatura "salubre"
   * @param MinValidAlcalinità:       valore minimo dell'intervallo valido di Alcalinità "ammissibile"
   * @param MaxValidAlcalinità:       valore massimo dell'intervallo valido di Alcalinità "ammissibile"
   * @param MinValidAcidità:          valore minimo dell'intervallo valido di Acidità "ammissibile"
   * @param MaxValidAcidità:          valore massimo dell'intervallo valido di Acidità "ammissibile"
   * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - 
   * se il range di valori per la temperatura non è corretto - se il range di valori per Alcalinità non è corretto - se il range di valori per l'Acidità non è corretto
   */
 SensoreAcqua(const std::string &Nome, unsigned int Precisione, unsigned int ID, double MinValidTemperatura,
 double MaxValidTemperatura,int MinValidAlcalinità, int MaxValidAlcalinità, int MinValidAcidità, int MaxValidAcidità);

 /**
 * @brief getMinValidAlcalinità:    getter per il valore minimo dell'intervallo valido di Alcalinità "ammissibile"
 */
int getMinValidAlcalinità() const;

 /**
 * @brief getMaxValidAlcalinità:    getter per il valore massimo dell'intervallo valido di Alcalinità "ammissibile"
 */
 int getMaxValidAlcalinità() const;

 /**
 * @brief getMinValidAcidità:    getter per il valore minimo dell'intervallo valido di Acidità "ammissibile"
 */
 int getMinValidAcidità() const;

 /**
 * @brief getMaxValidAcidità:    getter per il valore massimo dell'intervallo valido di Acidità "ammissibile"
 */
 int getMaxValidAcidità() const;

   /**
   * @brief setMinValidAlcalinità:           setter per il valore minimo dell'intervallo valido di Alcalinità "ammissibile"
   * @param MinValidAlcalinità:              nuovo valore minimo dell'intervallo valido di Alcalinità "ammissibile" del sensore
   * @throw std::invalid_argument:          se l'alcalinità minima è superiore all'alcalinità massima
   */

  void setMinValidAlcalinità(int MinValidAlcalinità);

  /**
   * @brief setMaxValidAlcalinità:          setter per il valore massimo dell'intervallo valido di Alcalinità "ammissibile"
   * @param MaxValidAlcalinità:             nuovo valore massimo dell'intervallo valido di Alcalinità "ammissibile" del sensore
   * @throw std::invalid_argument:          se l'alcalinità massima è inferiore l'alcalinità minima
   */
  void setMaxValidAlcalinità(int MaxValidAlcalinità);

   /**
   * @brief setMinValidAcidità:           setter per il valore minimo dell'intervallo valido di Acidità "ammissibile"
   * @param MinValidAcidità:              nuovo valore minimo dell'intervallo valido di Acidità "ammissibile" del sensore
   * @throw std::invalid_argument:         se l'acidità minima è superiore all'acidità massima
   */

  void setMinValidAcidità(int MinValidCAcidità);

  /**
   * @brief setMaxValidOssigen:        setter per il valore massimo dell'intervallo valido di Acidità "ammissibile"
   * @param MaxValidAcidità:          nuovo valore massimo dell'intervallo valido di Acidità "ammissibile" del sensore
   * @throw std::invalid_argument:     se l'acidità massima è inferiore all'acidità minima
   */
  void setMaxValidAcidità(int MaxValidAcidità);
  

 /**
 * @brief getAlcalinitàVector:     getter (per riferimento) del vettore di Alcalinità
 */
 const std::vector<int> &getAlcalinitàVector();

  /**
  * @brief getAciditàVector:     getter (per riferimento) del vettore dell' Acidità
  */
  const std::vector<int> &getAciditàVector();

  /**
  * @brief MinAlcalinità:                   restituisce il valore minimo del vettore del Alcalinità
  * @throw std::length_error         se il vettore Alcalinità è vuoto
  */
  int MinAlcalinità() const;

  /**
   * @brief MaxAlcalinità:                  restituisce il valore massimo del vettore del Alcalinità
   * @throw std::length_error        se il vettore Alcalinità è vuoto
   */
  int MaxAlcalinità() const;

  /**
  * @brief MinAcidità:              restituisce il valore minimo del vettore dell'Acidità campionati
  * @throw std::length_error         se il vettore Acidità è vuoto
  */
  int MinAcidità() const;

  /**
   * @brief MaxAcidità:              restituisce il valore massimo del vettore dell'Acidità campionati
   * @throw std::length_error        se il vettore Acidità è vuoto
   */
  int MaxAcidità() const;

  /**
   * @brief addAlcalinitàRecord:      metodo per aggiungere un dato al vettore di alcalinità campionate
   * @param record:                    nuovo record da aggiungere al vettore di alcalinità campionate
   */
  void addAlcalinitàRecord(int record);

  /**
   * @brief removeAlcalinitàRecord:  metodo per rimuovere un dato dal vettore di alcalinità campionate
   * @param posizione:                posizione dalla quale rimuovere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void removeAlcalinitàRecord(unsigned int posizione);

  /**
   * @brief getAlcalinitàRecord:     metodo per ottenere un dato dal vettore di alcalinità campionate
   * @param posizione:                posizione dalla quale ottenere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  int getAlcalinitàRecord(unsigned int posizione);

  /**
   * @brief insertAlcalinitàRecord:  metodo per inserire un dato nel vettore di alcalinità campionate in una posizione specifica
   * @param posizione:                posizione dalla quale inserire il dato
   * @param record:                   nuovo record da aggiungere al vettore di alcalinità campionate
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void insertAlcalinitàRecord(unsigned int posizione, int record);

  /**
   * @brief updateAlcalinitàRecord:    update di un valore dell'array delle alcalinità
   * @param posizione:                  posizione della modifica da effettuare
   * @param record:                     valore della modifica
   * @throw std::invalid_argument:      se si vuole modificare un dato in una posizione non esistente!
   */
  void updateAlcalinitàRecord(unsigned int posizione, int record);

    /**
   * @brief addAlcalinitàRecord:      metodo per aggiungere un dato al vettore di acidità campionate
   * @param record:                    nuovo record da aggiungere al vettore di acidità campionate
   */
  void addAciditàRecord(int record);

  /**
   * @brief removeAciditàRecord:  metodo per rimuovere un dato dal vettore di acidità campionate
   * @param posizione:                posizione dalla quale rimuovere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void removeAciditàRecord(unsigned int posizione);

  /**
   * @brief getAciditàRecord:     metodo per ottenere un dato dal vettore di acidità campionate
   * @param posizione:                posizione dalla quale ottenere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  int getAciditàRecord(unsigned int posizione);

  /**
   * @brief insertAciditàRecord:  metodo per inserire un dato nel vettore di acidità campionate in una posizione specifica
   * @param posizione:                posizione dalla quale inserire il dato
   * @param record:                   nuovo record da aggiungere al vettore di acidità campionate
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void insertAciditàRecord(unsigned int posizione, int record);

  /**
   * @brief updateAciditàRecord:    update di un valore dell'array delle acidità
   * @param posizione:                  posizione della modifica da effettuare
   * @param record:                     valore della modifica
   * @throw std::invalid_argument:      se si vuole modificare un dato in una posizione non esistente!
   */
  void updateAciditàRecord(unsigned int posizione, int record);

  /**
   * @brief Qualità:                  restituisce un valore in percentuale che indica la qualità dell'ambiente analizzato
   */
  int Qualità() const override;

  /**
   * @brief clone:                    metodo per implementare il clonable pattern per la  gerarchia
   */
  SensoreAcqua *clone() const override;

};


#endif // SENSOREACQUA_H