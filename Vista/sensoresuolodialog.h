#ifndef SENSORESUOLODIALOG_H
#define SENSORESUOLODIALOG_H

#include "sensoredialog.h"
#include "../dialogvalues.h"
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

    /**
     * @brief sensoreSuoloDialog:       costruttore
     * @param parent:                   widget padre
     * @param act:                      azione relativa al dialog concreto (aggiunta/rimozione di un sensore di tipo suolo)
     * @param sensore:                  sensore in ingresso, nullptr in caso l'azione sia l'aggiunta
     */
    explicit sensoreSuoloDialog(QWidget *parent, action act, SensoreSuolo* sensore);

    /**
     * @brief getValues:                metodo per ottenere i valori dal dialog
     * @param parent:                   widget padre
     * @param ok:                       booleano che indica la validità del form
     * @param act:                      azione relativa al dialog concreto (aggiunta/rimozione di un sensore di tipo suolo)
     * @param sensore:                  sensore in ingresso, nullptr in caso l'azione sia l'aggiunta
     * @return:                         dati provenienti dal dialog
     */
    static dialogValues getValues(QWidget *parent, bool *ok, action act, SensoreSuolo *sensore);
};

#endif // SENSORESUOLODIALOG_H
