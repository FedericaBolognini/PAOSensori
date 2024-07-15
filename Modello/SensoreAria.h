#ifndef SENSOREARIA_H
#define SENSOREARIA_H

#include <string>
#include <vector>
#include <stdexcept>

class SensoreAria:public SensoreAria
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
 SensoreAria(const std::string &Nome, unsigned int Precisione, int ID, double MinValidTemperatura,
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
   * @throw std::invalid_argument:    se la temperatura minima è superiore alla temperatura massima
   */

  void setMinValidCO2(double MinValidCO2);

  /**
   * @brief setMaxValidCO2:          setter per il valore massimo dell'intervallo valido di CO2 "ammissibile"
   * @param MaxValidCO2:             nuovo valore massimo dell'intervallo valido di CO2 "ammissibile" del sensore
   * @throw std::invalid_argument:   se la temperatura massima è inferiore alla temperatura minima
   */
  void setMaxValidCO2(double MaxValidCO2);

   /**
   * @brief setMinValidOssigeno:           setter per il valore minimo dell'intervallo valido di Ossigeno "ammissibile"
   * @param MinValidOssigeno:              nuovo valore minimo dell'intervallo valido di Ossigeno "ammissibile" del sensore
   * @throw std::invalid_argument:         se la temperatura minima è superiore alla temperatura massima
   */

  void setMinValidOssigeno(double MinValidCOssigeno);

  /**
   * @brief setMaxValidOssigen:        setter per il valore massimo dell'intervallo valido di Ossigeno "ammissibile"
   * @param MaxValidOssigeno:          nuovo valore massimo dell'intervallo valido di Ossigeno "ammissibile" del sensore
   * @throw std::invalid_argument:     se la temperatura massima è inferiore alla temperatura minima
   */
  void setMaxValidOssigeno(double MaxValidOssigeno);
  

 /**
 * @brief getCO2Vector:     getter (per riferimento) del vettore di CO2 campionati
 */
 const std::vector<int> &getCO2Vector();

  /**
  * @brief getOssigenoVector:     getter (per riferimento) del vettore dell' Ossigeno campionati
  */
  const std::vector<int> &getOssigenoVector();

  /**
  * @brief MinCO2:                   restituisce il valore minimo del vettore del CO2 campionati
  * @throw std::length_error         se il vettore delle temperature è vuoto
  */
  int MinCO2() const;

  /**
   * @brief MaxCO2:                  restituisce il valore massimo del vettore del CO2 campionati
   * @throw std::length_error        se il vettore delle temperature è vuoto
   */
  int MaxCO2() const;

  /**
  * @brief MinOssigeno:              restituisce il valore minimo del vettore dell'Ossigeno campionati
  * @throw std::length_error         se il vettore delle temperature è vuoto
  */
  int MinOssigeno() const;

  /**
   * @brief MaxOssigeno:              restituisce il valore massimo del vettore dell'Ossigeno campionati
   * @throw std::length_error        se il vettore delle temperature è vuoto
   */
  int MaxOssigeno() const;

  /**
   * @brief Qualità:                  restituisce un valore in percentuale che indica la qualità dell'ambiente analizzato
   */
  virtual int Qualità() const = 0;

  /**
   * @brief clone:                    metodo per implementare il clonable pattern per la  gerarchia
   */
  virtual SensoreAria *clone() const = 0;

  /**
   * @brief ~SensoreAria:                distruttore 
   */
  virtual ~SensoreAria() = default;
};


#endif // SENSOREARIA_H