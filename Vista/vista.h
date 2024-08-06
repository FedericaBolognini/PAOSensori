#ifndef VISTA_H
#define VISTA_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QLabel>
#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include <QPainter>
#include <QHeaderView>
#include <QSize>
#include <QMessageBox>
#include <tabellaSensori.h>
#include <dettagliSensore.h>

class Vista : public QWidget
{
    Q_OBJECT

public:
    explicit Vista(QWidget *parent = nullptr);

    /**
     * @brief showWarning:          mostra a video i messaggi di errore dell'applicazione
     * @param message:              messaggio di errore
     */
    void showWarning(const QString& message);

    virtual ~Vista();
signals:
private:

    // Barra dei menù
    QMenuBar *menuBar;

    // Menù dei file
    QMenu *file;

    // Layout principale
    QVBoxLayout *mainLayout;

    // Layout secondario
    QHBoxLayout *horizontalmainLayout;

    TabellaSensori *leftWidget;
    DettagliSensore *rightWidget;

    void addMenus(QVBoxLayout *mainLayout);
};

#endif // VISTA_H
