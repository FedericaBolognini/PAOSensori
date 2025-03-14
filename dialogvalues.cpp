#include "dialogvalues.h"

dialogValues::dialogValues(QString type, QString name, double precisione, double minValidTemperatura, double maxValidTemperatura, double minValidFirstVector, double maxValidFirstVector, double minValidSecondVector, double maxValidSecondVector)
    : type(type), name(name), precisione(precisione), minValidTemperatura(minValidTemperatura), maxValidTemperatura(maxValidTemperatura), minValidFirstVector(minValidFirstVector), maxValidFirstVector(maxValidFirstVector), minValidSecondVector(minValidSecondVector), maxValidSecondVector(maxValidSecondVector){}
