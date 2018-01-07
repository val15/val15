SOURCES += \
    Main.cpp \
    Fenetre0.cpp \
    fenetregererCalendrier.cpp \
    evenement.cpp \
    Arduino.cpp \
    ap.cpp \
    Serveur.cpp

HEADERS += \
    Fenetre0.h \
    fenetregererCalendrier.h \
    evenement.h \
    Arduino.h \
    ap.h \
    Serveur.h
QT += sql \
     network

include(/home/pi/workspace/c++/Qt/rbpQt/arduinoSerieHorlogeIneractifWifii/fenetre0/qextserialport-master/src/qextserialport.pri)
