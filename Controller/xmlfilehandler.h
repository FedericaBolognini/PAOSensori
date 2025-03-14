#ifndef XMLFILEHANDLER_H
#define XMLFILEHANDLER_H

#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFileDialog>
#include "../Modello/Sensore.h"
#include "../Modello/SensoreAcqua.h"
#include "../Modello/SensoreAria.h"
#include "../Modello/SensoreSuolo.h"
#include "../Modello/SensoreCreator.h"

class xmlFileHandler
{

private:

    /**
     * @brief readSensori:                  gestisce la lettura sullo stream XML in ingresso dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @throw std::runtime_error:           se i dati non sono leggibili
     * @return std::vector<Sensore>: valori dei sensori letti
     */
    static std::vector<Sensore*> readSensori(QXmlStreamReader& reader);

    /**
     * @brief readType:                     gestisce la lettura sullo stream XML in ingresso del tipo dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @param type:                         variabile in cui salvare il tipo del sensore letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readType(QXmlStreamReader &reader, QString& type);

    /**
     * @brief readName:                     gestisce la lettura sullo stream XML in ingresso del nome dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @param name:                         variabile in cui salvare il nome del sensore letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readName(QXmlStreamReader &reader, QString& name);

    /**
     * @brief readPrecisione:               gestisce la lettura sullo stream XML in ingresso della precisione dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @param precisione:                   variabile in cui salvare la precisione del sensore letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readPrecisione(QXmlStreamReader &reader, int& precisione);

    /**
     * @brief readId:                       gestisce la lettura sullo stream XML in ingresso dell'id dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @param id:                           variabile in cui salvare l'id del sensore letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readId(QXmlStreamReader &reader, int& id);

    /**
     * @brief readMinValidTemperatura:      gestisce la lettura sullo stream XML in ingresso della temperatura minima valida dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @param minValidTemperatura:          variabile in cui salvare la temperatura minima valida del sensore letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readMinValidTemperatura(QXmlStreamReader &reader, double& minValidTemperatura);

    /**
     * @brief readMaxValidTemperatura:      gestisce la lettura sullo stream XML in ingresso della temperatura massima valida dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @param maxValidTemperatura:          variabile in cui salvare la temperatura massima valida del sensore letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readMaxValidTemperatura(QXmlStreamReader &reader, double& maxValidTemperatura);

    /**
     * @brief readTemperatura:              gestisce la lettura sullo stream XML in ingresso del vettore delle temperature dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @param temperatura:                  vettorein cui salvare le temperatura del sensore letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readTemperatura(QXmlStreamReader &reader, std::vector<double>& temperatura);

    /**
     * @brief readMinValidFirstVector:      gestisce la lettura sullo stream XML in ingresso del minimo valore del primo vettore di classe concreta dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @param minValidFirstVector:          variabile in cui salvare il minimo valore del primo vettore di classe concreta del sensore letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readMinValidFirstVector(QXmlStreamReader &reader, int& minValidFirstVector);

    /**
     * @brief readMaxValidFirstVector:      gestisce la lettura sullo stream XML in ingresso del massimo valore del primo vettore di classe concreta dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @param maxValidFirstVector:          variabile in cui salvare il massimo valore del primo vettore di classe concreta del sensore letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readMaxValidFirstVector(QXmlStreamReader &reader, int& maxValidFirstVector);

    /**
     * @brief readVector:                   gestisce la lettura sullo stream XML in ingresso di uno dei due vettori di classe concreta dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @param vector:                       variabile in cui salvare i campionamenti del vettore desiderato del sensore letto
     * @param vectorName:                   nome del vettore da leggere
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readVector(QXmlStreamReader &reader, std::vector<int>& vector, const std::string& vectorName);

    /**
     * @brief readMinValidSecondVector:     gestisce la lettura sullo stream XML in ingresso del minimo valore del secondo vettore di classe concreta dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @param minValidSecondVector:         variabile in cui salvare il minimo valore del secondo vettore di classe concreta del sensore letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readMinValidSecondVector(QXmlStreamReader &reader, int& minValidSecondVector);

    /**
     * @brief readMaxValidSecondVector:     gestisce la lettura sullo stream XML in ingresso del massimo valore del secondo vettore di classe concreta dei sensori
     * @param reader:                       stream XML da cui leggere i dati
     * @param maxValidSecondVector:         variabile in cui salvare il massimo valore del secondo vettore di classe concreta del sensore letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readMaxValidSecondVector(QXmlStreamReader &reader, int& maxValidSecondVector);

    /**
     * @brief throwReadError:               lancia un'eccezione std::runtime_error comune per ogni metodo
     * @throw std::runtime_error:           sempre
     */
    static void throwReadError();

    /**
     * @brief writeVector:                  gestisce la scrittura di uno dei vettori di interi tipici delle classi concrete della gerarchia di sensori
     * @param writer:                       stream XML in cui scrivere i dati
     * @param vector:                       vettore di campionamenti da salvare
     * @param vectorName:                   nome da assegnare al tag XML contenente i campionamenti
     */
    static void writeVector(QXmlStreamWriter& writer, const std::vector<int>& vector, std::string vectorName);

    /**
     * @brief writeTemperaturaVector:       gestisce la scrittura del vettore dei campionamenti relativi alle temperature
     * @param writer:                       stream XML in cui scrivere i dati
     * @param temperature:                  vettore di temperature da salvare
     */
    static void writeTemperaturaVector(QXmlStreamWriter& writer, const std::vector<double>& temperature);

    /**
     * @brief writeAriaSensore:             gestisce la scrittura dei parametri tipici di un sensore di tipo aria
     * @param writer:                       stream XML in cui scrivere il sensore
     * @param sensore:                      sensore di tipo aria da salvare
     */
    static void writeAriaSensore(QXmlStreamWriter& writer, SensoreAria* sensore);

    /**
     * @brief writeAcquaSensore             gestisce la scrittura dei parametri tipici di un sensore di tipo acqua
     * @param writer:                       stream XML in cui scrivere il sensore
     * @param sensore:                      sensore di tipo acqua da salvare
     */
    static void writeAcquaSensore(QXmlStreamWriter& writer, SensoreAcqua* sensore);


    /**
     * @brief writeSuoloSensore             gestisce la scrittura dei parametri tipici di un sensore di tipo suolo
     * @param writer:                       stream XML in cui scrivere il sensore
     * @param sensore:                      sensore di tipo suolo da salvare
     */
    static void writeSuoloSensore(QXmlStreamWriter& writer, SensoreSuolo* sensore);

public:
    explicit xmlFileHandler() = delete;
    explicit xmlFileHandler(const xmlFileHandler&) = delete;

    /**
     * @brief write:        gestisce la scrittura sul device di IO in ingresso dei sensori in ingresso
     * @param device:       IO device in cui salvare i dati
     * @param sensori:      sensori da salvare
     */
    static void write(QIODevice *device, const std::vector<Sensore*>& sensori);

    /**
     * @brief getWriteFileName:     gestisce la richiesta del path del file su cui scrivere i sensori
     * @param parent:               widget genitore del dialog di richiesta del path
     * @throw std::runtime_error:   se la richiesta del path va a vuoto (utente esce dal dialog specifico)
     * @return QString:             path del file su cui scrivere
     */
    static QString getWriteFileName(QWidget* parent);

    /**
     * @brief read:                                     gestisce l'apertura di uno stream XML sul device di IO in ingresso
     * @param device:                                   IO device da cui leggere i dati
     * @throw std::runtime_error:                       se il device non è leggibile
     * @return std::vector<Sensore>:                    valori dei sensori letti
     */
    static std::vector<Sensore*> read(QIODevice *device);

    /**
     * @brief getReadFileName:      gestisce la richiesta del path del file da cui leggere i sensori
     * @param parent:               widget genitore del dialog di richiesta del path
     * @throw std::runtime_error:   se la richiesta del path va a vuoto (utente esce dal dialog specifico)
     * @return QString:             path del file su cui leggere
     */
    static QString getReadFileName(QWidget* parent);
};

#endif // XMLFILEHANDLER_H
