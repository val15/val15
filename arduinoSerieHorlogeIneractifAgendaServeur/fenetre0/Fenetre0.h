#ifndef FENETRE0_H
#define FENETRE0_H


#include <QtWidgets>
#include <QTcpSocket>
#include <qextserialport.h>
#include "fenetregererCalendrier.h"
#include "Arduino.h"
#include "Serveur.h"
#include "serveurandroid.h"
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


    void ecrireDernerCoor();//wifi
    void envoyerEtatAlrme();
    void desactiverAllumAuto();
    void activerAllumAuto();




    private:
    void repondreAuRequete(QStringList rqt,int indiceEnvoyeur,int typeDuSeveur);
    void exeAjouterEnregister(QStringList rqt);//"exe"correspend a l'execution du requete du client
    void exeAjouterEnregisterEtRelecture(QStringList rqt,int indiceEnvoyeur,int typeDuSeveur);
    void exeModifierEvenement(QStringList rqt);
    void exeModifierEvenementEtRelecture(QStringList rqt,int indiceEnvoyeur,int typeDuSeveur);
    void exeModifierEvenementEtRelectureEvenementDuJour(QStringList rqt,int indiceEnvoyeur,int typeDuSeveur);
    void exeSupprimer(QStringList rqt);
    void exeSupprimerEtRelecture(QStringList rqt,int indiceEnvoyeur,int typeDuSeveur);
    void exeSupprimerEvenementEtRelectureEvenementDuJour(QStringList rqt,int indiceEnvoyeur,int typeDuSeveur);




    void exeLectureTypeDebit(QStringList lst);
    void exeLectureDebit(QStringList lst);
    void actiVOuDesactiVVitesseFnc();

    void actiVOuDesactiVEspace();








    //pour l'horloge
    //QPushButton *m_bt_apropo;//on ceer un atribu de type QPushButton s'est un pointeur
    QLineEdit *m_lePort; //Permet de choisir le port série
    QLabel *m_lb_typeDebit;
    QComboBox *m_cbTypeDebit;
    bool m_estDebitInterne;
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
     QPushButton *m_btVitesse;
     QCheckBox *m_chbActiverAutoLedVitesse;
     bool m_activerAutoLedVitesse;
      QPushButton *m_btEspace;

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
    QPushButton *m_pb_gereCalentdier;
    fenetregererCalendrier *m_fcl;


    QString m_evenementDuJour;
    QString m_evenementReste;
   /* QString m_evenement1;
    QString m_evenement2;
    QString m_evenement3;*/
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
    QString m_debit;
    QString m_peutDEspace;

    //pour le serveur
    Serveur *m_serveur;
   // Serveur *m_serveurDebit;
    //IL FAUT IMPLEMENT UN AUTRE SERVEUR POUR LES CLIENT ANDROIS
    ServeurAndroid *m_serveurAndroid;

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
    void repLectureDesDatesImportantesDuMois(int year,int month,int indiceEnvoyeur,int typeDuSeveur);//"rep" correspend au repond des requetes du client
    void repLectureDesDatesImportantesDuMoisATout(int year,int month);
    void lectureDesDatesImportantsDuMois();
    void lectureDesEvenementsDuJour(QDate date);
    void repLectureDesEvenementsDuJour(QString date,int indiceEnvoyeur,int typeDuSeveur);
    void repLectureDesEvenementsDuJourAndroid(QString date,int indiceEnvoyeur,int typeDuSeveur);
    void repLectureDesEvenements(int indiceEnvoyeur,int typeDuSeveur);

    void lectureDesEvenementsDuJour();
    void ajouterEvenement();
    void selectionTypeEvenement(QString texte);
    void ajouterEnregister();

    //le slot automatique du bouton de connexion
    void connection();


    void temp();

    void gererCalendrier();
    void lireEvenementDuJourEtProch1();
    void actiVOuDesactiVClignotement();
    void setRecepton(QString txtRecu);
    void desativerActiverAllumeAuto();

     void allumerOuEteindreLumiR();
     void eteindreAlarme();




     void traiterMessagServeur(QString msg,int indiceEnvoyeur,int typeDuSeveur);
     void deconnectionClient();

     void ecrirConfig();//ce slot est appeler qaund on modifie un configuration
     void exeEcrireConfig(QStringList rqt);
     void repLectureConfig();

    void lireDebit();
    void typeDebitChange(QString typeDebit);
    void lireEspceLibre();
    void actiVOuDesactiVVitesse();
    void actiVOuDesactiVVitesseAuto();
    void actiVOueteindrePrise();



     void miseMA38();

};



#endif // FENETRE0_H
