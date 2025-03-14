#include <dettagliSensore.h>

DettagliSensore::DettagliSensore(QWidget *parent) : QWidget(parent)
{

    // Creazione layout principale
    mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(10, 5, 10, 5);

    // Aggiunta label di intestazione
    QLabel *details = new QLabel("Dettagli sensore:", this);
    details->setStyleSheet("font-size: 18px; font-weight: bold;");
    mainLayout->addWidget(details);

    // Creazione layout dei dettagli (e sottolayouts)
    detailsLayout = new QHBoxLayout;
    leftdetailsLayout = new QVBoxLayout;
    rightdetailsLayout = new QVBoxLayout;
    detailsLayout->setSpacing(10);

    // Aggiunta labels e relativi layouts
    addLeftLabels(leftdetailsLayout);
    addRightLabels(rightdetailsLayout);

    detailsLayout->addLayout(leftdetailsLayout);
    detailsLayout->addLayout(rightdetailsLayout);

    mainLayout->addLayout(detailsLayout);

    // Aggiunta bottone di simulazione dati
    simula = new QPushButton("Simula", this);
    mainLayout->addWidget(simula, 0, Qt::AlignRight);

    // Aggiunta grafico
    addChart(mainLayout);

    setupConnections();

    setLayout(mainLayout);
}

void DettagliSensore::checkSensoreAttivo(const std::vector<Sensore *> *sensori)
{
    bool found = false;
    if(sensori && sensori->size() && sensoreAttivo){
        for(Sensore* sensore : *sensori){
            if(sensore->getID() == sensoreAttivo->getID()){
                found = true;
            }
        }

        if(!found){
            sensoreAttivo = sensori->at(0);
        }
    } else {
        sensoreAttivo = nullptr;
    }
}

DettagliSensore::~DettagliSensore() {}

void DettagliSensore::aggiornaDati()
{
    this->aggiornaSensore(nullptr);
}

void DettagliSensore::resetSensoreAttivo()
{
    sensoreAttivo = nullptr;
}

void DettagliSensore::aggiornaSensore(Sensore *sensore)
{
    if(sensore){
        sensoreAttivo = sensore;
    }

    if(sensoreAttivo){
        std::string tipoSensore = typeid(*sensoreAttivo).name();
        tipoSensore = tipoSensore.substr(9);

        std::string idSensore = std::to_string(sensoreAttivo->getID());
        std::string precisioneSensore = std::to_string(sensoreAttivo->getPrecisione());

        std::ostringstream out;
        out << std::fixed << std::setprecision(2) << sensoreAttivo->getMinValidTemperatura();
        std::string tempMinSensore = out.str();

        out.str("");
        out.clear();

        out << std::fixed << std::setprecision(2) << sensoreAttivo->getMaxValidTemperatura();
        std::string tempMaxSensore = out.str();
        std::string qualitàSensore = std::to_string(sensoreAttivo->Qualità());

        nome->setText("Nome: " + QString::fromStdString(sensoreAttivo->getNome()));
        tipo->setText("Tipo: " + QString::fromStdString(tipoSensore));
        id->setText("ID: " + QString::fromStdString(idSensore));
        precisione->setText(("Precisione: " + QString::fromStdString(precisioneSensore + "%")));
        mintemperatura->setText(("Temperatura minima: " + QString::fromStdString(tempMinSensore) + "°C"));
        maxtemperatura->setText(("Temperatura massima: " + QString::fromStdString(tempMaxSensore) + "°C"));
        qualità->setText(("Qualità: " + QString::fromStdString(qualitàSensore)));

        // Aggiorno il grafico
        aggiornaGrafico(sensoreAttivo);
    } else {
        nome->setText("Nome: ");
        tipo->setText("Tipo: ");
        id->setText("ID: ");
        precisione->setText("Precisione: " );
        mintemperatura->setText(("Temperatura minima: _°C"));
        maxtemperatura->setText(("Temperatura massima: _°C"));
        qualità->setText("Qualità: " );

        temperatureSeries->clear();
        secondSeries->clear();
        thirdSeries->clear();

        chart->removeSeries(temperatureSeries);
        chart->removeSeries(secondSeries);
        chart->removeSeries(thirdSeries);

        temperatureSeries = new QLineSeries(this);
        secondSeries = new QLineSeries(this);
        thirdSeries = new QLineSeries(this);

        temperatureSeries->setName("Temperature");
        secondSeries->setName("Parametro 1");
        thirdSeries->setName("Parametro 2");

        chart->addSeries(temperatureSeries);
        chart->addSeries(secondSeries);
        chart->addSeries(thirdSeries);
        chart->createDefaultAxes();
    }
}

void DettagliSensore::gestisciRichiestaSimulazione()
{
    emit simulazioneRichiesta(this->sensoreAttivo);
}

void DettagliSensore::addLeftLabels(QVBoxLayout *layout)
{
    nome = new QLabel("Nome:", this);
    layout->addWidget(nome);
    tipo = new QLabel("Tipo:", this);
    layout->addWidget(tipo);
    id = new QLabel("ID:", this);
    layout->addWidget(id);
}

void DettagliSensore::addRightLabels(QVBoxLayout *layout)
{
    precisione = new QLabel("Precisione:", this);
    layout->addWidget(precisione);
    mintemperatura = new QLabel("Temperatura minima:", this);
    layout->addWidget(mintemperatura);
    maxtemperatura = new QLabel("Temperatura massima:", this);
    layout->addWidget(maxtemperatura);
    qualità = new QLabel("Qualità:", this);
    layout->addWidget(qualità);
}

void DettagliSensore::addChart(QVBoxLayout *layout)
{
    temperatureSeries = new QLineSeries(this);
    secondSeries = new QLineSeries(this);
    thirdSeries = new QLineSeries(this);

    temperatureSeries->setName("Temperature");
    secondSeries->setName("Parametro 1");
    thirdSeries->setName("Parametro 2");

    chart = new QChart();
    chart->addSeries(temperatureSeries);
    chart->addSeries(secondSeries);
    chart->addSeries(thirdSeries);
    chart->createDefaultAxes();
    chart->setTitle("Valori campionati");

    chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(chartView);
}

void DettagliSensore::aggiornaGrafico(Sensore* sensore)
{
    temperatureSeries->clear();
    secondSeries->clear();
    thirdSeries->clear();

    chart->removeSeries(temperatureSeries);
    chart->removeSeries(secondSeries);
    chart->removeSeries(thirdSeries);

    temperatureSeries = new QLineSeries(this);
    secondSeries = new QLineSeries(this);
    thirdSeries = new QLineSeries(this);

    temperatureSeries->setName("Temperature");

    const std::vector<double>& aux = sensore->getTemperaturaVector();

    for(unsigned int i=0; i<aux.size(); i++){
        temperatureSeries->append(i, aux.at(i));
    }

    SensoreAcqua* sensoreAcqua = dynamic_cast<SensoreAcqua*>(sensoreAttivo);
    SensoreAria* sensoreAria = dynamic_cast<SensoreAria*>(sensoreAttivo);
    SensoreSuolo* sensoreSuolo = dynamic_cast<SensoreSuolo*>(sensoreAttivo);


    if(sensoreAcqua){
        secondSeries->setName("Acidità");

        const std::vector<int>& auxAcidità = sensoreAcqua->getAciditàVector();
        for(unsigned int i=0; i<auxAcidità.size(); i++){
            secondSeries->append(i, auxAcidità.at(i));
        }

        thirdSeries->setName("Alcalinità");
        const std::vector<int>& auxAlcalinità = sensoreAcqua->getAlcalinitàVector();
        for(unsigned int i=0; i<auxAlcalinità.size(); i++){
            thirdSeries->append(i, auxAlcalinità.at(i));
        }
    }

    if(sensoreAria){
        secondSeries->setName("CO2");

        const std::vector<int>& auxCO2 = sensoreAria->getCO2Vector();
        for(unsigned int i=0; i<auxCO2.size(); i++){
            secondSeries->append(i, auxCO2.at(i));
        }

        thirdSeries->setName("Ossigeno");
        const std::vector<int>& auxO2 = sensoreAria->getOssigenoVector();
        for(unsigned int i=0; i<auxO2.size(); i++){
            thirdSeries->append(i, auxO2.at(i));
        }
    }

    if(sensoreSuolo){
        secondSeries->setName("PH");
        const std::vector<int>& auxPH = sensoreSuolo->getPHVector();
        for(unsigned int i=0; i<auxPH.size(); i++){
            secondSeries->append(i, auxPH.at(i));
        }

        thirdSeries->setName("Umidità");
        const std::vector<int>& auxUmidità = sensoreSuolo->getUmiditàVector();
        for(unsigned int i=0; i<auxUmidità.size(); i++){
            thirdSeries->append(i, auxUmidità.at(i));
        }
    }

    chart->addSeries(temperatureSeries);
    chart->addSeries(secondSeries);
    chart->addSeries(thirdSeries);

    chart->createDefaultAxes();
}

void DettagliSensore::setupConnections()
{
    connect(simula,SIGNAL(clicked()),this, SLOT(gestisciRichiestaSimulazione()));
    connect(this->parent(), SIGNAL(selezioneSensore(Sensore*)), this, SLOT(aggiornaSensore(Sensore*)));
}
