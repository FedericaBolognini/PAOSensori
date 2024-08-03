#include "vista.h"

void Vista::addMenus(QVBoxLayout *mainLayout)
{
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *file = new QMenu("File", menuBar);
    menuBar->addMenu(file);
    file->addAction(new QAction("Salva", file));
    file->addAction(new QAction("Ripristina", file));
    file->addAction(new QAction("Chiudi", file));
    mainLayout->addWidget(menuBar);
}

void Vista::addFindSection(QVBoxLayout *layout)
{
    QLineEdit *searchBar = new QLineEdit(this);
    searchBar->setPlaceholderText("Cerca sensori...");
    QPushButton *searchButton = new QPushButton("Cerca", this);

    layout->addWidget(searchBar);
    layout->addWidget(searchButton);
}

void Vista::addTable(QVBoxLayout *layout)
{
    QTableWidget *tableWidget = new QTableWidget(3, 5, this);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Nome" << "Tipo" << "ID" << "Precisione" << "Qualità");
    // tableWidget->setVerticalHeaderLabels(QStringList()<<"Sensore Acqua"<<"Sensore Aria"<<"Sensore Suolo");//?
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout->addWidget(tableWidget, 0, Qt::AlignBottom);
}

void Vista::addButtons(QHBoxLayout* layout){
    QPushButton *bottomButtonElimina = new QPushButton("Elimina", this);
    bottomButtonElimina->setStyleSheet("background-color:red");
    QPushButton *bottomButtonModifica = new QPushButton("Modifica", this);
    bottomButtonModifica->setStyleSheet("background-color:orange");
    QPushButton *bottomButtonAggiungi = new QPushButton("Aggiungi", this);
    bottomButtonAggiungi->setStyleSheet("background-color:green");

    layout->addWidget(bottomButtonElimina);
    layout->addWidget(bottomButtonModifica);
    layout->addWidget(bottomButtonAggiungi);
    layout->setSpacing(10);
    layout->setContentsMargins(0, 5, 0, 5);
}

void Vista::addLeftLabels(QVBoxLayout* layout){
    QLabel *nome = new QLabel("Nome:", this);
    layout->addWidget(nome);
    QLabel *tipo = new QLabel("Tipo:", this);
    layout->addWidget(tipo);
    QLabel *id = new QLabel("ID:", this);
    layout->addWidget(id);
}

void Vista::addRightLabels(QVBoxLayout* layout){
    QLabel *precisione = new QLabel("Precisione:", this);
    layout->addWidget(precisione);
    QLabel *mintemperatura = new QLabel("Temperatura minima:", this);
    layout->addWidget(mintemperatura);
    QLabel *maxtemperatura = new QLabel("Temperatura massima:", this);
    layout->addWidget(maxtemperatura);
    QLabel *qualità = new QLabel("Qualità:", this);
    layout->addWidget(qualità);
}

void Vista::addChart(QVBoxLayout* layout){
    QLineSeries *series = new QLineSeries(this);
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple Line Chart");

    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(chartView);
}

Vista::Vista(QWidget *parent) : QWidget(parent)
{

    // Creazione layout principale
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Aggiunta menù
    addMenus(mainLayout);

    // Creazione layout orizzontale principale
    QHBoxLayout *horizontalmainLayout = new QHBoxLayout;

    // Creazione layout della metà sinistra di UI
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->setContentsMargins(10, 5, 10, 5);

    // Aggiunta sezione di widget di ricerca sensori
    addFindSection(leftLayout);

    // Aggiunta tabella
    addTable(leftLayout);

    // Creazione layout bottoni
    QHBoxLayout *bottomButtonLayout = new QHBoxLayout();

    // Aggiunta bottoni
    addButtons(bottomButtonLayout);

    // Aggiunta layout bottoni al layout di sinistra
    leftLayout->addLayout(bottomButtonLayout);

    // Creazione layout di destra
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->setContentsMargins(10, 5, 10, 5);

    // Aggiunta label di intestazione
    QLabel *details = new QLabel("Dettagli sensore:", this);
    rightLayout->addWidget(details);

    // Creazione layout dei dettagli (e sottolayouts)
    QHBoxLayout *detailsLayout = new QHBoxLayout;
    QVBoxLayout *leftdetailsLayout = new QVBoxLayout;
    QVBoxLayout *rightdetailsLayout = new QVBoxLayout;
    detailsLayout->setSpacing(10);

    // Aggiunta labels e relativi layouts
    addLeftLabels(leftdetailsLayout);
    addRightLabels(rightdetailsLayout);

    detailsLayout->addLayout(leftdetailsLayout);
    detailsLayout->addLayout(rightdetailsLayout);

    rightLayout->addLayout(detailsLayout);

    // Aggiunta bottone di simulazione dati
    QPushButton *simula = new QPushButton("Simula", this);
    rightLayout->addWidget(simula, 0, Qt::AlignRight);

    // Aggiunta grafico
    addChart(rightLayout);

    // Aggiunta layout sinistro e destro al principale
    horizontalmainLayout->addLayout(leftLayout);
    horizontalmainLayout->addLayout(rightLayout);
    horizontalmainLayout->setStretch(0, 1);
    horizontalmainLayout->setStretch(1, 1);

    mainLayout->addLayout(horizontalmainLayout);
    mainLayout->setSpacing(0);

    setLayout(mainLayout);
}
Vista::~Vista() {};
