/*
 Auteur : val15
 Date De Creation : 19/06/16

Role :
cette classe represente un serveur qui vas assurer la communication avec le client

 */


#ifndef SERVEUR_H
#define SERVEUR_H
#include <QtGui>
#include <QtNetwork>


class Serveur: public QWidget
{
    Q_OBJECT

        public:
            Serveur(QString host,int port);
            void envoyer(const QString &message);
            void lancement();

        private slots:
            void nouvelleConnexion();
            void donneesRecues();
            void deconnexionClient();

        private:


            QTcpServer *serveur;
            QTcpSocket *client;
            quint16 tailleMessage;

            QString m_host;
            int m_port;
        signals:
            void emmetreMessage(QString message);


};

#endif //SERVEUR_H
