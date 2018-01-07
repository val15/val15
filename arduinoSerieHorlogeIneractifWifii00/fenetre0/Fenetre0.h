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
#include "fenetregererCalendrier.h"
#include "Arduino.h"
#include "ap.h"
#include "Serveur.h"

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
Q_OBJECT
    public:
    MaFenetre();//constructeur par defaut
    void envoyerText(QString text);
    void lireHeurReveille();
    void lireEtatReveille();
    void ecrireEtatReveille();
    void ecrireDernerCoor();//wifi
    void envoyerEtatAlrme();
    void desactiverAllumAuto();
    void activerAllumAuto();


   // MaFenetre(int longueur,int hauteur);//constructeur par valeur
    private:



    //L'objet mentionnant les infos

    //on met ces infos dans une liste
    //QList<QextPortInfo> ports = enumerateur.getPorts();



    private:

    void actiVOuDesactiVVitesseFnc();

    //pour e wifi
    bool m_premierDemarage;//pour l'envoi ducoordonn�e par d�faut
    int m_C;
    QGridLayout *m_gltWifi;
    QGridLayout *m_gltHaut;
    QGridLayout *m_gltMilieu;
    QGridLayout *m_gltCommande;
    QGridLayout *m_gltHorizontal;
    QGridLayout *m_gltVeritcal;
    QGridLayout *m_gltBas;
    QGridLayout *m_gltEnregistrement;

    QLabel *m_lbSIDD;
    QComboBox *m_cbSIDD;
    QPushButton *m_btSupprimer;
    QPushButton *m_btVider;

    QPushButton *m_btCharger;
    QLCDNumber *m_lcdnAngleH;
    QLCDNumber *m_lcdnAngleV;
    QLabel *m_lbE;
    QLabel *m_lbW;
    QLabel *m_lbM;
    QLabel *m_lbD;
    QSlider *m_sldH;
    QSlider *m_sldV;
    QPushButton *m_btEnvoyerCoorH;
    QPushButton *m_btEnvoyerCoorV;

    QLabel *m_lbEnrNomSIDD;
    QLineEdit *m_leEnrNomSIDD;
    QPushButton *m_btEnregister;
    void lireDb();
    QString m_dbMon;
    QString m_nomFichierDernierCoord;
    QString m_dernierCoord;
    void lireDernierCoord();
    int m_id;
    bool m_estConnecT;

    //les angle
    QString m_angleH;
    QString m_angleV;
    QList <Ap *> m_lstAp;
    QStringList m_lstNomAp;
    QStringListModel *m_modele;



    //pour l'horloge
    //QPushButton *m_bt_apropo;//on ceer un atribu de type QPushButton s'est un pointeur
    QLineEdit *m_lePort; //Permet de choisir le port série
    QLabel *m_lb_typeDebit;
    QComboBox *m_cbTypeDebit;
    bool m_estDebitInterne;
    QComboBox *m_comboVitesse; // Permet de choisir la vitesse de communication
    QPushButton *m_btnconnexion;// (Dé)Connecte la voie série (bouton “checkable”)
    QPushButton *m_btActiverAllumAutomatque;
    QPushButton *m_btPrise;
    QPushButton *m_btLumiere;
    QPushButton *m_btClignote;
     QPushButton *m_btVitesse;
     QCheckBox *m_chbActiverAutoLedVitesse;
     bool m_activerAutoLedVitesse;
      QPushButton *m_btEspace;
      QGridLayout *m_layoutLed;

     QGridLayout *m_layoutGenerale;
    QGridLayout *m_layoutHaut;



    //pour le commande du wifi


    //l'objet représentant le port
    Arduino *m_ard0;
    Arduino *m_ard1;
    QString m_portArd0;
    QString m_portArd1;


    bool m_estConnecter;
    bool m_clignotementEstActivE;
    bool m_ledVitesseEstActivE;
     bool m_ledEspaceEstActivE;
    bool m_allumAuto;

    bool m_lumiereActvE;
    bool m_priseActivE;



  //  QPushButton *m_pb_allumerEtindreLed;

    QDateTime *m_dateTempsActuel;
    QTimer *m_timer;


    QGridLayout *m_layoutAlarme;
    QCheckBox *m_cb_alarme;
    QTimeEdit *m_te_selectionRevaille;

   // QTimer *m_timerConnectionAutomatique;

    //element pour le calendrier
    QPushButton *m_pb_gereCalentdier;
    fenetregererCalendrier *m_fcl;
    QString m_cheminEtNomDb;
    QString m_evenementDuJour;
    QString m_evenementReste;
    QString m_evenement1;
    QString m_evenement2;
    QString m_evenement3;
    QString m_messageAEnvoyer;
    QString m_textAEnvoyer;
    QList <QStringList > m_lstEvenement;
    int m;
    int pas;
    QString m_chemin;
    QString m_modeDAffichage;
    QString m_etindreAlrme;
    QString m_etatClignotement;//a ou d
    QString m_etatVitesse;
    QString m_etatEspace;
    QString m_debit;
    QString m_peutDEspace;

    //pour le serveur
    Serveur *m_serveur;






private slots:
    //le slot automatique du bouton de connexion
    void connection();


    void temp();

    void ecrireActiverReveille();
    void slotEnvoyerEtatAlerte();

    //pour arduinoSerieHorlogeIneractif
    void gererCalendrier();
    void lireEvenementDuJourEtProch1();
    void actiVOuDesactiVClignotement();
    void actiVOuDesactiVEspace();
    void setRecepton(QString txtRecu);
    void desativerActiverAllumeAuto();
    void lireDebit();
    void lireEspceLibre();
    void actiVOuDesactiVVitesse();
    void actiVOuDesactiVVitesseAuto();
    void actiVOueteindrePrise();
     void allumerOuEteindreLumiR();
    //pour arduinoSerieHorlogeIneractif


  //pour le wifi
     void changerValeurH(int h);
     void changerValeurV(int v);
     void enregister();
     void charger();
     void supprimer();
     void vider();

     //pour le arduino
     void envoyerCoordH();
     void envoyerCoordV();
     void readData();

     //pour le serveur
    // void lancerServeur();
     void traiterMessagServeur(QString msg);
     void deconnectionClient();
};



#endif // FENETRE0_H
