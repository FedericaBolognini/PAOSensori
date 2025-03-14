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

    /**
     * @brief sensoreAriaDialog         costruttore
     * @param parent:                   widget padre
     * @param act:                      azione relativa al dialog concreto (aggiunta/rimozione di un sensore di tipo aria)
     * @param sensore:                  sensore in ingresso, nullptr in caso l'azione sia l'aggiunta
     */
    explicit sensoreAriaDialog(QWidget *parent, action act, SensoreAria* sensore);

    /**
     * @brief getValues                 metodo per ottenere i valori dal dialog
     * @param parent:                   widget padre
     * @param ok:                       booleano che indica la validità del form
     * @param act:                      azione relativa al dialog concreto (aggiunta/rimozione di un sensore di tipo aria)
     * @param sensore:                  sensore in ingresso, nullptr in caso l'azione sia l'aggiunta
     * @return:                         dati provenienti dal dialog
     */
    static dialogValues getValues(QWidget *parent, bool *ok, action act, SensoreAria *sensore);
};

#endif // SENSOREARIADIALOG_H
