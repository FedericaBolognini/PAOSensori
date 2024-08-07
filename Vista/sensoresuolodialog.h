#ifndef SENSORESUOLODIALOG_H
#define SENSORESUOLODIALOG_H

#include "sensoredialog.h"
#include "../dialogValues.h"
#include <QObject>

class sensoreSuoloDialog : public sensoreDialog
{

    Q_OBJECT

private:
    //spin box per l'inserimento/visualizzazione del valore minimo di Umidità
    QDoubleSpinBox* minUmidità;

    //spin box per l'inserimento/visualizzazione del valore massimo di Umidità
    QDoubleSpinBox* maxUmidità;

    //spin box per l'inserimento/visualizzazione del valore minimo di PH
    QDoubleSpinBox* minPH;

    //spin box per l'inserimento/visualizzazione del valore massimo di PH
    QDoubleSpinBox* maxPH;
public:
    explicit sensoreSuoloDialog(QWidget *parent, action act, sensoreSuolo* sensore);

    static dialogValues getValues(QWidget *parent, bool *ok, action act, sensoreSuolo *sensore);
};

#endif // SENSORESUOLODIALOG_H
