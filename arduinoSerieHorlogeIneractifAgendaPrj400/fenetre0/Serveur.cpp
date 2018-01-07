#include "Serveur.h"


Serveur::Serveur(int port)
{
    m_host="any";
    m_port=port;
    m_tailleMessage=0;
    m_unClientEstConnecT=false;

}

void Serveur::lancement()
{
    serveur = new QTcpServer();
        if (!serveur->listen(QHostAddress::Any, m_port)) // Dmarrage du serveur sur toutes les IP disponibles et sur le port 50585
        {
            // Si le serveur n'a pas t dmarr correctement
           qDebug() << "Le serveur n'a pas pu tre dmarr. Raison :<br />" + serveur->errorString();
        }
        else
        {
            // Si le serveur a t dmarr correctement
            qDebug() << "Le serveur a ete demarrer sur le port <strong>" + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter.");
            QObject::connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
        }
}

void Serveur::nouvelleConnexion()
{
    // QMessageBox::critical(0, QObject::tr("java"),"java");
      // envoyerATous(tr("<em>Un nouveau client vient de se connecter</em>"));
       qDebug() << "nouvelle connexion";
       QTcpSocket *nouveauClient = serveur->nextPendingConnection();
       client= nouveauClient;
       //nouveauClient->

       QObject::connect(nouveauClient, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
       QObject::connect(nouveauClient, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));
        m_unClientEstConnecT=true;
}
void Serveur::donneesRecues()
{

    // 1 : on reoit un paquet (ou un sous-paquet) d'un des clients

    // On dtermine quel client envoie le message (recherche du QTcpSocket du client)
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouv le client  l'origine du signal, on arrte la mthode
        return;

    // Si tout va bien, on continue : on rcupre le message
    QDataStream in(socket);

    if (m_tailleMessage == 0) // Si on ne connat pas encore la taille du message, on essaie de la rcuprer
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16)) // On n'a pas reu la taille du message en entier
             return;

        in >> m_tailleMessage; // Si on a reu la taille du message en entier, on la rcupre
    }

    // Si on connat la taille du message, on vrifie si on a reu le message en entier
    if (socket->bytesAvailable() < m_tailleMessage) // Si on n'a pas encore tout reu, on arrte la mthode
        return;


    // Si ces lignes s'excutent, c'est qu'on a reu tout le message : on peut le rcuprer !
    QString message;
    in >> message;


    // 2 : on renvoie le message  tous les clients


    // 3 : remise de la taille du message  0 pour permettre la rception des futurs messages
    m_tailleMessage = 0;

    qDebug() << "message recu : "  << message << endl;
    emmetreMessage(message);

}

void Serveur::deconnexionClient()
{
    qDebug() << QString::fromUtf8("Un client vient de se dconnecter");

    // On dtermine quel client se dconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouv le client  l'origine du signal, on arrte la mthode
        return;


    socket->deleteLater();
    emmetreDeconnecionClient();
    m_unClientEstConnecT=false;
}

void Serveur::envoyer(const QString &message)//doit etre à 64 bit
{
    QByteArray paquet;//pour stoker le paquet en envoiyer sur le rseau
    QDataStream out(&paquet, QIODevice::WriteOnly);//On utilise un QDataStream comme tout  l'heure pour crire dans le QByteArray facilementgr
    out << (quint32) 0; // On crit 0 au dbut du paquet pour rserver la place pour crire la taille
    out << message; // On ajoute le message  la suite
    out.device()->seek(0); // On se replace au dbut du paquet
    out << (quint32) (paquet.size() - sizeof(quint32)); // On crase le 0 qu'on avait rserv par la longueur du message:taille total- taille d'un int
    client->write(paquet);
}


bool Serveur::getUnCientConnecT()
{
    return m_unClientEstConnecT;
}



