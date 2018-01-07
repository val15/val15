/*
 Auteur : val15
 Date De Creation : 02/09/14

Role :
represente une evenement

 */


#ifndef RDV_H
#define RDV_H
#include <QtWidgets>
#include <QtSql>

class Rdv: public QWidget
{
    Q_OBJECT
public :
    Rdv(QString date,QString time,QString evenement,int id,QString cheminEtNomDb);

protected:


private:
    QString m_cheminEtNomDb;
    QString m_evenement;
    QString m_sDate;
    QString m_sTime;
    int m_id;

    QGridLayout *m_layoutGenerale;
   QGridLayout *m_layoutHaut;
   QGridLayout *m_layoutBas;
   QDateEdit *m_deDate;
   QTimeEdit *m_tieTime;
   QLineEdit *m_leDate;
   QLineEdit *m_leEvenement;
   QPushButton *m_btModifier;
   QPushButton *m_btSupprimer;


    QGroupBox *m_GRPBox;

private slots:
    void supprimer();
    void enregister();
signals:
    void lireListe();



};

#endif //EVENEMENT_H
