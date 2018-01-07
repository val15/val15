#include "Fenetre0.h"
MaFenetre::MaFenetre() : QWidget()
{

    //il faut installer bwm-ng
    //il faut que la base de donne contienne des donnes
    //il faut que les fichiers "heurReveille" et "etatReveille" existent et ne sont pas vide




    m_chemin="/home/pi/";
    m_nomFichierDeConfig="horlogeAgenda.conf";//ce ficher contioen tout les config comme l'heur du reveil....
     m_cheminEtNomDb=m_chemin+"dbArduinoSerieHorlogeIneractifAgenda";
    m_portArd0="ttyACM0";
    m_portArd1="ttyACM1";


    m=0;
    pas=40;




    //creeation de la db
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;
   query.exec("create table evenement (id int primary key ,dateEvenement DATE,type varchar(255),heure TIME,evenement varchar(255))");
    query.clear();
    db.close();



    m_etindreAlrme="d";//d activer l'etinte
    m_etatClignotement="a";//a ou d
    m_etatVitesse="d";
    m_etatEspace="a";
    m_allumAuto=false;
    m_estConnecter=false;
    m_clignotementEstActivE=true;
    m_ledVitesseEstActivE=false;
    m_ledEspaceEstActivE=true;
    m_lumiereActvE=false;
    m_priseActivE=false;
    m_peutDEspace="f";
    m_btnconnexion=new QPushButton("connexion");// (D)Connecte la voie srie (bouton checkable)

    m_layoutGenerale=new QGridLayout;
    m_layoutHaut=new QGridLayout;

      m_layoutHaut->addWidget(m_btnconnexion,0,0);


    m_layoutAlarme=new QGridLayout;
    m_chbAlarme=new QCheckBox("activer réveil");
    m_lbReveil=new QLabel("réveil : ");
    m_btEteindreAlarme=new QPushButton("éteindre réveil");

    m_layoutCommande=new QGridLayout;
    m_btPrise=new QPushButton("activer prise");
    m_btLumiere=new QPushButton("allumer lumière");

    m_chbAllumAutomatque=new QCheckBox("allumage automatique à :");
    m_tieAllumAutomatque=new QTimeEdit;
    m_chbExtinctionAutomatque=new QCheckBox("éxtinction automatique à :");
    m_tieExtinctionAutomatque=new QTimeEdit;
    m_btClignote=new QPushButton("désactiver clignotement");
    m_layoutLed=new QGridLayout;
    m_layoutLed->addWidget(m_btClignote,0,0);
    m_tieSelectionReveille=new QTimeEdit();


    m_btClignote->setEnabled(false);
   /* m_chbAllumAutomatque->setEnabled(false);
    m_chbExtinctionAutomatque->setEnabled(false);*/
    m_btPrise->setEnabled(false);
    m_btLumiere->setEnabled(false);
    m_btLumiere=new QPushButton("allumer lumière");

    m_layoutAlarme->addWidget(m_lbReveil,0,0);
    m_layoutAlarme->addWidget(m_tieSelectionReveille,0,1);
    m_layoutAlarme->addWidget(m_chbAlarme,0,2);
    m_layoutAlarme->addWidget(m_btEteindreAlarme,0,3);

     m_layoutCommande->addWidget(m_chbAllumAutomatque,0,0);
     m_layoutCommande->addWidget(m_tieAllumAutomatque,0,1);
     m_layoutCommande->addWidget(m_chbExtinctionAutomatque,1,0);
     m_layoutCommande->addWidget(m_tieExtinctionAutomatque,1,1);
     m_layoutCommande->addWidget(m_btLumiere,0,2);
     m_layoutCommande->addWidget(m_btPrise,1,2);



     //pour le calandrier
     m_btGereCalentdier=new QPushButton("gérer calendrier");
     m_layoutCalandrier=new QGridLayout();
     m_cldr=new MaClandrier();
     m_lbEvenementsDuJour=new QLabel();
     QLabel *lbRdvDuJour= new QLabel("Les rendez-vous du jour : ");
     m_conteneurRvdDuJour=new QWidget;
     m_layoutRdvDuJour=new QGridLayout;
     m_areaConteneurRvdDuJour=new QScrollArea;
     m_areaConteneurRvdDuJour->setWidgetResizable(true);
     m_areaConteneurRvdDuJour->setWidget(m_conteneurRvdDuJour);

     m_conteneurRvdDuJour->setLayout(m_layoutRdvDuJour);
     m_btAjouterEvenement=new QPushButton("ajouter événement");
     m_layoutCalandrier->addWidget(m_btGereCalentdier,0,0);
     m_layoutCalandrier->addWidget(m_cldr,1,0);
     m_layoutCalandrier->addWidget(m_lbEvenementsDuJour,2,0);
     m_layoutCalandrier->addWidget(lbRdvDuJour,3,0);
     m_layoutCalandrier->addWidget(m_areaConteneurRvdDuJour,4,0);
     m_layoutCalandrier->addWidget(m_btAjouterEvenement,5,0);




    m_layoutGenerale->addLayout(m_layoutHaut,0,0);
    m_layoutGenerale->addLayout(m_layoutAlarme,1,0);
    m_layoutGenerale->addLayout(m_layoutCommande,2,0);
    m_layoutGenerale->addLayout(m_layoutLed,3,0);
    m_layoutGenerale->addLayout(m_layoutCalandrier,4,0);

   // m_pb_allumerEtindreLed=new QPushButton("allumer led");
  //  m_pb_allumerEtindreLed->setEnabled(false);
   // m_layoutGenerale->addWidget(m_pb_allumerEtindreLed,6,0);

    setLayout(m_layoutGenerale);





    m_dateTempsActuel=new QDateTime;
    m_timer=new QTimer;







    //pour le calandrier
    connect(m_cldr, SIGNAL(clicked(QDate)), this, SLOT(lectureDesEvenementsDuJour(QDate)));//lis les dade important du mois courant pour les colorer;
    connect(m_cldr, SIGNAL(currentPageChanged(int,int)), this, SLOT(lectureDesDatesImportantsDuMois(int,int)));//lis les dade important du mois courant pour les colorer;
    connect(m_btAjouterEvenement, SIGNAL(clicked()), this, SLOT(ajouterEvenement()));//lis les dade important du mois courant pour les colorer;





    QObject::connect(m_btGereCalentdier, SIGNAL(clicked()), this,SLOT(gererCalendrier()));

    //  QMessageBox::critical(0, QObject::tr("Database Error"),m_dateTempsActuel->currentDateTime().toString("mm:ss"));
    QObject::connect(m_btnconnexion , SIGNAL(clicked()), this,SLOT(connection()));
  //  QObject::connect(m_pb_allumerEtindreLed , SIGNAL(clicked()), this,SLOT(allumerEtindreLed()));
     QObject::connect(m_btClignote, SIGNAL(clicked()), this,SLOT(actiVOuDesactiVClignotement()));
     QObject::connect(m_btLumiere , SIGNAL(clicked()), this,SLOT(allumerOuEteindreLumiR()));
     QObject::connect(m_btPrise , SIGNAL(clicked()), this,SLOT(actiVOueteindrePrise()));
     QObject::connect(m_chbAllumAutomatque, SIGNAL(clicked()), this,SLOT(desativerActiverAllumeAuto()));
    QObject::connect(m_tieSelectionReveille , SIGNAL(editingFinished()), this,SLOT(ecrirConfig()));
    QObject::connect(m_chbAlarme , SIGNAL(clicked()), this,SLOT(ecrirConfig()));
    QObject::connect(m_tieAllumAutomatque , SIGNAL(editingFinished()), this,SLOT(ecrirConfig()));
    QObject::connect(m_chbAllumAutomatque , SIGNAL(clicked()), this,SLOT(ecrirConfig()));
    QObject::connect(m_chbExtinctionAutomatque , SIGNAL(clicked()), this,SLOT(ecrirConfig()));
    QObject::connect(m_tieExtinctionAutomatque , SIGNAL(editingFinished()), this,SLOT(ecrirConfig()));
    QObject::connect(m_btEteindreAlarme , SIGNAL(clicked()), this,SLOT(eteindreAlarme()));

    lireConfig();

    //lecture des dates
    lectureDesDatesImportantsDuMois(QDate::currentDate().year(),QDate::currentDate().month());
    lectureDesEvenementsDuJour(QDate::currentDate());

    //  connect(m_timerConnectionAutomatique,SIGNAL(timeout()),this,SLOT(connectionAutomatique()));
   connection();


   //lancement des serveur
   m_serveur=new Serveur(5115);
   QObject::connect(m_serveur,SIGNAL(emmetreMessageRecu(QString,int,int)),this,SLOT(traiterMessagServeur(QString,int,int)));
   QObject::connect(m_serveur,SIGNAL(emmetreDeconnecionClient()),this,SLOT(deconnectionClient()));
   m_serveur->lancement();
   m_serveurAndroid=new ServeurAndroid(6115);
   QObject::connect(m_serveurAndroid,SIGNAL(emmetreMessageRecu(QString,int,int)),this,SLOT(traiterMessagServeur(QString,int,int)));
  //GESTION DE LA DECONNEXION D'UN CLIENT A FAIRE
   QObject::connect(m_serveurAndroid,SIGNAL(emmetreDeconnecionClient()),this,SLOT(deconnectionClient()));
   m_serveurAndroid->lancement();




   MaFenetre::setWindowTitle("horloge agenda serveur");
   setFixedWidth(600);


}

void MaFenetre::traiterMessagServeur(QString msg,int indiceEnvoyeur,int typeDuSeveur)//7-1-17
{

    qDebug() << msg << " indice : "<<indiceEnvoyeur<< "type : " <<typeDuSeveur << endl;
   /* if(msg=="test")
        m_serveur->envoyerAUn("rep test");*/
    //on reçois la requette et on le change en tableau
    QStringList rqt=msg.split("#");
    repondreAuRequete(rqt,indiceEnvoyeur, typeDuSeveur);

}

void MaFenetre::repondreAuRequete(QStringList rqt,int indiceEnvoyeur,int typeDuSeveur)
{

    qDebug() << rqt << endl;
    QString type=rqt.at(0);
    if(type=="demandeDatesImportantesDuMois")
    {
        QString anneE=rqt.at(1);
        QString mois=rqt.at(2);
        repLectureDesDatesImportantesDuMois(anneE.toInt(),mois.toInt(),indiceEnvoyeur,typeDuSeveur);
    }
    if(type=="demandeEvenementsDuJourAndroid")
        repLectureDesEvenementsDuJourAndroid(rqt.at(1),indiceEnvoyeur,typeDuSeveur);
    if(type=="demandeEvenementsDuJour")
        repLectureDesEvenementsDuJour(rqt.at(1),indiceEnvoyeur,typeDuSeveur);
   // if(type==)
    if(type=="ajouterEvenement")
        exeAjouterEnregister(rqt);
    if(type=="ajouterEvenementEtRelecture")
        exeAjouterEnregisterEtRelecture(rqt,indiceEnvoyeur,typeDuSeveur);
    if(type=="supprimerEvenement")
        exeSupprimer(rqt);
    if(type=="supprimerEvenementEtRelecture")
        exeSupprimerEtRelecture(rqt,indiceEnvoyeur,typeDuSeveur);
    if(type=="supprimerEvenementEtRelectureEvenementDuJour")
        exeSupprimerEvenementEtRelectureEvenementDuJour(rqt,indiceEnvoyeur,typeDuSeveur);
    if(type=="modifierEvenement")
        exeModifierEvenement(rqt);
    if(type=="modifierEvenementEtRelecture")
        exeModifierEvenementEtRelecture(rqt,indiceEnvoyeur,typeDuSeveur);
    if(type=="modifierEvenementEtRelectureEvenementDuJour")
        exeModifierEvenementEtRelectureEvenementDuJour(rqt,indiceEnvoyeur,typeDuSeveur);
    if(type=="demandeToutLesEvenements")
        repLectureDesEvenements(indiceEnvoyeur,typeDuSeveur);
   if(type=="ecrireConfig")
       exeEcrireConfig(rqt);
   if(type=="demandeConfig")
       repLectureConfig();
   if(type=="demandeAllumerOuEteindreLumiR")//12-01-13h
       allumerOuEteindreLumiR();
   if(type=="demandeActiVOueteindrePrise")
       actiVOueteindrePrise();

   if(type=="demandeActiVOuDesactiVClignotement")
       actiVOuDesactiVClignotement();

   if(type=="demandeEteindreAlarme")
       eteindreAlarme();
}

void MaFenetre::deconnectionClient()
{

}

//pour arduinoSerieHorlogeIneractif
void MaFenetre::gererCalendrier()
{
    m_fcl=new fenetregererCalendrier(m_cheminEtNomDb);
    connect(m_fcl,SIGNAL(lireListeApreAjout()),this,SLOT(miseMA38()));//res particuliéera car affiche l'évement qui vien d'etre ajouté
    connect(m_fcl,SIGNAL(lireListe()),this,SLOT(lireEvenementDuJourEtProch1()));//a ne pas oublier
    connect(m_fcl,SIGNAL(lireListe()),this,SLOT(lectureDesDatesImportantsDuMois()));
    connect(m_fcl,SIGNAL(lireListe()),this,SLOT(lectureDesEvenementsDuJour()));

    m_fcl->setModal(true);
    m_fcl->show();
}

//slote qui appele les slotes des meme nom
void MaFenetre::lectureDesDatesImportantsDuMois()
{
    lectureDesDatesImportantsDuMois(QDate::currentDate().year(),QDate::currentDate().month());
  //  repLectureDesDatesImportantesDuMoisATout(QDate::currentDate().year(),QDate::currentDate().month());//on met à jour les calandriers des clients connéctés
}

void MaFenetre::lectureDesEvenementsDuJour()
{
    lectureDesEvenementsDuJour(QDate::currentDate());
}

//pour arduinoSerieHorlogeIneractif
void MaFenetre::lireEvenementDuJourEtProch1()
{
    //afin d'aviter de réafficher apres un suppretion
    m_lstEvenementAEnvoyer.clear();
    m_evenementDuJour.clear();
    QList <QStringList > lstEvenement;//un liste de QStringListe
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_cheminEtNomDb);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }

    QSqlQuery query;
    if(query.exec("SELECT * FROM evenement ORDER BY evenement.dateEvenement ASC"))
    {
        while(query.next())
        {
           // qDebug() << query.value(4).toString() << endl;
            //QMessageBox::critical(0, QObject::tr("test "),query.value(4).toString());
            QStringList conte;//il faut prendre: la date, le type, te temps et l'evenement
            conte.append(query.value(1).toString());
            conte.append(query.value(2).toString());
            //on enleve le seconde
            conte.append(query.value(3).toString().split(":").at(0)+":"+query.value(3).toString().split(":").at(1));
            conte.append(query.value(4).toString());

            lstEvenement.append(conte);//on met dans une liste de liste tout les evenneent
        }
    }
    else
    {
        qDebug() << "pas d'evennement" << endl;
        return;
    }

    query.clear();
    db.close();

   if(lstEvenement.isEmpty())
    {
       return;
    }
    else
    {
        //il faut verifier que le drnier evennement ne s'est pas dja passer
        //il faut une contion qui compare deux date (jour,mois)
       /* QString sDernierDate=lstEvenement.at(lstEvenement.count()-1).at(0);

        QDate dernierDateEv(sDernierDate.split("-").at(0).toInt(),sDernierDate.split("-").at(1).toInt(),sDernierDate.split("-").at(2).toInt());
    */ //   qDebug() << "dernier date : "<< dernierDateEv.toString("MM:dd") << endl;
      //  qDebug() << comparerDeuxDate(dernierDateEv.toString("MM-dd"),QDate::currentDate().toString("MM-dd")) << endl;

       if(lstEvenement.at(lstEvenement.count()-1).at(0)>=QDate::currentDate().toString("yyyy-MM-dd"))//comparerDeuxDate(dernierDateEv.toString("MM-dd"),QDate::currentDate().toString("MM-dd"))  !=-1 )// si il y a encore des evennemnt apres
        {
             int c=0;
             qDebug() << lstEvenement.count() << endl;

                 for(c=0;c<lstEvenement.count();c++)
                 {
                     if(lstEvenement.at(c).at(0).split("-").at(1)+"-"+lstEvenement.at(c).at(0).split("-").at(2) ==QDate::currentDate().toString("MM-dd"))//si la date de l'evenneent est egale  aujourduit
                     {
                         //QMessageBox::critical(0, QObject::tr("evenement du jour : "),"evenement du jour : "+m_lstEvenement.at(c).at(1));

                         if(lstEvenement.at(c).at(1)=="rendez-vous")//si C un rendevouz, on affiche l'heur du rdv
                             m_evenementDuJour+=">>"+lstEvenement.at(c).at(2)+":"+lstEvenement.at(c).at(3)+" ";//on le met dans l'evenneent du jour !!!
                         else
                             m_evenementDuJour+=">>"+lstEvenement.at(c).at(3)+" ";//on le met dans l'evenneent du jour !!!

                     //    m_etatClignotement="a";
                     }



                 }
               //on prend tout les évenement du meme date
                QList <QStringList > lstEvenementEnUnJour;//chaque element contient tout les évenement d'une date donnée,
               int i=0;
               while(i<lstEvenement.count())
               {

                   QStringList evenements;
                   evenements.append(lstEvenement.at(i).at(0));//le premiere element correspond à la date
                   evenements.append(lstEvenement.at(i).at(3));//les autres les évenement
                   int d=i+1;
                   while(d<lstEvenement.count())//on cherche les autres evenement du meme date
                   {
                       if(lstEvenement.at(i).at(0)==lstEvenement.at(d).at(0))//si la date est égal à la date actuel
                       {
                           evenements.append(lstEvenement.at(d).at(3));
                           i=d;//si on trouve, on passe dirrectement à l'indrice de l'élement
                       }
                       d++;
                   }
                    i++;
                   lstEvenementEnUnJour.append(evenements);
               }

               qDebug() << "les evenenem regouper par date : " << endl;
               for(int x=0;x<lstEvenementEnUnJour.count();x++)
                qDebug() <<  lstEvenementEnUnJour.at(x) << endl;
              //  determination de indexAujourdui

               if(!lstEvenementEnUnJour.isEmpty())
               {
                   int indexAujourdui=0;
                   bool suivantTrouvE=false;
                   for(int c=0;c<lstEvenementEnUnJour.count();c++)
                   {
                       if(lstEvenementEnUnJour.at(c).at(0)==QDate::currentDate().toString("yyyy-MM-dd"))//si il y a un evemenent le jour
                       {
                           indexAujourdui=c+1;
                           suivantTrouvE=true;
                        }
                       if(lstEvenementEnUnJour.at(c).at(0)>QDate::currentDate().toString("yyyy-MM-dd") && !suivantTrouvE)//si il n'y a pas d'evenemet, alors index devie le premier date apes ojourdui
                       {
                           indexAujourdui=c;
                           suivantTrouvE=true;
                       }
                   }
                   qDebug() << " index aujourduit : " << indexAujourdui << endl;

                   //QStringList lstDes3;
                    if(indexAujourdui<lstEvenementEnUnJour.count())
                    {
                        for(int c=0;c<3 ;c++)
                        {
                            //QString date=lstEvenementEnUnJour.at(indexAujourdui).at(0);//la date est le premiere element
                            QString date=lstEvenementEnUnJour.at(indexAujourdui).at(0).split("-").at(1)+"-"+lstEvenementEnUnJour.at(indexAujourdui).at(0).split("-").at(2);//la date est le premiere element

                            //QString date=lstEvenementEnUnJour.at(indexAujourdui).at(0);//la date est le premiere element

                            QString evenement;
                            for(int d=1;d<lstEvenementEnUnJour.at(indexAujourdui).count();d++)//les reste sont les evenements
                                 evenement+=lstEvenementEnUnJour.at(indexAujourdui).at(d)+";  ";
                            m_lstEvenementAEnvoyer.append(date+":"+evenement);
                            indexAujourdui++;
                            if(indexAujourdui==lstEvenementEnUnJour.count())//si en arrive à la fin, on revie à au
                                indexAujourdui=0;
                        }
                    }

                   qDebug() << m_lstEvenementAEnvoyer << endl;
                }
        }
       else
       {
           return;
       }
    }
}

//pour le calandrier
void MaFenetre::lectureDesDatesImportantsDuMois(int year,int month)
{
    QStringList lstDateEvenementDuMois;
    QStringList lstRdvDuMois;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_cheminEtNomDb);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }

    QSqlQuery query;
    if(query.exec("SELECT * FROM evenement ORDER BY evenement.dateEvenement ASC"))
    {
        while(query.next())
        {
            //qDebug() << query.value(1).toString().split("-").at(1) << QDate::currentDate().toString("mm") << endl;

                  //on ne prend que les evenement du mois en cour pour ne pas trop charger l'appication
            if(query.value(1).toString().split("-").at(1).toInt() == month)
            {
                if(query.value(2).toString()=="evenement a un jour")
                    lstDateEvenementDuMois.append(query.value(1).toString());
                if(query.value(2).toString()=="rendez-vous")
                     lstRdvDuMois.append(query.value(1).toString());
            }

        }
    }
    else
    {
        QMessageBox::critical(0, QObject::tr("erreur lecture"),query.lastError().text());
        return;
    }
    query.clear();
    db.close();
    m_cldr->colorerNormalepourLesAutres(month);


    for(int c=0;c<lstDateEvenementDuMois.count();c++)
    {
        QString a=lstDateEvenementDuMois.at(c).split("-").at(0);
        QString m=lstDateEvenementDuMois.at(c).split("-").at(1);
        QString j=lstDateEvenementDuMois.at(c).split("-").at(2);
        QDate d0(a.toInt(),m.toInt(),j.toInt());
        m_cldr->colorerEnBleu(d0);
    }
    for(int c=0;c<lstRdvDuMois.count();c++)
    {
        QString a=lstRdvDuMois.at(c).split("-").at(0);
        QString m=lstRdvDuMois.at(c).split("-").at(1);
        QString j=lstRdvDuMois.at(c).split("-").at(2);
        QDate d0(a.toInt(),m.toInt(),j.toInt());
        m_cldr->colorerEnJaune(d0);
    }
}

void MaFenetre::repLectureDesDatesImportantesDuMois(int year,int month,int indiceEnvoyeur,int typeDuSeveur)
{
   bool ilYADesEvenementsDansLeMois=false;
   QStringList lstDates;
    //QStringList lstRdvDuMois;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_cheminEtNomDb);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }

    QSqlQuery query;
    if(query.exec("SELECT * FROM evenement ORDER BY evenement.dateEvenement ASC"))
    {
        while(query.next())
        {
           // qDebug() << query.value(1).toString().split("-").at(1) << QDate::currentDate().toString("MM") << endl;

                  //on ne prend que les evenement du mois en cour pour ne pas trop charger l'appication
            if(query.value(1).toString().split("-").at(1).toInt() == month)
            {
                ilYADesEvenementsDansLeMois=true;
                    lstDates.append(query.value(1).toString()+"-"+query.value(2).toString());//query.value(2).toString() => type de l'évenement
            }
        }
    }
    else
    {
        QMessageBox::critical(0, QObject::tr("erreur lecture"),query.lastError().text());
        return;
    }
    query.clear();
    db.close();
    if(ilYADesEvenementsDansLeMois)
    {
        QString rep;
        rep+="lstDatesImportantesDuMois#";
        rep+=lstDates.join("#");//on envois les évemements
        if(typeDuSeveur==0)
            m_serveur->envoyerAUn(rep,indiceEnvoyeur);
        if(typeDuSeveur==1)
            m_serveurAndroid->envoyerAUn(rep,indiceEnvoyeur);
    }

}

void MaFenetre::repLectureDesDatesImportantesDuMoisATout(int year,int month)
{
    bool ilYADesEvenementsDansLeMois=false;
    QStringList lstDates;
     //QStringList lstRdvDuMois;
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(m_cheminEtNomDb);
        if(!db.open())
        {
            QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
        }

     QSqlQuery query;
     if(query.exec("SELECT * FROM evenement ORDER BY evenement.dateEvenement ASC"))
     {
         while(query.next())
         {
            // qDebug() << query.value(1).toString().split("-").at(1) << QDate::currentDate().toString("MM") << endl;

                   //on ne prend que les evenement du mois en cour pour ne pas trop charger l'appication
             if(query.value(1).toString().split("-").at(1).toInt() == month)
             {
                 ilYADesEvenementsDansLeMois=true;
                     lstDates.append(query.value(1).toString()+"-"+query.value(2).toString());//query.value(2).toString() => type de l'évenement
             }

         }
     }
     else
     {
         QMessageBox::critical(0, QObject::tr("erreur lecture"),query.lastError().text());
         return;
     }
     query.clear();
     db.close();
     if(ilYADesEvenementsDansLeMois)
     {
         QString rep;
         rep+="lstDatesImportantesDuMois#";
         rep+=lstDates.join("#");//on envois les évemements

             m_serveur->envoyerATous(rep);

             m_serveurAndroid->envoyerATous(rep);
     }
}

void MaFenetre::lectureDesEvenementsDuJour(QDate date)
{
    m_lbEvenementsDuJour->clear();
    m_listWidgetRdv.clear();
    m_areaConteneurRvdDuJour->setVisible(false);
    //QMessageBox::critical(0, QObject::tr("query Error"),"query.lastError().text()");
    QStringList lstEvenementsDuJour;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_cheminEtNomDb);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }

    QSqlQuery query;
    if(query.exec("SELECT * FROM evenement ORDER BY evenement.dateEvenement ASC"))
    {
        while(query.next())
        {
            //qDebug() << query.value(1).toString().split("-").at(1) << QDate::currentDate().toString("mm") << endl;

                  //on ne prend que les evenement du mois en cour pour ne pas trop charger l'appication
           // qDebug() << query.value(1).toString()  << endl;

            if(query.value(1).toString() == date.toString("yyyy-MM-dd"))
            {
                qDebug() << query.value(1).toString() << query.value(2).toString()  << endl;

                lstEvenementsDuJour.append(query.value(4).toString());
                if(query.value(2).toString()=="rendez-vous")
                {
                    qDebug() << query.value(1).toString() << query.value(2).toString()  << endl;
                    m_listWidgetRdv.append(new Rdv(query.value(1).toString(),query.value(3).toString(),query.value(4).toString(),query.value(0).toInt(),m_cheminEtNomDb));

                }
            }
        }
    }
    else
    {
        QMessageBox::critical(0, QObject::tr("query Error"),query.lastError().text());
        return;
    }
    query.clear();
    db.close();

    if(!lstEvenementsDuJour.isEmpty())
    {
        QString contenu="<strong>";
        for(int c=0;c<lstEvenementsDuJour.count();c++)
            contenu+=lstEvenementsDuJour.at(c) +" ; ";
        contenu+="</strong>";
        m_lbEvenementsDuJour->setText(date.toString("dd MMMM  :")+contenu);    
    }

  //  QMessageBox::critical(0, QObject::tr("query Error"),QString::number(m_listWidgetRdv.count()));

    if(!m_listWidgetRdv.isEmpty())
    {
        m_areaConteneurRvdDuJour->setVisible(true);
        for(int c=0;c<m_listWidgetRdv.count();c++ )
        {
            //QMessageBox::critical(0, QObject::tr("query Error"),QString::number(c));
            m_layoutRdvDuJour->addWidget(m_listWidgetRdv.at(c),c,0);
            //m_layoutEvenement->addItem(m_espaceMessageHorizontal,c,1);
            connect(m_listWidgetRdv.at(c),SIGNAL(lireListe()),this,SLOT(lectureDesEvenementsDuJour()));
        }
   }
   // m_leText->setText(date.toString("ddd MMMM d yy")+" ");
}

void MaFenetre::repLectureDesEvenementsDuJour(QString date,int indiceEnvoyeur,int typeDuSeveur)
{
    //QMessageBox::critical(0, QObject::tr("query Error"),"query.lastError().text()");
    QStringList lstEvenementsDuJour;
    QStringList lstRdv;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_cheminEtNomDb);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }

    QSqlQuery query;
    if(query.exec("SELECT * FROM evenement ORDER BY evenement.dateEvenement ASC"))
    {
        while(query.next())
        {
            /*qDebug() << ".toString() =" << query.value(1).toString() << endl;
            qDebug() << "date =" << date << endl;*/
            if(query.value(1).toString() == date)
            {
                qDebug() << query.value(1).toString() << query.value(2).toString()  << endl;

                lstEvenementsDuJour.append(query.value(4).toString());
                if(query.value(2).toString()=="rendez-vous")
                {
                    qDebug() << query.value(1).toString() << query.value(2).toString()  << endl;
                    lstRdv.append(query.value(1).toString()+";"+query.value(3).toString()+";"+query.value(4).toString()+";"+query.value(0).toString());

                }
            }
        }
    }
    else
    {
        QMessageBox::critical(0, QObject::tr("query Error"),query.lastError().text());
        return;
    }
    query.clear();
    db.close();

    QString rep;
    rep+="lstEvemenetDuJour#";
    rep+=lstEvenementsDuJour.join("#");//on envois les évemements
    rep+="#rdv#";//une sorte de separateur
    rep+=lstRdv.join("#");//on envoi les rdv
    if(!lstRdv.isEmpty())
        rep+="#";
    if(typeDuSeveur==0)
        m_serveur->envoyerAUn(rep,indiceEnvoyeur);
    if(typeDuSeveur==1)
        m_serveurAndroid->envoyerAUn(rep,indiceEnvoyeur);
}

void MaFenetre::repLectureDesEvenements(int indiceEnvoyeur,int typeDuSeveur)
{
    //QMessageBox::critical(0, QObject::tr("query Error"),"query.lastError().text()");
    QStringList lstEvenements;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_cheminEtNomDb);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }

    QSqlQuery query;
    if(query.exec("SELECT * FROM evenement ORDER BY evenement.dateEvenement ASC"))
    {
        while(query.next())
            lstEvenements.append(query.value(1).toString()+";"+query.value(2).toString()+";"+query.value(3).toString()+";"+query.value(4).toString()+";"+query.value(0).toString());
    }
    else
    {
        QMessageBox::critical(0, QObject::tr("query Error"),query.lastError().text());
        return;
    }
    query.clear();
    db.close();

    QString rep;
    rep+="lstEvenement#";
    rep+=lstEvenements.join("#");
    if(typeDuSeveur==0)
        m_serveur->envoyerAUn(rep,indiceEnvoyeur);
    if(typeDuSeveur==1)
        m_serveurAndroid->envoyerAUn(rep,indiceEnvoyeur);
}

void MaFenetre::repLectureDesEvenementsDuJourAndroid(QString date,int indiceEnvoyeur,int typeDuSeveur)
{
    //QMessageBox::critical(0, QObject::tr("query Error"),"query.lastError().text()");
    QStringList lstEvenements;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_cheminEtNomDb);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }

    QSqlQuery query;
    if(query.exec("SELECT * FROM evenement ORDER BY evenement.dateEvenement ASC"))
    {
        while(query.next())
        {
            if(query.value(1).toString() == date)
                lstEvenements.append(query.value(1).toString()+";"+query.value(2).toString()+";"+query.value(3).toString()+";"+query.value(4).toString()+";"+query.value(0).toString());
        }
    }
    else
    {
        QMessageBox::critical(0, QObject::tr("query Error"),query.lastError().text());
        return;
    }
    query.clear();
    db.close();

    QString rep;
    rep+="lstEvenement#";
    rep+=lstEvenements.join("#");
    if(typeDuSeveur==0)
        m_serveur->envoyerAUn(rep,indiceEnvoyeur);
    if(typeDuSeveur==1)
        m_serveurAndroid->envoyerAUn(rep,indiceEnvoyeur);
}

void MaFenetre::ajouterEvenement()
{
    QDialog *fenetreAjouter=new QDialog();
    fenetreAjouter->setModal(true);
    fenetreAjouter->setWindowTitle("ajout événement ou rdv");
    fenetreAjouter->show();
    QGridLayout *layoutAjoutPrincipal=new QGridLayout;
    QGridLayout *layoutAjoutElement=new QGridLayout;
   // m_lb_ajoutDate=new QLabel *;
    m_deAjoutDate=new QDateEdit(m_cldr->selectedDate());
    QLabel *lbDate=new QLabel("date");
    QLabel *lbType=new QLabel("type");
    QLabel *lbHeure=new QLabel("heure");
    QLabel *lbEvenement=new QLabel("evenement");
    m_leAjoutEvenement=new QLineEdit;
    m_btAjoutEnregister=new QPushButton("enregister");
    m_cbTypeAjoutEvennemt=new QComboBox();
    m_tieHeurAjoutEvennemt=new QTimeEdit();
    m_tieHeurAjoutEvennemt->setEnabled(false);
    QSpacerItem *spiV=new QSpacerItem(200,400,QSizePolicy::Minimum,QSizePolicy::Expanding);

    m_cbTypeAjoutEvennemt->addItem("evenement a un jour");
    m_cbTypeAjoutEvennemt->addItem("rendez-vous");
    layoutAjoutElement->addWidget(lbDate,0,0);
    layoutAjoutElement->addWidget(lbType,0,1);
    layoutAjoutElement->addWidget(lbHeure,0,2);
    layoutAjoutElement->addWidget(lbEvenement,0,3);
    layoutAjoutElement->addWidget(m_deAjoutDate,1,0);
    layoutAjoutElement->addWidget(m_leAjoutEvenement,1,3);
    layoutAjoutElement->addWidget(m_cbTypeAjoutEvennemt,1,1);
    layoutAjoutElement->addWidget(m_tieHeurAjoutEvennemt,1,2);
    layoutAjoutPrincipal->addLayout(layoutAjoutElement,0,0);
    layoutAjoutPrincipal->addWidget(m_btAjoutEnregister,1,0);
    layoutAjoutPrincipal->addItem(spiV,2,0);


    fenetreAjouter->setLayout(layoutAjoutPrincipal);
  /*  connect(btAjoutEnregister , SIGNAL(clicked()), this,SLOT(enregister()));
*/   connect(m_cbTypeAjoutEvennemt , SIGNAL(currentIndexChanged(QString)), this,SLOT(selectionTypeEvenement(QString)));
    connect(m_btAjoutEnregister , SIGNAL(clicked()), this,SLOT(ajouterEnregister()));
   /* connect(m_btAjoutEnregister , SIGNAL(clicked()), this,SLOT(lectureDesDatesImportantsDuMois()));
    connect(m_btAjoutEnregister , SIGNAL(clicked()), this,SLOT(lectureDesEvenementsDuJour()));
    connect(m_btAjoutEnregister , SIGNAL(clicked()), this,SLOT(lireEvenementDuJourEtProch1()));
  */  connect(m_btAjoutEnregister , SIGNAL(clicked()), fenetreAjouter,SLOT(accept()));
}

void MaFenetre::selectionTypeEvenement(QString texte)
{
   // QMessageBox::critical(0, QObject::tr("query Error"),"jjrj");
    if(texte=="evemenet a un jour")
        m_tieHeurAjoutEvennemt->setEnabled(false);
    if(texte=="rendez-vous")
        m_tieHeurAjoutEvennemt->setEnabled(true);
}

void MaFenetre::ajouterEnregister()
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

         lectureDesDatesImportantsDuMois();
       lectureDesEvenementsDuJour();
         lireEvenementDuJourEtProch1();
         m=38;//afin de tout de suite lire l'évement qui vient d'étre entré
}

void MaFenetre::exeAjouterEnregister(QStringList rqt)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;//c8

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
             query.bindValue(":dateEvenement",rqt.at(1));
             query.bindValue(":type",rqt.at(2));
             query.bindValue(":heure",rqt.at(3));
             query.bindValue(":evenement",rqt.at(4));
             query.exec();

         query.clear();
         db.close();

         lectureDesDatesImportantsDuMois();
       lectureDesEvenementsDuJour();
         lireEvenementDuJourEtProch1();
         m=38;//afin de tout de suite lire l'évement qui vient d'étre entré
}

void MaFenetre::exeAjouterEnregisterEtRelecture(QStringList rqt,int indiceEnvoyeur,int typeDuSeveur)
{
    exeAjouterEnregister(rqt);
    repLectureDesEvenements(indiceEnvoyeur,typeDuSeveur);//pour actualiser l'affichage du client

}

void MaFenetre::exeSupprimer(QStringList rqt)
{

       // QString sid=rqt.at(1).split('\n').first();
       qDebug() << "evenement à supprimer" << rqt.at(1).toInt() << endl;
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(m_cheminEtNomDb);
        if(!db.open())
        {
            QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
        }
        QSqlQuery query;
        query.prepare("delete from evenement where id=:id");
        query.bindValue(":id",rqt.at(1).toInt());
        query.exec();
        query.clear();
        db.close();


        lectureDesDatesImportantsDuMois();
        lectureDesEvenementsDuJour();
        lireEvenementDuJourEtProch1();
}

void MaFenetre::exeSupprimerEtRelecture(QStringList rqt,int indiceEnvoyeur,int typeDuSeveur)
{
        exeSupprimer(rqt);
        //on l'envoi à tout les clients pour s'assurer que tout les clients sont maj
        repLectureDesEvenements(indiceEnvoyeur,typeDuSeveur);//pour actualiser l'affichage du client
}

void MaFenetre::exeSupprimerEvenementEtRelectureEvenementDuJour(QStringList rqt,int indiceEnvoyeur,int typeDuSeveur)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;
    query.prepare("delete from evenement where id=:id");
    query.bindValue(":id",rqt.at(1).toInt());
    query.exec();
    query.clear();
    db.close();


    lectureDesDatesImportantsDuMois();
    lectureDesEvenementsDuJour();
    lireEvenementDuJourEtProch1();
    repLectureDesEvenementsDuJour(rqt.at(2),indiceEnvoyeur,typeDuSeveur);
}

void MaFenetre::exeModifierEvenement(QStringList rqt)
{
    //QString envt=rqt.at(5).split('\n').first();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
   // QMessageBox::critical(0, QObject::tr("Database Error"),m_cheminEtNomDb);

    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;
    query.prepare("update evenement set dateEvenement=:dateEvenement,type=:type,heure=:heure, evenement=:evenement where id=:id");
    query.bindValue(":id",rqt.at(1).toInt());
    query.bindValue(":dateEvenement",rqt.at(2));
    query.bindValue(":type",rqt.at(3));
    query.bindValue(":heure",rqt.at(4));
    query.bindValue(":evenement",rqt.at(5));
    query.exec();
    query.clear();
    db.close();
    lectureDesDatesImportantsDuMois();
    lectureDesEvenementsDuJour();
    lireEvenementDuJourEtProch1();
}

void MaFenetre::exeModifierEvenementEtRelecture(QStringList rqt,int indiceEnvoyeur,int typeDuSeveur)
{
    exeModifierEvenement(rqt);
    repLectureDesEvenements(indiceEnvoyeur,typeDuSeveur);//pour actualiser l'affichage du client
}

void MaFenetre::exeModifierEvenementEtRelectureEvenementDuJour(QStringList rqt,int indiceEnvoyeur,int typeDuSeveur)
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
    query.bindValue(":id",rqt.at(1).toInt());
    query.bindValue(":dateEvenement",rqt.at(2));
    query.bindValue(":type",rqt.at(3));
    query.bindValue(":heure",rqt.at(4));
    query.bindValue(":evenement",rqt.at(5));
    query.exec();
    query.clear();
    db.close();
    repLectureDesEvenementsDuJour(rqt.at(6),indiceEnvoyeur,typeDuSeveur);
    lectureDesDatesImportantsDuMois();
    lectureDesEvenementsDuJour();
    lireEvenementDuJourEtProch1();
}


//lecture et ecriture des configs
void MaFenetre::lireConfig()
{
    Fichier fConfig(m_chemin+m_nomFichierDeConfig);
    if(!fConfig.siExiste())
        return;
    else
    {
        m_heurReveil=fConfig.lireUneLigne(0);
        QStringList lst=m_heurReveil.split(":");
        int h=lst.at(0).toInt();
        int m=lst.at(1).toInt();
        QTime timeAlarm(h,m);
        m_tieSelectionReveille->setTime(timeAlarm);

        m_etatReveil=fConfig.lireUneLigne(1);//etat reveille
         if(m_etatReveil=="1")
            m_chbAlarme->setChecked(true);
         else
             m_chbAlarme->setChecked(false);

        m_heurAllumAutomatque=fConfig.lireUneLigne(2);
        lst=m_heurAllumAutomatque.split(":");
        h=lst.at(0).toInt();
        m=lst.at(1).toInt();
        QTime timeAllum(h,m);
        m_tieAllumAutomatque->setTime(timeAllum);

        m_etatAllumAutomatque=fConfig.lireUneLigne(3);//etat reveille
         if(m_etatAllumAutomatque=="1")
            m_chbAllumAutomatque->setChecked(true);
         else
            m_chbAllumAutomatque->setChecked(false);

         m_heurExtinctionAutomatque=fConfig.lireUneLigne(4);
         lst=m_heurExtinctionAutomatque.split(":");
         h=lst.at(0).toInt();
         m=lst.at(1).toInt();
         QTime time(h,m);
         m_tieExtinctionAutomatque->setTime(time);

         m_etatExtinctionAutomatique=fConfig.lireUneLigne(5);//etat reveille
          if(m_etatExtinctionAutomatique=="1")
             m_chbExtinctionAutomatque->setChecked(true);
          else
             m_chbExtinctionAutomatque->setChecked(false);
    }
}

void MaFenetre::ecrirConfig()
{
    if(m_chbAlarme->isChecked())
            m_etatReveil = "1";
    else
           m_etatReveil = "0";
    m_heurReveil=m_tieSelectionReveille->text();
    if(m_chbAllumAutomatque->isChecked())
        m_etatAllumAutomatque = "1";
    else
        m_etatAllumAutomatque = "0";
    m_heurAllumAutomatque=m_tieAllumAutomatque->text();

    if(m_chbExtinctionAutomatque->isChecked())
        m_etatExtinctionAutomatique="1";
    else
        m_etatExtinctionAutomatique="0";
    m_heurExtinctionAutomatque=m_tieExtinctionAutomatque->text();

     QString strConfig;//ce string contiedra les configuration
     strConfig+=m_heurReveil;
     strConfig+="\r\n";
     strConfig+=m_etatReveil;
     strConfig+="\r\n";
     strConfig+=m_heurAllumAutomatque;
     strConfig+="\r\n";
     strConfig+=m_etatAllumAutomatque;
     strConfig+="\r\n";
     strConfig+=m_heurExtinctionAutomatque;
     strConfig+="\r\n";
     strConfig+=m_etatExtinctionAutomatique;

     //ecriture dans le fichier
     QString nomFichier(m_chemin+m_nomFichierDeConfig);
     QFile fichier(nomFichier);
    // QMessageBox::critical(0, QObject::tr("Database Error"),"");//31
     fichier.open(QIODevice::WriteOnly);
     QTextStream strm( &fichier );
     strm << strConfig;
     //QMessageBox::critical(0, QObject::tr("Database Error"),m_te_selectionRevaille->text());
     fichier.close();

     repLectureConfig();
}

void MaFenetre::exeEcrireConfig(QStringList rqt)
{
    QString strConfig=rqt.at(1);//on écri dirrectement ce que l'on reçois dans le fichier
    //ecriture dans le fichier
    QString nomFichier(m_chemin+m_nomFichierDeConfig);
    QFile fichier(nomFichier);
   // QMessageBox::critical(0, QObject::tr("Database Error"),"");//31
    fichier.open(QIODevice::WriteOnly);
    QTextStream strm( &fichier );
    strm << strConfig;
    //QMessageBox::critical(0, QObject::tr("Database Error"),m_te_selectionRevaille->text());
    fichier.close();

    lireConfig();
    repLectureConfig();//on envoi à tout les clients la noveulle configuration
}

void MaFenetre::repLectureConfig()//11-01
{

    QString etatLumiere;
    QString etatPrise;
    QString etatClignotement;
    QString etatLedEspace;
    QString chActiverLedAutoVitesse;
    QString etatVitesseEstActivE;
    if(m_lumiereActvE)
        etatLumiere="1";
    else
        etatLumiere="0";
    if(m_priseActivE)
        etatPrise="1";
    else
        etatPrise="0";
    if(m_clignotementEstActivE)
        etatClignotement="1";
    else
        etatClignotement="0";
    if(m_ledEspaceEstActivE)
        etatLedEspace="1";
    else
        etatLedEspace="0";
    bool activerAutoLedVitesse=false;
    if(activerAutoLedVitesse)
        chActiverLedAutoVitesse="1";
    else
        chActiverLedAutoVitesse="0";
    if(m_ledVitesseEstActivE)
        etatVitesseEstActivE="1";
    else
        etatVitesseEstActivE="0";

    QStringList lstConfig;
    lstConfig.append("lstConfig");;
    lstConfig.append(m_etatReveil);
    lstConfig.append(m_heurReveil);
    lstConfig.append(m_etatAllumAutomatque);
    lstConfig.append(m_heurAllumAutomatque);
    lstConfig.append(m_etatExtinctionAutomatique);
    lstConfig.append(m_heurExtinctionAutomatque);
    lstConfig.append(etatLumiere);
    lstConfig.append(etatPrise);
    lstConfig.append(etatClignotement);
    lstConfig.append(etatLedEspace);
    lstConfig.append(chActiverLedAutoVitesse);
    lstConfig.append( etatVitesseEstActivE);
    QString rep;
    rep+=lstConfig.join("#");
    //m_serveur->envoyerAUn(rep,indice);
    m_serveur->envoyerATous(rep);
    m_serveurAndroid->envoyerATous(rep);
}






//Slot pour le click sur le bouton de connexion
void MaFenetre::connection()
{
    //deux cas de figures   grer, soit on coche (connecte), soit on dcoche (dconnecte)

    //on coche > connexion
    if(!m_estConnecter)
    {


        m_btClignote->setEnabled(true);


        m_btPrise->setEnabled(true);
        m_btLumiere->setEnabled(true);
        m_chbAllumAutomatque->setEnabled(true);
        m_estConnecter=true;

        //creation getBaudRateFromString
        m_arduinoAfficheur=new Arduino(m_portArd0,"9600");
        m_arduinoAfficheur->connection();
        connect(m_arduinoAfficheur,SIGNAL(recevoirDonnee(QString)),this,SLOT(setRecepton(QString)));
       m_arduinoCommande=new Arduino(m_portArd1,"900");
        m_arduinoCommande->connection();
        connect(m_arduinoCommande,SIGNAL(recevoirDonnee(QString)),this,SLOT(setRecepton(QString)));


        m_timer->start(1000);
        connect(m_timer,SIGNAL(timeout()),this,SLOT(temp()));

        m_btnconnexion->setText("Déconnecter");


        lireEvenementDuJourEtProch1();//a ne pas oublier quand les eveneoemnt est vide




    }
    else
    {

        m_btPrise->setEnabled(false);
        m_btLumiere->setEnabled(false);

        m_estConnecter=false;
        m_btClignote->setEnabled(false);

        //on se dconnecte de la carte Arduino
       //
        //**deconnection
        m_arduinoAfficheur->deConnection();
        m_arduinoCommande->deConnection();
        //puis on dtruit l'objet port srie devenu inutile
      //  delete port;
        m_btnconnexion->setText("Connecter");
        m_timer->stop();
    }


}

/*
void MaFenetre::enoyerEteindreLed()
{
  //  envoyerText("l=");
     m_etindreLeb="d";
}*/

void MaFenetre::actiVOuDesactiVClignotement()
{
    if(m_clignotementEstActivE)
    {
        m_etatClignotement="d";
        m_btClignote->setText("activer clignotement");

    }
    else
    {
        m_etatClignotement="a";
       m_btClignote->setText("désactiver clignotement");
    }
    m_clignotementEstActivE=!m_clignotementEstActivE;
    repLectureConfig();
}




void MaFenetre::temp()
{
    if(m_dateTempsActuel->currentDateTime().toString("HH:mm:ss")=="10:00:10")
        lireEvenementDuJourEtProch1();

    QString j;
    if(m_dateTempsActuel->currentDateTime().toString("ddd")=="Sun")
        j="dimanche";
    if(m_dateTempsActuel->currentDateTime().toString("ddd")=="Mon")
        j="lundi";
    if(m_dateTempsActuel->currentDateTime().toString("ddd")=="Tue")
        j="mardi";
    if(m_dateTempsActuel->currentDateTime().toString("ddd")=="Wed")
        j="mercredi";
    if(m_dateTempsActuel->currentDateTime().toString("ddd")=="Thu")
        j="jeudi";
    if(m_dateTempsActuel->currentDateTime().toString("ddd")=="Fri")
        j="vendredi";
    if(m_dateTempsActuel->currentDateTime().toString("ddd")=="Sat")
        j="samedi";
   QString mois;
   if(m_dateTempsActuel->currentDateTime().toString("MM")=="01")
       mois="janvier";
   if(m_dateTempsActuel->currentDateTime().toString("MM")=="02")
       mois="frevrier";
   if(m_dateTempsActuel->currentDateTime().toString("MM")=="03")
       mois="mars";
   if(m_dateTempsActuel->currentDateTime().toString("MM")=="04")
       mois="avril";
   if(m_dateTempsActuel->currentDateTime().toString("MM")=="05")
       mois="mai";
   if(m_dateTempsActuel->currentDateTime().toString("MM")=="06")
       mois="juin";
   if(m_dateTempsActuel->currentDateTime().toString("MM")=="07")
       mois="juillet";
   if(m_dateTempsActuel->currentDateTime().toString("MM")=="08")
       mois="aout";
   if(m_dateTempsActuel->currentDateTime().toString("MM")=="09")
       mois="septembre";
   if(m_dateTempsActuel->currentDateTime().toString("MM")=="10")
       mois="octobre";
   if(m_dateTempsActuel->currentDateTime().toString("MM")=="11")
       mois="novembre";
   if(m_dateTempsActuel->currentDateTime().toString("MM")=="12")
       mois="decembre";






    QString a;
    if(m_chbAlarme->isChecked())
        a="a";
    else
        a="d";

    QString lancherAlarm;
    if(m_chbAlarme->isChecked())
    {
        if(m_dateTempsActuel->currentDateTime().toString("HH:mm:ss")==m_tieSelectionReveille->time().toString("HH:mm:ss"))
        {
            lancherAlarm="a";
            m_etindreAlrme="a";
        }
    }
    else
    {
        lancherAlarm="d";
    }
    if(m_chbExtinctionAutomatque->isChecked())
    {
        if(m_dateTempsActuel->currentDateTime().toString("HH:mm:ss")==m_tieExtinctionAutomatque->time().toString("HH:mm:ss"))
        {
            qDebug() << "extinction des feux" << m_messageAEnvoyer  << endl;
            m_arduinoCommande->envoyerText("toutEtindre");
        }

    }

    //allume auto
    if(m_dateTempsActuel->currentDateTime().toString("HH:mm:ss")==m_tieAllumAutomatque->time().toString("HH:mm:ss"))
        activerAllumAuto();
    if(m_dateTempsActuel->currentDateTime().toString("HH:mm:ss")=="20:00:00")//desactivation de l'allumge auto
        desactiverAllumAuto();

    QString etatUneHeur="d";
    if(m_dateTempsActuel->currentDateTime().toString("mm:ss")=="00:00")
        etatUneHeur="a";
    else
        etatUneHeur="d";

    //pour les calendrier
    if(m>=0&&m<pas)
        m_messageAEnvoyer=j+m_dateTempsActuel->currentDateTime().toString(" dd ")+mois+m_dateTempsActuel->currentDateTime().toString(" yyyy");
    if(m>=pas&&m<pas*2)
    {
        if(m_evenementDuJour.isEmpty())
        {
            m=pas*3;
        }
        else
            m_messageAEnvoyer=m_evenementDuJour;
    }


    /*if(m>=pas*3&&m<pas*4)
        m_messageAEnvoyer=m_evenement1;
    if(m>=pas*4&&m<pas*5)
        m_messageAEnvoyer=m_evenement2;
    if(m>=pas*5&&m<pas*6)
        m_messageAEnvoyer=m_evenement3;*/
    int p=3;
    for(int c=0;c<m_lstEvenementAEnvoyer.count() && c<3;c++)
    {
        if(m>=pas*p&&m<pas*p+1)
            m_messageAEnvoyer=m_lstEvenementAEnvoyer.at(c);
        p++;
    }
  //  qDebug() << "m= " << m <<" ;ev du jour " << m_messageAEnvoyer  << endl;


    if(m>=pas*6)
        m=0;



    envoyerText("timeDate="+m_dateTempsActuel->currentDateTime().toString("HH:mm:ss")+"/"+a+"*"+etatUneHeur+"+"+lancherAlarm+"<"+m_etindreAlrme+">"+m_etatClignotement+"~"+m_messageAEnvoyer+"%"+"0k"+"\\"+m_peutDEspace+"{"+m_etatVitesse+"}"+m_etatEspace+"");


    m++;

}

void MaFenetre::desativerActiverAllumeAuto()
{
    if(m_allumAuto)
    {
        desactiverAllumAuto();
        m_allumAuto=false;

    }
    else
    {
        activerAllumAuto();
        m_allumAuto=true;

    }
}

void MaFenetre::desactiverAllumAuto()
{
    m_arduinoCommande->envoyerText("desactiverAllumAuto");
    //m_btActiverAllumAutomatque->setText("activer allumage automatisue");

}

void MaFenetre::activerAllumAuto()
{
    m_arduinoCommande->envoyerText("activerAllumAuto");
}

void MaFenetre::actiVOueteindrePrise()
{

    if(m_priseActivE)
    {
        m_arduinoCommande->envoyerText("desactiverPrise");
        m_btPrise->setText("activer prise");

    }
    else
    {
        m_arduinoCommande->envoyerText("activerPrise");
        m_btPrise->setText("désactiver prise");
    }
    m_priseActivE=!m_priseActivE;
    repLectureConfig();
}

void MaFenetre::allumerOuEteindreLumiR()
{
    if(m_lumiereActvE)
    {
        m_arduinoCommande->envoyerText("eteindreLumiere");
        m_btLumiere->setText("allumer lumière");

    }
    else
    {
        m_arduinoCommande->envoyerText("allumerLumiere");
        m_btLumiere->setText("éteindre lumiere");
    }
    m_lumiereActvE=!m_lumiereActvE;
    repLectureConfig();
}

void MaFenetre::eteindreAlarme()
{
    m_etindreAlrme="d";//pour eteindre l'alarme
}


/*
void MaFenetre::readData()
{

    if(str=="0")
    {
        caractere =  "allumer";
    }
    else if(str=="1")
    {
        caractere =  "etindre";
    }


}*/

void MaFenetre::envoyerText(QString text)
{
    m_arduinoAfficheur->envoyerText(text);
}

void MaFenetre::setRecepton(QString txtRecu)
{

    qDebug() << txtRecu << endl;
    if(txtRecu.contains("ttyACM1:b"))
    {
        m_etatClignotement="d";//eteindre le clignotement
       // qDebug() << txtRecu << endl;
    }

    if(txtRecu.contains("ttyACM1:a"))
    {
       //m_btActiverAllumAutomatque->setText("activer allumage automatisue");
        m_etindreAlrme="d";//pour eteindre l'alarme


    }


    m_lumiereActvE=!m_lumiereActvE;
}

void MaFenetre::miseMA38()
{
    m=38;//afin de tout de suite lire l'évement qui vient d'étre entré
}
