#ifndef FENETRE0_H
#define FENETRE0_H
/*#include <QApplication>
#include <QWidget>
#include <QPushButton>
# include <QPushButton>
#include <QLCDNumber>
#include <QSlider>*/


#include <QtGui>
#include <qextserialport.h>
#include <qextserialenumerator.h>
#include "Trajet.h"
#include "Serveur.h"



class MaFenetre : public QWidget // On hrite de QWidget (IMPORTANT)
{
Q_OBJECT
    public:
    MaFenetre();//constructeur par defaut
    void envoyerText(QString text);
    void lireListeTrj();
    void lireUnTrj(QString nomFichier);
    void lireTemps();


   // MaFenetre(int longueur,int hauteur);//constructeur par valeur
    private:


    //L'objet mentionnant les infos
    QextSerialEnumerator enumerateur;
    //on met ces infos dans une liste
    //QList<QextPortInfo> ports = enumerateur.getPorts();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);



    private:
    //QPushButton *m_bt_apropo;//on ceer un atribu de type QPushButton s'est un pointeur
    QLineEdit *m_lePort; //Permet de choisir le port srie
    QComboBox *m_comboVitesse; // Permet de choisir la vitesse de communication
    QLabel *m_lbIpServeur;
    QLineEdit *m_leAdresseIp;
    QPushButton *m_btLancementServeur;
    QPushButton *m_btnconnexion;// (D)Connecte la voie srie (bouton checkable)
    QLineEdit *m_leEmission;// Nous crirons ici le texte  envoyer
    QPushButton *m_pb_envoyer;
    QGridLayout *m_layoutEmission;
    QTextEdit *m_boxInformation;// Ici apparaitra le texte  recevoir
    QGridLayout *m_layoutGenerale;
    QGridLayout *m_layoutServeur;
    QGridLayout *m_layoutHaut;
    QPushButton *m_btEnregister;
    QPushButton *m_btPlay;
    QPushButton *m_btPlayInv;
    QGridLayout *m_layoutEnregistrement;
    QLabel *m_lbNomTrj;
    QLineEdit *m_leTrjEnregistrE;
    QPushButton *m_btEregistrerTrjEnregistrE;
    QGridLayout *m_layoutTrjEnregistrEHaut;
    QLabel *m_lbTrj;
    QComboBox *m_cbTrj;
    QPushButton *m_btPlayTrjEnregistrE;
    QPushButton *m_btPlayInvTrjEnregistrE;
    QGridLayout *m_layoutTrjEnregistrEBas;
    QLabel *m_lbTemps;
    QLCDNumber *m_lcdTemps;
    //QLabel *m_leTmps;
    QPushButton *m_btMaz;
    QGridLayout *m_layoutTemps;
    QLabel *m_lbInfo;
    //QGridLayout *m_layoutBas;
    //l'objet reprsentant le port
    QextSerialPort * port;

    //une fonction pour recuperer la vitesse
    BaudRateType getBaudRateFromString(QString baudRate);
    bool m_estConnecter;
    bool m_enregistrementEnCour;
    bool m_lectureEnCour;

  //  QPushButton *m_pb_allumerEtindreLed;

    Trajet m_tr0;
    Trajet m_trTrj;

    QTimer *m_timerTrjEnregistrement;
    QTimer *m_timerTrjLecture;
    QTimer *m_timerCompteur;
    long m_vtimerTrj;//pour retenir la valeur du timer
    QString m_actionEnCour;//pour enregister l'action en cour
    long m_vtimerTrjLectur;//pour retenir la valeur du timer
    int m_sensLecture;//si 1 sens dirrect si 2 sens inverse,si 3 sens dirrectTrj si 4 sens inverseTrj
    long m_compteur;
    bool m_activerCompteur;


    QString m_adresseIp;
    Serveur *m_serveur;
   // QTimer *m_timerConnectionAutomatique;

    //element pour le calendrier






private slots:
    //le slot automatique du bouton de connexion
    void connection();
    void sendData();
    void readData();
    void enoyer();
    void lancerEnregistrement();
    void incrementerTmptrj();
    void incrementerCompteur();
    void tretementTrjLecture();
    void playTrj();
    void playTrjInv();
    void playTrjEnregistrE();
    void playInvTrjEnregistrE();

    void modifNomEreregister();



    void enregisterTrj();
    void mazTemps();

    void lancerServeur();
    void afficherInfo(QString info);

    //pour arduinoSerieHorlogeIneractif


  //  void connectionAutomatique();
};



#endif // FENETRE0_H
