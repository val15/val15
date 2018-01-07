QT += widgets
QT += network
QT += sql


SOURCES += \
    Main.cpp \
    Fenetre0.cpp \
    fenetregererCalendrier.cpp \
    evenement.cpp \
    Arduino.cpp \
    Serveur.cpp \
    fichier.cpp \
    maclandrier.cpp \
    rdv.cpp \
    serveurandroid.cpp

HEADERS += \
    Fenetre0.h \
    fenetregererCalendrier.h \
    evenement.h \
    Arduino.h \
    Serveur.h \
    fichier.h \
    maclandrier.h \
    rdv.h \
    serveurandroid.h


include(/home/pi/workspace/c++/Qt/rbpQt/arduinoSerieHorlogeIneractifServeur5is-iesi/fenetre0/qextserialport-master/src/qextserialport.pri)
