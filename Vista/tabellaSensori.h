#ifndef TABELLA_SENSORI_H
#define TABELLA_SENSORI_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QAbstractItemView>
#include <QLabel>
#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include <QPainter>
#include <QHeaderView>
#include <QSize>
#include <QMessageBox>
#include <finestratipo.h>
#include <finestrasensore.h>
#include <sensoreacquadialog.h>
#include <sensoreariadialog.h>
#include <sensoresuolodialog.h>
#include <iostream>
#include <string>

class TabellaSensori:public QWidget{
    Q_OBJECT

public:
    explicit TabellaSensori(QWidget *parent=nullptr);

    /**
     * @brief showWarning:          mostra a video i messaggi di errore dell'applicazione
     * @param message:              messaggio di errore
     */
    void showWarning(const QString& message);
    virtual ~TabellaSensori();

signals:
void richiestaCerca();
void richiestaElimina();
void richiestaModifica();
void richiestaAggiungi();

private slots:
void aggiornaTabella();
void pulisciCampoRicerca();
void gestisciRichiestaCerca();
void gestisciRichiestaElimina();
void gestisciRichiestaModifica();
void gestisciRichiestaAggiungi();
void cellDoubleClicked(int iRow, int iColumn);

private:
    std::vector<Sensore *>* sensori;

    // Layout principale
    QVBoxLayout* mainLayout;

    // Layout bottoni
    QHBoxLayout *bottomButtonLayout;

    // Barra di ricerca
    QLineEdit *searchBar;

    // Bottone di ricerca
    QPushButton *searchButton;

    // Bottone di eliminazione
    QPushButton *bottomButtonElimina;

    // Bottone di modifica
    QPushButton *bottomButtonModifica;

    // Bottone di aggiunta
    QPushButton *bottomButtonAggiungi;

    // Tabella
    QTableWidget *tableWidget;

    // Aggiunta della sezione di ricerca
    void addFindSection(QVBoxLayout* layout);

    // Aggiunta della tabella
    void addTable(QVBoxLayout *layout);

    // Aggiunta bottoni
    void addButtons(QHBoxLayout *layout);

    // Collegamento segnali e slot
    void setupConnections();

    // Metodo per rimuovere tutti gli elementi dalla tabella
    void pulisciTabella();
};

#endif // TABELLA_SENSORI_H
