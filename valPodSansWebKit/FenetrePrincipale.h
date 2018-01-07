#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H
#include <QtWidgets>
#include "WidgetMedia.h"
#include <QtSql>
#include <QDateTime>

class FenetrePrincipale: public QMainWindow
{
     Q_OBJECT
public :
    FenetrePrincipale();



protected:


private:
    QString m_db;
    QString m_chemin;
    QString m_rangerPar;

  //  QMdiArea *m_zoneCentrale;
    QTabWidget *m_QTABOnglets;
   // QWidget *m_widgetCentral;
    QWidget *m_sousFenetreVideo;
    QWidget *m_sousFenetreAudio;
    QGridLayout *m_layoutVideo;
    QGridLayout *m_layoutAudio;
    //QWidget *m_conteneurAudio;



    QSpacerItem *m_espaceMessageVartical;
    QScrollArea *m_scl_areaAudio;
    QScrollArea *m_scl_areaVideo;


    QDateTime m_dateTempsActuel;

    QList<WidgetMedia *> m_listAudio;
    QList<WidgetMedia *> m_listVideo;

    QAction *actionAfficherParTitre;
     QAction *actionAfficherParId;

private slots:
    void ajouter();
    void viderAudio();
    void viderVideo();
    void slotLireListeMedia();
    void lireListeMediaParId();
    void lireListeMediaParTitre();


};


#endif // FENETREPRINCIPALE_H
