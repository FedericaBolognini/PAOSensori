#include "sensoreacquadialog.h"

sensoreAcquaDialog::sensoreAcquaDialog(QWidget *parent, action act, SensoreAcqua* sensore)
    : sensoreDialog(parent)
{
    setupCommon(mainL,act,sensore);
    QHBoxLayout *minAlcalinitàLayout = new QHBoxLayout;
    QHBoxLayout *maxAlcalinitàLayout = new QHBoxLayout;
    QHBoxLayout *minAciditàLayout = new QHBoxLayout;
    QHBoxLayout *maxAciditàLayout = new QHBoxLayout;
    QFont font;
    font.setBold(true);


    minAlcalinità = new QDoubleSpinBox(this);
    maxAlcalinità = new QDoubleSpinBox(this);

    minAcidità = new QDoubleSpinBox(this);
    maxAcidità = new QDoubleSpinBox(this);

    if (act != add)
    {
        minAlcalinità->setValue(sensore->getMinValidAlcalinità());
        maxAlcalinità->setValue(sensore->getMaxValidAlcalinità());
        minAcidità->setValue(sensore->getMinValidAcidità());
        maxAcidità->setValue(sensore->getMaxValidAcidità());
    }


    minAlcalinità->setFixedWidth(150);
    minAlcalinità->setMinimum(0.01);
    minAlcalinità->setAlignment(Qt::AlignCenter);

    maxAlcalinità->setFixedWidth(150);
    maxAlcalinità->setMinimum(0.01);
    maxAlcalinità->setAlignment(Qt::AlignCenter);

    minAcidità->setFixedWidth(150);
    minAcidità->setMinimum(0.01);
    minAcidità->setAlignment(Qt::AlignCenter);

    maxAcidità->setFixedWidth(150);
    maxAcidità->setMinimum(0.01);
    maxAcidità->setAlignment(Qt::AlignCenter);


    QLabel* minAlcalinitàLabel = new QLabel(QString("Alcalinità minima valida: "), this);
    minAlcalinitàLabel->setFixedWidth(150);
    minAlcalinitàLabel->setFont(font);

    QLabel* maxAlcalinitàLabel = new QLabel(QString("Alcalinità massima valida: "), this);
    maxAlcalinitàLabel->setFixedWidth(150);
    maxAlcalinitàLabel->setFont(font);

    QLabel* minAciditàLabel = new QLabel(QString("Acidità minima valida: "), this);
    minAciditàLabel->setFixedWidth(150);
    minAciditàLabel->setFont(font);

    QLabel* maxAciditàLabel = new QLabel(QString("Acidità massima valida: "), this);
    maxAciditàLabel->setFixedWidth(150);
    maxAciditàLabel->setFont(font);

    addToLayout(maxAciditàLayout,maxAciditàLabel,maxAcidità);

    this->setFixedSize(327,200);

    mainL->addLayout(minAlcalinitàLayout);
    mainL->addLayout(maxAlcalinitàLayout);
    mainL->addLayout(minAciditàLayout);
    mainL->addLayout(maxAciditàLayout);
    addButtons();
}

dialogValues sensoreAcquaDialog::getValues(QWidget *parent, bool *ok, action act, SensoreAcqua *sensore)
{
    sensoreAcquaDialog *dialog = new sensoreAcquaDialog(parent,act,sensore);

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    QString name;
    double precision;
    double minTemperatura;
    double maxTemperatura;
    double minAlcalinità;
    double maxAlcalinità;
    double minAcidità;
    double maxAcidità;
    if (ret) {
        name = dialog->nome->text();
        precision = dialog->precisione->value();
        minTemperatura = dialog->minTemperatura->value();
        maxTemperatura = dialog->maxTemperatura->value();
        minAlcalinità= dialog->minAlcalinità->value();
        maxAlcalinità = dialog->maxAlcalinità->value();
        minAcidità = dialog->minAcidità->value();
        maxAcidità = dialog->maxAcidità->value();
    }
    else
        throw std::runtime_error("Operazione annullata!");
    dialog->deleteLater();
    return dialogValues("",name, precision,minTemperatura,maxTemperatura,minAlcalinità,maxAlcalinità,minAcidità,maxAcidità);
}
