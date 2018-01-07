#ifndef SERVEURANDROID_H
#define SERVEURANDROID_H
#include "Serveur.h"

class ServeurAndroid: public QWidget
{
    Q_OBJECT

        public:
            ServeurAndroid(int port);
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
            int typeDuServeur=1;//serveur Android
        signals:
            void emmetreMessageRecu(QString message,int indiceDeLEnvoyeur,int typeDuSeveur);
            void emmetreDeconnecionClient();


};

#endif // SERVEURANDROID_H
