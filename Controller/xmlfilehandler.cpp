    #include "xmlfilehandler.h"

    void xmlFileHandler::readType(QXmlStreamReader &reader, QString& type)
    {
        QString attr = reader.attributes().value("tipo").toString();

        if( attr == "Aria" || attr== "Acqua" || attr == "Suolo")
            type = reader.attributes().value("tipo").toString();
        else
            throwReadError();
    }

    void xmlFileHandler::readName(QXmlStreamReader &reader, QString& name)
    {
        if(reader.name().toString() == "nome")
            name = reader.readElementText();
        else
            throwReadError();
    }

    void xmlFileHandler::readPrecisione(QXmlStreamReader &reader, int &precisione)
    {
        if(reader.name().toString() == "precisione")
            precisione = std::stoi(reader.readElementText().toStdString());
        else
            throwReadError();
    }

    void xmlFileHandler::readId(QXmlStreamReader &reader, int &id)
    {
        if(reader.name().toString() == "id")
            id = std::stoi(reader.readElementText().toStdString());
        else
            throwReadError();
    }

    void xmlFileHandler::readMinValidTemperatura(QXmlStreamReader &reader, double &minValidTemperatura)
    {
        if(reader.name().toString() == "minValidTemperatura"){
            std::string minTemperatura = reader.readElementText().toStdString();
            #ifdef Q_OS_WIN
                    std::replace(minTemperatura.begin(),minTemperatura.end(), ',', '.');
            #else
                    std::replace(minTemperatura.begin(),minTemperatura.end(), '.', ',');

            #endif
            minValidTemperatura = std::stod(minTemperatura);
        } else
            throwReadError();
    }

    void xmlFileHandler::readMaxValidTemperatura(QXmlStreamReader &reader, double &maxValidTemperatura)
    {
        if(reader.name().toString() == "maxValidTemperatura"){
            std::string maxTemperatura = reader.readElementText().toStdString();
            #ifdef Q_OS_WIN
                    std::replace(maxTemperatura.begin(),maxTemperatura.end(), ',', '.');
            #else
                    std::replace(maxTemperatura.begin(),maxTemperatura.end(), '.', ',');

            #endif
            maxValidTemperatura = std::stod(maxTemperatura);
        } else
            throwReadError();
    }

    void xmlFileHandler::readTemperatura(QXmlStreamReader &reader, std::vector<double>& temperatura)
    {
        if (reader.name().toString() == "temperature") {
            QString temperatureStr = reader.readElementText();
            QStringList temperatureList = temperatureStr.split(" - ");
            for (const QString& temperatureStr : temperatureList) {
                if(temperatureStr != ""){
                    std::string temperaturaStr = temperatureStr.toStdString();
                    #ifdef Q_OS_WIN
                        std::replace(temperaturaStr.begin(),temperaturaStr.end(), ',', '.');
                    #else
                        std::replace(temperatura.begin(),temperatura.end(), '.', ',');

                    #endif
                    double temperature = std::stod(temperaturaStr);
                    temperatura.push_back(temperature);
                }
            }
        } else {
            throwReadError();
        }
    }

    void xmlFileHandler::readMinValidFirstVector(QXmlStreamReader &reader, int &minValidFirstVector)
    {
        if(reader.name().toString() == "minValidFirstVector"){
            minValidFirstVector = std::stoi(reader.readElementText().toStdString());
        }
        else
            throwReadError();
    }

    void xmlFileHandler::readMaxValidFirstVector(QXmlStreamReader &reader, int &maxValidFirstVector)
    {
        if(reader.name().toString() == "maxValidFirstVector")
            maxValidFirstVector = std::stoi(reader.readElementText().toStdString());
        else
            throwReadError();
    }

    void xmlFileHandler::readVector(QXmlStreamReader &reader, std::vector<int>& vector, const std::string& vectorName)
    {
        if (reader.name().toString().toStdString() == vectorName) {
            QString valuesStr = reader.readElementText();
            QStringList valuesList = valuesStr.split(" - ");
            for (const QString& valueStr : valuesList) {

                if(valueStr != ""){
                    bool ok;
                    int value = valueStr.toInt(&ok);
                    if (ok) {
                        vector.push_back(value);
                    } else {
                        throwReadError();
                    }
                }
            }
        } else {
            throwReadError();
        }
    }

    void xmlFileHandler::readMinValidSecondVector(QXmlStreamReader &reader, int &minValidSecondVector)
    {
        if(reader.name().toString() == "minValidSecondVector")
            minValidSecondVector = std::stoi(reader.readElementText().toStdString());
        else
            throwReadError();
    }

    void xmlFileHandler::readMaxValidSecondVector(QXmlStreamReader &reader, int &maxValidSecondVector)
    {
        if(reader.name().toString() == "maxValidSecondVector")
            maxValidSecondVector = std::stoi(reader.readElementText().toStdString());
        else
            throwReadError();
    }

    void xmlFileHandler::throwReadError()
    {
        throw std::runtime_error("Il file non è leggibile!");
    }

    void xmlFileHandler::writeVector(QXmlStreamWriter &writer, const std::vector<int>& vector, std::string vectorName)
    {
        QString valori = "";

        for(auto it= vector.begin(); it != vector.end(); ++it){
            valori += QString::fromStdString(std::to_string(*it));
            valori += " - ";
        }

        writer.writeTextElement(QString::fromStdString(vectorName), valori);
    }

    void xmlFileHandler::writeTemperaturaVector(QXmlStreamWriter &writer, const std::vector<double>& temperature)
    {
        QString valori = "";

        for(auto it= temperature.begin(); it != temperature.end(); ++it){
            valori += QString::fromStdString(std::to_string(*it));
            valori += " - ";
        }

        writer.writeTextElement("temperature", valori);

    }

    void xmlFileHandler::writeAriaSensore(QXmlStreamWriter &writer, SensoreAria* sensore)
    {
        // CO2 primo vettore, ossigeno secondo vettore

        writer.writeTextElement("minValidFirstVector", QString::fromStdString(std::to_string(sensore->getMinValidCO2())));
        writer.writeTextElement("maxValidFirstVector", QString::fromStdString(std::to_string(sensore->getMaxValidCO2())));

        writeVector(writer, sensore->getCO2Vector(), "firstVector");

        writer.writeTextElement("minValidSecondVector", QString::fromStdString(std::to_string(sensore->getMinValidOssigeno())));
        writer.writeTextElement("maxValidSecondVector", QString::fromStdString(std::to_string(sensore->getMaxValidOssigeno())));

        writeVector(writer, sensore->getOssigenoVector(), "secondVector");
    }

    void xmlFileHandler::writeAcquaSensore(QXmlStreamWriter &writer, SensoreAcqua *sensore)
    {
        // Alcalinità primo vettore, acidità secondo vettore

        writer.writeTextElement("minValidFirstVector", QString::fromStdString(std::to_string(sensore->getMinValidAlcalinità())));
        writer.writeTextElement("maxValidFirstVector", QString::fromStdString(std::to_string(sensore->getMaxValidAlcalinità())));

        writeVector(writer, sensore->getAlcalinitàVector(), "firstVector");

        writer.writeTextElement("minValidSecondVector", QString::fromStdString(std::to_string(sensore->getMinValidAcidità())));
        writer.writeTextElement("maxValidSecondVector", QString::fromStdString(std::to_string(sensore->getMaxValidAcidità())));
        writeVector(writer, sensore->getAciditàVector(), "secondVector");
    }

    void xmlFileHandler::writeSuoloSensore(QXmlStreamWriter &writer, SensoreSuolo *sensore)
    {
        // PH primo vettore, umidità secondo vettore

        writer.writeTextElement("minValidFirstVector", QString::fromStdString(std::to_string(sensore->getMinValidPH())));
        writer.writeTextElement("maxValidFirstVector", QString::fromStdString(std::to_string(sensore->getMaxValidPH())));

        writeVector(writer, sensore->getPHVector(), "firstVector");

        writer.writeTextElement("minValidSecondVector", QString::fromStdString(std::to_string(sensore->getMinValidUmidità())));
        writer.writeTextElement("maxValidSecondVector", QString::fromStdString(std::to_string(sensore->getMaxValidUmidità())));

        writeVector(writer, sensore->getUmiditàVector(), "secondVector");
    }

    std::vector<Sensore*> xmlFileHandler::readSensori(QXmlStreamReader &reader)
    {
        Q_ASSERT(reader.isStartElement() && reader.name() == QLatin1String("collezione"));
        std::vector<Sensore*> vector;

        while (reader.readNextStartElement()) {             //avanza l'input per ogni sensore
            QString tipo = "";
            QString nome = "";
            int precisione = 0, id = 0, minFirstVector = 0, maxFirstVector = 0, minSecondVector = 0, maxSecondVector = 0;
            double minTemperatura = 0.0, maxTemperatura = 0.0;
            std::vector<double> temperatura;
            std::vector<int> firstVector, secondVector;

            if (reader.name().toString() == "sensore")
            {
                readType(reader,tipo);

                if(reader.readNextStartElement())
                    readName(reader, nome);
                else
                    throwReadError();

                if(reader.readNextStartElement())
                    readPrecisione(reader, precisione);
                else
                    throwReadError();

                if(reader.readNextStartElement())
                    readId(reader, id);
                else
                    throwReadError();

                if(reader.readNextStartElement())
                    readMinValidTemperatura(reader, minTemperatura);
                else
                    throwReadError();

                if(reader.readNextStartElement())
                    readMaxValidTemperatura(reader, maxTemperatura);
                else
                    throwReadError();

                if(reader.readNextStartElement())
                    readTemperatura(reader, temperatura);
                else
                    throwReadError();

                if(reader.readNextStartElement())
                    readMinValidFirstVector(reader, minFirstVector);
                else
                    throwReadError();

                if(reader.readNextStartElement())
                    readMaxValidFirstVector(reader, maxFirstVector);
                else
                    throwReadError();

                if(reader.readNextStartElement())
                    readVector(reader, firstVector, "firstVector");
                else
                    throwReadError();

                if(reader.readNextStartElement())
                    readMinValidSecondVector(reader, minSecondVector);
                else
                    throwReadError();

                if(reader.readNextStartElement())
                    readMaxValidSecondVector(reader, maxSecondVector);
                else
                    throwReadError();

                if(reader.readNextStartElement())
                    readVector(reader, secondVector, "secondVector");
                else
                    throwReadError();

                Sensore* sensore = SensoreCreator::createSensore(tipo.toStdString(), id, nome.toStdString(), precisione, minTemperatura, maxTemperatura, minFirstVector, maxFirstVector, minSecondVector, maxSecondVector);

                for(auto record: temperatura){
                    sensore->addTemperaturaRecord(record);
                }

                SensoreAcqua* sensoreAcqua = dynamic_cast<SensoreAcqua*>(sensore);
                SensoreAria* sensoreAria = dynamic_cast<SensoreAria*>(sensore);
                SensoreSuolo* sensoreSuolo = dynamic_cast<SensoreSuolo*>(sensore);

                if(sensoreAcqua){

                    for(auto record: firstVector){
                        sensoreAcqua->addAlcalinitàRecord(record);
                    }

                    for(auto record: secondVector){
                        sensoreAcqua->addAciditàRecord(record);
                    }

                } else if(sensoreAria){
                    for(auto record: firstVector){
                        sensoreAria->addCO2Record(record);
                    }

                    for(auto record: secondVector){
                        sensoreAria->addOssigenoRecord(record);
                    }
                } else if(sensoreSuolo){
                    for(auto record: firstVector){
                        sensoreSuolo->addPHRecord(record);
                    }

                    for(auto record: secondVector){
                        sensoreSuolo->addUmiditàRecord(record);
                    }
                } else {
                    throw std::runtime_error("Il sensore letto non è di tipo noto!");
                }

                vector.push_back(sensore);

            }
            else
                throwReadError();
            reader.readNextStartElement();
        }
        return vector;
    }

    void xmlFileHandler::write(QIODevice *device, const std::vector<Sensore*>& sensori)
    {

        QXmlStreamWriter writer(device);
        writer.setAutoFormatting(true);
        writer.writeStartDocument();
        writer.writeStartElement("collezione");

        for(auto it = sensori.begin(); it != sensori.end(); ++it)
        {
            writer.writeStartElement("sensore");

            std::string tipo = typeid(**it).name();
            tipo = tipo.substr(9);

            if(tipo != "Aria" && tipo != "Acqua" && tipo != "Suolo")
                throw std::runtime_error("Tipo di sensore non riconosciuto!");

            writer.writeAttribute("tipo", QString::fromStdString(tipo));

            writer.writeTextElement("nome", QString::fromStdString((*it)->getNome()));
            writer.writeTextElement("precisione", QString::fromStdString(std::to_string((*it)->getPrecisione())));
            writer.writeTextElement("id", QString::fromStdString(std::to_string((*it)->getID())));
            writer.writeTextElement("minValidTemperatura", QString::fromStdString(std::to_string((*it)->getMinValidTemperatura())));
            writer.writeTextElement("maxValidTemperatura", QString::fromStdString(std::to_string((*it)->getMaxValidTemperatura())));

            writeTemperaturaVector(writer, (*it)->getTemperaturaVector());

            Sensore* sensore = *it;

            if(tipo == "Aria")
                writeAriaSensore(writer, dynamic_cast<SensoreAria*>(sensore));
            else if(tipo == "Acqua"){
                writeAcquaSensore(writer, dynamic_cast<SensoreAcqua*>(sensore));
            } else {
                writeSuoloSensore(writer, dynamic_cast<SensoreSuolo*>(sensore));
            }

            writer.writeEndElement();
        }


        writer.writeEndElement();
        writer.writeEndDocument();


    }

    QString xmlFileHandler::getWriteFileName(QWidget* parent)
    {
        QString fileName = QFileDialog::getSaveFileName(parent, ("Save File"),
                                                        "/home",
                                                        ("XML Files (*.xml)"));
        if (fileName == "")
            throw std::runtime_error("Nessun file scelto, aggiunta annullata!");

        if(fileName.size() > 4)
        {
            QString ext = fileName.mid(fileName.size()-4);

            if(ext != ".xml")
                fileName += ".xml";
        }
        else
            fileName += ".xml";
        return fileName;
    }

    std::vector<Sensore*> xmlFileHandler::read(QIODevice *device)
    {
        QXmlStreamReader reader(device);

        if (reader.readNextStartElement() && reader.name().toString() == "collezione")
            return readSensori(reader);
        else
            throw std::runtime_error("Il file non è leggibile!");

    }

    QString xmlFileHandler::getReadFileName(QWidget* parent)
    {
        QString fileName = QFileDialog::getOpenFileName(parent, ("Open file"),
                                                        "/home",
                                                        ("XML Files (*.xml)"));
        if (fileName == "")
            throw std::runtime_error("Nessun file scelto, apertura annullata!");

        return fileName;
    }
