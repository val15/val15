#ifndef FENETRE0_H
#define FENETRE0_H


#include <QtGui>
#include <QtSql>
#include <qextserialport.h>

#include "ap.h"



class MaFenetre : public QWidget // On hrite de QWidget (IMPORTANT)
{
Q_OBJECT
    public:
    MaFenetre();//constructeur par defaut
    void lireDb();
    void envoyer(QString str);

    QList <Ap *> m_lstAp;
    QStringList m_lstNomAp;
    QStringListModel *m_modele;

    //arduino
    BaudRateType getBaudRateFromString(QString baudRate);

private:
    QGridLayout *m_gltPrincipal;
    QGridLayout *m_gltConnexionArd;
    QGridLayout *m_gltHaut;
    QGridLayout *m_gltMilieu;
    QGridLayout *m_gltCommande;
    QGridLayout *m_gltHorizontal;
    QGridLayout *m_gltVeritcal;

    QGridLayout *m_gltBas;
    QGridLayout *m_gltEnregistrement;

    QLineEdit *m_lePort;
    QComboBox *m_cbVitesse;
    QPushButton *m_btConnexionArd;
    QTextEdit *m_teInfo;

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

    QString m_dbMon;
    int m_id;

    //les angle
    QString m_angleH;
    QString m_angleV;

     //pour la connexion Ard
    //L'objet mentionnant les infos
    //on met ces infos dans une liste
     QextSerialPort *m_port;
     bool m_estConnecT;
public slots:
    void changerValeurH(int h);
    void changerValeurV(int v);

private slots:
     void connexion();
    void enregister();
    void charger();
    void supprimer();
    void vider();

    //pour le arduino
    void envoyerCoordH();
    void envoyerCoordV();
    void readData();


};



#endif // FENETRE0_H
