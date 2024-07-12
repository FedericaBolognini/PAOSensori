#include "Sensore.h"

Sensore::Sensore()
    : Nome("Sensore generico"), Precisione(100), ID(-1),
      MinValidTemperatura(10), MaxValidTemperatura(50), Temperatura() {}

Sensore::Sensore(const std::string &Nome, unsigned int Precisione,
                 unsigned int ID, double MinValidTemperatura,
                 double MaxValidTemperatura)
    : Nome(Nome != ""? Nome
               : throw std::invalid_argument("Tentativo di creazione di un sensore con nome nullo!")),
      Precisione(Precisione), ID(ID), MinValidTemperatura(MinValidTemperatura),
      MaxValidTemperatura(MaxValidTemperatura) {}

double Sensore::MinTemperatura() const {
  double minima = Temperatura[0];
  if (Temperatura.empty()) {
    throw std::length_error("Il vettore delle temperatura è vuoto!");
  } else {
    for (int i = 1; i < Temperatura.size(); ++i) {
      if (Temperatura[i] < minima) {
        minima = Temperatura[i];
      }
    }
  }
  return minima;
}

double Sensore::MaxTemperatura() const {
    double massima = Temperatura[0];
    if(Temperatura.empty()){
        throw std::length_error("Il vettore delle temperature è vuoto!");
    } else {
        for (int i = 1; i < Temperatura.size(); ++i) {
            if (Temperatura[i] > massima) {
                massima = Temperatura[i];
            }
        }
    }
    return massima;
}