#ifndef FENETRE0_H
#define FENETRE0_H


#include <QtWidgets>
#include <QTcpSocket>
#include <qextserialport.h>
#include "fenetregererCalendrier.h"
#include "Arduino.h"
#include "ap.h"
#include "Serveur.h"
#include "fichier.h"
#include "maclandrier.h"
#include "rdv.h"

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
Q_OBJECT
    public:
    MaFenetre();//constructeur par defaut
    void envoyerText(QString text);
    void lireConfig();


    void envoyerEtatAlrme();
    void desactiverAllumAuto();
    void activerAllumAuto();




    private:
    void repondreAuRequete(QStringList rqt);
    void exeAjouterEnregister(QStringList rqt);//"exe"correspend a l'execution du requete du client
    void exeAjouterEnregisterEtRelecture(QStringList rqt);
    void exeModifierEvenement(QStringList rqt); 
    void exeModifierEvenementEtRelecture(QStringList rqt);
    void exeModifierEvenementEtRelectureEvenementDuJour(QStringList rqt);
    void exeSupprimer(QStringList rqt);
    void exeSupprimerEtRelecture(QStringList rqt);
    void exeSupprimerEvenementEtRelectureEvenementDuJour(QStringList rqt);









    //pour l'horloge
    //QPushButton *m_bt_apropo;//on ceer un atribu de type QPushButton s'est un pointeur
    QLineEdit *m_lePort; //Permet de choisir le port série

    QComboBox *m_comboVitesse; // Permet de choisir la vitesse de communication
    QPushButton *m_btnconnexion;// (Dé)Connecte la voie série (bouton “checkable”)

    //pour les commades des �lement de la maison
    QGridLayout *m_layoutCommande;
    QCheckBox *m_chbAllumAutomatque;
    QTimeEdit *m_tieAllumAutomatque;
    QCheckBox *m_chbExtinctionAutomatque;
    QTimeEdit *m_tieExtinctionAutomatque;
    QPushButton *m_btPrise;

    //pour les leds
    QGridLayout *m_layoutLed;
    QPushButton *m_btLumiere;
    QPushButton *m_btClignote;


      //pour le calandrier
     QGridLayout *m_layoutCalandrier;
     MaClandrier *m_cldr;
     QLabel *m_lbEvenementsDuJour;
     QList<Rdv *> m_listWidgetRdv;
     QPushButton *m_btAjouterEvenement;
     QDateEdit *m_deAjoutDate;
     QPushButton *m_btAjoutEnregister;
     QComboBox *m_cbTypeAjoutEvennemt;
     QTimeEdit *m_tieHeurAjoutEvennemt;
     QLineEdit *m_leAjoutEvenement;
     //pour afficher les rvd du jour
     QScrollArea *m_areaConteneurRvdDuJour;//pour avoir les crollbares
     QWidget *m_conteneurRvdDuJour;
     QGridLayout *m_layoutRdvDuJour;


     QGridLayout *m_layoutGenerale;
    QGridLayout *m_layoutHaut;


    //pour la base de donn�e
    //pour la base de donn�e
    QString m_cheminEtNomDb;





    //l'objet représentant le port
    Arduino *m_arduinoAfficheur;
    Arduino *m_arduinoCommande;
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

    //pour le reveil
    QGridLayout *m_layoutAlarme;
    QTimeEdit *m_tieSelectionReveille;
    QCheckBox *m_chbAlarme;
    QLabel *m_lbReveil;
    QPushButton *m_btEteindreAlarme;

   // QTimer *m_timerConnectionAutomatique;

    //element pour le fenetre calendrier
    QPushButton *m_btGereCalentdier;
    fenetregererCalendrier *m_fcl;


    QString m_evenementDuJour;
    QString m_evenementReste;
    QStringList m_lstEvenementAEnvoyer;
    QString m_messageAEnvoyer;
    QString m_textAEnvoyer;

    int m;
    int pas;
    QString m_chemin;
    QString m_modeDAffichage;
    QString m_etindreAlrme;
    QString m_etatClignotement;//a ou d
    QString m_etatVitesse;
    QString m_etatEspace;
    QString m_peutDEspace;

    //pour le serveur
    Serveur *m_serveur;

    //pour la config
    QString m_nomFichierDeConfig;
   // QString m_strConfig;//ce string contiedra les configuration
    QString m_heurReveil;
    QString m_etatReveil;
    QString m_heurAllumAutomatque;
    QString m_etatAllumAutomatque;
    QString m_etatExtinctionAutomatique;
    QString m_heurExtinctionAutomatque;







private slots:

    //pour le calandrier
    void lectureDesDatesImportantsDuMois(int year,int month);//lis les dade important du mois courant pour les colorer
    void repLectureDesDatesImportantesDuMois(int year,int month);//"rep" correspend au repond des requetes du client

    void lectureDesDatesImportantsDuMois();
    void lectureDesEvenementsDuJour(QDate date);
    void repLectureDesEvenementsDuJour(QString date);
    void repLectureDesEvenements();

    void lectureDesEvenementsDuJour();
    void ajouterEvenement();
    void selectionTypeEvenement(QString texte);
    void ajouterEnregister();

    //le slot automatique du bouton de connexion
    void connection();


    void temp();



    //pour arduinoSerieHorlogeIneractif
    void gererCalendrier();
    void lireEvenementDuJourEtProch1();
    void actiVOuDesactiVClignotement();
    void setRecepton(QString txtRecu);
    void desativerActiverAllumeAuto();

    void actiVOueteindrePrise();
     void allumerOuEteindreLumiR();
     void eteindreAlarme();




     void traiterMessagServeur(QString msg);
     void deconnectionClient();

     void ecrirConfig();//ce slot est appeler qaund on modifie un configuration
     void exeEcrireConfig(QStringList rqt);
     void repLectureConfig();

     void miseMA38();

};



#endif // FENETRE0_H
