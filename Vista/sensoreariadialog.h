#ifndef SENSOREARIADIALOG_H
#define SENSOREARIADIALOG_H

#include "sensoredialog.h"
#include "../dialogvalues.h"
#include <QObject>

class sensoreAriaDialog : public sensoreDialog
{

    Q_OBJECT

private:
    //spin box per l'inserimento/visualizzazione del valore minimo di CO2
    QDoubleSpinBox* minCO2;

    //spin box per l'inserimento/visualizzazione del valore massimo di CO2
    QDoubleSpinBox* maxCO2;

    //spin box per l'inserimento/visualizzazione del valore minimo di ossigeno
    QDoubleSpinBox* minOssigeno;

    //spin box per l'inserimento/visualizzazione del valore massimo di ossigeno
    QDoubleSpinBox* maxOssigeno;
public:
    explicit sensoreAriaDialog(QWidget *parent, action act, SensoreAria* sensore);

    static dialogValues getValues(QWidget *parent, bool *ok, action act, SensoreAria *sensore);
};

#endif // SENSOREARIADIALOG_H
