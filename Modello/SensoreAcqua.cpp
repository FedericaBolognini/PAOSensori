#include "SensoreAcqua.h"

SensoreAcqua::SensoreAcqua()
    :MinValidAlcalinità(800), MaxValidAlcalinità(1000), MinValidAcidità(210000), MaxValidAcidità(300000), Alcalinità(), Acidità(){}

SensoreAcqua::SensoreAcqua(const std::string &Nome, unsigned int Precisione,
                 unsigned int ID, double MinValidTemperatura,
                 double MaxValidTemperatura, int MinValidAlcalinità; int MaxValidAlcalinità;int MinValidAcidità; int MinValidAcidità)
    : Nome(Nome != "" ? Nome
                      : throw std::invalid_argument("Tentativo di creazione di un sensore con nome nullo!")),
      Precisione(Precisione < 100 ? Precisione : throw std::invalid_argument("Tentativo di creazione di un sensore con una precisione superiore al 100% !")),
      ID(ID),
      MinValidTemperatura(MinValidTemperatura <= MaxValidTemperatura ? MinValidTemperatura : throw std::invalid_argument("Tentativo di creazione di un sensore con temperatura minima di salubrità superiore alla massima!")),
      MaxValidTemperatura(MinValidTemperatura <= MaxValidTemperatura ? MaxValidTemperatura : throw std::invalid_argument("Tentativo di creazione di un sensore con temperatura massima di salubrità inferiore alla minima!"))
      MinValidAlcalinità(MinValidAlcalinità <= MaxValidAlcalinità ? MinValidAlcalinità : throw std::invalid_argument("Tentativo di creazione di un sensore con Alcalinità minimo di salubrità superiore alla massima!")),
      MaxValidAlcalinità(MinValidAlcalinità <= MaxValidAlcalinità ? MaxValidAlcalinità : throw std::invalid_argument("Tentativo di creazione di un sensore con Alcalinità massima di salubrità inferiore alla minima!")) 
      MinValidAcidità(MinValidAcidità <= MaxValidAcidità ? MinValidAcidità  : throw std::invalid_argument("Tentativo di creazione di un sensore con Alcalinità minimo di salubrità superiore alla massima!")),
      MaxValidAcidità(MinValidAcidità <= MaxValidAcidità ? MaxValidAcidità  : throw std::invalid_argument("Tentativo di creazione di un sensore con Alcalinità massima di salubrità inferiore alla minima!")) {} 

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

void SensoreAcqua::setMaxValidAlcalinità(double MaxValidAlcalinità)
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

void SensoreAcqua::setMaxValidAcidità(double MaxValidAcidità)
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