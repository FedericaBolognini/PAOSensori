#ifndef SENSOREACQUADIALOG_H
#define SENSOREACQUADIALOG_H

#include "sensoredialog.h"
#include "../dialogValues.h"
#include <QObject>

class sensoreAcquaDialog : public sensoreDialog
{

    Q_OBJECT

private:
    //spin box per l'inserimento/visualizzazione del valore minimo di alcalinità
    QDoubleSpinBox* minAlcalinità;

    //spin box per l'inserimento/visualizzazione del valore massimo di alcalinità
    QDoubleSpinBox* maxAlcalinità;

    //spin box per l'inserimento/visualizzazione del valore minimo di acidità
    QDoubleSpinBox* minAcidità;

    //spin box per l'inserimento/visualizzazione del valore massimo di acidità
    QDoubleSpinBox* maxAcidità;
public:
    explicit sensoreAcquaDialog(QWidget *parent, action act, SensoreAcqua* sensore);

    static dialogValues getValues(QWidget *parent, bool *ok, action act, SensoreAcqua *sensore);
};

#endif // SENSOREACQUADIALOG_H
