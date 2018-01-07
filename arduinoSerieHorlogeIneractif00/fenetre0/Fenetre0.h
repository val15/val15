#ifndef FENETRE0_H
#define FENETRE0_H
/*#include <QApplication>
#include <QWidget>
#include <QPushButton>
# include <QPushButton>
#include <QLCDNumber>
#include <QSlider>*/


#include <QtWidgets>
#include "fenetregererCalendrier.h"
#include "Arduino.h"

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
Q_OBJECT
    public:
    MaFenetre();//constructeur par defaut
    void envoyerText(QString text);
    void lireHeurReveille();
    void lireEtatReveille();
    void ecrireEtatReveille();
    void envoyerEtatAlrme();
    void desactiverAllumAuto();
    void activerAllumAuto();


   // MaFenetre(int longueur,int hauteur);//constructeur par valeur
    private:



    //L'objet mentionnant les infos

    //on met ces infos dans une liste
    //QList<QextPortInfo> ports = enumerateur.getPorts();



    private:
    //QPushButton *m_bt_apropo;//on ceer un atribu de type QPushButton s'est un pointeur
    QLineEdit *m_lePort; //Permet de choisir le port série
    QLabel *m_lb_vitesse;
    QComboBox *m_comboVitesse; // Permet de choisir la vitesse de communication
    QPushButton *m_btnconnexion;// (Dé)Connecte la voie série (bouton “checkable”)
    QPushButton *m_btActiverAllumAutomatque;
    QPushButton *m_btPrise;
    QPushButton *m_btLumiere;
    QPushButton *m_btClignote;
     QPushButton *m_btVitesse;
      QPushButton *m_btEspace;
      QGridLayout *m_layoutLed;
    QTextEdit *m_boxEmission;// Nous écrirons ici le texte à envoyer
    QTextEdit *m_boxReception;// Ici apparaitra le texte à recevoir
    QGridLayout *m_layoutGenerale;
    QGridLayout *m_layoutHaut;
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
    QPushButton *m_pb_envoyer;
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




private slots:
    //le slot automatique du bouton de connexion
    void connection();

    void enoyer();
    void temp();

    void ecrireActiverReveille();
    void slotEnvoyerEtatAlerte();

    //pour arduinoSerieHorlogeIneractif
    void gererCalendrier();
    void lireEvenementDuJourEtProch1();
    void actiVOuDesactiVClignotement();
    void actiVOuDesactiVVitesse();
    void actiVOuDesactiVEspace();
    void setRecepton(QString txtRecu);
    void desativerActiverAllumeAuto();
    void lireDedit();
    void lireEspceLibre();

    void actiVOueteindrePrise();
     void allumerOuEteindreLumiR();
    //pour arduinoSerieHorlogeIneractif


  //  void connectionAutomatique();
};



#endif // FENETRE0_H
