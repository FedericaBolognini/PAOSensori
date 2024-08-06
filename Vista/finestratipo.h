#ifndef FINESTRATIPO_H
#define FINESTRATIPO_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QComboBox>
#include <QPushButton>

class finestraTipo : public QDialog
{
    Q_OBJECT

private:
    //combo box contenente tutti i tipi disponibili di sensore
    QComboBox* typeBox;
public:

    /**
     * @brief finestraTipo:  costruttore di finestraTipo, un dialog per la scelta del tipo di sensore
     * @param parent:        widget genitore di tale dialog
     */
    explicit finestraTipo(QWidget* parent = nullptr);

    /**
     * @brief Tipo                  metodo statico per garantire l'esecuzione del dialog senza doverlo allocare
     * @param parent:               widget genitore di tale dialog
     * @param ok:                   booleano che serve per indicare se il dialog ha ritornato valori validi o meno
     * @return QString:             stringa contenente il tipo di sensore scelto
     */
    static QString getTipo(QWidget* parent, bool* ok = nullptr);
};

#endif // FINESTRATIPO_H
