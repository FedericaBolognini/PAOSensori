#pragma once

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include "../Modello/Modello.h"
#include "../Vista/vista.h"
#include "xmlfilehandler.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    // componente grafico principale
    Vista *vista;

    // modello
    Model *modello;

    // memorizza se i dati salvati nel modello (e disponibili nella vista) sono stati salvati sul file "filenameSaved"
    bool saved;

    // path del file dove è salvato l'insieme di dati memorizzati nel modello e mostrati nella vista
    QString filenameSaved;

public:
    /**
     * @brief Controller:           costruttore del Controller
     * @param parent:               parent del Controller
     */
    explicit Controller(QObject *parent = nullptr);

    /**
     * @brief setView:         collega la vista
     * @param v:               vista
     */
    void setView(Vista *v);

    /**
     * @brief setModel:        collega il modello
     * @param m:               vista
     */
    void setModel(Model *m);

    /**
     * @brief ~Controller:     scollega vista e modello, deallocandoli
     */
    ~Controller();

public slots:

    /**
     * @brief add:     gestisce una richiesta di inserimento di un sensore
     */
    void add(dialogValues dati);

    /**
     * @brief set:     gestisce una richiesta di modifica di un sensore
     */
    void set(dialogValues dati, unsigned int posizione);

    /**
     * @brief remove:     gestisce una richiesta di rimozione di un sensore
     */
    void remove(unsigned int posizione);

    /**
     * @brief save:     gestisce una richiesta di salvataggio di tutti i sensori attivi nel file "filenameSaved"
     *                  potendo modificare i campi saved e filenameSaved
     */
    void save();

    /**
     * @brief saveAs:     gestisce una richiesta di salvataggio di tutti i sensori attivi, facendo scegliere il file all'utente;
     *                      i campi saved e filenameSaved non sono modificati
     */
    void saveAs() const;

    /**
     * @brief open:     gestisce una richiesta di ripristino di sensori da un file (da selezionare)
     */
    void open();

    /**
     * @brief closeApp:     gestisce una richiesta di uscita dal programma chiedendo, qualora i dati fossero aperti da un file
     *                      ("filenameSaved") e non fossero stati più scritti, se si vogliono aggiornare i dati prima di chiudere l'applicazione
     */
    void closeApp();

    /**
     * @brief simulazione:  gestisce la simulazione di campionamento di valori per il sensore in ingresso
     * @param sensore:      sensore in cui inserire i dati di campionamento
     */
    void simulazione(Sensore* sensore);
};

#endif // CONTROLLER_H
