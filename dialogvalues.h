#ifndef DIALOGVALUES_H
#define DIALOGVALUES_H

#include <QString>
class dialogValues
{
    public:

    //tipo del sensore
    QString type;

    //nome del sensore
    QString name;

    //precisione del sensore
    double precisione;

    //temperatura minima valida del sensore
    double minValidTemperatura;

    //temperatura massima valida del sensore
    double maxValidTemperatura;

    //valore massimo valido per il primo vettore del sensore
    double minValidFirstVector;

    //valore massimo valido per il secondo vettore del sensore
    double maxValidFirstVector;

    //valore minimo valido per il secondo vettore del sensore
    double minValidSecondVector;

    //valore massimo valido per il primo vettore del sensore
    double maxValidSecondVector;

    dialogValues(QString type, QString name, double precisione, double minValidTemperatura, double maxValidTemperatura, double minValidFirstVector, double maxValidFirstVector, double minValidSecondVector, double maxValidSecondVector);
};

#endif // DIALOGVALUES_H
