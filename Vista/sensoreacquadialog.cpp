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

    minAlcalinità->setFixedWidth(165);
    minAlcalinità->setMinimum(0.00);
    minAlcalinità->setMaximum(1000.00);
    minAlcalinità->setAlignment(Qt::AlignCenter);

    maxAlcalinità->setFixedWidth(165);
    maxAlcalinità->setMinimum(0.00);
    maxAlcalinità->setMaximum(1000.00);
    maxAlcalinità->setAlignment(Qt::AlignCenter);

    minAcidità->setFixedWidth(165);
    minAcidità->setMinimum(0.00);
    minAcidità->setMaximum(1000.00);
    minAcidità->setAlignment(Qt::AlignCenter);

    maxAcidità->setFixedWidth(165);
    maxAcidità->setMinimum(0.00);
    maxAcidità->setMaximum(1000.00);
    maxAcidità->setAlignment(Qt::AlignCenter);

    if (act != add)
    {
        minAlcalinità->setValue(sensore->getMinValidAlcalinità());
        maxAlcalinità->setValue(sensore->getMaxValidAlcalinità());
        minAcidità->setValue(sensore->getMinValidAcidità());
        maxAcidità->setValue(sensore->getMaxValidAcidità());
    }

    QLabel* minAlcalinitàLabel = new QLabel(QString("Alcalinità minima valida: "), this);
    minAlcalinitàLabel->setFixedWidth(250);
    minAlcalinitàLabel->setFont(font);

    QLabel* maxAlcalinitàLabel = new QLabel(QString("Alcalinità massima valida: "), this);
    maxAlcalinitàLabel->setFixedWidth(250);
    maxAlcalinitàLabel->setFont(font);

    QLabel* minAciditàLabel = new QLabel(QString("Acidità minima valida: "), this);
    minAciditàLabel->setFixedWidth(250);
    minAciditàLabel->setFont(font);

    QLabel* maxAciditàLabel = new QLabel(QString("Acidità massima valida: "), this);
    maxAciditàLabel->setFixedWidth(250);
    maxAciditàLabel->setFont(font);

    addToLayout(minAlcalinitàLayout,minAlcalinitàLabel,minAlcalinità);
    addToLayout(maxAlcalinitàLayout,maxAlcalinitàLabel,maxAlcalinità);
    addToLayout(minAciditàLayout,minAciditàLabel,minAcidità);
    addToLayout(maxAciditàLayout,maxAciditàLabel,maxAcidità);

    this->setFixedSize(600,300);

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
    return dialogValues("Acqua",name, precision,minTemperatura,maxTemperatura,minAlcalinità,maxAlcalinità,minAcidità,maxAcidità);
}
