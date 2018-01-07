#ifndef WidgetMedia_H
#define WidgetMedia_H
#include <QtWidgets>
#include <QtSql>



/*
 Auteur : val15
 Date De Creation : 01/11/13

Role :
widget represente un fichier audio

 */

class WidgetMedia: public QWidget
{
    Q_OBJECT
public :
    WidgetMedia(QString id,QString titre,QString date,QString emplacement,QString cathegorie,QString etat);
    void  creerpage();
    void supprimerFonct();


protected:


private:
    QString m_db;
    QString m_cheminWeb;
    QString m_page;
    QString m_nomDuFichierWeb;
    QString m_cheminEtNomDuFichier;

    QString m_id;
    QString m_titre;
    QString m_date;
    QString m_cheminRelationEtNom;
    QString m_etat;
    QString m_cathegorie;
    QGroupBox *m_GRPBox;

   // QWidget *m_wg_conteneur;
    QGridLayout *m_glt_layoutPrincipale;
    QGridLayout *m_glt_layoutBouton;
    QGridLayout *m_glt_layoutLabel;
    QLabel *m_lb_titre;
    QLabel *m_lb_date;
    QLabel *m_lb_emplacement;
    QLabel *m_lb_etat;
    QPushButton *m_bt_lire;
    QPushButton *m_bt_suprimer;
    QPushButton *m_bt_suprimerDuDisqueDure;

    QDialog *m_fenetreVisualisation;
    QGridLayout *m_glt_layoutFenetreDeVisionnage;


private slots:

    void supprimerDefinitif();
    void supprimer();
signals:
    void singSupprimer();

};


#endif // WidgetMedia_H
