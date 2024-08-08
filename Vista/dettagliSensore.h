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
#include <iostream>
#include <sstream>
#include <iomanip>
#include "../Modello/Sensore.h"

class DettagliSensore:public QWidget{
    Q_OBJECT

public:
    explicit DettagliSensore(QWidget *parent=nullptr);

virtual ~DettagliSensore();

signals:
void richiestaSimulazione();
void puntoSelezionato();

public slots:
void aggiornaSensore(Sensore* sensore);

private slots:
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

    // Serie di dati del grafico
    QLineSeries *series;

    // grafico
    QChart *chart;

    // vista del grafico
    QChartView *chartView;

    //aggiunta labels
    void addLeftLabels(QVBoxLayout* layout);

    //aggiunta labels
    void addRightLabels(QVBoxLayout* layout);

    //aggiunta grafico
    void addChart(QVBoxLayout* layout);

    //aggiunta bottone simula
    void addButtons(QHBoxLayout* layout);
    
    //
    void setupConnections();
};

#endif // DETTAGLI_SENSORE_H
