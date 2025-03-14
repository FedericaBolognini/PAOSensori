#ifndef SENSOREDIALOG_H
#define SENSOREDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QInputDialog>
#include "../Modello/Sensore.h"
#include "../Modello/SensoreAcqua.h"
#include "../Modello/SensoreAria.h"
#include "../Modello/SensoreSuolo.h"
#include "finestratipo.h"
#include "../action.h"

class sensoreDialog : public QDialog
{
    Q_OBJECT

protected:

    //line edit in cui scrivere/visualizzare il nome di un sensore
    QLineEdit* nome;

    //spin box per l'inserimento/visualizzazione della precisione di un sensore
    QDoubleSpinBox* precisione;

    //spin box per l'inserimento/visualizzazione della temperatura minima di un sensore
    QDoubleSpinBox* minTemperatura;

    //spin box per l'inserimento/visualizzazione della temperatura massima di un sensore
    QDoubleSpinBox* maxTemperatura;

    //layout principale
    QVBoxLayout *mainL;

    /**
     * @brief addToLayout:  gestisce l'aggiunta dei widget desiderati nel layout indicato
     * @param layout:       layout in cui aggiungere i widget
     * @param w1:           widget da aggiungere per primo nel layout
     * @param w2:           widget da aggiungere per secondo nel layout
     */
    void addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2);

    /**
     * @brief setupCommon:  gestisce il setup dell'header, comune a tutti i dialog custom di visualizzazione dati di sensori
     * @param layout:       layout in cui aggiungere i widget di header
     * @param act:          azione da compiere sui sensori: il suo valore può rendere editabile o meno dei widget
     * @param sensore:      sensore da visualizzare se "act" è diverso da "add"
     */
    void setupCommon(QBoxLayout *layout, action act, Sensore* sensore = nullptr);

    /**
     * @brief addButtons:           aggiunta dei pulsanti di conferma/rifiuto al layout principale (solitamente ultimi widget
     *                              ad essere aggiunti)
     */
    void addButtons();


public:

    /**
     * @brief sensoreDialog:        costruttore
     * @param parent:               widget padre
     */
    explicit sensoreDialog(QWidget *parent);
};

#endif // SENSOREDIALOG_H
