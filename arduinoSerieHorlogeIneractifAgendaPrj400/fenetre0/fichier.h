/*
 Auteur : val15
 Date De Creation : 10/12/15

Role :
cette classe servirar pour manipuler les fichiers

 */


#ifndef FICHIER_H
#define FICHIER_H

#include <QFile>       // Pour utiliser le fichier
#include <QStringList>
#include <QString>     // Stocke le contenu du fichier
#include <QTextStream> // Flux sortant du fichier
#include <QInputDialog>
#include <QMessageBox>

class Fichier
{
public :
    Fichier();
    Fichier(QString nom);
    QString litreToutLeFichier();
    QString lireUneLigne(int numLigne);
    void creationDUFichierEtEcritureALInterieu();
    void ecrire(QString texte);
    void ecrireAlLaFin(QString texte);
    void ecrireAlLaFinAvecUnALaLigneAvant(QString texte);
    void copier(QString nomCopie);
    void remomer(QString nouveauNom);
    bool siExiste();
    void supprimer();
    int getTailler();


protected:


private:
    QString m_nom;
    QFile *m_file;
    QStringList m_lstContenu;


};

#endif //FICHIER_H
