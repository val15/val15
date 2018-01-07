/*
 Auteur : val15
 Date De Creation : 02/09/14

Role :
pour arduinoSerieHorlogeIneractif une Qdialogue pour gerer la calendrier

 */


#ifndef FENETREGERERCALENDRIER_H
#define FENETREGERERCALENDRIER_H
#include <QtWidgets>
#include <QtSql>
#include "evenement.h"
#include "rdv.h"

class fenetregererCalendrier: public QDialog
{
    Q_OBJECT
public :
    fenetregererCalendrier(QString cheminEtNomD);



protected:


private:
    QString m_cheminEtNomDb;
    QGridLayout *m_layoutGenerale;
    QGridLayout *m_layoutEvenement;
    QPushButton *m_btAjouter;
    QPushButton *m_btMajAnnee;
    QDialog *m_fenetreAjouter;
    QGridLayout *m_layoutAjout;
   // QLabel *m_lb_ajoutDate;
    QDateEdit *m_deAjoutDate;
  //  QLabel *m_lb_ajoutEvenement;
    QLineEdit *m_leAjoutEvenement;
    QComboBox *m_cbTypeAjoutEvennemt;
    QTimeEdit *m_tieHeurAjoutEvennemt;
    QPushButton *m_btAjoutEnregister;

    //pour gere et afficher liste de evenement
    QScrollArea *m_areaEnevement;
    QWidget *m_conteneurEnevement;
    QSpacerItem *m_espaceMessageVartical;
    QSpacerItem *m_espaceMessageHorizontal;

    QList<QWidget *> m_listWidgetEvenementEtRdv;

    //pour la configuration
    QString m_heureReveil;
    QString m_etatReveil;
    QString m_config;//un string qui contient les configuration



private slots:
    void ajouter();
    void selectionTypeEvenement(QString texte);
    void enregister();
    void lireListeEvenement();
    void slotFermer();
    void miseAJourAnnE();


signals:
    void lireListe();
    void lireListeApresAjout();

};

#endif //FENETREGERERCALENDRIER_H
