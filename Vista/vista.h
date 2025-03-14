#pragma once
#ifndef VISTA_H
#define VISTA_H

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
#include <QMessageBox>
#include <tabellaSensori.h>
#include <dettagliSensore.h>

class Controller;

class Vista : public QWidget
{
    Q_OBJECT

public:
    explicit Vista(QWidget *parent = nullptr);

    /**
     * @brief showWarning:          mostra a video i messaggi di errore dell'applicazione
     * @param message:              messaggio di errore
     */
    void showWarning(const QString& message);

    /**
     * @brief setController:        imposta il riferimento al controller
     * @param controller:           controller
     */
    void setController(Controller* controller);

    /**
     * @brief setSensori:           imposta il riferimento al puntatore del vettore di sensori
     * @param sensori:              vettore di sensori
     */
    void setSensori(const std::vector<Sensore*>* sensori) const;

    /**
     * @brief checkActiveSensor:    controlla se il sensore attivo è ancora valido (dopo eliminazione, potrebbe non essere più valido)
     * @param sensori:              vettore di sensori in cui controllare
     */
    void checkActiveSensor(const std::vector<Sensore*>* sensori) const;

    /**
     * @brief resetSensoreAttivo:   resetta il sensore attivo
     */
    void resetSensoreAttivo() const;

    /**
     * @brief ~Vista:               distruttore virtuale
     */
    virtual ~Vista();

public slots:
    /**
     * @brief aggiornaDati:         slot di aggiornamento della UI dopo operazioni sulla collezione di sensori
     */
    void aggiornaDati();

signals:
    void selezioneSensore(Sensore*);
    void simulazioneRichiesta(Sensore*);
    void aggiungiSensore(dialogValues);
    void modificaSensore(dialogValues, unsigned int);
    void rimuoviSensore(unsigned int);
    void open();
    void save();
    void saveAs();

private:

    //riferimento al controller
    Controller* controller;

    // Barra dei menù
    QMenuBar *menuBar;

    // Menù dei file
    QMenu *file;

    // Layout principale
    QVBoxLayout *mainLayout;

    // Layout secondario
    QHBoxLayout *horizontalmainLayout;

    // Widget che rappresenta la metà di sinistra della UI
    TabellaSensori *leftWidget;

    // Widget che rappresenta la metà di destra della UI
    DettagliSensore *rightWidget;

    /**
     * @brief addMenus:                 gestisce l'aggiunta della barra del menù e il collegamento coi relativi segnali
     * @param mainLayout:               layout dove includere il menù
     */
    void addMenus(QVBoxLayout *mainLayout);

    /**
     * @brief setupConnections:         gestisce il collegamento tra segnali e slots
     */
    void setupConnections();
};

#endif // VISTA_H
