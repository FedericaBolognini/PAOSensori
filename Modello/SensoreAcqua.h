#ifndef SENSOREACQUA_H
#define SENSOREACQUA_H

#include <string>
#include <vector>
#include <stdexcept>

class SensoreAcqua:public SensoreAcqua
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
   * @param MinValidAlcalinità:              valore minimo dell'intervallo valido di Alcalinità "ammissibile"
   * @param MaxValidAlcalinità:              valore massimo dell'intervallo valido di Alcalinità "ammissibile"
   * @param MinValidAcidità:         valore minimo dell'intervallo valido di Acidità "ammissibile"
   * @param MaxValidAcidità:         valore massimo dell'intervallo valido di Acidità "ammissibile"
   * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - 
   * se il range di valori per la temperatura non è corretto - se il range di valori per Alcalinità non è corretto - se il range di valori per l'Acidità non è corretto
   */
 SensoreAcqua(const std::string &Nome, unsigned int Precisione, int ID, double MinValidTemperatura,
 double MaxValidTemperatura,int MinValidAlcalinità, int MaxValidAlcalinità, int MinValidAcidità,int MaxValidAcidità);

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
   * @throw std::invalid_argument:    se la temperatura minima è superiore alla temperatura massima
   */

  void setMinValidAlcalinità(double MinValidAlcalinità);

  /**
   * @brief setMaxValidAlcalinità:          setter per il valore massimo dell'intervallo valido di Alcalinità "ammissibile"
   * @param MaxValidAlcalinità:             nuovo valore massimo dell'intervallo valido di Alcalinità "ammissibile" del sensore
   * @throw std::invalid_argument:   se la temperatura massima è inferiore alla temperatura minima
   */
  void setMaxValidAlcalinità(double MaxValidAlcalinità);

   /**
   * @brief setMinValidAcidità:           setter per il valore minimo dell'intervallo valido di Acidità "ammissibile"
   * @param MinValidAcidità:              nuovo valore minimo dell'intervallo valido di Acidità "ammissibile" del sensore
   * @throw std::invalid_argument:         se la temperatura minima è superiore alla temperatura massima
   */

  void setMinValidAcidità(double MinValidCAcidità);

  /**
   * @brief setMaxValidOssigen:        setter per il valore massimo dell'intervallo valido di Acidità "ammissibile"
   * @param MaxValidAcidità:          nuovo valore massimo dell'intervallo valido di Acidità "ammissibile" del sensore
   * @throw std::invalid_argument:     se la temperatura massima è inferiore alla temperatura minima
   */
  void setMaxValidAcidità(double MaxValidAcidità);
  

 /**
 * @brief getAlcalinitàVector:     getter (per riferimento) del vettore di Alcalinità campionati
 */
 const std::vector<int> &getAlcalinitàVector();

  /**
  * @brief getAciditàVector:     getter (per riferimento) del vettore dell' Acidità campionati
  */
  const std::vector<int> &getAciditàVector();

  /**
  * @brief MinAlcalinità:                   restituisce il valore minimo del vettore del Alcalinità campionati
  * @throw std::length_error         se il vettore delle temperature è vuoto
  */
  int MinAlcalinità() const;

  /**
   * @brief MaxAlcalinità:                  restituisce il valore massimo del vettore del Alcalinità campionati
   * @throw std::length_error        se il vettore delle temperature è vuoto
   */
  int MaxAlcalinità() const;

  /**
  * @brief MinAcidità:              restituisce il valore minimo del vettore dell'Acidità campionati
  * @throw std::length_error         se il vettore delle temperature è vuoto
  */
  int MinAcidità() const;

  /**
   * @brief MaxAcidità:              restituisce il valore massimo del vettore dell'Acidità campionati
   * @throw std::length_error        se il vettore delle temperature è vuoto
   */
  int MaxAcidità() const;

  /**
   * @brief Qualità:                  restituisce un valore in percentuale che indica la qualità dell'ambiente analizzato
   */
  virtual int Qualità() const = 0;

  /**
   * @brief clone:                    metodo per implementare il clonable pattern per la  gerarchia
   */
  virtual SensoreAcqua *clone() const = 0;

  /**
   * @brief ~SensoreAcqua:                distruttore 
   */
  override ~SensoreAcqua() = default;
};


#endif // SENSOREACQUA_H