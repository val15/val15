/*#include <QApplication>
#include <QWidget>
#include <QPushButton>*/
#include <QtGui>
#include "Fenetre0.h"
/*
  il faut qu'il y ais au moins 3 evennement
  il faut que "df" et "bwm-ng" soient installer
 */
int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QApplication app(argc, argv);//on crée un objet de type QApplication pour pouvoir utiliser Qt
    MaFenetre fenetre;

    fenetre.show();
    return app.exec();
}

