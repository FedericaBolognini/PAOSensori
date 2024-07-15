#ifndef SENSORESUOLO_H
#define SENSORESUOLO_H

#include <string>
#include <vector>
#include <stdexcept>

class SensoreSuolo:public SensoreSuolo
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
 SensoreSuolo(const std::string &Nome, unsigned int Precisione, int ID, double MinValidTemperatura,
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

  void setMinValidPH(double MinValidPH);

  /**
   * @brief setMaxValidPH:          setter per il valore massimo dell'intervallo valido di PH "ammissibile"
   * @param MaxValidPH:             nuovo valore massimo dell'intervallo valido di PH "ammissibile" del sensore
   * @throw std::invalid_argument:   se la temperatura massima è inferiore alla temperatura minima
   */
  void setMaxValidPH(double MaxValidPH);

   /**
   * @brief setMinValidUmidità:           setter per il valore minimo dell'intervallo valido di Umidità "ammissibile"
   * @param MinValidUmidità:              nuovo valore minimo dell'intervallo valido di Umidità "ammissibile" del sensore
   * @throw std::invalid_argument:         se la temperatura minima è superiore alla temperatura massima
   */

  void setMinValidUmidità(double MinValidCUmidità);

  /**
   * @brief setMaxValidOssigen:        setter per il valore massimo dell'intervallo valido di Umidità "ammissibile"
   * @param MaxValidUmidità:          nuovo valore massimo dell'intervallo valido di Umidità "ammissibile" del sensore
   * @throw std::invalid_argument:     se la temperatura massima è inferiore alla temperatura minima
   */
  void setMaxValidUmidità(double MaxValidUmidità);
  

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
  * @throw std::length_error         se il vettore delle temperature è vuoto
  */
  int MinPH() const;

  /**
   * @brief MaxPH:                  restituisce il valore massimo del vettore del PH campionati
   * @throw std::length_error        se il vettore delle temperature è vuoto
   */
  int MaxPH() const;

  /**
  * @brief MinUmidità:              restituisce il valore minimo del vettore dell'Umidità campionati
  * @throw std::length_error         se il vettore delle temperature è vuoto
  */
  int MinUmidità() const;

  /**
   * @brief MaxUmidità:              restituisce il valore massimo del vettore dell'Umidità campionati
   * @throw std::length_error        se il vettore delle temperature è vuoto
   */
  int MaxUmidità() const;

  /**
   * @brief Qualità:                  restituisce un valore in percentuale che indica la qualità dell'ambiente analizzato
   */
  virtual int Qualità() const = 0;

  /**
   * @brief clone:                    metodo per implementare il clonable pattern per la  gerarchia
   */
  virtual SensoreSuolo *clone() const = 0;

  /**
   * @brief ~SensoreSuolo:                distruttore 
   */
  virtual ~SensoreSuolo() = default;
};


#endif // SENSORESUOLO_H