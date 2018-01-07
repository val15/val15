#include "FenetrePrincipale.h"
#include "WidgetMedia.h"



FenetrePrincipale::FenetrePrincipale()
{
    m_db="/var/www/html/valPod/valPodDB";
    m_chemin="/var/www/html/valPod/media/";
    m_rangerPar="id";

    setFixedSize(800,600);
    //zone central Ã  plusieurs element
    //m_zoneCentrale = new QMdiArea;//on cree une zone central Ã  multiple Ã©lements
    m_QTABOnglets = new QTabWidget;
    setCentralWidget(m_QTABOnglets);//on indique qu'il faut afficher "zoneCentrale" comment CentralWidget
   // m_widgetCentral= new QWidget;
    m_espaceMessageVartical = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_sousFenetreVideo =new QWidget;
   // m_sousFenetreVideo->setFixedSize(800,1600);
    m_sousFenetreAudio =new QWidget;
  //  m_sousFenetreAudio->setFixedSize(800,600);
    m_layoutVideo=new QGridLayout;
    m_layoutAudio=new QGridLayout;
    m_sousFenetreVideo->setLayout(m_layoutVideo);
    m_sousFenetreAudio->setLayout(m_layoutAudio);
    m_scl_areaAudio=new QScrollArea;
    m_scl_areaAudio->setWidgetResizable(true);
    m_scl_areaVideo=new QScrollArea;
    m_scl_areaVideo->setWidgetResizable(true);

    m_QTABOnglets->addTab(m_scl_areaVideo,"vidÃ©o");
    m_scl_areaVideo->setWidget(m_sousFenetreVideo);
    m_QTABOnglets->addTab(m_scl_areaAudio,"audio");
    m_scl_areaAudio->setWidget(m_sousFenetreAudio);




    //zone des menu
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QMenu *menuEdition = menuBar()->addMenu("&Edition");
    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");


    /*QMenu *fichiersRecents = menuFichier->addMenu("Fichiers &rÃ©cents");//on cree un nouveau menue au sein de la menu Fichier
    fichiersRecents->addAction("Fichier bidon 1.txt");//on ajoute en suit les action
    fichiersRecents->addAction("Fichier bidon 2.txt");
    fichiersRecents->addAction("Fichier bidon 3.txt");*/


    QAction *actionAjouter = new QAction("&Ajouter", this);//creation de l'action quiter
    menuFichier->addAction(actionAjouter);//ajout de l'action quiter au menu Fichier
    QAction *actionQuitter = menuFichier->addAction("&Quitter");//on cree l'action on mÃªme temps qu' on cree le menue on fait appelle Ã  une vertion surcharger de la mÃ©thode addAction
    actionQuitter->setShortcut(QKeySequence("ctrl+Q"));//ajout l'une racourcie clavier
    actionQuitter->setIcon(QIcon("quitter.ico"));//ajout d'une icone
    //ajout des sous menus
    QMenu *sm_videListe=menuFichier->addMenu("videl liste");
    QAction *actionViderAudio=sm_videListe->addAction("Vide liste audio");
    QAction *actionViderVideo=sm_videListe->addAction("Vide liste video");
    QAction *actionAfficherParTitre = new QAction("afficher par &titre ",this);
     QAction *actionAfficherParId = new QAction("afficher par &id ",this);
     menuAffichage->addAction(actionAfficherParTitre);
    menuAffichage->addAction(actionAfficherParId);


    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));//evenement quiter du menu fichier
    connect(actionAjouter, SIGNAL(triggered()), this, SLOT(ajouter()));
    connect(actionViderAudio, SIGNAL(triggered()), this, SLOT(viderAudio()));
    connect(actionViderVideo, SIGNAL(triggered()), this, SLOT(viderVideo()));
    connect(actionAfficherParTitre, SIGNAL(triggered()), this, SLOT(lireListeMediaParTitre()));
    connect(actionAfficherParId, SIGNAL(triggered()), this, SLOT(lireListeMediaParId()));






    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_db);
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;
    query.exec("create table media (id int primary key,titre varchar(255),date varchar(255),emplacement varchar(255),cathegorie varchar(255),etat varchar(255))");

    lireListeMediaParId();
}

void FenetrePrincipale::ajouter()
{


    /*QDir repParDfo("/home/val15/pod/");*/

  //  emplassement=QFileDialog::getOpenFileName(this, "chiosisser le fichier",,,,1);

    QStringList files=QFileDialog::getOpenFileNames(this,"chiosisser le(s) fichier(s)",m_chemin, "(*.webm *.ogg *.mp3 *.MP3 *.mp4 *.mp3*)");
    for(int c=0;c<files.count();c++)
    {
       /* QString emplassement;
       exist=false;
        emplassement=files.at(c);
        QString titreExtention;
        titreExtention=emplassement.mid(emplassement.lastIndexOf("/")+1);
        QString extention;
        extention=titreExtention.mid(titreExtention.lastIndexOf(".")+1);
        QString titre;
        titre+=titreExtention.left(titreExtention.indexOf("."));
        QMessageBox::critical(0, QObject::tr("emplassement"),emplassement);
        QMessageBox::critical(0, QObject::tr("titre"),titre);
        QMessageBox::critical(0, QObject::tr("extention"),extention);*/



        QString cheminEtTitre=files.at(c);
        bool exist=false;
        QString emplassement=cheminEtTitre.left(cheminEtTitre.lastIndexOf("/")+1);
        QString titre=cheminEtTitre.mid(cheminEtTitre.lastIndexOf("/")+1);
        QString extention=titre.mid(titre.lastIndexOf(".")+1);
        qDebug() << "emplassement : " << emplassement << endl;
        qDebug() << "titre : " <<titre << endl;
        qDebug() << "extention : "<<extention << endl;




        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
           db.setDatabaseName(m_db);
           if(!db.open())
           {
               QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
           }

           QSqlQuery query;

           if(query.exec("SELECT * FROM media"))
           {
               while(query.next())
               {
                   if(query.value(3).toString()==emplassement && query.value(1).toString()==titre)
                       exist=true;
               }
           }


        if(!exist)
        {
            QString cathegorie;
            if(extention.indexOf("mp3")!=-1 || extention.indexOf("ogg")!=-1 || extention.indexOf("MP3")!=-1)
            {
              cathegorie="audio";
            }
            else
            {
                cathegorie="video";
            }
           int T(0);
           if(query.exec("select max(id) FROM media"))
           {
               while(query.next())
               {
                   T=query.value(0).toInt();
               }
           }

        //query.exec("create table media (id int primary key,titre varchar(255),date varchar(255),emplacement varchar(255),cathegorie varchar(255))etat varchar(255),");

            query.prepare("insert into media values(:id, :titre,:date ,:emplacement,:cathegorie,:etat)");
            query.bindValue(":id",T+1);
           // qDebug() << "titre : " << titre << endl;
            query.bindValue(":titre",titre);
            query.bindValue(":date",m_dateTempsActuel.currentDateTime().toString("dd-MM-yyyy   H:m:s"));
            query.bindValue(":emplacement",emplassement);
            query.bindValue(":cathegorie",cathegorie);
            query.bindValue(":etat","non lue");

            query.exec();
            query.clear();
            db.close();
        }
    }

    if(m_rangerPar=="id")
        lireListeMediaParId();
    if(m_rangerPar=="titre")
        lireListeMediaParTitre();

}

void FenetrePrincipale::lireListeMediaParId()
{
   // actionAfficherParTitre->setEnabled(true);
   // actionAfficherParId->setEnabled(false);
    m_rangerPar="id";
    for(int c=0;c<m_listAudio.count();c++)
    {
        m_listAudio.at(c)->close();
    }
    for(int d=0;d<m_listVideo.count();d++)
    {
        m_listVideo.at(d)->close();
    }
    m_listAudio.clear();
    m_listVideo.clear();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_db);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }
    QSqlQuery query;

        if(query.exec("SELECT * FROM media ORDER BY media.id ASC"))
        {
            while(query.next())
            {
              //  qDebug() << query.value(1).toString()<< endl;
                if(query.value(4).toString()=="audio")
                {
                   // QMessageBox::critical(0, QObject::tr("Database Error"),query.value(1).toString());
                    //WidgetMedia(QString id,QString titre,QString date,QString emplacement,QString etat);
                    m_listAudio.append(new WidgetMedia(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
                }
                else
                {
                    m_listVideo.append(new WidgetMedia(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));

                }
            }
        }
    int j(0);
    QList<WidgetMedia *> ::iterator it;
    for(it = m_listAudio.begin() ; it!=m_listAudio.end(); ++it)
    {
        m_layoutAudio->addWidget(m_listAudio.at(j),j,0);
        j++;
    }
    m_layoutAudio->addItem(m_espaceMessageVartical,j,0);
    int i(0);
    QList<WidgetMedia *> ::iterator itv;
    for(itv = m_listVideo.begin() ; itv!=m_listVideo.end(); ++itv)
    {
        m_layoutVideo->addWidget(m_listVideo.at(i),i,0);
        i++;
    }
  // m_layoutVideo->addItem(m_espaceMessageVartical,i,0);
    query.clear();
    db.close();

    for(int a=0;a<m_listAudio.count();a++)
    {
        connect(m_listAudio.at(a), SIGNAL(singSupprimer()), this, SLOT(slotLireListeMedia()));
    }
    for(int b=0;b<m_listVideo.count();b++)
    {
        connect(m_listVideo.at(b), SIGNAL(singSupprimer()), this, SLOT(slotLireListeMedia()));
    }

}

void FenetrePrincipale::lireListeMediaParTitre()
{
   // actionAfficherParTitre->setEnabled(false);
  //  actionAfficherParId->setEnabled(true);
    m_rangerPar="titre";
    for(int c=0;c<m_listAudio.count();c++)
    {
        m_listAudio.at(c)->close();
    }
    for(int d=0;d<m_listVideo.count();d++)
    {
        m_listVideo.at(d)->close();
    }
    m_listAudio.clear();
    m_listVideo.clear();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_db);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }
    QSqlQuery query;
        if(query.exec("SELECT * FROM media ORDER BY media.titre"))
        {
            while(query.next())
            {
                if(query.value(4).toString()=="audio")
                {
                   // QMessageBox::critical(0, QObject::tr("Database Error"),query.value(1).toString());
                    //WidgetMedia(QString id,QString titre,QString date,QString emplacement,QString etat);
                    m_listAudio.append(new WidgetMedia(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
                }
                else
                {
                    m_listVideo.append(new WidgetMedia(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
                }
            }
        }
    int j(0);
    QList<WidgetMedia *> ::iterator it;
    for(it = m_listAudio.begin() ; it!=m_listAudio.end(); ++it)
    {
        m_layoutAudio->addWidget(m_listAudio.at(j),j,0);
        j++;
    }
    m_layoutAudio->addItem(m_espaceMessageVartical,j,0);
    int i(0);
    QList<WidgetMedia *> ::iterator itv;
    for(itv = m_listVideo.begin() ; itv!=m_listVideo.end(); ++itv)
    {
        m_layoutVideo->addWidget(m_listVideo.at(i),i,0);
        i++;
    }
  // m_layoutVideo->addItem(m_espaceMessageVartical,i,0);
    query.clear();
    db.close();

    for(int a=0;a<m_listAudio.count();a++)
    {
        connect(m_listAudio.at(a), SIGNAL(singSupprimer()), this, SLOT(slotLireListeMedia()));
    }
    for(int b=0;b<m_listVideo.count();b++)
    {
        connect(m_listVideo.at(b), SIGNAL(singSupprimer()), this, SLOT(slotLireListeMedia()));
    }
}

void FenetrePrincipale::slotLireListeMedia()
{
    if(m_rangerPar=="id")
        lireListeMediaParId();
    if(m_rangerPar=="titre")
        lireListeMediaParTitre();


}

void FenetrePrincipale::viderAudio()
{
    int reponse = QMessageBox::question(this, "Interrogatoire","Voulez vous reelment vider la liste des fichiers audios?", QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
           db.setDatabaseName(m_db);
           if(!db.open())
           {
               QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
           }
           QSqlQuery query;
        query.prepare("delete from media where media.cathegorie = :cathegorie");
        query.bindValue(":cathegorie","audio");
        query.exec();
        query.clear();
        db.close();
        for(int c=0;c<m_listAudio.count();c++)
        {
            m_listAudio.at(c)->supprimerFonct();
        }
    }
    lireListeMediaParId();

}

void FenetrePrincipale::viderVideo()
{
    int reponse = QMessageBox::question(this, "Interrogatoire","Voulez vous reelment vider la liste des fichiers videos?", QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
           db.setDatabaseName(m_db);
           if(!db.open())
           {
               QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
           }
           QSqlQuery query;
        query.prepare("delete from media where media.cathegorie = :cathegorie");
        query.bindValue(":cathegorie","video");
        query.exec();
        query.clear();
        db.close();

        for(int c=0;c<m_listVideo.count();c++)
        {

            m_listVideo.at(c)->supprimerFonct();

        }
        lireListeMediaParId();
    }

}

