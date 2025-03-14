#include "SensoreAcqua.h"

SensoreAcqua::SensoreAcqua()
    : MinValidAlcalinità(800), MaxValidAlcalinità(1000), MinValidAcidità(210000), MaxValidAcidità(300000), Alcalinità(), Acidità() {}

SensoreAcqua::SensoreAcqua(const std::string &Nome, unsigned int Precisione,
                           unsigned int ID, double MinValidTemperatura,
                           double MaxValidTemperatura, int MinValidAlcalinità, int MaxValidAlcalinità, int MinValidAcidità, int MaxValidAcidità)
    : Sensore(Nome, Precisione, ID, MinValidTemperatura, MaxValidTemperatura),
      MinValidAlcalinità(MinValidAlcalinità <= MaxValidAlcalinità ? MinValidAlcalinità : throw std::invalid_argument("Tentativo di creazione di un sensore con valore minimo di alcalinità superiore al massimo!")),
      MaxValidAlcalinità(MinValidAlcalinità <= MaxValidAlcalinità ? MaxValidAlcalinità : throw std::invalid_argument("Tentativo di creazione di un sensore con valore massimo di alcalinità inferiore al minimo!")),
      MinValidAcidità(MinValidAcidità <= MaxValidAcidità ? MinValidAcidità : throw std::invalid_argument("Tentativo di creazione di un sensore con valore minimo di acidità superiore al massimo!")),
      MaxValidAcidità(MinValidAcidità <= MaxValidAcidità ? MaxValidAcidità : throw std::invalid_argument("Tentativo di creazione di un sensore con valore massimo di acidità inferiore al minimo!")) {}

int SensoreAcqua::getMinValidAlcalinità() const
{
  return MinValidAlcalinità;
}

int SensoreAcqua::getMaxValidAlcalinità() const
{
  return MaxValidAlcalinità;
}

int SensoreAcqua::getMinValidAcidità() const
{
  return MinValidAcidità;
}

int SensoreAcqua::getMaxValidAcidità() const
{
  return MaxValidAcidità;
}

void SensoreAcqua::setMinValidAlcalinità(int MinValidAlcalinità)
{
  if (MinValidAlcalinità > MaxValidAlcalinità)
  {
    throw std::invalid_argument("Il valore di Alcalinità minimo non può essere più grande del massimo!");
  }
  this->MinValidAlcalinità = MinValidAlcalinità;
}

void SensoreAcqua::setMaxValidAlcalinità(int MaxValidAlcalinità)
{
  if (MinValidAlcalinità > MaxValidAlcalinità)
  {
    throw std::invalid_argument("Il valore di Alcalinità massimo non può essere più piccolo del minimo!");
  }
  this->MaxValidAlcalinità = MaxValidAlcalinità;
}

void SensoreAcqua::setMinValidAcidità(int MinValidAcidità)
{
  if (MinValidAcidità > MaxValidAcidità)
  {
    throw std::invalid_argument("Il valore di Acidità minimo non può essere più grande del massimo!");
  }
  this->MinValidAcidità = MinValidAcidità;
}

void SensoreAcqua::setMaxValidAcidità(int MaxValidAcidità)
{
  if (MinValidAcidità > MaxValidAcidità)
  {
    throw std::invalid_argument("Il valore di Acidità massimo non può essere più piccolo del minimo!");
  }
  this->MaxValidAcidità = MaxValidAcidità;
}

const std::vector<int> &SensoreAcqua::getAlcalinitàVector()
{
  return Alcalinità;
}

const std::vector<int> &SensoreAcqua::getAciditàVector()
{
  return Acidità;
}

int SensoreAcqua::MinAlcalinità() const
{
  int minima = Alcalinità[0];
  if (Alcalinità.empty())
  {
    throw std::length_error("Il vettore delle alcalinità è vuoto!");
  }
  else
  {
    for (int i = 1; i < Alcalinità.size(); ++i)
    {
      if (Alcalinità[i] < minima)
      {
        minima = Alcalinità[i];
      }
    }
  }
  return minima;
}

int SensoreAcqua::MaxAlcalinità() const
{
  int massima = Alcalinità[0];
  if (Alcalinità.empty())
  {
    throw std::length_error("Il vettore dell'alcalinità è vuoto!");
  }
  else
  {
    for (int i = 1; i < Alcalinità.size(); ++i)
    {
      if (Alcalinità[i] > massima)
      {
        massima = Alcalinità[i];
      }
    }
  }
  return massima;
}

int SensoreAcqua::MinAcidità() const
{
  int minima = Acidità[0];
  if (Acidità.empty())
  {
    throw std::length_error("Il vettore delle acidità è vuoto!");
  }
  else
  {
    for (int i = 1; i < Acidità.size(); ++i)
    {
      if (Acidità[i] < minima)
      {
        minima = Acidità[i];
      }
    }
  }
  return minima;
}

int SensoreAcqua::MaxAcidità() const
{
  int massima = Acidità[0];
  if (Acidità.empty())
  {
    throw std::length_error("Il vettore dell'acidità' è vuoto!");
  }
  else
  {
    for (int i = 1; i < Acidità.size(); ++i)
    {
      if (Acidità[i] > massima)
      {
        massima = Acidità[i];
      }
    }
  }
  return massima;
}

void SensoreAcqua::addAlcalinitàRecord(int record)
{
  Alcalinità.push_back(record);
}

void SensoreAcqua::removeAlcalinitàRecord(unsigned int posizione)
{
  if (Alcalinità.size() == 0 || posizione > Alcalinità.size() - 1)
  {
    throw std::invalid_argument("Tentativo di rimozione di un dato in posizione non esistente!");
  }

  auto elem = Alcalinità.begin();
  std::advance(elem, posizione);
  Alcalinità.erase(elem);
}

int SensoreAcqua::getAlcalinitàRecord(unsigned int posizione)
{
  if (Alcalinità.size() == 0 || posizione > Alcalinità.size() - 1)
  {
    throw std::invalid_argument("Tentativo di ottenimento di un dato in posizione non esistente!");
  }

  return Alcalinità.at(posizione);
}

void SensoreAcqua::insertAlcalinitàRecord(unsigned int posizione, int record)
{
  if (Alcalinità.size() == 0 || posizione > Alcalinità.size() - 1)
  {
    throw std::invalid_argument("Tentativo di inserimento di un dato in posizione non esistente!");
  }

  Alcalinità.insert(Alcalinità.begin() + posizione, record);
}

void SensoreAcqua::updateAlcalinitàRecord(unsigned int posizione, int record)
{
  if (Alcalinità.size() == 0 || posizione > Alcalinità.size() - 1)
  {
    throw std::invalid_argument("Tentativo di modifica di un dato in posizione non esistente!");
  }
  Alcalinità[posizione] = record;
}

void SensoreAcqua::addAciditàRecord(int record)
{
  Acidità.push_back(record);
}

void SensoreAcqua::removeAciditàRecord(unsigned int posizione)
{
  if (Acidità.size() == 0 || posizione > Acidità.size() - 1)
  {
    throw std::invalid_argument("Tentativo di rimozione di un dato in posizione non esistente!");
  }

  auto elem = Acidità.begin();
  std::advance(elem, posizione);
  Acidità.erase(elem);
}

int SensoreAcqua::getAciditàRecord(unsigned int posizione)
{
  if (Acidità.size() == 0 || posizione > Acidità.size() - 1)
  {
    throw std::invalid_argument("Tentativo di ottenimento di un dato in posizione non esistente!");
  }

  return Acidità.at(posizione);
}

void SensoreAcqua::insertAciditàRecord(unsigned int posizione, int record)
{
  if (Acidità.size() == 0 || posizione > Acidità.size() - 1)
  {
    throw std::invalid_argument("Tentativo di inserimento di un dato in posizione non esistente!");
  }

  Acidità.insert(Acidità.begin() + posizione, record);
}

void SensoreAcqua::updateAciditàRecord(unsigned int posizione, int record)
{
  if (Acidità.size() == 0 || posizione > Acidità.size() - 1)
  {
    throw std::invalid_argument("Tentativo di modifica di un dato in posizione non esistente!");
  }
  Acidità[posizione] = record;
}

SensoreAcqua *SensoreAcqua::clone() const
{
    return new SensoreAcqua(*this);
}

int SensoreAcqua::Qualità() const {
    // Inizializziamo le variabili per calcolare la percentuale di ciascun parametro
    double percentualeTemperatura = 0.0;
    double percentualeAlcalinità = 0.0;
    double percentualeAcidità = 0.0;

    // Controlliamo il vettore delle temperature
    if (!(const_cast<SensoreAcqua*>(this))->getTemperaturaVector().empty()) {
        // Calcoliamo la percentuale di temperature valide
        int countValidTemperature = 0;
        for (double temp : (const_cast<SensoreAcqua*>(this))->getTemperaturaVector()) {
            if (temp >= (const_cast<SensoreAcqua*>(this))->getMinValidTemperatura() && temp <= (const_cast<SensoreAcqua*>(this))->getMaxValidTemperatura()) {
                countValidTemperature++;
            }
        }
        percentualeTemperatura = (static_cast<double>(countValidTemperature) / (const_cast<SensoreAcqua*>(this))->getTemperaturaVector().size()) * 100.0;
    }

    // Controlliamo il vettore del Alcalinità
    if (!Alcalinità.empty()) {
        // Calcoliamo la percentuale di Alcalinità valide
        int countValidAlcalinità = 0;
        for (int Alcalinità : Alcalinità) {
            if (Alcalinità >= MinValidAlcalinità && Alcalinità <= MaxValidAlcalinità) {
                countValidAlcalinità++;
            }
        }
        percentualeAlcalinità = (static_cast<double>(countValidAlcalinità) / Alcalinità.size()) * 100.0;
    }

    // Controlliamo il vettore dell'Acidità
    if (!Acidità.empty()) {
        // Calcoliamo la percentuale di Acidità valido
        int countValidAcidità = 0;
        for (int oss : Acidità) {
            if (oss >= MinValidAcidità && oss <= MaxValidAcidità) {
                countValidAcidità++;
            }
        }
        percentualeAcidità = (static_cast<double>(countValidAcidità) / Acidità.size()) * 100.0;
    }

    // Calcoliamo la qualità totale come media delle tre percentuali
    double qualitàTotale = (percentualeTemperatura + percentualeAlcalinità + percentualeAcidità) / 3.0;

    // Arrotondiamo il risultato e lo restituiamo come intero
    return static_cast<int>(qualitàTotale);
}
