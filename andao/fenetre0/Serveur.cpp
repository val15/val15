#include "Serveur.h"


Serveur::Serveur(QString host,int port)
{
    m_host=host;
    m_port=port;

}

void Serveur::lancement()
{
    serveur = new QTcpServer();
        if (!serveur->listen(QHostAddress::Any, m_port)) // Dmarrage du serveur sur toutes les IP disponibles et sur le port 50585
        {
            // Si le serveur n'a pas t dmarr correctement
           emit emmetreMessage("Le serveur n'a pas pu tre dmarr. Raison :<br />" + serveur->errorString());
        }
        else
        {
            // Si le serveur a t dmarr correctement
            emit emmetreMessage("Le serveur a ete demarrer sur le port <strong>" + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter."));
            QObject::connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
        }
}

void Serveur::nouvelleConnexion()
{
    // QMessageBox::critical(0, QObject::tr("java"),"java");
      // envoyerATous(tr("<em>Un nouveau client vient de se connecter</em>"));
       emit emmetreMessage("nouvelle connexion");
       QTcpSocket *nouveauClient = serveur->nextPendingConnection();
       client= nouveauClient;
       //nouveauClient->

       QObject::connect(nouveauClient, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
}
void Serveur::donneesRecues()
{
       // 1 : on reoit un paquet (ou un sous-paquet) d'un des clients

    // On dtermine quel client envoie le message (recherche du QTcpSocket du client)
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    QByteArray message;
    if (socket->bytesAvailable() < 0)
    return;
    message = socket->readAll();
   /* qDebug() << QString::fromUtf8("Des donnes ont t reues en provenance du serveur");
    qDebug() << QString::fromUtf8("Octets reus : ") << message.size();
    qDebug() << QString::fromUtf8("Message reu du serveur : ") << message;
   */
   // m_parent->afficherInfo( QString::fromUtf8("message : " ) << message);
    emit emmetreMessage( QString::fromUtf8("message : " )+ message);
  // envoyerATous("test");
    envoyer("0");
}

void Serveur::deconnexionClient()
{
    qDebug() << QString::fromUtf8("Un client vient de se dconnecter");

    // On dtermine quel client se dconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouv le client  l'origine du signal, on arrte la mthode
        return;


    socket->deleteLater();
}

void Serveur::envoyer(const QString &message)
{
    // Prparation du paquet
       QByteArray paquet;
       QDataStream out(&paquet, QIODevice::WriteOnly);

     //  out << (quint16) 0; // On crit 0 au dbut du paquet pour rserver la place pour crire la taille
       out << message; // On ajoute le message  la suite
       //out.device()->seek(0); // On se replace au dbut du paquet
       //out << (quint16) (paquet.size() - sizeof(quint16)); // On crase le 0 qu'on avait rserv par la longueur du message


       // Envoi du paquet prpar  tous les clients connects au serveur

       client->write(paquet);
}



