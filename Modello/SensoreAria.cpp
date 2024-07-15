#include "SensoreAria.h"

SensoreAria::SensoreAria()
    :MinValidCO2(800), MaxValidCO2(1000), MinValidOssigeno(210000), MaxValidOssigeno(300000), CO2(), Ossigeno(){}

SensoreAria::SensoreAria(const std::string &Nome, unsigned int Precisione,
                 unsigned int ID, double MinValidTemperatura,
                 double MaxValidTemperatura, int MinValidCO2; int MaxValidCO2;int MinValidOssigeno; int MinValidOssigeno)
    : Nome(Nome != "" ? Nome
                      : throw std::invalid_argument("Tentativo di creazione di un sensore con nome nullo!")),
      Precisione(Precisione < 100 ? Precisione : throw std::invalid_argument("Tentativo di creazione di un sensore con una precisione superiore al 100% !")),
      ID(ID),
      MinValidTemperatura(MinValidTemperatura <= MaxValidTemperatura ? MinValidTemperatura : throw std::invalid_argument("Tentativo di creazione di un sensore con temperatura minima di salubrità superiore alla massima!")),
      MaxValidTemperatura(MinValidTemperatura <= MaxValidTemperatura ? MaxValidTemperatura : throw std::invalid_argument("Tentativo di creazione di un sensore con temperatura massima di salubrità inferiore alla minima!"))
      MinValidCO2(MinValidCO2 <= MaxValidCO2 ? MinValidCO2 : throw std::invalid_argument("Tentativo di creazione di un sensore con CO2 minimo di salubrità superiore alla massima!")),
      MaxValidCO2(MinValidCO2 <= MaxValidCO2 ? MaxValidCO2 : throw std::invalid_argument("Tentativo di creazione di un sensore con CO2 massima di salubrità inferiore alla minima!")) 
      MinValidOssigeno(MinValidOssigeno <= MaxValidOssigeno ? MinValidOssigeno  : throw std::invalid_argument("Tentativo di creazione di un sensore con CO2 minimo di salubrità superiore alla massima!")),
      MaxValidOssigeno(MinValidOssigeno <= MaxValidOssigeno ? MaxValidOssigeno  : throw std::invalid_argument("Tentativo di creazione di un sensore con CO2 massima di salubrità inferiore alla minima!")) {} 

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

void SensoreAria::setMaxValidCO2(double MaxValidCO2)
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

void SensoreAria::setMaxValidOssigeno(double MaxValidOssigeno)
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
  int massima = Temperatura[0];
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