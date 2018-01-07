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

class MaFenetre : public QWidget // On h√©rite de QWidget (IMPORTANT)
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

    void actiVOuDesactiVVitesseFnc();

    //pour e wifi
    bool m_premierDemarage;//pour l'envoi ducoordonnÈe par dÈfaut
    int m_C;






    //pour l'horloge
    //QPushButton *m_bt_apropo;//on ceer un atribu de type QPushButton s'est un pointeur
    QLineEdit *m_lePort; //Permet de choisir le port s√©rie
    QLabel *m_lb_typeDebit;
    QComboBox *m_cbTypeDebit;
    bool m_estDebitInterne;
    QComboBox *m_comboVitesse; // Permet de choisir la vitesse de communication
    QPushButton *m_btnconnexion;// (D√©)Connecte la voie s√©rie (bouton ‚Äúcheckable‚Äù)

    //pour les commades des Èlement de la maison
    QGridLayout *m_layoutCommande;
    QCheckBox *m_chbAllumAutomatque;
    QTimeEdit *m_tieAllumAutomatque;
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
     int comparerDeuxDate(QString d0,QString d1); //reÁon en paramatre "MM-dd" return 1 si d0 est plus grand;-1 si d1 est plus grand et 0 si egale


     QGridLayout *m_layoutGenerale;
    QGridLayout *m_layoutHaut;


    //pour la base de donnÈe
    //pour la base de donnÈe
    QString m_cheminEtNomDb;





    //l'objet repr√©sentant le port
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

    //pour le reveil
    QGridLayout *m_layoutAlarme;
    QTimeEdit *m_tieSelectionReveille;
    QCheckBox *m_chbAlarme;
    QLabel *m_lbReveil;

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

    //pour la config
    QString m_nomFichierDeConfig;
   // QString m_strConfig;//ce string contiedra les configuration
    QString m_heurReveil;
    QString m_etatReveil;
    QString m_heurAllumAutomatque;
    QString m_etatAllumAutomatque;







private slots:

    //pour le calandrier
    void lectureDesDatesImportantsDuMois(int year,int month);//lis les dade important du mois courant pour les colorer
    void lectureDesDatesImportantsDuMois();
    void lectureDesEvenementsDuJour(QDate date);
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
    void actiVOuDesactiVEspace();
    void setRecepton(QString txtRecu);
    void desativerActiverAllumeAuto();
    void lireDebit();
    void lireEspceLibre();
    void actiVOuDesactiVVitesse();
    void actiVOuDesactiVVitesseAuto();
    void actiVOueteindrePrise();
     void allumerOuEteindreLumiR();





    //
     void readData();

     //pour le serveur
    // void lancerServeur();
     void traiterMessagServeur(QString msg);
     void deconnectionClient();

     void ecrirConfig();//ce slot est appeler qaund on modifie un configuration


};



#endif // FENETRE0_H
