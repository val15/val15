/*
 Auteur : val15
 Date De Creation : 02/09/14

Role :
represente une evenement

 */


#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QtWidgets>
#include <QtSql>

class evenement: public QWidget
{
    Q_OBJECT
public :
    evenement(QString date,QString evenement,int id,QString cheminEtNomDb);

protected:


private:
    QString m_cheminEtNomDb;
    QString m_evenement;
    QString m_sDate;
    int m_id;

    QGridLayout *m_layoutGenerale;
   QGridLayout *m_layoutHaut;
   QGridLayout *m_layoutBas;
    QDateEdit *m_de_date;
    QLineEdit *m_le_date;
    QLineEdit *m_le_evenement;
    QPushButton *m_pb_modifier;
    QPushButton *m_pb_supprimer;


    QGroupBox *m_GRPBox;

private slots:
    void supprimer();
    void enregister();
signals:
    void lireListe();



};

#endif //EVENEMENT_H
