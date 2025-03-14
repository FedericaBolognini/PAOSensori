QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Controller/xmlfilehandler.cpp \
    ../Modello/Sensore.cpp \
    ../Modello/SensoreAcqua.cpp \
    ../Modello/SensoreAria.cpp \
    ../Modello/SensoreSuolo.cpp \
    ../Modello/SensoreCreator.cpp \
    ../Modello/CollezioneSensori.cpp \
    ../Modello/Modello.cpp \
    ../Controller/controller.cpp \
    ../Modello/sensoresimulator.cpp \
    ../dialogvalues.cpp \
    ../main.cpp \
    finestrasensore.cpp \
    finestratipo.cpp \
    sensoreacquadialog.cpp \
    sensoreariadialog.cpp \
    sensoresuolodialog.cpp \
    sensoredialog.cpp \
    vista.cpp \
    tabellaSensori.cpp \
    dettagliSensore.cpp

HEADERS += \
    ../Controller/xmlfilehandler.h \
    ../Modello/Sensore.h \
    ../Modello/SensoreAcqua.h \
    ../Modello/SensoreAria.h \
    ../Modello/SensoreSuolo.h \
    ../Modello/SensoreCreator.h \
    ../Modello/CollezioneSensori.h \
    ../Modello/Modello.h \
    ../Controller/controller.h \
    ../Modello/sensoresimulator.h \
    ../action.h \
    ../dialogvalues.h \
    finestrasensore.h \
    finestratipo.h \
    sensoreacquadialog.h \
    sensoreariadialog.h \
    sensoresuolodialog.h \
    sensoredialog.h \
    vista.h \
    tabellaSensori.h \
    dettagliSensore.h



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
