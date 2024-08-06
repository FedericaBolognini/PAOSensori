#include "finestratipo.h"

finestraTipo::finestraTipo(QWidget* parent): QDialog(parent)
{
    QVBoxLayout *mainL = new QVBoxLayout;
    QHBoxLayout *typeLayout = new QHBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QFont font;
    font.setBold(true);

    setFixedSize(250,90);

    typeBox = new QComboBox(this);
    typeBox->setFixedSize(100,25);

    typeBox->addItem(QString("Acqua"));
    typeBox->addItem(QString("Aria"));
    typeBox->addItem(QString("Suolo"));

    QLabel* type = new QLabel(QString("Tipo sensore"), this);
    type->setFont(font);
    typeLayout->addWidget(type);
    typeLayout->addWidget(typeBox);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                           | QDialogButtonBox::Close,this);

    buttonsLayout->addWidget(buttonBox);
    mainL->addLayout(typeLayout);
    mainL->addLayout(buttonsLayout);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &finestraTipo::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &finestraTipo::reject);


    setLayout(mainL);
}

QString finestraTipo::getTipo(QWidget *parent, bool *ok)
{
    finestraTipo *dialog = new finestraTipo(parent);
    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret)
        return (dialog->typeBox->currentText());
    else
        throw std::runtime_error("Nessun tipo scelto, operazione annullata!");
}
