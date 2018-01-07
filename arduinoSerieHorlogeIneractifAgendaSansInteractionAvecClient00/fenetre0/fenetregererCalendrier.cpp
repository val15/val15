#include "fenetregererCalendrier.h"


fenetregererCalendrier::fenetregererCalendrier(QString cheminEtNomDb)
{
   //setFixedSize(800,8000);
    //setFixedWidth(500);
    m_cheminEtNomDb=cheminEtNomDb;




    m_layoutGenerale=new QGridLayout;
    setLayout(m_layoutGenerale);
    m_layoutEvenement=new QGridLayout;
    m_btAjouter=new QPushButton("ajouter");
    m_layoutGenerale->addWidget(m_btAjouter,0,0);
    //m_layoutEvenement->


    m_areaEnevement=new QScrollArea(this);
    m_areaEnevement->setWidgetResizable(true);
    m_conteneurEnevement=new QWidget;
   // m_conteneurEnevement->setFixedSize(500,8000);
    m_conteneurEnevement->adjustSize();
    m_areaEnevement->setWidget(m_conteneurEnevement);
    m_conteneurEnevement->setLayout(m_layoutEvenement);
    m_layoutGenerale->addWidget(m_areaEnevement,1,0);
    m_btMajAnnee=new QPushButton("mise a jour annee");
    m_layoutGenerale->addWidget(m_btMajAnnee,2,0);
    m_espaceMessageVartical=new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);;
    m_espaceMessageHorizontal = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

  //  mieAJourAnnE();
    lireListeEvenement();

    connect(this, SIGNAL(close()), this,SLOT(slotFermer()));
    connect(m_btAjouter, SIGNAL(clicked()), this,SLOT(ajouter()));
    connect(m_btMajAnnee, SIGNAL(clicked()), this,SLOT(miseAJourAnnE()));
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
        QMessageBox::critical(0, QObject::tr("erreur lors lecture de la base"),query.lastError().text());
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
    for(c=0;c<m_listWidgetEvenementEtRdv.count();c++)
    {
        m_listWidgetEvenementEtRdv.at(c)->close();
    }
    m_listWidgetEvenementEtRdv.clear();



    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_cheminEtNomDb);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }
    //query.exec("create table evenement (id int primary key ,dateEvenement DATE,evenement varchar(255))");

    QSqlQuery query;
    if(query.exec("SELECT * FROM evenement ORDER BY evenement.dateEvenement ASC"))
    {
        while(query.next())
        {//m_listWidgetPhoto.append(new miniWidgetPhoto(query.value(0).toInt(),m_cheminMediaPhoto+ query.value(1).toString(),m_cheminMediaPhoto+query.value(2).toString(),m_le_psedo->text(),m_socketMessage,m_socketFichier,m_sID,query.value(3).toString(),m_socketInfo,m_socketListe,query.value(7).toString(),this));

           // qDebug() << query.value(0).toString()<< query.value(1).toString() << query.value(2).toString()<< query.value(3).toString() << query.value(4).toString()<< endl;
            if(query.value(2).toString()=="evenement a un jour")
                m_listWidgetEvenementEtRdv.append(new Evenement(query.value(1).toString(),query.value(4).toString(),query.value(0).toInt(),m_cheminEtNomDb));
            if(query.value(2).toString()=="rendez-vous")
                m_listWidgetEvenementEtRdv.append(new Rdv(query.value(1).toString(),query.value(3).toString(),query.value(4).toString(),query.value(0).toInt(),m_cheminEtNomDb));
        }
    }
    else
    {
        QMessageBox::critical(0, QObject::tr("query Error"),query.lastError().text());
    }
    query.clear();
    db.close();




    for(c=0;c<m_listWidgetEvenementEtRdv.count();c++)
    {
        m_layoutEvenement->addWidget(m_listWidgetEvenementEtRdv.at(c),c,0);
        m_layoutEvenement->addItem(m_espaceMessageHorizontal,c,1);
     connect(m_listWidgetEvenementEtRdv.at(c),SIGNAL(lireListe()),this,SLOT(lireListeEvenement()));

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
    m_deAjoutDate=new QDateEdit(QDate::currentDate());
 //   QLabel *m_lb_ajoutEvenement;
    m_leAjoutEvenement=new QLineEdit;
    m_btAjoutEnregister=new QPushButton("enregister");
    m_cbTypeAjoutEvennemt=new QComboBox();
    m_tieHeurAjoutEvennemt=new QTimeEdit();
    m_tieHeurAjoutEvennemt->setEnabled(false);
    m_cbTypeAjoutEvennemt->addItem("evenement a un jour");
    m_cbTypeAjoutEvennemt->addItem("rendez-vous");
    m_layoutAjout->addWidget(m_deAjoutDate,0,0);
    m_layoutAjout->addWidget(m_cbTypeAjoutEvennemt,0,1);
    m_layoutAjout->addWidget(m_tieHeurAjoutEvennemt,0,2);
    m_layoutAjout->addWidget(m_leAjoutEvenement,0,3);
    m_layoutAjout->addWidget(m_btAjoutEnregister,0,4);
    m_fenetreAjouter->setLayout(m_layoutAjout);
    connect(m_cbTypeAjoutEvennemt , SIGNAL(currentIndexChanged(QString)), this,SLOT(selectionTypeEvenement(QString)));
    connect(m_btAjoutEnregister , SIGNAL(clicked()), this,SLOT(enregister()));
    connect(m_btAjoutEnregister , SIGNAL(clicked()), m_fenetreAjouter,SLOT(accept()));

}

void fenetregererCalendrier::selectionTypeEvenement(QString texte)
{
   // QMessageBox::critical(0, QObject::tr("query Error"),"jjrj");
    if(texte=="evemenet a un jour")
        m_tieHeurAjoutEvennemt->setEnabled(false);
    if(texte=="rendez-vous")
        m_tieHeurAjoutEvennemt->setEnabled(true);
}

void fenetregererCalendrier::enregister()
{
    // QMessageBox::critical(0, QObject::tr("Database Error"),"db.lastError().text(");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;//c8

    //verifier si competement identique

    //si pas identique
    //pour les evenements en un jour

             int t(0);
             if(query.exec("select max(id) FROM evenement"))
             {
                 while(query.next())
                 {
                     t=query.value(0).toInt();
                 }
             }
         //   query.exec("create table evenement (id int primary key ,dateEvenement varchar(255),evenement varchar(255))");
             //   query.exec("create table evenement (id int primary key ,dateEvenement DATE,type varchar(255),heure TIME,evenement varchar(255))");

             query.prepare("insert into evenement values(:id,:dateEvenement,:type,:heure,:evenement)");//myr
             query.bindValue(":id", t+1);
             query.bindValue(":dateEvenement",m_deAjoutDate->date().toString("yyyy-MM-dd"));
             query.bindValue(":type",m_cbTypeAjoutEvennemt->currentText());
             query.bindValue(":heure",m_tieHeurAjoutEvennemt->time().toString("hh:mm:ss"));
             query.bindValue(":evenement",m_leAjoutEvenement->text());
             query.exec();


         query.clear();
         db.close();




    lireListeEvenement();
    emit lireListe();
}

void fenetregererCalendrier::slotFermer()
{
    emit lireListe();
}

