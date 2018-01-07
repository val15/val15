/*
 Auteur : val15
 Date De Creation : 19/06/16

Role :
cette classe represente un serveur qui vas assurer la communication avec le client

 */


#ifndef SERVEUR_H
#define SERVEUR_H
#include <QtWidgets>
#include <QtNetwork>


class Serveur: public QWidget
{
    Q_OBJECT

        public:
            Serveur(int port);
            void envoyerAUn(const QString &message,int indiceDuReceveur);
            void envoyerATous(const QString &message);
            void lancement();

        private slots:
            void nouvelleConnexion();
            void donneesRecues();
            void deconnexionClient();

        private:
            QTcpServer *serveur;
            QList <QTcpSocket *> lstClient;
            quint16 m_tailleMessage;

            QString m_host;
            int m_port;
            int typeDuServeur=0;//serveur PC
            /*il faut cette int pour differencier le type de serveur qui à envoyer la requette
             *  si non on se retrouve avec un quette envoyer en meme temps par les deux serveurs
             */
        signals:
            void emmetreMessageRecu(QString message,int indiceDeLEnvoyeur,int typeDuSeveur);//
            void emmetreDeconnecionClient();


};

#endif //SERVEUR_H
