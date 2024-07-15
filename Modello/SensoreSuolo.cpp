#include "SensoreSuolo.h"

SensoreSuolo::SensoreSuolo()
    :MinValidPH(800), MaxValidPH(1000), MinValidUmidità(210000), MaxValidUmidità(300000), PH(), Umidità(){}

SensoreSuolo::SensoreSuolo(const std::string &Nome, unsigned int Precisione,
                 unsigned int ID, double MinValidTemperatura,
                 double MaxValidTemperatura, int MinValidPH; int MaxValidPH;int MinValidUmidità; int MinValidUmidità)
    : Nome(Nome != "" ? Nome
                      : throw std::invalid_argument("Tentativo di creazione di un sensore con nome nullo!")),
      Precisione(Precisione < 100 ? Precisione : throw std::invalid_argument("Tentativo di creazione di un sensore con una precisione superiore al 100% !")),
      ID(ID),
      MinValidTemperatura(MinValidTemperatura <= MaxValidTemperatura ? MinValidTemperatura : throw std::invalid_argument("Tentativo di creazione di un sensore con temperatura minima di salubrità superiore alla massima!")),
      MaxValidTemperatura(MinValidTemperatura <= MaxValidTemperatura ? MaxValidTemperatura : throw std::invalid_argument("Tentativo di creazione di un sensore con temperatura massima di salubrità inferiore alla minima!"))
      MinValidPH(MinValidPH <= MaxValidPH ? MinValidPH : throw std::invalid_argument("Tentativo di creazione di un sensore con PH minimo di salubrità superiore alla massima!")),
      MaxValidPH(MinValidPH <= MaxValidPH ? MaxValidPH : throw std::invalid_argument("Tentativo di creazione di un sensore con PH massima di salubrità inferiore alla minima!")) 
      MinValidUmidità(MinValidUmidità <= MaxValidUmidità ? MinValidUmidità  : throw std::invalid_argument("Tentativo di creazione di un sensore con PH minimo di salubrità superiore alla massima!")),
      MaxValidUmidità(MinValidUmidità <= MaxValidUmidità ? MaxValidUmidità  : throw std::invalid_argument("Tentativo di creazione di un sensore con PH massima di salubrità inferiore alla minima!")) {} 

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

void SensoreSuolo::setMaxValidPH(double MaxValidPH)
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

void SensoreSuolo::setMaxValidUmidità(double MaxValidUmidità)
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
  int massima = Temperatura[0];
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