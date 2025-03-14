#include "SensoreAria.h"

SensoreAria::SensoreAria()
    :MinValidCO2(800), MaxValidCO2(1000), MinValidOssigeno(210000), MaxValidOssigeno(300000), CO2(), Ossigeno(){}

SensoreAria::SensoreAria(const std::string &Nome, unsigned int Precisione,
                 unsigned int ID, double MinValidTemperatura,
                 double MaxValidTemperatura, int MinValidCO2, int MaxValidCO2, int MinValidOssigeno, int MaxValidOssigeno)
    :Sensore(Nome,Precisione,ID,MinValidTemperatura,MaxValidTemperatura),
      MinValidCO2(MinValidCO2 <= MaxValidCO2 ? MinValidCO2 : throw std::invalid_argument("Tentativo di creazione di un sensore con CO2 minimo superiore al massimo!")),
      MaxValidCO2(MinValidCO2 <= MaxValidCO2 ? MaxValidCO2 : throw std::invalid_argument("Tentativo di creazione di un sensore con CO2 massimo inferiore al minimo!")),
      MinValidOssigeno(MinValidOssigeno <= MaxValidOssigeno ? MinValidOssigeno  : throw std::invalid_argument("Tentativo di creazione di un sensore con ossigenazione minima superiore alla massima!")),
      MaxValidOssigeno(MinValidOssigeno <= MaxValidOssigeno ? MaxValidOssigeno  : throw std::invalid_argument("Tentativo di creazione di un sensore con ossigenazione massima inferiore alla minima!")) {}

int SensoreAria::getMinValidCO2() const
{
  return MinValidCO2;
}

int SensoreAria::getMaxValidCO2() const
{
  return MaxValidCO2;
}

int SensoreAria::getMinValidOssigeno() const
{
  return MinValidOssigeno;
}

int SensoreAria::getMaxValidOssigeno() const
{
  return MaxValidOssigeno;
}

void SensoreAria::setMinValidCO2(int MinValidCO2)
{
  if (MinValidCO2 > MaxValidCO2)
  {
    throw std::invalid_argument("Il valore di CO2 minimo non può essere più grande del massimo!");
  }
  this->MinValidCO2 = MinValidCO2;
}

void SensoreAria::setMaxValidCO2(int MaxValidCO2)
{
  if (MinValidCO2 > MaxValidCO2)
  {
    throw std::invalid_argument("Il valore di CO2 massimo non può essere più piccolo del minimo!");
  }
  this->MaxValidCO2 = MaxValidCO2;
}


void SensoreAria::setMinValidOssigeno(int MinValidOssigeno)
{
  if (MinValidOssigeno > MaxValidOssigeno)
  {
    throw std::invalid_argument("Il valore di Ossigeno minimo non può essere più grande del massimo!");
  }
  this->MinValidOssigeno = MinValidOssigeno;
}

void SensoreAria::setMaxValidOssigeno(int MaxValidOssigeno)
{
  if (MinValidOssigeno > MaxValidOssigeno)
  {
    throw std::invalid_argument("Il valore di Ossigeno massimo non può essere più piccolo del minimo!");
  }
  this->MaxValidOssigeno = MaxValidOssigeno;
}

const std::vector<int> &SensoreAria::getCO2Vector()
{
  return CO2;
}

const std::vector<int> &SensoreAria::getOssigenoVector()
{
  return Ossigeno;
}

int SensoreAria::MinCO2() const
{
  int minima = CO2[0];
  if (CO2.empty())
  {
    throw std::length_error("Il vettore del CO2 è vuoto!");
  }
  else
  {
    for (int i = 1; i < CO2.size(); ++i)
    {
      if (CO2[i] < minima)
      {
        minima = CO2[i];
      }
    }
  }
  return minima;
}

int SensoreAria::MaxCO2() const
{
  int massima = CO2[0];
  if (CO2.empty())
  {
    throw std::length_error("Il vettore del CO2 è vuoto!");
  }
  else
  {
    for (int i = 1; i < CO2.size(); ++i)
    {
      if (CO2[i] > massima)
      {
        massima = CO2[i];
      }
    }
  }
  return massima;
}

int SensoreAria::MinOssigeno() const
{
  int minima = Ossigeno[0];
  if (Ossigeno.empty())
  {
    throw std::length_error("Il vettore dell' ossigeno è vuoto!");
  }
  else
  {
    for (int i = 1; i < Ossigeno.size(); ++i)
    {
      if (Ossigeno[i] < minima)
      {
        minima = Ossigeno[i];
      }
    }
  }
  return minima;
}

int SensoreAria::MaxOssigeno() const
{
  int massima = Ossigeno[0];
  if (Ossigeno.empty())
  {
    throw std::length_error("Il vettore dell' ossigeno è vuoto!");
  }
  else
  {
    for (int i = 1; i < Ossigeno.size(); ++i)
    {
      if (Ossigeno[i] > massima)
      {
        massima = Ossigeno[i];
      }
    }
  }
  return massima;
}

void SensoreAria::addCO2Record(int record)
{
  CO2.push_back(record);
}

void SensoreAria::removeCO2Record(unsigned int posizione)
{
  if (CO2.size() == 0 || posizione > CO2.size() - 1)
  {
    throw std::invalid_argument("Tentativo di rimozione di un dato in posizione non esistente!");
  }

  auto elem = CO2.begin();
  std::advance(elem, posizione);
  CO2.erase(elem);
}

int SensoreAria::getCO2Record(unsigned int posizione)
{
  if (CO2.size() == 0 || posizione > CO2.size() - 1)
  {
    throw std::invalid_argument("Tentativo di ottenimento di un dato in posizione non esistente!");
  }

  return CO2.at(posizione);
}

void SensoreAria::insertCO2Record(unsigned int posizione, int record)
{
  if (CO2.size() == 0 || posizione > CO2.size() - 1)
  {
    throw std::invalid_argument("Tentativo di inserimento di un dato in posizione non esistente!");
  }

  CO2.insert(CO2.begin() + posizione, record);
}

void SensoreAria::updateCO2Record(unsigned int posizione, int record)
{
  if (CO2.size() == 0 || posizione > CO2.size() - 1)
  {
    throw std::invalid_argument("Tentativo di modifica di un dato in posizione non esistente!");
  }
  CO2[posizione] = record;
}

void SensoreAria::addOssigenoRecord(int record)
{
  Ossigeno.push_back(record);
}

void SensoreAria::removeOssigenoRecord(unsigned int posizione)
{
  if (Ossigeno.size() == 0 || posizione > Ossigeno.size() - 1)
  {
    throw std::invalid_argument("Tentativo di rimozione di un dato in posizione non esistente!");
  }

  auto elem = Ossigeno.begin();
  std::advance(elem, posizione);
  Ossigeno.erase(elem);
}

int SensoreAria::getOssigenoRecord(unsigned int posizione)
{
  if (Ossigeno.size() == 0 || posizione > Ossigeno.size() - 1)
  {
    throw std::invalid_argument("Tentativo di ottenimento di un dato in posizione non esistente!");
  }

  return Ossigeno.at(posizione);
}

void SensoreAria::insertOssigenoRecord(unsigned int posizione, int record)
{
  if (Ossigeno.size() == 0 || posizione > Ossigeno.size() - 1)
  {
    throw std::invalid_argument("Tentativo di inserimento di un dato in posizione non esistente!");
  }

  Ossigeno.insert(Ossigeno.begin() + posizione, record);
}

void SensoreAria::updateOssigenoRecord(unsigned int posizione, int record)
{
  if (Ossigeno.size() == 0 || posizione > Ossigeno.size() - 1)
  {
    throw std::invalid_argument("Tentativo di modifica di un dato in posizione non esistente!");
  }
  Ossigeno[posizione] = record;
}

SensoreAria *SensoreAria::clone() const
{
    return new SensoreAria(*this);
}

int SensoreAria::Qualità() const {
    // Inizializziamo le variabili per calcolare la percentuale di ciascun parametro
    double percentualeTemperatura = 0.0;
    double percentualeCO2 = 0.0;
    double percentualeOssigeno = 0.0;

    // Controlliamo il vettore delle temperature
    if(!(const_cast<SensoreAria*>(this))->getTemperaturaVector().empty()) {
        // Calcoliamo la percentuale di temperature valide
        int countValidTemperature = 0;
        for (double temp : (const_cast<SensoreAria*>(this))->getTemperaturaVector()) {
            if (temp >= (const_cast<SensoreAria*>(this))->getMinValidTemperatura() && temp <= (const_cast<SensoreAria*>(this))->getMaxValidTemperatura()) {
                countValidTemperature++;
            }
        }
        percentualeTemperatura = (static_cast<double>(countValidTemperature) / (const_cast<SensoreAria*>(this))->getTemperaturaVector().size()) * 100.0;
    }

    // Controlliamo il vettore del CO2
    if (!CO2.empty()) {
        // Calcoliamo la percentuale di CO2 valide
        int countValidCO2 = 0;
        for (int co2 : CO2) {
            if (co2 >= MinValidCO2 && co2 <= MaxValidCO2) {
                countValidCO2++;
            }
        }
        percentualeCO2 = (static_cast<double>(countValidCO2) / CO2.size()) * 100.0;
    }

    // Controlliamo il vettore dell'ossigeno
    if (!Ossigeno.empty()) {
        // Calcoliamo la percentuale di Ossigeno valido
        int countValidOssigeno = 0;
        for (int oss : Ossigeno) {
            if (oss >= MinValidOssigeno && oss <= MaxValidOssigeno) {
                countValidOssigeno++;
            }
        }
        percentualeOssigeno = (static_cast<double>(countValidOssigeno) / Ossigeno.size()) * 100.0;
    }

    // Calcoliamo la qualità totale come media delle tre percentuali
    double qualitàTotale = (percentualeTemperatura + percentualeCO2 + percentualeOssigeno) / 3.0;

    // Arrotondiamo il risultato e lo restituiamo come intero
    return static_cast<int>(qualitàTotale);
}

