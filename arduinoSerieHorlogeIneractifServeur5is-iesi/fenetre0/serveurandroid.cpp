#include "serveurandroid.h"


ServeurAndroid::ServeurAndroid(int port)
{
    m_host="any";
    m_port=port;
    m_tailleMessage=0;
}

void ServeurAndroid::lancement()
{
    serveur = new QTcpServer();
        if (!serveur->listen(QHostAddress::Any, m_port)) // Dmarrage du ServeurAndroid sur toutes les IP disponibles et sur le port 50585
        {
            // Si le ServeurAndroid n'a pas t dmarr correctement
           qDebug() << "Le ServeurAndroid n'a pas pu tre dmarr. Raison :<br />" + serveur->errorString();
        }
        else
        {
            // Si le ServeurAndroid a t dmarr correctement
            qDebug() << "Le ServeurAndroid Android a ete demarrer sur le port <strong>" + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter.");
            QObject::connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
        }
}

void ServeurAndroid::nouvelleConnexion()
{
    // QMessageBox::critical(0, QObject::tr("java"),"java");
      // envoyerATous(tr("<em>Un nouveau client vient de se connecter</em>"));
       qDebug() << "nouvelle connexion Adroid";
       QTcpSocket *nouveauClient = serveur->nextPendingConnection();

       //nouveauClient->

       QObject::connect(nouveauClient, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
       QObject::connect(nouveauClient, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));
       lstClient << nouveauClient;//on ajoute le nouveau client dans la liste des clients
}
void ServeurAndroid::donneesRecues()
{

    // 1 : on reçoit un paquet (ou un sous-paquet) d'un des clients
    // On détermine quel client envoie le message (recherche du QTcpSocket du client)
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    QByteArray message;
    if (socket->bytesAvailable() < 0)
    return;
    message = socket->readAll();
    qDebug() << QString::fromUtf8("Des données ont été reçues en provenance du serveur");
    qDebug() << QString::fromUtf8("Octets reçus : ") << message.size();
    qDebug() << QString::fromUtf8("Message reçu du serveur : ") << message;

    int indiceDeLEnvoyeur=-1;
    QList<QTcpSocket *> ::iterator it;
    int i(0);
    for(it=lstClient.begin();it!=lstClient.end();++it)
    {
        if(lstClient.at(i)==socket)
        {
           indiceDeLEnvoyeur=i;
        }
        else
            i++;
    }
    qDebug() << "message recu : "  << message << endl;
    qDebug() << "indice de l'envoyeur' : "  << indiceDeLEnvoyeur << endl;

  //envoyerATous("R TEST");
    emmetreMessageRecu(message,indiceDeLEnvoyeur,typeDuServeur);


}

void ServeurAndroid::deconnexionClient()
{
    qDebug() << QString::fromUtf8("Un client vient de se dconnecter");

    // On dtermine quel client se dconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouv le client  l'origine du signal, on arrte la mthode
        return;



    if(!lstClient.isEmpty())
    {
        QList<QTcpSocket *> ::iterator it;
        int i(0);
        for(it=lstClient.begin();it!=lstClient.end();++it)
        {
            if(lstClient.at(i)== socket);
                lstClient.removeAt(i);
            i++;
        }
    }
    socket->deleteLater();


}

void ServeurAndroid::envoyerAUn(const QString &message,int indiceDuReceveur)//doit etre à 64 bit
{
 /*   QByteArray paquet;//pour stoker le paquet en envoiyer sur le rseau
    QDataStream out(&paquet, QIODevice::WriteOnly);//On utilise un QDataStream comme tout  l'heure pour crire dans le QByteArray facilementgr
    out << (quint32) 0; // On crit 0 au dbut du paquet pour rserver la place pour crire la taille
    out << message; // On ajoute le message  la suite
    out.device()->seek(0); // On se replace au dbut du paquet
    out << (quint32) (paquet.size() - sizeof(quint32)); // On crase le 0 qu'on avait rserv par la longueur du message:taille total- taille d'un int
    //client->write(paquet);*/
    QByteArray paquet = message.toUtf8()+ "\n";
    lstClient.at(indiceDuReceveur)->write(paquet);
}


void ServeurAndroid::envoyerATous(const QString &message)//doit etre à 64 bit
{
   /* QByteArray paquet;//pour stoker le paquet en envoiyer sur le rseau
    QDataStream out(&paquet, QIODevice::WriteOnly);//On utilise un QDataStream comme tout  l'heure pour crire dans le QByteArray facilementgr
    out << (quint32) 0; // On crit 0 au dbut du paquet pour rserver la place pour crire la taille
    out << message; // On ajoute le message  la suite
    out.device()->seek(0); // On se replace au dbut du paquet
    out << (quint32) (paquet.size() - sizeof(quint32)); // On crase le 0 qu'on avait rserv par la longueur du message:taille total- taille d'un int
    *///client->write(paquet);
    QByteArray paquet = message.toUtf8() + "\n";

    // Envoi du paquet préparé à tous les clients connectés au serveur
    /*for ( int i = 0 ; i < clients.size() ; i++ ) {
        clients[i]->write(paquet);
    }
    QByteArray paquet = message.toUtf8();*/
    if(!lstClient.isEmpty())
    {
        QList<QTcpSocket *> ::iterator it;
        int i(0);
        for(it=lstClient.begin();it!=lstClient.end();++it)
        {
            lstClient.at(i)->write(paquet);
            i++;
        }
    }

}



