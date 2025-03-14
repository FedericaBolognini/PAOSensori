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

    /**
     * @brief dialogValues                      Costruttore di default
     */
    dialogValues() = default;

    /**
     * @brief dialogValues                      Costruttore completo di parametri
     * @param type                              Tipo del sensore
     * @param name                              Nome del sensore
     * @param precisione                        Precisione del sensore
     * @param minValidTemperatura               Temperatura minima valida
     * @param maxValidTemperatura               Temperatura massima valida
     * @param minValidFirstVector               Valore minimo valido per il primo vettore
     * @param maxValidFirstVector               Valore massimo valido per il primo vettore
     * @param minValidSecondVector              Valore minimo valido per il secondo vettore
     * @param maxValidSecondVector              Valore massimo valido per il secondo vettore
     */
    dialogValues(QString type, QString name, double precisione, double minValidTemperatura, double maxValidTemperatura, double minValidFirstVector, double maxValidFirstVector, double minValidSecondVector, double maxValidSecondVector);
};

#endif // DIALOGVALUES_H
