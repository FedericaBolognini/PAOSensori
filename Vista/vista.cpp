#include "vista.h"

void Vista::addMenus(QVBoxLayout *mainLayout)
{
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *file= new QMenu("File",menuBar);
    menuBar->addMenu(file);
    file->addAction(new QAction("Salva",file));
    file->addAction(new QAction("Ripristina",file));
    file->addAction(new QAction("Chiudi",file));
    mainLayout->addWidget(menuBar);
}

Vista::Vista(QWidget *parent):QWidget(parent) {
    QVBoxLayout *mainLayout =new QVBoxLayout;

    addMenus(mainLayout);


    QHBoxLayout *horizontalmainLayout =new QHBoxLayout;

    QVBoxLayout *leftLayout= new QVBoxLayout;
    leftLayout->setContentsMargins(10,5,10,5);

    QLineEdit *searchBar= new QLineEdit();
    searchBar->setPlaceholderText("Cerca sensori...");
    QPushButton *searchButton= new QPushButton("Cerca");

    QTableWidget *tableWidget= new QTableWidget(3,5,this);
    tableWidget->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Tipo"<<"ID"<<"Precisione"<<"Qualità");
    //tableWidget->setVerticalHeaderLabels(QStringList()<<"Sensore Acqua"<<"Sensore Aria"<<"Sensore Suolo");//?
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QHBoxLayout *bottomButtonLayout= new QHBoxLayout();
    QPushButton *bottomButtonElimina= new QPushButton ("Elimina");
    bottomButtonElimina->setStyleSheet("background-color:red");
    QPushButton *bottomButtonModifica= new QPushButton ("Modifica");
    bottomButtonModifica->setStyleSheet("background-color:orange");
    QPushButton *bottomButtonAggiungi= new QPushButton ("Aggiungi");
    bottomButtonAggiungi->setStyleSheet("background-color:green");
    bottomButtonLayout->addWidget(bottomButtonElimina);
    bottomButtonLayout->addWidget(bottomButtonModifica);
    bottomButtonLayout->addWidget(bottomButtonAggiungi);
    bottomButtonLayout->setSpacing(10);
    bottomButtonLayout->setContentsMargins(0,5,0,5);

    leftLayout->addWidget(searchBar);
    leftLayout->addWidget(searchButton);
    leftLayout->addWidget(tableWidget,0,Qt::AlignBottom);
    leftLayout->addLayout(bottomButtonLayout);

    QVBoxLayout *rightLayout= new QVBoxLayout;
    rightLayout->setContentsMargins(10,5,10,5);
    QLabel *details= new QLabel("Dettagli sensore:",this);
    rightLayout->addWidget(details);
    QHBoxLayout *detailsLayout= new QHBoxLayout;
    QVBoxLayout *leftdetailsLayout= new QVBoxLayout;
    QVBoxLayout *rightdetailsLayout= new QVBoxLayout;
    detailsLayout->setSpacing(10);

    QLabel *nome= new QLabel("Nome:",this);
    leftdetailsLayout->addWidget(nome);
    QLabel *tipo= new QLabel("Tipo:",this);
    leftdetailsLayout->addWidget(tipo);
    QLabel *id= new QLabel("ID:",this);
    leftdetailsLayout->addWidget(id);
    QLabel *precisione= new QLabel("Precisione:",this);
    rightdetailsLayout->addWidget(precisione);
    QLabel *mintemperatura= new QLabel("Temperatura minima:",this);
    rightdetailsLayout->addWidget(mintemperatura);
    QLabel *maxtemperatura= new QLabel("Temperatura massima:",this);
    rightdetailsLayout->addWidget(maxtemperatura);
    QLabel *qualità= new QLabel("Qualità:",this);
    rightdetailsLayout->addWidget(qualità);

    detailsLayout->addLayout(leftdetailsLayout);
    detailsLayout->addLayout(rightdetailsLayout);


    QPushButton *simula= new QPushButton("Simula",this);

    QLineSeries *series= new QLineSeries(this);
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
    QChart *chart= new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple Line Chart");

    QChartView* chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    rightLayout->addLayout(detailsLayout);
    rightLayout->addWidget(simula,0,Qt::AlignRight);
    rightLayout->addWidget(chartView);


    horizontalmainLayout->addLayout(leftLayout);
    horizontalmainLayout->addLayout(rightLayout);
    horizontalmainLayout->setStretch(0,1);
    horizontalmainLayout->setStretch(1,1);

    mainLayout->addLayout(horizontalmainLayout);
    mainLayout->setSpacing(0);

    setLayout(mainLayout);

}
Vista::~Vista() {};
