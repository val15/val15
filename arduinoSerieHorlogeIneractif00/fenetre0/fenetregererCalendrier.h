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

class fenetregererCalendrier: public QDialog
{
    Q_OBJECT
public :
    fenetregererCalendrier();



protected:


private:
    QString m_cheminEtNomDb;
    QGridLayout *m_layoutGenerale;
    QGridLayout *m_layoutEvenement;
    QPushButton *m_pb_ajouter;
    QPushButton *m_pb_majAnnee;
    QDialog *m_fenetreAjouter;
    QGridLayout *m_layoutAjout;
   // QLabel *m_lb_ajoutDate;
    QDateEdit *m_de_ajoutDate;
  //  QLabel *m_lb_ajoutEvenement;
    QLineEdit *m_txe_ajoutEvenement;
    QPushButton *m_pb_ajoutEnregister;

    //pour gere et afficher liste de evenement
    QScrollArea *m_areaEnevement;
    QWidget *m_conteneurEnevement;
    QSpacerItem *m_espaceMessageVartical;
    QSpacerItem *m_espaceMessageHorizontal;

    QList<evenement *> m_listWidgetEvenement;



private slots:
    void ajouter();
    void enregister();
    void lireListeEvenement();
    void slotFermer();
    void miseAJourAnnE();

signals:
    void lireListe();

};

#endif //FENETREGERERCALENDRIER_H
