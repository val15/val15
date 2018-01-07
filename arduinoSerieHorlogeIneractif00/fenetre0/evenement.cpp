#include "evenement.h"

evenement::evenement(QString date,QString evenement,int id,QString cheminEtNomDb)
{
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
    m_de_date=new QDateEdit;
    m_de_date->setDate(dateD);
    //m_le_date=new QLineEdit(m_sDate);
    m_le_evenement=new QLineEdit(m_evenement);
    m_pb_modifier=new QPushButton("enregister");
    m_pb_supprimer=new QPushButton("supprimer");
   // m_layoutHaut->addWidget(m_le_date,0,0);
    m_layoutHaut->addWidget(m_de_date,0,0);
    m_layoutHaut->addWidget(m_le_evenement,0,1);
    m_layoutBas->addWidget(m_pb_modifier,0,0);
    m_layoutBas->addWidget(m_pb_supprimer,0,1);
    m_layoutGenerale->addLayout(m_layoutHaut,0,0);
    m_layoutGenerale->addLayout(m_layoutBas,1,0);

    connect(m_pb_supprimer, SIGNAL(clicked()), this,SLOT(supprimer()));
    connect(m_pb_modifier, SIGNAL(clicked()), this,SLOT(enregister()));
}

void evenement::supprimer()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;
    query.prepare("delete from evenement where dateEvenement = :dateEvenement");
    query.bindValue(":dateEvenement",m_de_date->date().toString("yyyy-MM-dd"));
    query.exec();
    query.clear();
    db.close();


    emit lireListe();

}

void evenement::enregister()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;
    //uery.exec("create table evenement (id int primary key ,dateEvenement varchar(255),evenement varchar(255))");
    //query.prepare("insert into evenement values(:id,:dateEvenement,:evenement)");
    //query.prepare("update message set auteur=:auteur,cathegorie=:cathegorie ,message=:message, dateDeCreation=:date, destination=:destination where id=:id");
    query.prepare("update evenement set id=:id, dateEvenement=:dateEvenement, evenement=:evenement where id=:id");
    query.bindValue(":id",m_id);
    query.bindValue(":dateEvenement",m_de_date->date().toString("yyyy-MM-dd"));
    query.bindValue(":evenement",m_le_evenement->text());
    query.exec();
    query.clear();
    db.close();

    emit lireListe();
}
