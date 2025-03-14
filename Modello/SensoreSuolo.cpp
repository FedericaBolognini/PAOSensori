#include "SensoreSuolo.h"

SensoreSuolo::SensoreSuolo()
    :MinValidPH(800), MaxValidPH(1000), MinValidUmidità(210000), MaxValidUmidità(300000), PH(), Umidità(){}

SensoreSuolo::SensoreSuolo(const std::string &Nome, unsigned int Precisione,
                 unsigned int ID, double MinValidTemperatura,
                 double MaxValidTemperatura, int MinValidPH, int MaxValidPH, int MinValidUmidità, int MaxValidUmidità)
    :Sensore(Nome,Precisione,ID,MinValidTemperatura,MaxValidTemperatura),
      MinValidPH(MinValidPH <= MaxValidPH ? MinValidPH : throw std::invalid_argument("Tentativo di creazione di un sensore con PH minimo superiore al massimo!")),
      MaxValidPH(MinValidPH <= MaxValidPH ? MaxValidPH : throw std::invalid_argument("Tentativo di creazione di un sensore con PH massimo inferiore al minimo!")),
      MinValidUmidità(MinValidUmidità <= MaxValidUmidità ? MinValidUmidità  : throw std::invalid_argument("Tentativo di creazione di un sensore con umidità minima superiore al massimo!")),
      MaxValidUmidità(MinValidUmidità <= MaxValidUmidità ? MaxValidUmidità  : throw std::invalid_argument("Tentativo di creazione di un sensore con umidità massima inferiore al minimo!")) {}

int SensoreSuolo::getMinValidPH() const
{
  return MinValidPH;
}

int SensoreSuolo::getMaxValidPH() const
{
  return MaxValidPH;
}

int SensoreSuolo::getMinValidUmidità() const
{
  return MinValidUmidità;
}

int SensoreSuolo::getMaxValidUmidità() const
{
  return MaxValidUmidità;
}

void SensoreSuolo::setMinValidPH(int MinValidPH)
{
  if (MinValidPH > MaxValidPH)
  {
    throw std::invalid_argument("Il valore di PH minimo non può essere più grande del massimo!");
  }
  this->MinValidPH = MinValidPH;
}

void SensoreSuolo::setMaxValidPH(int MaxValidPH)
{
  if (MinValidPH > MaxValidPH)
  {
    throw std::invalid_argument("Il valore di PH massimo non può essere più piccolo del minimo!");
  }
  this->MaxValidPH = MaxValidPH;
}


void SensoreSuolo::setMinValidUmidità(int MinValidUmidità)
{
  if (MinValidUmidità > MaxValidUmidità)
  {
    throw std::invalid_argument("Il valore di Umidità minimo non può essere più grande del massimo!");
  }
  this->MinValidUmidità = MinValidUmidità;
}

void SensoreSuolo::setMaxValidUmidità(int MaxValidUmidità)
{
  if (MinValidUmidità > MaxValidUmidità)
  {
    throw std::invalid_argument("Il valore di Umidità massimo non può essere più piccolo del minimo!");
  }
  this->MaxValidUmidità = MaxValidUmidità;
}

const std::vector<int> &SensoreSuolo::getPHVector()
{
  return PH;
}

const std::vector<int> &SensoreSuolo::getUmiditàVector()
{
  return Umidità;
}

int SensoreSuolo::MinPH() const
{
  int minima = PH[0];
  if (PH.empty())
  {
    throw std::length_error("Il vettore del PH è vuoto!");
  }
  else
  {
    for (int i = 1; i < PH.size(); ++i)
    {
      if (PH[i] < minima)
      {
        minima = PH[i];
      }
    }
  }
  return minima;
}

int SensoreSuolo::MaxPH() const
{
  int massima = PH[0];
  if (PH.empty())
  {
    throw std::length_error("Il vettore del PH è vuoto!");
  }
  else
  {
    for (int i = 1; i < PH.size(); ++i)
    {
      if (PH[i] > massima)
      {
        massima = PH[i];
      }
    }
  }
  return massima;
}

int SensoreSuolo::MinUmidità() const
{
  int minima = Umidità[0];
  if (Umidità.empty())
  {
    throw std::length_error("Il vettore dell' Umidità è vuoto!");
  }
  else
  {
    for (int i = 1; i < Umidità.size(); ++i)
    {
      if (Umidità[i] < minima)
      {
        minima = Umidità[i];
      }
    }
  }
  return minima;
}

int SensoreSuolo::MaxUmidità() const
{
  int massima = Umidità[0];
  if (Umidità.empty())
  {
    throw std::length_error("Il vettore dell' Umidità è vuoto!");
  }
  else
  {
    for (int i = 1; i < Umidità.size(); ++i)
    {
      if (Umidità[i] > massima)
      {
        massima = Umidità[i];
      }
    }
  }
  return massima;
}

void SensoreSuolo::addPHRecord(int record)
{
  PH.push_back(record);
}

void SensoreSuolo::removePHRecord(unsigned int posizione)
{
  if (PH.size() == 0 || posizione > PH.size() - 1)
  {
    throw std::invalid_argument("Tentativo di rimozione di un dato in posizione non esistente!");
  }

  auto elem = PH.begin();
  std::advance(elem, posizione);
  PH.erase(elem);
}

int SensoreSuolo::getPHRecord(unsigned int posizione)
{
  if (PH.size() == 0 || posizione > PH.size() - 1)
  {
    throw std::invalid_argument("Tentativo di ottenimento di un dato in posizione non esistente!");
  }

  return PH.at(posizione);
}

void SensoreSuolo::insertPHRecord(unsigned int posizione, int record)
{
  if (PH.size() == 0 || posizione > PH.size() - 1)
  {
    throw std::invalid_argument("Tentativo di inserimento di un dato in posizione non esistente!");
  }

  PH.insert(PH.begin() + posizione, record);
}

void SensoreSuolo::updatePHRecord(unsigned int posizione, int record)
{
  if (PH.size() == 0 || posizione > PH.size() - 1)
  {
    throw std::invalid_argument("Tentativo di modifica di un dato in posizione non esistente!");
  }
  PH[posizione] = record;
}

void SensoreSuolo::addUmiditàRecord(int record)
{
  Umidità.push_back(record);
}

void SensoreSuolo::removeUmiditàRecord(unsigned int posizione)
{
  if (Umidità.size() == 0 || posizione > Umidità.size() - 1)
  {
    throw std::invalid_argument("Tentativo di rimozione di un dato in posizione non esistente!");
  }

  auto elem = Umidità.begin();
  std::advance(elem, posizione);
  Umidità.erase(elem);
}

int SensoreSuolo::getUmiditàRecord(unsigned int posizione)
{
  if (Umidità.size() == 0 || posizione > Umidità.size() - 1)
  {
    throw std::invalid_argument("Tentativo di ottenimento di un dato in posizione non esistente!");
  }

  return Umidità.at(posizione);
}

void SensoreSuolo::insertUmiditàRecord(unsigned int posizione, int record)
{
  if (Umidità.size() == 0 || posizione > Umidità.size() - 1)
  {
    throw std::invalid_argument("Tentativo di inserimento di un dato in posizione non esistente!");
  }

  Umidità.insert(Umidità.begin() + posizione, record);
}

void SensoreSuolo::updateUmiditàRecord(unsigned int posizione, int record)
{
  if (Umidità.size() == 0 || posizione > Umidità.size() - 1)
  {
    throw std::invalid_argument("Tentativo di modifica di un dato in posizione non esistente!");
  }
  Umidità[posizione] = record;
}

SensoreSuolo *SensoreSuolo::clone() const
{
    return new SensoreSuolo(*this);
}

int SensoreSuolo::Qualità() const {
    // Inizializziamo le variabili per calcolare la percentuale di ciascun parametro
    double percentualeTemperatura = 0.0;
    double percentualePH = 0.0;
    double percentualeUmidità = 0.0;

    // Controlliamo il vettore delle temperature
    if (!(const_cast<SensoreSuolo*>(this))->getTemperaturaVector().empty()) {
        // Calcoliamo la percentuale di temperature valide
        int countValidTemperature = 0;
        for (double temp : (const_cast<SensoreSuolo*>(this))->getTemperaturaVector()) {
            if (temp >= (const_cast<SensoreSuolo*>(this))->getMinValidTemperatura() && temp <= (const_cast<SensoreSuolo*>(this))->getMaxValidTemperatura()) {
                countValidTemperature++;
            }
        }
        percentualeTemperatura = (static_cast<double>(countValidTemperature) / (const_cast<SensoreSuolo*>(this))->getTemperaturaVector().size()) * 100.0;
    }

    // Controlliamo il vettore del PH
    if (!PH.empty()) {
        // Calcoliamo la percentuale di PH valide
        int countValidPH = 0;
        for (int PH : PH) {
            if (PH >= MinValidPH && PH <= MaxValidPH) {
                countValidPH++;
            }
        }
        percentualePH = (static_cast<double>(countValidPH) / PH.size()) * 100.0;
    }

    // Controlliamo il vettore dell'Umidità
    if (!Umidità.empty()) {
        // Calcoliamo la percentuale di Umidità valido
        int countValidUmidità = 0;
        for (int oss : Umidità) {
            if (oss >= MinValidUmidità && oss <= MaxValidUmidità) {
                countValidUmidità++;
            }
        }
        percentualeUmidità = (static_cast<double>(countValidUmidità) / Umidità.size()) * 100.0;
    }

    // Calcoliamo la qualità totale come media delle tre percentuali
    double qualitàTotale = (percentualeTemperatura + percentualePH + percentualeUmidità) / 3.0;

    // Arrotondiamo il risultato e lo restituiamo come intero
    return static_cast<int>(qualitàTotale);
}

