#ifndef DETTAGLI_SENSORE_H
#define DETTAGLI_SENSORE_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QLabel>
#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include <QPainter>
#include <QHeaderView>
#include <QSize>
#include <sstream>
#include <iomanip>
#include <vector>
#include "../Modello/Sensore.h"
#include "../Modello/SensoreAcqua.h"
#include "../Modello/SensoreAria.h"
#include "../Modello/SensoreSuolo.h"

class DettagliSensore:public QWidget{
    Q_OBJECT

public:
    explicit DettagliSensore(QWidget *parent=nullptr);

    /**
     * @brief checkSensoreAttivo:   controlla se il sensore attivo è ancora valido (dopo eliminazione, potrebbe non essere più valido)
     * @param sensori:              vettore di sensori in cui controllare
     */
    void checkSensoreAttivo(const std::vector<Sensore*>* sensori);

    /**
     * @brief resetSensoreAttivo:         resetta a nullptr il sensore attivo (apertura di un file se ci sono già dei dati)
     */
    void resetSensoreAttivo();

    /**
    * @brief ~DettagliSensore:            Distruttore virtuale
    */
    virtual ~DettagliSensore();

public slots:
    /**
     * @brief aggiornaDati:               aggiorna i dati del widget senza cambiare il sensore attivo
     */
    void aggiornaDati();

    /**
    * @brief aggiornaSensore:             aggiorna il sensore attivo e la UI
    * @param *sensore:                    nuovo sensore attivo
    */
    void aggiornaSensore(Sensore* sensore);
signals:

    /**
     * @brief simulazioneRichiesta                  Richiede una simulazione col sensore attivo
     * @param sensore                               Sensore attivo
     */
    void simulazioneRichiesta(Sensore* sensore);

private slots:

    /**
    * @brief gestisciRichiestaSimulazione:             Gestisce la richiesta di simulazione di un sensore
    */
    void gestisciRichiestaSimulazione();

private:

    // Sensore attivo
    Sensore* sensoreAttivo = nullptr;

    // layout principale
    QVBoxLayout *mainLayout;

    // layout dettagli
    QHBoxLayout *detailsLayout;

    // layout sinistro dei dettagli
    QVBoxLayout *leftdetailsLayout;

    // layout destro dei dettagli
    QVBoxLayout *rightdetailsLayout;

    // bottone di simulazione
    QPushButton *simula;

    // label del nome
    QLabel *nome;

    // label del tipo
    QLabel *tipo;

    // label dell'id
    QLabel *id;

    // label della precisione
    QLabel *precisione;

    // label della temperatura minima
    QLabel *mintemperatura;

    // label della temperatura massima
    QLabel *maxtemperatura;

    // Label della qualità
    QLabel *qualità;

    // Serie di temperature del grafico
    QLineSeries *temperatureSeries;

    // Serie di dati del grafico - 1
    QLineSeries *secondSeries;

    // Serie di dati del grafico - 2
    QLineSeries *thirdSeries;

    // grafico
    QChart *chart;

    // vista del grafico
    QChartView *chartView;

    /**
    * @brief addButtons:                   Aggiunta labels sinistra
    * @param layout:                      Layout aggiunto
    */
    void addLeftLabels(QVBoxLayout* layout);

    /**
    * @brief addButtons:                   Aggiunta labels destra
    * @param layout:                      Layout aggiunto
    */
    void addRightLabels(QVBoxLayout* layout);

    /**
    * @brief addButtons:                   Aggiunta grafico    
    * @param layout:                      Layout aggiunto
    */
    void addChart(QVBoxLayout* layout);

    /**
    * @brief addButtons:                   Aggiunta bottone       
    * @param layout:                      Layout aggiunto
    */
    void addButtons(QHBoxLayout* layout);
    
    /**
    * @brief setupConnections():                Connessione segnali e slot     
    */
    void setupConnections();

    /**
    * @brief aggiornaGrafico:                   Aggiornamento grafico       
    * @param sensore:                           Sensore selezionato
    */
    void aggiornaGrafico(Sensore* sensore);
};

#endif // DETTAGLI_SENSORE_H
