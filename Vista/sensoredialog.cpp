#include "sensoredialog.h"

void sensoreDialog::addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2)
{
    layout->addWidget(w1);
    layout->addWidget(w2);
}

void sensoreDialog::setupCommon(QBoxLayout* layout, action act, Sensore* sensore)
{
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QHBoxLayout *precisioneLayout = new QHBoxLayout;
    QHBoxLayout *minTemperaturaLayout = new QHBoxLayout;
    QHBoxLayout *maxTemperaturaLayout  = new QHBoxLayout;
    QFont font;
    font.setBold(true);

    QLabel* nameLabel = new QLabel(QString("Nome"), this);
    QLabel* precisionLabel = new QLabel(QString("Precisione"), this);
    QLabel* minValidTempLabel = new QLabel(QString("Temperatura minima valida"), this);
    QLabel* maxValidTempLabel  = new QLabel(QString("Temperatura massima valida"), this);

    precisione = new QDoubleSpinBox(this);
    minTemperatura = new QDoubleSpinBox(this);
    maxTemperatura = new QDoubleSpinBox(this);

    if (act == add)
    {
        nome = new QLineEdit(QString("Nome Sensore"), this);
    }
    else
    {
        if (!sensore)
            throw std::runtime_error("Sensore non valido!");
        int sensorePrecisione = sensore->getPrecisione();
        int minTemp = sensore->getMinValidTemperatura();
        int maxTemp = sensore->getMaxValidTemperatura();

        QString nomeSensore= QString::fromStdString(sensore->getNome());

        nome = new QLineEdit(nomeSensore, this);

        precisione->setValue(sensorePrecisione);
        minTemperatura->setValue(minTemp);
        maxTemperatura->setValue(maxTemp);

    }

    nameLabel->setFont(font);
    nome->setFixedWidth(150);
    nome->setAlignment(Qt::AlignCenter);

    addToLayout(nameLayout,nameLabel,nome);
    addToLayout(precisioneLayout,precisionLabel,precisione);
    addToLayout(minTemperaturaLayout,minValidTempLabel,minTemperatura);
    addToLayout(maxTemperaturaLayout,maxValidTempLabel,maxTemperatura);

    layout->addLayout(nameLayout);
    layout->addLayout(precisioneLayout);
    layout->addLayout(minTemperaturaLayout);
    layout->addLayout(maxTemperaturaLayout);
}

void sensoreDialog::addButtons()
{
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                           | QDialogButtonBox::Close,this);

    buttonsLayout->addWidget(buttonBox);
    mainL->addLayout(buttonsLayout);

    connect(buttonBox, &QDialogButtonBox::accepted,
            this, &sensoreDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected,
            this, &sensoreDialog::reject);

}

sensoreDialog::sensoreDialog(QWidget *parent) : QDialog(parent)
{
    mainL = new QVBoxLayout;
    setLayout(mainL);
}

