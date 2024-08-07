#include "sensoreariadialog.h"

sensoreAriaDialog::sensoreAriaDialog(QWidget *parent, action act, sensoreAria* sensore)
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

    if (act != add)
    {
        minCO2->setValue(sensore->getMinCO2());
        maxCO2->setValue(sensore->getMaxValidCO2());
        minOssigeno->setValue(sensore->getMinValidOssigeno());
        maxOssigeno->setValue(sensore->getMaxValidOssigeno());
    }


    minCO2->setFixedWidth(150);
    minCO2->setMinimum(0.01);
    minCO2->setAlignment(Qt::AlignCenter);

    maxCO2->setFixedWidth(150);
    maxCO2->setMinimum(0.01);
    maxCO2->setAlignment(Qt::AlignCenter);

    minOssigeno->setFixedWidth(150);
    minOssigeno->setMinimum(0.01);
    minOssigeno->setAlignment(Qt::AlignCenter);

    maxOssigeno->setFixedWidth(150);
    maxOssigeno->setMinimum(0.01);
    maxOssigeno->setAlignment(Qt::AlignCenter);


    QLabel* minCO2Label = new QLabel(QString("CO2 minimo valido: "), this);
    minCO2Label->setFixedWidth(150);
    minCO2Label->setFont(font);

    QLabel* maxCO2Label = new QLabel(QString("CO2 massimo valido: "), this);
    maxCO2Label->setFixedWidth(150);
    maxCO2Label->setFont(font);

    QLabel* minOssigenoLabel = new QLabel(QString("Ossigeno minimo valido: "), this);
    minOssigenoLabel->setFixedWidth(150);
    minOssigenoLabel->setFont(font);

    QLabel* maxOssigenoLabel = new QLabel(QString("Ossigeno massimo valido: "), this);
    maxOssigenoLabel->setFixedWidth(150);
    maxOssigenoLabel->setFont(font);

    addToLayout(minCO2Layout,minCO2Label,minCO2);
    addToLayout(maxCO2Layout,maxCO2Label,maxCO2);
    addToLayout(minOssigenoLayout,minOssigenoLabel,minOssigeno);
    addToLayout(maxOssigenoLayout,maxOssigenoLabel,maxOssigeno);

    this->setFixedSize(327,200);

    mainL->addLayout(minCO2Layout);
    mainL->addLayout(maxCO2Layout);
    mainL->addLayout(minOssigenoLayout);
    mainL->addLayout(maxOssigenoLayout);
    addButtons();
}

dialogValues sensoreAriaDialog::getValues(QWidget *parent, bool *ok, action act, sensoreAria *sensore)
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
    return dialogValues("",name, precision,minTemperatura,maxTemperatura,minCO2,maxCO2,minOssigeno,maxOssigeno);
}
