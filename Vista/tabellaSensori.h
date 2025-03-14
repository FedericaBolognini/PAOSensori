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
#include <string>

class TabellaSensori:public QWidget{
    Q_OBJECT

public:
    explicit TabellaSensori(QWidget *parent=nullptr);

    /**
     * @brief showWarning:              Mostra a video i messaggi di errore dell'applicazione
     * @param message:                  Messaggio di errore
     */
    void showWarning(const QString& message);

    /**
     * @brief setSensori:               Setter per il vettore di sensori
     * @param sensori:                  Vettore di sensori
     */
    void setSensori(const std::vector<Sensore*>* sensori);

    /**
    * @brief ~TabellaSensori:            Distruttore virtuale
    */
    virtual ~TabellaSensori();

public slots:
    /**
    * @brief aggiornaDati:                      Aggiorna la tabella
    */
    void aggiornaDati();

signals:
    void selezioneSensore(Sensore*);

    void aggiungiSensore(dialogValues);

    void modificaSensore(dialogValues, unsigned int);

    void rimuoviSensore(unsigned int);

private slots:

    /**
    * @brief gestisciRichiestaElimina:             Gestisce la richiesta di eliminazione di un sensore                  
    */
    void gestisciRichiestaElimina();

    /**
    * @brief gestisciRichiestaModifica:            Gestisce la richiesta di modifica di un sensore                              
    */
    void gestisciRichiestaModifica();   

    /**
    * @brief gestisciRichiestaAggiungi:             Gestisce la richiesta di aggiunta di un sensore                  
    */
    void gestisciRichiestaAggiungi();

    /**
    * @brief cellDoubleClicked:                    Gestisce l'evento di doppio clic su una cella della tabella selezionando l'intera riga della cella corrispondente
    * @param iRow:                                 L'indice della riga cliccata
    * @param iColumn:                              L'indice della colonna cliccata 
    */
    void cellDoubleClicked(int iRow, int iColumn);

private:
    // Collezione di sensori 
    const std::vector<Sensore *>* sensori;

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

    /**
    * @brief addFindSection:                    Aggiunta della sezione di ricerca         
    * @param layout:                            Layout aggiunto
    */
    void addFindSection(QVBoxLayout *layout);


    /**
    * @brief addTable:                           Aggiunta della tabella        
    * @param layout:                             Layout aggiunto
    */
    void addTable(QVBoxLayout *layout);

    /**
    * @brief addButtons:                         Aggiunta bottoni      
    * @param layout:                             Layout aggiunto
    */
    void addButtons(QHBoxLayout *layout);

    /**
    * @brief setupConnections:                   Collegamento segnali e slot             
    */
    void setupConnections();

    /**
    * @brief pulisciTabella:                     Rimuove tutti gli elementi dalla tabella            
    */
    void pulisciTabella();

};

#endif // TABELLA_SENSORI_H
