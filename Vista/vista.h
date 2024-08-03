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

class Vista:public QWidget{
    Q_OBJECT

public:
    explicit Vista(QWidget *parent=nullptr);

virtual ~Vista();
signals:
private:
QMenuBar * addMenus();
void addMenus(QVBoxLayout *mainLayout);
};

#endif // VISTA_H
