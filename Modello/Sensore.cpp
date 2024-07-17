#include "Sensore.h"

Sensore::Sensore()
    : Nome("Sensore generico"), Precisione(100), ID(-1),
      MinValidTemperatura(10), MaxValidTemperatura(50), Temperatura() {}

Sensore::Sensore(const std::string &Nome, unsigned int Precisione,
                 unsigned int ID, double MinValidTemperatura,
                 double MaxValidTemperatura)
    : Nome(Nome != "" ? Nome
                      : throw std::invalid_argument("Tentativo di creazione di un sensore con nome nullo!")),
      Precisione(Precisione < 100 ? Precisione : throw std::invalid_argument("Tentativo di creazione di un sensore con una precisione superiore al 100% !")),
      ID(ID),
      MinValidTemperatura(MinValidTemperatura <= MaxValidTemperatura ? MinValidTemperatura : throw std::invalid_argument("Tentativo di creazione di un sensore con temperatura minima di salubrità superiore alla massima!")),
      MaxValidTemperatura(MinValidTemperatura <= MaxValidTemperatura ? MaxValidTemperatura : throw std::invalid_argument("Tentativo di creazione di un sensore con temperatura massima di salubrità inferiore alla minima!")) {}

std::string Sensore::getNome() const
{
  return Nome;
}

unsigned int Sensore::getPrecisione() const
{
  return Precisione;
}

unsigned int Sensore::getID() const
{
  return ID;
}

double Sensore::getMinValidTemperatura() const
{
  return MinValidTemperatura;
}

double Sensore::getMaxValidTemperatura() const
{
  return MaxValidTemperatura;
}

void Sensore::addTemperaturaRecord(double record)
{
  Temperatura.push_back(record);
}

void Sensore::removeTemperaturaRecord(unsigned int posizione)
{
  if (Temperatura.size() == 0 || posizione > Temperatura.size() - 1)
  {
    throw std::invalid_argument("Tentativo di rimozione di un dato in posizione non esistente!");
  }

  auto temp = Temperatura.begin();
  std::advance(temp, posizione);
  Temperatura.erase(temp);
}

double Sensore::getTemperaturaRecord(unsigned int posizione)
{
  if (Temperatura.size() == 0 || posizione > Temperatura.size() - 1)
  {
    throw std::invalid_argument("Tentativo di ottenimento di un dato in posizione non esistente!");
  }

  return Temperatura.at(posizione);
}

void Sensore::insertTemperaturaRecord(unsigned int posizione, double record)
{
  if (Temperatura.size() == 0 || posizione > Temperatura.size() - 1)
  {
    throw std::invalid_argument("Tentativo di inserimento di un dato in posizione non esistente!");
  }

  Temperatura.insert(Temperatura.begin() + posizione, record);
}

void Sensore::updateTemperaturaRecord(unsigned int posizione, double record)
{
  if (Temperatura.size() == 0 || posizione > Temperatura.size() - 1)
  {
    throw std::invalid_argument("Tentativo di modifica di un dato in posizione non esistente!");

  }
  Temperatura[posizione]=record;
}

void Sensore::setNome(const std::string &Nome)
{
  if (Nome == "")
  {
    throw std::invalid_argument("Il nome non può essere nullo!");
  }

  this->Nome = Nome;
}

void Sensore::setPrecisione(unsigned int Precisione)
{
  if (Precisione > 100)
  {
    throw std::invalid_argument("La precisione non può essere superiore al 100% !");
  }

  this->Precisione = Precisione;
}

void Sensore::setID(unsigned int ID)
{
  this->ID = ID;
}

void Sensore::setMinValidTemperatura(double MinValidTemperatura)
{
  if (MinValidTemperatura > MaxValidTemperatura)
  {
    throw std::invalid_argument("La temperatura minima non può essere più grande della massima!");
  }
  this->MinValidTemperatura = MinValidTemperatura;
}

void Sensore::setMaxValidTemperatura(double MaxValidTemperatura)
{
  if (MinValidTemperatura > MaxValidTemperatura)
  {
    throw std::invalid_argument("La temperatura massima non può essere più piccola della minima!");
  }
  this->MaxValidTemperatura = MaxValidTemperatura;
}

const std::vector<double> &Sensore::getTemperaturaVector()
{
  return Temperatura;
}

double Sensore::MinTemperatura() const
{
  double minima = Temperatura[0];
  if (Temperatura.empty())
  {
    throw std::length_error("Il vettore delle temperatura è vuoto!");
  }
  else
  {
    for (int i = 1; i < Temperatura.size(); ++i)
    {
      if (Temperatura[i] < minima)
      {
        minima = Temperatura[i];
      }
    }
  }
  return minima;
}

double Sensore::MaxTemperatura() const
{
  double massima = Temperatura[0];
  if (Temperatura.empty())
  {
    throw std::length_error("Il vettore delle temperature è vuoto!");
  }
  else
  {
    for (int i = 1; i < Temperatura.size(); ++i)
    {
      if (Temperatura[i] > massima)
      {
        massima = Temperatura[i];
      }
    }
  }
  return massima;
}