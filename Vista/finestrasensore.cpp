#include "finestrasensore.h"

finestraSensore::finestraSensore(QWidget* parent, const std::vector<Sensore *>* sensori): QDialog(parent)
{
    QVBoxLayout *mainL = new QVBoxLayout;
    QHBoxLayout *typeLayout = new QHBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QFont font;
    font.setBold(true);

    setFixedSize(350,90);

    sensoreBox = new QComboBox(this);
    sensoreBox->setFixedSize(200,25);

    for(Sensore* sensore: *sensori){
        QString etichettaSensore = QString::fromStdString(std::to_string(sensore->getID()) + " - " + sensore->getNome());
        sensoreBox->addItem(etichettaSensore);
    }

    QLabel* type = new QLabel(QString("Scegli il sensore"), this);
    type->setFont(font);
    typeLayout->addWidget(type);
    typeLayout->addWidget(sensoreBox);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                           | QDialogButtonBox::Close,this);

    buttonsLayout->addWidget(buttonBox);
    mainL->addLayout(typeLayout);
    mainL->addLayout(buttonsLayout);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &finestraSensore::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &finestraSensore::reject);


    setLayout(mainL);
}

QString finestraSensore::getSensore(QWidget *parent, const std::vector<Sensore *>* sensori, bool *ok)
{
    finestraSensore *dialog = new finestraSensore(parent, sensori);
    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret){
        QString risultato = dialog->sensoreBox->currentText();
        return risultato;
    }
    else
        throw std::runtime_error("Nessun tipo scelto, operazione annullata!");
}
