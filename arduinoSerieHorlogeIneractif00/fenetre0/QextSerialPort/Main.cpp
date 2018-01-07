/*#include <QApplication>
#include <QWidget>
#include <QPushButton>*/
#include <QtGui>
#include "Fenetre0.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);//on crée un objet de type QApplication pour pouvoir utiliser Qt
    MaFenetre fenetre(170,300);
    //MaFenetre fenetre2;
    fenetre.show();
    //fenetre2.show();
    return app.exec();
}

