#include "sensoresuolodialog.h"

sensoreSuoloDialog::sensoreSuoloDialog(QWidget *parent, action act, sensoreSuolo* sensore)
    : sensoreDialog(parent)
{
    setupCommon(mainL,act,sensore);
    QHBoxLayout *minUmiditàLayout = new QHBoxLayout;
    QHBoxLayout *maxUmiditàLayout = new QHBoxLayout;
    QHBoxLayout *minPHLayout = new QHBoxLayout;
    QHBoxLayout *maxPHLayout = new QHBoxLayout;
    QFont font;
    font.setBold(true);


    minUmidità = new QDoubleSpinBox(this);
    maxUmidità = new QDoubleSpinBox(this);

    minPH = new QDoubleSpinBox(this);
    maxPH = new QDoubleSpinBox(this);

    if (act != add)
    {
        minUmidità->setValue(sensore->getMinValidUmidità());
        maxUmidità->setValue(sensore->getMaxValidUmidità());
        minPH->setValue(sensore->getMinValidPH());
        maxPH->setValue(sensore->getMaxValidPH());
    }


    minUmidità->setFixedWidth(150);
    minUmidità->setMinimum(0.01);
    minUmidità->setAlignment(Qt::AlignCenter);

    maxUmidità->setFixedWidth(150);
    maxUmidità->setMinimum(0.01);
    maxUmidità->setAlignment(Qt::AlignCenter);

    minPH->setFixedWidth(150);
    minPH->setMinimum(0.01);
    minPH->setAlignment(Qt::AlignCenter);

    maxPH->setFixedWidth(150);
    maxPH->setMinimum(0.01);
    maxPH->setAlignment(Qt::AlignCenter);


    QLabel* minUmiditàLabel = new QLabel(QString("Umidità minima valida: "), this);
    minUmiditàLabel->setFixedWidth(150);
    minUmiditàLabel->setFont(font);

    QLabel* maxUmiditàLabel = new QLabel(QString("Umidità massima valida: "), this);
    maxUmiditàLabel->setFixedWidth(150);
    maxUmiditàLabel->setFont(font);

    QLabel* minPHLabel = new QLabel(QString("PH minimo valido: "), this);
    minPHLabel->setFixedWidth(150);
    minPHLabel->setFont(font);

    QLabel* maxPHLabel = new QLabel(QString("PH massimo valido: "), this);
    maxPHLabel->setFixedWidth(150);
    maxPHLabel->setFont(font);

    addToLayout(minUmiditàLayout,minUmiditàLabel,minUmidità);
    addToLayout(maxUmiditàLayout,maxUmiditàLabel,maxUmidità);
    addToLayout(minPHLayout,minPHLabel,minPH);
    addToLayout(maxPHLayout,maxPHLabel,maxPH);

    this->setFixedSize(327,200);

    mainL->addLayout(minUmiditàLayout);
    mainL->addLayout(maxUmiditàLayout);
    mainL->addLayout(minPHLayout);
    mainL->addLayout(maxPHLayout);
    addButtons();
}

dialogValues sensoreSuoloDialog::getValues(QWidget *parent, bool *ok, action act, sensoreSuolo *sensore)
{
    sensoreSuoloDialog *dialog = new sensoreSuoloDialog(parent,act,sensore);

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    QString name;
    double precision;
    double minTemperatura;
    double maxTemperatura;
    double minUmidità;
    double maxUmidità;
    double minPH;
    double maxPH;
    if (ret) {
        name = dialog->nome->text();
        precision = dialog->precisione->value();
        minTemperatura = dialog->minTemperatura->value();
        maxTemperatura = dialog->maxTemperatura->value();
        minUmidità= dialog->minUmidità->value();
        maxUmidità = dialog->maxUmidità->value();
        minPH = dialog->minPH->value();
        maxPH = dialog->maxPH->value();
    }
    else
        throw std::runtime_error("Operazione annullata!");
    dialog->deleteLater();
    return dialogValues("",name, precision,minTemperatura,maxTemperatura,minUmidità,maxUmidità,minPH,maxPH);
}
