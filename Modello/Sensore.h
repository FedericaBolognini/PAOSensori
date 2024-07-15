#ifndef SENSORE_H
#define SENSORE_H

#include <string>
#include <vector>
#include <stdexcept>

class Sensore
{
private:
  // Nome del sensore
  std::string Nome;

  // Precisione delle misurazioni
  unsigned int Precisione;

  // Identificativo del sensore
  unsigned int ID;

  // Valore minimo dell'intervallo valido di temperatura "salubre"
  double MinValidTemperatura;

  // Valore massimo dell'intervallo valido di temperatura "salubre"
  double MaxValidTemperatura;

  // Vettore contenente i dati di temperatura campionati
  std::vector<double> Temperatura;

public:
  /**
   * @brief Sensore: costruttore di default, inizializza le stringhe con valori
   * vuoti e gli interi/double a zero
   */
  Sensore();

  /**
   * @brief Sensore: costruttore, costruisce un sensore a partire da nome, precisione, ID, valore minimo e massimo della temperatura
   * @param Nome:                     nome del sensore
   * @param Precisione:               precisione del sensore, utilizzato nelle simulazioni
   * @param ID:                       identificativo del sensore
   * @param MinValidTemperatura:      valore minimo dell'intervallo valido di temperatura "salubre"
   * @param MaxValidTemperatura:      valore massimo dell'intervallo valido di temperatura "salubre"
   * @throw std::invalid_argument     se il nome è vuoto - se la precisione supera il 100% - se il range di valori per la temperatura non è corretto
   */
  Sensore(const std::string &Nome, unsigned int Precisione, unsigned int ID,
          double MinValidTemperatura, double MaxValidTemperatura);

  /**
   * @brief getNome:                  getter per il nome
   */
  std::string getNome() const;

  /**
   * @brief getPrecisione:            getter per la precisione
   */
  unsigned int getPrecisione() const;

  /**
   * @brief getID:                    getter per l'ID
   */
  unsigned int getID() const;

  /**
   * @brief getMinValidTemperatura:    getter per il valore minimo dell'intervallo valido di temperatura "salubre"
   */
  double getMinValidTemperatura() const;

  /**
   * @brief getMaxValidTemperatura:    getter per il valore massimo dell'intervallo valido di temperatura "salubre"
   */
  double getMaxValidTemperatura() const;

  /**
   * @brief addTemperaturaRecord:      metodo per aggiungere un dato al vettore di temperature campionate
   * @param record:                    nuovo record da aggiungere al vettore di temperature campionate
   */
  void addTemperaturaRecord(double record);

  /**
   * @brief removeTemperaturaRecord:  metodo per rimuovere un dato dal vettore di temperature campionate
   * @param posizione:                posizione dalla quale rimuovere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void removeTemperaturaRecord(unsigned int posizione);

  /**
   * @brief getTemperaturaRecord:     metodo per ottenere un dato dal vettore di temperature campionate
   * @param posizione:                posizione dalla quale ottenere il dato
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  double getTemperaturaRecord(unsigned int posizione);

  /**
   * @brief insertTemperaturaRecord:  metodo per inserire un dato nel vettore di temperature campionate in una posizione specifica
   * @param posizione:                posizione dalla quale inserire il dato
   * @param record:                   nuovo record da aggiungere al vettore di temperature campionate
   * @throw std::invalid_argument:    se la posizione indicata eccede i limiti del vettore
   */
  void insertTemperaturaRecord(unsigned int posizione, double record);

  /**
   * @brief setNome:                  setter per il nome
   * @param Nome:                     nuovo nome del sensore
   * @throw std::invalid_argument:    se il nome del sensore è vuoto
   */
  void setNome(const std::string &Nome);

  /**
   * @brief setPrecisione:            setter per la precisione
   * @param Precisione:               nuova precisione del sensore
   * @throw std::invalid_argument:    se la precisione del sensore supera il 100%
   */
  void setPrecisione(unsigned int Precisione);

  /**
   * @brief setID:                    setter per l'ID
   * @param ID:                       nuovo ID del sensore
   */
  void setID(unsigned int ID);

  /**
   * @brief setMinValidTemperatura:   setter per il valore minimo dell'intervallo valido di temperatura "salubre"
   * @param MinValidTemperatura:      nuovo valore minimo dell'intervallo valido di temperatura "salubre" del sensore
   * @throw std::invalid_argument:    se la temperatura minima è superiore alla temperatura massima
   */
  void setMinValidTemperatura(double MinValidTemperatura);

  /**
   * @brief setMaxValidTemperatura:    setter per il valore massimo dell'intervallo valido di temperatura "salubre"
   * @param MaxValidTemperatura:       nuovo valore massimo dell'intervallo valido di temperatura "salubre" del sensore
   * @throw std::invalid_argument:    se la temperatura massima è inferiore alla temperatura minima
   */
  void setMaxValidTemperatura(double MaxValidTemperatura);

  /**
   * @brief updateTemperaturaRecord:    update di un valore dell'array delle temperature
   * @param posizione:                  posizione della modifica da effettuare
   * @param record:                     valore della modifica
   * @throw std::invalid_argument:      se si vuole modificare un dato in una posizione non esistente!
   */
  void updateTemperaturaRecord(unsigned int posizione, double record);

  /**
   * @brief getTemperaturaVector:     getter (per riferimento) del vettore di temperature campionate
   */
  const std::vector<double> &getTemperaturaVector();

  /**
   * @brief MinTemperatura:           restituisce il valore minimo del vettore delle temperature campionate
   * @throw std::length_error         se il vettore delle temperature è vuoto
   */
  double MinTemperatura() const;

  /**
   * @brief MaxTemperatura:           restituisce il valore massimo del vettore delle temperature campionate
   * @throw std::length_error         se il vettore delle temperature è vuoto
   */
  double MaxTemperatura() const;

  /**
   * @brief Qualità:                  restituisce un valore in percentuale che indica la qualità dell'ambiente analizzato
   */
  virtual int Qualità() const = 0;

  /**
   * @brief clone:                    metodo per implementare il clonable pattern per la  gerarchia
   */
  virtual Sensore *clone() const = 0;

  /**
   * @brief ~Sensore:                distruttore virtuale per la gerarchia
   */
  virtual ~Sensore() = default;
};

#endif // SENSORE_H