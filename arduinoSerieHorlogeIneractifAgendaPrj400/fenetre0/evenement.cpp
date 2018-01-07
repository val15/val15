#include "evenement.h"

Evenement::Evenement(QString date,QString evenement,int id,QString cheminEtNomDb)
{
    setWindowTitle("les evenements et rdv");
    m_sDate=date;
    m_evenement=evenement;
    m_id=id;
    m_cheminEtNomDb=cheminEtNomDb;
    int annee=m_sDate.split("-").at(0).toInt();
    int mois=m_sDate.split("-").at(1).toInt();
    int jour=m_sDate.split("-").at(2).toInt();
    QDate dateD;
    dateD.setDate(annee,mois,jour);
    m_GRPBox=new QGroupBox(this);
    setFixedWidth(500);
    m_GRPBox->setFixedWidth(500);
    m_layoutGenerale=new QGridLayout;
    setLayout(m_layoutGenerale);
   m_layoutHaut=new QGridLayout;
   m_layoutBas=new QGridLayout;
    m_deDate=new QDateEdit;
    m_deDate->setDate(dateD);
    //m_le_date=new QLineEdit(m_sDate);
    m_leEvenement=new QLineEdit(m_evenement);
    m_btModifier=new QPushButton("enregister");
    m_btSupprimer=new QPushButton("supprimer");
   // m_layoutHaut->addWidget(m_le_date,0,0);
    m_layoutHaut->addWidget(m_deDate,0,0);
    m_layoutHaut->addWidget(m_leEvenement,0,1);
    m_layoutBas->addWidget(m_btModifier,0,0);
    m_layoutBas->addWidget(m_btSupprimer,0,1);
    m_layoutGenerale->addLayout(m_layoutHaut,0,0);
    m_layoutGenerale->addLayout(m_layoutBas,1,0);

    connect(m_btSupprimer, SIGNAL(clicked()), this,SLOT(supprimer()));
    connect(m_btModifier, SIGNAL(clicked()), this,SLOT(enregister()));
   // Evenement::setWindowTitle("evenement : "+QString::number(m_id));
}

void Evenement::supprimer()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;
    query.prepare("delete from evenement where id=:id");
    query.bindValue(":id",m_id);
    query.exec();
    query.clear();
    db.close();
    emit lireListe();
}

void Evenement::enregister()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
   // QMessageBox::critical(0, QObject::tr("Database Error"),m_cheminEtNomDb);

    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;
    query.prepare("update evenement set dateEvenement=:dateEvenement,type=:type,heure=:heure, evenement=:evenement where id=:id");
    query.bindValue(":id",m_id);
    query.bindValue(":dateEvenement",m_deDate->date().toString("yyyy-MM-dd"));
    query.bindValue(":type","evenement a un jour");
    query.bindValue(":heure","00:00:00");
    query.bindValue(":evenement",m_leEvenement->text());
    query.exec();
    query.clear();
    db.close();



    emit lireListe();
}
