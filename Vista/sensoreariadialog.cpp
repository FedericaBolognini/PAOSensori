#include "sensoreariadialog.h"

sensoreAriaDialog::sensoreAriaDialog(QWidget *parent, action act, SensoreAria* sensore)
    : sensoreDialog(parent)
{
    setupCommon(mainL,act,sensore);
    QHBoxLayout *minCO2Layout = new QHBoxLayout;
    QHBoxLayout *maxCO2Layout = new QHBoxLayout;
    QHBoxLayout *minOssigenoLayout = new QHBoxLayout;
    QHBoxLayout *maxOssigenoLayout = new QHBoxLayout;
    QFont font;
    font.setBold(true);


    minCO2 = new QDoubleSpinBox(this);
    maxCO2 = new QDoubleSpinBox(this);

    minOssigeno = new QDoubleSpinBox(this);
    maxOssigeno = new QDoubleSpinBox(this);


    minCO2->setFixedWidth(165);
    minCO2->setMinimum(0.00);
    minCO2->setMaximum(1000.00);
    minCO2->setAlignment(Qt::AlignCenter);

    maxCO2->setFixedWidth(165);
    maxCO2->setMinimum(0.00);
    maxCO2->setMaximum(1000.00);
    maxCO2->setAlignment(Qt::AlignCenter);

    minOssigeno->setFixedWidth(165);
    minOssigeno->setMinimum(0.00);
    minOssigeno->setMaximum(1000.00);
    minOssigeno->setAlignment(Qt::AlignCenter);

    maxOssigeno->setFixedWidth(165);
    maxOssigeno->setMinimum(0.00);
    maxOssigeno->setMaximum(1000.00);
    maxOssigeno->setAlignment(Qt::AlignCenter);

    if (act != add)
    {
        minCO2->setValue(sensore->getMinValidCO2());
        maxCO2->setValue(sensore->getMaxValidCO2());
        minOssigeno->setValue(sensore->getMinValidOssigeno());
        maxOssigeno->setValue(sensore->getMaxValidOssigeno());
    }


    QLabel* minCO2Label = new QLabel(QString("CO2 minimo valido: "), this);
    minCO2Label->setFixedWidth(250);
    minCO2Label->setFont(font);

    QLabel* maxCO2Label = new QLabel(QString("CO2 massimo valido: "), this);
    maxCO2Label->setFixedWidth(250);
    maxCO2Label->setFont(font);

    QLabel* minOssigenoLabel = new QLabel(QString("Ossigeno minimo valido: "), this);
    minOssigenoLabel->setFixedWidth(250);
    minOssigenoLabel->setFont(font);

    QLabel* maxOssigenoLabel = new QLabel(QString("Ossigeno massimo valido: "), this);
    maxOssigenoLabel->setFixedWidth(250);
    maxOssigenoLabel->setFont(font);

    addToLayout(minCO2Layout,minCO2Label,minCO2);
    addToLayout(maxCO2Layout,maxCO2Label,maxCO2);
    addToLayout(minOssigenoLayout,minOssigenoLabel,minOssigeno);
    addToLayout(maxOssigenoLayout,maxOssigenoLabel,maxOssigeno);

    this->setFixedSize(600,300);

    mainL->addLayout(minCO2Layout);
    mainL->addLayout(maxCO2Layout);
    mainL->addLayout(minOssigenoLayout);
    mainL->addLayout(maxOssigenoLayout);
    addButtons();
}

dialogValues sensoreAriaDialog::getValues(QWidget *parent, bool *ok, action act, SensoreAria *sensore)
{
    sensoreAriaDialog *dialog = new sensoreAriaDialog(parent,act,sensore);

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    QString name;
    double precision;
    double minTemperatura;
    double maxTemperatura;
    double minCO2;
    double maxCO2;
    double minOssigeno;
    double maxOssigeno;
    if (ret) {
        name = dialog->nome->text();
        precision = dialog->precisione->value();
        minTemperatura = dialog->minTemperatura->value();
        maxTemperatura = dialog->maxTemperatura->value();
        minCO2= dialog->minCO2->value();
        maxCO2 = dialog->maxCO2->value();
        minOssigeno = dialog->minOssigeno->value();
        maxOssigeno = dialog->maxOssigeno->value();
    }
    else
        throw std::runtime_error("Operazione annullata!");
    dialog->deleteLater();
    return dialogValues("Aria",name, precision,minTemperatura,maxTemperatura,minCO2,maxCO2,minOssigeno,maxOssigeno);
}
