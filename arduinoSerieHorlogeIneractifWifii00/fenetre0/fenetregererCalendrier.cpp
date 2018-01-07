#include "fenetregererCalendrier.h"

fenetregererCalendrier::fenetregererCalendrier()
{
   //setFixedSize(800,8000);
    //setFixedWidth(500);
    m_cheminEtNomDb="/home/pi/dbarduinoSerieHorlogeIneractif";


    //creeation de la db
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;//c8
   query.exec("create table evenement (id int primary key ,dateEvenement DATE,evenement varchar(255))");
    query.clear();
    db.close();

    m_layoutGenerale=new QGridLayout;
    setLayout(m_layoutGenerale);
    m_layoutEvenement=new QGridLayout;
    m_pb_ajouter=new QPushButton("ajouter");
    m_layoutGenerale->addWidget(m_pb_ajouter,0,0);
    //m_layoutEvenement->


    m_areaEnevement=new QScrollArea(this);
    m_areaEnevement->setWidgetResizable(true);
    m_conteneurEnevement=new QWidget;
   // m_conteneurEnevement->setFixedSize(500,8000);
    m_conteneurEnevement->adjustSize();
    m_areaEnevement->setWidget(m_conteneurEnevement);
    m_conteneurEnevement->setLayout(m_layoutEvenement);
    m_layoutGenerale->addWidget(m_areaEnevement,1,0);
    m_pb_majAnnee=new QPushButton("mise a jour annee");
    m_layoutGenerale->addWidget(m_pb_majAnnee,2,0);
    m_espaceMessageVartical=new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);;
    m_espaceMessageHorizontal = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

  //  mieAJourAnnE();
    lireListeEvenement();

    connect(this, SIGNAL(close()), this,SLOT(slotFermer()));
    connect(m_pb_ajouter, SIGNAL(clicked()), this,SLOT(ajouter()));
    connect(m_pb_majAnnee, SIGNAL(clicked()), this,SLOT(miseAJourAnnE()));
    //

}

void fenetregererCalendrier::miseAJourAnnE()
{
    QStringList lstId;
    QStringList lstDate;
    QStringList lstEevenement;


   // query.exec("create table evenement (id int primary key ,dateEvenement DATE,evenement varchar(255))");
    //remplissage
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_cheminEtNomDb);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }
    //query.exec("create table evenement (id int primary key ,dateEvenement DATE,evenement varchar(255))");

    QSqlQuery query;//SELECT pseudo, message, DATE_FORMAT(date, '%d/%m/%Y %Hh%imin%ss') AS date FROM minichat
    if(query.exec("SELECT * FROM evenement ORDER BY evenement.id"))
    {
        while(query.next())
        {//m_listWidgetPhoto.append(new miniWidgetPhoto(query.value(0).toInt(),m_cheminMediaPhoto+ query.value(1).toString(),m_cheminMediaPhoto+query.value(2).toString(),m_le_psedo->text(),m_socketMessage,m_socketFichier,m_sID,query.value(3).toString(),m_socketInfo,m_socketListe,query.value(7).toString(),this));
           // m_listWidgetEvenement.append(new evenement(query.value(1).toString(),query.value(2).toString(),query.value(0).toInt(),m_cheminEtNomDb));
            lstId.append(query.value(0).toString());
            lstDate.append(query.value(1).toString());
            lstEevenement.append(query.value(2).toString());
        }
    }
    else
    {
        QMessageBox::critical(0, QObject::tr("query Error"),query.lastError().text());
    }
   /* query.clear();
    db.close();*/
   // m_listWidgetEvenement.append(new evenement(query.value(1).toString(),query.value(2).toString(),query.value(0).toInt(),m_cheminEtNomDb));


    //modification
    QStringList lstDateDef;
    for(int c=0;c<lstDate.count();c++)
    {
        if(lstEevenement.at(c).split(" ").at(0)=="anniv")
        {
            if(lstDate.at(c).split("-").at(0)!=QDate::currentDate().toString("yyyy"))
           {
              //  QMessageBox::critical(0, QObject::tr("query Error"),lstDate.at(c).split("-").at(0));

                lstDateDef.append(QDate::currentDate().toString("yyyy")+"-"+lstDate.at(c).split("-").at(1)+"-"+lstDate.at(c).split("-").at(2));

            }
            else
                lstDateDef.append(lstDate.at(c));
        }

    }
 if(query.exec("DELETE FROM evenement"))
    {

    }
    else
        QMessageBox::critical(0, QObject::tr("query Error supppretion non faite"),query.lastError().text());
    //28-01-15
    for(int c=0;c<lstId.count();c++)
    {
        query.prepare("insert into evenement values(:id,:dateEvenement,:evenement)");
        query.bindValue(":id", lstId.at(c).toInt());
        query.bindValue(":dateEvenement",lstDateDef.at(c));
        query.bindValue(":evenement",lstEevenement.at(c));
        query.exec();
    }
    query.clear();
    db.close();


}

void fenetregererCalendrier::lireListeEvenement()
{
    int c;
    for(c=0;c<m_listWidgetEvenement.count();c++)
    {
        m_listWidgetEvenement.at(c)->close();
    }
    m_listWidgetEvenement.clear();



    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_cheminEtNomDb);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }
    //query.exec("create table evenement (id int primary key ,dateEvenement DATE,evenement varchar(255))");

    QSqlQuery query;//SELECT pseudo, message, DATE_FORMAT(date, '%d/%m/%Y %Hh%imin%ss') AS date FROM minichat
    if(query.exec("SELECT * FROM evenement ORDER BY evenement.dateEvenement ASC"))
    {
        while(query.next())
        {//m_listWidgetPhoto.append(new miniWidgetPhoto(query.value(0).toInt(),m_cheminMediaPhoto+ query.value(1).toString(),m_cheminMediaPhoto+query.value(2).toString(),m_le_psedo->text(),m_socketMessage,m_socketFichier,m_sID,query.value(3).toString(),m_socketInfo,m_socketListe,query.value(7).toString(),this));
            m_listWidgetEvenement.append(new evenement(query.value(1).toString(),query.value(2).toString(),query.value(0).toInt(),m_cheminEtNomDb));
        }
    }
    else
    {
        QMessageBox::critical(0, QObject::tr("query Error"),query.lastError().text());
    }
    query.clear();
    db.close();




    for(c=0;c<m_listWidgetEvenement.count();c++)
    {
        m_layoutEvenement->addWidget(m_listWidgetEvenement.at(c),c,0);
        m_layoutEvenement->addItem(m_espaceMessageHorizontal,c,1);
        connect(m_listWidgetEvenement.at(c),SIGNAL(lireListe()),this,SLOT(lireListeEvenement()));

    }
    m_layoutEvenement->addItem(m_espaceMessageVartical,c+1,0);


    emit lireListe();
    //m_conteneurEnevement->adjustSize();
   // m_conteneurEnevement->adjustSize();

}


void fenetregererCalendrier::ajouter()
{
    m_fenetreAjouter=new QDialog();
    m_fenetreAjouter->setModal(true);
    m_fenetreAjouter->show();
    m_layoutAjout=new QGridLayout;
   // m_lb_ajoutDate=new QLabel *;
    m_de_ajoutDate=new QDateEdit(QDate::currentDate());
 //   QLabel *m_lb_ajoutEvenement;
    m_txe_ajoutEvenement=new QLineEdit;
    m_pb_ajoutEnregister=new QPushButton("enregister");
    m_layoutAjout->addWidget(m_de_ajoutDate,0,0);
    m_layoutAjout->addWidget(m_txe_ajoutEvenement,0,1);
    m_layoutAjout->addWidget(m_pb_ajoutEnregister,0,2);
    m_fenetreAjouter->setLayout(m_layoutAjout);
    connect(m_pb_ajoutEnregister , SIGNAL(clicked()), this,SLOT(enregister()));
    connect(m_pb_ajoutEnregister , SIGNAL(clicked()), m_fenetreAjouter,SLOT(accept()));
}

void fenetregererCalendrier::enregister()
{
   // QMessageBox::critical(0, QObject::tr("Database Error"),"db.lastError().text(");
    bool existeDeja=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;//c8
   if(query.exec("SELECT * FROM evenement ORDER BY evenement.dateEvenement ASC"))
    {
        while(query.next())
        {
            if(query.value(1).toString()==m_de_ajoutDate->date().toString("yyyy-MM-dd"))
            {
              //  QMessageBox::critical(0, QObject::tr("Database Error"),"existe");
                existeDeja=true;
            }
        }
    }





    if(!existeDeja)
    {
        int t(0);
        if(query.exec("select max(id) FROM evenement"))
        {
            while(query.next())
            {
                t=query.value(0).toInt();
            }
        }
    //   query.exec("create table evenement (id int primary key ,dateEvenement varchar(255),evenement varchar(255))");
        query.prepare("insert into evenement values(:id,:dateEvenement,:evenement)");
        query.bindValue(":id", t+1);
        query.bindValue(":dateEvenement",m_de_ajoutDate->date().toString("yyyy-MM-dd"));
        query.bindValue(":evenement",m_txe_ajoutEvenement->text());
        query.exec();
    }
    else
    {
        QString precedent;
        query.prepare("select evenement FROM evenement WHERE dateEvenement=:dateEvenement");
        query.bindValue(":dateEvenement",m_de_ajoutDate->date().toString("yyyy-MM-dd"));
        if(query.exec())
        {
            while(query.next())
            {
                precedent=query.value(0).toString();
            }
       }

        query.prepare("update evenement set evenement=:evenement where dateEvenement=:dateEvenement");
        query.bindValue(":dateEvenement",m_de_ajoutDate->date().toString("yyyy-MM-dd"));
        query.bindValue(":evenement",precedent+" ; "+ m_txe_ajoutEvenement->text());
        query.exec();
    }


    query.clear();
    db.close();


    lireListeEvenement();
}

void fenetregererCalendrier::slotFermer()
{
    emit lireListe();
}

