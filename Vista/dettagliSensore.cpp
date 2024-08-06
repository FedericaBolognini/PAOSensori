#include <dettagliSensore.h>

DettagliSensore::DettagliSensore(QWidget *parent) : QWidget(parent)
{

    // Creazione layout principale
    mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(10, 5, 10, 5);

    // Aggiunta label di intestazione
    QLabel *details = new QLabel("Dettagli sensore:", this);
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

    setLayout(mainLayout);
}

DettagliSensore::~DettagliSensore() {}

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
    series = new QLineSeries(this);
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple Line Chart");

    chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(chartView);
}
void DettagliSensore::setupConnections();
{
    connect(simula,&QPushButton::clicked,this,&dettagliSensore::gestisciRichiestaSimulazione);

}
void DettagliSensore::gestisciRichiestaSimulazione()
{

}
void DettagliSensore::aggiornaGrafico()
{
    
}
void DettagliSensore::puntoSelezionato()
{

}
void DettagliSensore::aggiornaDatiSensore()
{

}
void DettagliSensore::pulisciDettagli()
{
    
}