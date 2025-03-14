#ifndef SENSOREACQUADIALOG_H
#define SENSOREACQUADIALOG_H

#include "sensoredialog.h"
#include "../dialogvalues.h"
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

    /**
     * @brief sensoreAcquaDialog:       costruttore
     * @param parent:                   widget padre
     * @param act:                      azione relativa al dialog concreto (aggiunta/rimozione di un sensore di tipo acqua)
     * @param sensore:                  sensore in ingresso, nullptr in caso l'azione sia l'aggiunta
     */
    explicit sensoreAcquaDialog(QWidget *parent, action act, SensoreAcqua* sensore);

    /**
     * @brief getValues:                metodo per ottenere i valori dal dialog
     * @param parent:                   widget padre
     * @param ok:                       booleano che indica la validità del form
     * @param act:                      azione relativa al dialog concreto (aggiunta/rimozione di un sensore di tipo acqua)
     * @param sensore:                  sensore in ingresso, nullptr in caso l'azione sia l'aggiunta
     * @return:                         dati provenienti dal dialog
     */
    static dialogValues getValues(QWidget *parent, bool *ok, action act, SensoreAcqua *sensore);
};

#endif // SENSOREACQUADIALOG_H
