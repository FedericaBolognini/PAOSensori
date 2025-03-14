#ifndef FINESTRASENSORE_H
#define FINESTRASENSORE_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QComboBox>
#include <QPushButton>
#include <../Modello/Sensore.h>
#include <iostream>

class finestraSensore : public QDialog
{
    Q_OBJECT

private:
    //combo box contenente tutti i sensori
    QComboBox* sensoreBox;
public:

    /**
     * @brief finestraSensore:    costruttore di finestraSensore, un dialog per la scelta del sensore
     * @param parent:             widget genitore di tale dialog
     */
    explicit finestraSensore(QWidget* parent = nullptr, const std::vector<Sensore *>* sensori = nullptr);

    /**
     * @brief Tipo                  metodo statico per garantire l'esecuzione del dialog senza doverlo allocare
     * @param parent:               widget genitore di tale dialog
     * @param ok:                   booleano che serve per indicare se il dialog ha ritornato valori validi o meno
     * @return int:                 stringa contenente l'ID del sensore scelto
     */
    static QString getSensore(QWidget* parent, const std::vector<Sensore *>* sensori, bool* ok = nullptr);
};

#endif // FINESTRASENSORE_H
