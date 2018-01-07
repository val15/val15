#include <QApplication>
#include <QtGui>
#include "FenetrePrincipale.h"


int main(int argc, char *argv[])
{
    /*pour que le serveur we affiche le medi, il faut que l chemin suit par rapport au repertoir local*/
    /*il faut donc un lien symbolique qui pointe ver le docier cyble dans me repertoire de la page*/
    QApplication app(argc, argv);
    FenetrePrincipale fenetre;
    fenetre.show();
   // fenetre.setWindowIcon(QIcon("/home/val15/valPod/images"));
    return app.exec();
}

