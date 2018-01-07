#include "Fichier.h"

Fichier::Fichier()
{

}

Fichier::Fichier(QString nom)
{
    m_nom=nom;
    m_file=new QFile(m_nom);

}

QString Fichier::litreToutLeFichier()
{
    QString contenu;

    if(m_file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
         contenu = m_file->readAll();
         m_file->close();
    }
    else
        contenu = "Impossible d'ouvrir le fichier !";
    return contenu;
}


QString Fichier::lireUneLigne(int numLigne)
{
    if(m_file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream flux(m_file);
            while(!flux.atEnd())
                m_lstContenu.append(flux.readLine());


        m_file->close();
    }

    return m_lstContenu.at(numLigne+1);

}

void Fichier::creationDUFichierEtEcritureALInterieu()
{
    QString chemin, texte;

        while((chemin = QInputDialog::getText(NULL,"Fichier","Quel est le chemin du fichier ?")).isEmpty())
            QMessageBox::critical(NULL,"Erreur","Aucun chemin n'a t spcifi !");

        while((texte = QInputDialog::getText(NULL, "Texte", "Que voulez-vous crire dans "+chemin.toLatin1())).isEmpty())
            QMessageBox::critical(NULL,"Erreur","Aucun texte n'a t spcifi !");

        QFile fichier(chemin);
        fichier.open(QIODevice::WriteOnly | QIODevice::Text);

        QTextStream flux(&fichier);
        flux << texte;

        fichier.close();
}

void Fichier::ecrire(QString texte)
{
    m_file->open(QIODevice::WriteOnly | QIODevice::Text);
    m_file->write(texte.toLatin1(),texte.size());
    m_file->close();
}


void Fichier::ecrireAlLaFin(QString texte)
{
    QString txt;
    txt+=this->litreToutLeFichier();
    txt+=texte;

    m_file->open(QIODevice::WriteOnly | QIODevice::Text);
    m_file->write(txt.toLatin1(),txt.size());
    m_file->close();
}

void Fichier::ecrireAlLaFinAvecUnALaLigneAvant(QString texte)
{
    QString txt;
    txt+=this->litreToutLeFichier();
    txt+="\n";
    txt+=texte;

    m_file->open(QIODevice::WriteOnly | QIODevice::Text);
    m_file->write(txt.toLatin1(),txt.size());
    m_file->close();
}

void Fichier::copier(QString nomCopie)
{

    if(!m_file->copy(nomCopie))
        QMessageBox::critical(NULL,"Erreur","Impossible de copier poeme.txt");

}

bool Fichier::siExiste()
{
    return m_file->exists();

}

void Fichier::supprimer()
{
    if(this->siExiste())
        m_file->remove();
}

void Fichier::remomer(QString nouveauNom)
{
    if(!m_file->rename(nouveauNom))
        QMessageBox::critical(NULL,"Erreur","Impossible de renommer le fichier !");

}

int Fichier::getTailler()
{
    return m_file->size();
}



