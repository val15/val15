SOURCES += \
    Main.cpp \
    Fenetre0.cpp \
    Trajet.cpp \
    Fichier.cpp \
    Serveur.cpp

HEADERS += \
    Fenetre0.h \
    Trajet.h \
    Fichier.h \
    Serveur.h
QT += sql \
     network

include(/home/pi/workspace/c++/Qt/rbpQt/andao/fenetre0/qextserialport-1.2rc/src/qextserialport.pri)
