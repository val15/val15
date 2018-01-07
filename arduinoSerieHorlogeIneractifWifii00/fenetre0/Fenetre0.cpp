#include "Fenetre0.h"
MaFenetre::MaFenetre() : QWidget()
{


    //il faut installer bwm-ng
    //il faut que la base de donn�e contienne des donn�es
    //il faut que les fichiers "heurReveille" et "etatReveille" existent et ne sont pas vide
    //pour le wifi
    m_angleH="90";
    m_angleV="90";

    m_dbMon="/home/pi/dbWifi";
    m_nomFichierDernierCoord="/home/pi/derierCoodr";
    m_dernierCoord="90";



    m_chemin="/home/pi/";
     m_cheminEtNomDb=m_chemin+"dbarduinoSerieHorlogeIneractif";
    m_portArd0="ttyACM0";
    m_portArd1="ttyACM1";

    m_debit="0K";

    m=0;
    pas=40;

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
    m_comboVitesse=new QComboBox; // Permet de choisir la vitesse de communication
    m_btnconnexion=new QPushButton("connection");// (Dé)Connecte la voie série (bouton “checkable”)

    m_layoutGenerale=new QGridLayout;
    m_layoutHaut=new QGridLayout;
    m_lb_typeDebit=new QLabel("type debit :");
    m_cbTypeDebit=new QComboBox;
    m_cbTypeDebit->addItem("debit client");
    m_cbTypeDebit->addItem("debit interne");
    m_estDebitInterne=false;
    m_layoutHaut->addWidget(m_lb_typeDebit,0,0);
    m_layoutHaut->addWidget(m_cbTypeDebit,0,1);
    m_pb_gereCalentdier=new QPushButton("gerecalendrier");
     m_layoutHaut->addWidget(m_btnconnexion,0,5);
    m_layoutHaut->addWidget(m_pb_gereCalentdier,0,4);

    m_layoutAlarme=new QGridLayout;
    m_cb_alarme=new QCheckBox;
    m_btPrise=new QPushButton("activer prise");
    m_btLumiere=new QPushButton("allumer lumiere");
    m_btActiverAllumAutomatque=new QPushButton("activer allumage automatisue");
    m_btClignote=new QPushButton("desactiver clignotement");
    m_btVitesse=new  QPushButton("activer led vitesse");
    m_chbActiverAutoLedVitesse=new QCheckBox("automatique led vitesse");
    m_activerAutoLedVitesse=false;
    m_chbActiverAutoLedVitesse->setChecked(false);
    m_btEspace=new   QPushButton("desactiver led espace faible");
    m_layoutLed=new QGridLayout;
    m_layoutLed->addWidget(m_btClignote,0,0);
    m_layoutLed->addWidget(m_btEspace,0,1);
    m_layoutLed->addWidget(m_btVitesse,0,2);
    m_layoutLed->addWidget(m_chbActiverAutoLedVitesse,0,3);
    m_te_selectionRevaille=new QTimeEdit;
    m_btClignote->setEnabled(false);
    m_btVitesse->setEnabled(false);
    m_btEspace->setEnabled(false);
    m_btActiverAllumAutomatque->setEnabled(false);
    m_btPrise->setEnabled(false);
    m_btLumiere->setEnabled(false);
    m_btLumiere=new QPushButton("allumer lumiere");
    m_layoutAlarme->addWidget(m_te_selectionRevaille,0,0);
    m_layoutAlarme->addWidget(m_cb_alarme,0,1);
     m_layoutAlarme->addWidget(m_btActiverAllumAutomatque,0,2);
     m_layoutAlarme->addWidget(m_btLumiere,0,3);
     m_layoutAlarme->addWidget(m_btPrise,0,4);



     //pour le wifi
     m_premierDemarage=true;
     m_C=0;
     m_modele = new QStringListModel(m_lstNomAp);//pour la liste des ap
     //base de bonnee
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName(m_dbMon);
     if(!db.open())
     {
         QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
     }
     QSqlQuery query;
     query.exec("create table ap (id int primary key,nom varchar(255),angleH varchar(255),angleV varchar(255))");
     m_estConnecT=false;

     m_gltWifi=new QGridLayout();
     m_gltHaut=new QGridLayout();
     m_gltMilieu=new QGridLayout();
     m_gltBas=new QGridLayout();
     m_gltCommande=new QGridLayout();
     m_gltHorizontal=new QGridLayout();
     m_gltVeritcal=new QGridLayout();
     m_gltEnregistrement=new QGridLayout();

     m_lbSIDD=new QLabel("SIDD :  ");
     m_cbSIDD=new QComboBox();
     m_btSupprimer=new QPushButton("supprimer");
     m_btVider=new QPushButton("vider");

     m_btCharger=new  QPushButton("charger");
     m_lcdnAngleH=new QLCDNumber();
     m_lcdnAngleV=new QLCDNumber();
     m_lcdnAngleH->display(90);
     m_lcdnAngleV->display(90);
     m_lcdnAngleH->setSegmentStyle(QLCDNumber::Flat);
     m_lcdnAngleV->setSegmentStyle(QLCDNumber::Flat);
     m_sldH=new QSlider(Qt::Horizontal);
     m_sldV=new QSlider();
     m_sldH->setMinimum(0);
     m_sldH->setMaximum(180);
     m_sldH->setValue(90);
     m_sldV->setMinimum(70);
     m_sldV->setMaximum(110);
     m_sldV->setValue(90);
    /* m_lcdnAngleH->setEnabled(false);
     m_sldH->setEnabled(false);*/
     m_lcdnAngleV->setEnabled(false);
     m_sldV->setEnabled(false);
     m_btCharger->setEnabled(false);
     m_lcdnAngleH->setEnabled(false);
     m_sldH->setEnabled(false);


     m_lbE=new QLabel("E");
     m_lbW=new QLabel("W");
     m_lbM=new QLabel("M");
     m_lbD=new QLabel("D");

      m_btEnvoyerCoorH=new QPushButton("envyer");
      m_btEnvoyerCoorV=new QPushButton("envyer");
      m_btEnvoyerCoorH->setEnabled(false);
      m_btEnvoyerCoorV->setEnabled(false);



     m_lbEnrNomSIDD=new QLabel("nom SIDD :  ");
     m_leEnrNomSIDD=new QLineEdit();
     m_btEnregister=new QPushButton("enregister");



     m_gltHaut->addWidget(m_lbSIDD,0,0);
     m_gltHaut->addWidget(m_cbSIDD,0,1);
     m_gltHaut->addWidget(m_btSupprimer,0,2);
     m_gltHaut->addWidget(m_btVider,0,3);

     m_gltHorizontal->addWidget(m_lbW,0,0);
     m_gltHorizontal->addWidget(m_sldH,0,1);
     m_gltHorizontal->addWidget(m_lbE,0,2);

     m_gltVeritcal->addWidget(m_lbD,0,0);
     m_gltVeritcal->addWidget(m_sldV,1,0);
     m_gltVeritcal->addWidget(m_lbM,2,0);

     m_gltCommande->addWidget(m_lcdnAngleH,0,0);
     m_gltCommande->addWidget(m_lcdnAngleV,0,1);
     m_gltCommande->addLayout(m_gltHorizontal,1,0);
     m_gltCommande->addLayout(m_gltVeritcal,1,1);
     m_gltCommande->addWidget(m_btEnvoyerCoorH,2,0);
     m_gltCommande->addWidget(m_btEnvoyerCoorV,2,1);
      m_gltMilieu->addWidget(m_btCharger,0,0);
       m_gltMilieu->addLayout(m_gltCommande,1,0);

     m_gltEnregistrement->addWidget(m_lbEnrNomSIDD,0,0);
     m_gltEnregistrement->addWidget(m_leEnrNomSIDD,0,1);
     m_gltBas->addLayout(m_gltEnregistrement,0,0);
      m_gltBas->addWidget(m_btEnregister,1,0);

      m_gltWifi->addLayout(m_gltHaut,2,0);
      m_gltWifi->addLayout(m_gltMilieu,3,0);
      m_gltWifi->addLayout(m_gltBas,4,0);



    m_layoutGenerale->addLayout(m_layoutHaut,0,0);
    m_layoutGenerale->addLayout(m_layoutAlarme,1,0);
    m_layoutGenerale->addLayout(m_layoutLed,2,0);
    m_layoutGenerale->addLayout(m_gltWifi,3,0);

   // m_pb_allumerEtindreLed=new QPushButton("allumer led");
  //  m_pb_allumerEtindreLed->setEnabled(false);
   // m_layoutGenerale->addWidget(m_pb_allumerEtindreLed,6,0);

    setLayout(m_layoutGenerale);


    m_comboVitesse->addItem("9600");
    m_comboVitesse->addItem("300");
    m_comboVitesse->addItem("1200");
    m_comboVitesse->addItem("2400");
    m_comboVitesse->addItem("4800");
    m_comboVitesse->addItem("19200");
    m_comboVitesse->addItem("38400");
    m_comboVitesse->addItem("57600");
    m_comboVitesse->addItem("115200");


    m_dateTempsActuel=new QDateTime;
    m_timer=new QTimer;


  /*  m_timerConnectionAutomatique=new QTimer;
    m_timerConnectionAutomatique->start(3);*/
    //pour arduinoSerieHorlogeIneractif

//    lireEvenementDuJourEtProch1();
    QObject::connect(m_pb_gereCalentdier  , SIGNAL(clicked()), this,SLOT(gererCalendrier()));


  //  QMessageBox::critical(0, QObject::tr("Database Error"),m_dateTempsActuel->currentDateTime().toString("mm:ss"));
    QObject::connect(m_btnconnexion , SIGNAL(clicked()), this,SLOT(connection()));
  //  QObject::connect(m_pb_allumerEtindreLed , SIGNAL(clicked()), this,SLOT(allumerEtindreLed()));
    QObject::connect(m_cb_alarme , SIGNAL(clicked()), this,SLOT(ecrireActiverReveille()));
    QObject::connect(m_cb_alarme , SIGNAL(clicked()), this,SLOT(slotEnvoyerEtatAlerte()));
     QObject::connect(m_btClignote, SIGNAL(clicked()), this,SLOT(actiVOuDesactiVClignotement()));
      QObject::connect(m_btVitesse, SIGNAL(clicked()), this,SLOT(actiVOuDesactiVVitesse()));
      QObject::connect(m_chbActiverAutoLedVitesse, SIGNAL(clicked()), this,SLOT(actiVOuDesactiVVitesseAuto()));
      QObject::connect(m_btEspace, SIGNAL(clicked()), this,SLOT(actiVOuDesactiVEspace()));
     QObject::connect(m_btLumiere , SIGNAL(clicked()), this,SLOT(allumerOuEteindreLumiR()));
     QObject::connect(m_btPrise , SIGNAL(clicked()), this,SLOT(actiVOueteindrePrise()));
     QObject::connect(m_btActiverAllumAutomatque, SIGNAL(clicked()), this,SLOT(desativerActiverAllumeAuto()));
    QObject::connect(m_te_selectionRevaille , SIGNAL(editingFinished()), this,SLOT(ecrireActiverReveille()));

    //wifi
    QObject::connect(m_sldH, SIGNAL(valueChanged(int)), this,SLOT(changerValeurH(int)));
    QObject::connect(m_sldV, SIGNAL(valueChanged(int)), this,SLOT(changerValeurV(int)));
    QObject::connect(m_btEnregister, SIGNAL(clicked()), this,SLOT(enregister()));
      QObject::connect(m_btSupprimer, SIGNAL(clicked()), this,SLOT(supprimer()));
    QObject::connect(m_btVider, SIGNAL(clicked()), this,SLOT(vider()));
     QObject::connect(m_btCharger, SIGNAL(clicked()), this,SLOT(charger()));
     QObject::connect(m_btEnvoyerCoorH, SIGNAL(clicked()), this,SLOT(envoyerCoordH()));
     QObject::connect(m_btEnvoyerCoorV, SIGNAL(clicked()), this,SLOT(envoyerCoordV()));



    lireHeurReveille();
    lireEtatReveille();
    //pour le wifi
    lireDernierCoord();
    lireDb();
    //  connect(m_timerConnectionAutomatique,SIGNAL(timeout()),this,SLOT(connectionAutomatique()));
   connection();


   //lancement du serveur

   m_serveur=new Serveur("192.168.15.115",5115);
   QObject::connect(m_serveur,SIGNAL(emmetreMessage(QString)),this,SLOT(traiterMessagServeur(QString)));
   QObject::connect(m_serveur,SIGNAL(emmetreDeconnecionClient()),this,SLOT(deconnectionClient()));

   m_serveur->lancement();
}

void MaFenetre::traiterMessagServeur(QString msg)
{
    m_debit=msg;
}

void MaFenetre::deconnectionClient()
{
    m_debit="0K";
}

//slote et fonction pour le wifi

void MaFenetre::enregister()
{
    if(m_leEnrNomSIDD->text()=="")
    {
        QMessageBox::critical(0, QObject::tr("Erreur"),"nom du sidd vide");
    }
    else
   {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
          db.setDatabaseName(m_dbMon);
          if(!db.open())
          {
              QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
          }

            QSqlQuery query;

            //verification si existe deja
            bool existeDeja=false;
            if(query.exec("SELECT * FROM ap ORDER BY ap.id ASC"))
            {
                while(query.next())
                {

                    //   QMessageBox::information(0, QObject::tr("info"),query.value(2).toString());
                      // QMessageBox::information(0, QObject::tr("info"),query.value(3).toString());
                    if(query.value(1).toString()==m_leEnrNomSIDD->text())
                    {
                        existeDeja=true;
                        break;
                    }

                }
            }
            query.clear();

            if(existeDeja)
            {
                //modif

              /*  query.prepare("update evenement set id=:id, dateEvenement=:dateEvenement, evenement=:evenement where id=:id");
                query.bindValue(":id",m_id);
                query.bindValue(":dateEvenement",m_de_date->date().toString("yyyy-MM-dd"));
                query.bindValue(":evenement",m_le_evenement->text());
                query.exec();
                query.clear();
                db.close();*/

               query.prepare("update ap set angleH=:angleH, angleV=:angleV where nom=:nom");
                query.bindValue(":angleH",QString::number(m_lcdnAngleH->value()));
                query.bindValue(":angleV",QString::number(m_lcdnAngleV->value()));
                query.bindValue(":nom",m_leEnrNomSIDD->text());
                query.exec();
                query.clear();
                db.close();
            }
            else
            {
                //ajout
                int T(0);
               if(query.exec("select max(id) FROM ap"))
               {
                   while(query.next())
                   {
                       T=query.value(0).toInt();
                   }
               }
                query.prepare("insert into ap values(:id, :nom,:angleH ,:angleV)");
                query.bindValue(":id",T+1);
                query.bindValue(":nom",m_leEnrNomSIDD->text());
                query.bindValue(":angleH",QString::number(m_lcdnAngleH->value()));
                query.bindValue(":angleV",QString::number(m_lcdnAngleV->value()));


                query.exec();
                query.clear();
                db.close();

           //     QMessageBox::information(0, QObject::tr("info"),m_leEnrNomSIDD->text());


            }
            lireDb();

    }
}

void MaFenetre::lireDb()
{
    m_lstAp.clear();
    m_lstNomAp.clear();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_dbMon);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }
    QSqlQuery query;

        if(query.exec("SELECT * FROM ap ORDER BY ap.id ASC"))
        {
            while(query.next())
            {

                //   QMessageBox::information(0, QObject::tr("info"),query.value(2).toString());
                  // QMessageBox::information(0, QObject::tr("info"),query.value(3).toString());
                Ap *ap=new Ap(query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt());
                m_lstAp.append(ap);

            }
        }

        query.clear();
        db.close();

        //m_cbSIDD->setmo
        //lireAngleCorrespondant
        for(int c=0;c<m_lstAp.size();c++)
            m_lstNomAp.append(m_lstAp.at(c)->getNom());

        m_modele->setStringList(m_lstNomAp);
        m_cbSIDD->setModel(m_modele);
        m_id=m_lstAp.size()-1;
}

void MaFenetre::supprimer()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(m_dbMon);
        if(!db.open())
        {
            QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
        }
        QSqlQuery query;
        query.prepare("delete from ap where nom = :nom");
        query.bindValue(":nom",m_cbSIDD->currentText());
        query.exec();
        query.clear();
        db.close();
    lireDb();
}
void MaFenetre::vider()
{
    int reponse = QMessageBox::question(this, "Interrogatoire","Voulez vous reelement vider la liste des ap ?", QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
               db.setDatabaseName(m_dbMon);
               if(!db.open())
               {
                   QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
               }
               QSqlQuery query;
            query.exec("delete from ap");
            query.clear();
            db.close();
            lireDb();

        }

}

void MaFenetre::charger()
{

    for(int c=0;c<m_lstAp.size();c++)
    {
        if(m_lstAp.at(c)->getNom()==m_cbSIDD->currentText())
        {
            m_leEnrNomSIDD->setText(m_lstAp.at(c)->getNom());
            m_lcdnAngleH->display(m_lstAp.at(c)->getAngleH());
            m_lcdnAngleV->display(m_lstAp.at(c)->getAngleV());
            m_sldH->setValue(m_lstAp.at(c)->getAngleH());
            m_sldV->setValue(m_lstAp.at(c)->getAngleV());
            m_id=c;
            m_angleH=QString::number(m_lstAp.at(c)->getAngleH());
            m_angleV=QString::number(m_lstAp.at(c)->getAngleV());
            break;
             //enoyer

        }
    }
    //envoyer("check");
    envoyerCoordH();
}

void MaFenetre::changerValeurH(int h)
{
    m_lcdnAngleH->display(h);
    m_angleH=QString::number(h);
}

 void MaFenetre::envoyerCoordH()
 {
     m_ard1->envoyerText("h="+m_angleH);
     m_dernierCoord=m_angleH;
     ecrireDernerCoor();
 }

 void MaFenetre::changerValeurV(int v)
 {
     m_lcdnAngleV->display(v);
     m_angleV=QString::number(v);
 }

 void MaFenetre::envoyerCoordV()
 {
     m_ard1->envoyerText("v="+m_angleV);
 }


//arduino




void MaFenetre::readData()
{

   /* QByteArray array = m_port->readAll();
    m_teInfo->insertPlainText(array);*/
    //QString strRecu;
}





/*void MaFenetre::connectionAutomatique()
{
    if(!m_estConnecter)
    {
        connection();
        m_timerConnectionAutomatique->stop();
   }
}*/
//pour arduinoSerieHorlogeIneractif
void MaFenetre::gererCalendrier()
{
    m_fcl=new fenetregererCalendrier();
    connect(m_fcl,SIGNAL(lireListe()),this,SLOT(lireEvenementDuJourEtProch1()));
    m_fcl->setModal(true);
    m_fcl->show();
}

//pour arduinoSerieHorlogeIneractif
void MaFenetre::lireEvenementDuJourEtProch1()
{
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
           // m_listWidgetEvenement.append(new evenement(query.value(1).toString(),query.value(2).toString(),query.value(0).toInt(),m_cheminEtNomDb));
            QStringList conte;
            conte.append(query.value(1).toString());
            conte.append(query.value(2).toString());
            m_lstEvenement.append(conte);
        }
    }
    query.clear();
    db.close();
    int c=0,indexAujourdui=0,v=0;

        for(c=0;c<m_lstEvenement.count();c++)
        {
            if(m_lstEvenement.at(c).at(0).split("-").at(1)+"-"+m_lstEvenement.at(c).at(0).split("-").at(2) ==QDate::currentDate().toString("MM-dd"))        
            {
                //QMessageBox::critical(0, QObject::tr("evenement du jour : "),"evenement du jour : "+m_lstEvenement.at(c).at(1));
                m_evenementDuJour=">>"+m_lstEvenement.at(c).at(1);
                indexAujourdui=c+1;
            }

            else if(m_lstEvenement.at(c).at(0).split("-").at(1)+"-"+m_lstEvenement.at(c).at(0).split("-").at(2)>=QDate::currentDate().toString("MM-dd") && v==0)
            {
                indexAujourdui=c;
                v=1;
            }

        }
        //QMessageBox::critical(0, QObject::tr("evenement du jour : "),QString::number(c));
       for(int i=0;i<3;i++)
       {
          // QMessageBox::critical(0, QObject::tr("evenement  :"),"evenement :"+QString::number(i)+"="+m_lstEvenement.at(indexAujourdui).at(0)+" "+m_lstEvenement.at(indexAujourdui).at(1));
           m_evenementReste+="|"+ m_lstEvenement.at(indexAujourdui).at(0).split("-").at(2)+"-"+m_lstEvenement.at(indexAujourdui).at(0).split("-").at(1)+":"+m_lstEvenement.at(indexAujourdui).at(1);
           indexAujourdui++;
            if(indexAujourdui==m_lstEvenement.count())
            {
              indexAujourdui=0;
            }
       }
       //m_textAEnvoyer=m_evenementDuJour+m_evenementReste;
       //QMessageBox::critical(0, QObject::tr("text : "),m_textAEnvoyer);
      //envoyerText("message=m_textAEnvoyer");
       m_evenement1=m_evenementReste.split("|").at(1);
       m_evenement2=m_evenementReste.split("|").at(2);
       m_evenement3=m_evenementReste.split("|").at(3);
      // QMessageBox::critical(0, QObject::tr("text : "),m_evenement1);
}

void MaFenetre::ecrireEtatReveille()
{
    QString nomFichier(m_chemin+"etatReveille");
    QFile fichier(nomFichier);
   // QMessageBox::critical(0, QObject::tr("Database Error"),"");//31
    fichier.open(QIODevice::WriteOnly);
    QTextStream strm( &fichier );
    if(m_cb_alarme->isChecked())
        strm << "1";
    if(!m_cb_alarme->isChecked())
        strm << "0";

    //QMessageBox::critical(0, QObject::tr("Database Error"),m_te_selectionRevaille->text());
    fichier.close();
}

void MaFenetre::lireEtatReveille()
{
    QString nomFichier(m_chemin+"etatReveille");
    QFile fichier(nomFichier);
   // QMessageBox::critical(0, QObject::tr("Database Error"),"");//31
    fichier.open(QIODevice::ReadOnly);
    QString contenu;
    contenu=fichier.readAll();

     if(contenu=="1")
     {
        m_cb_alarme->setChecked(true);

     }
     else
     {
         m_cb_alarme->setChecked(false);
     }

   //QMessageBox::critical(0, QObject::tr("Database Error"),m_te_selectionRevaille->text());
    fichier.close();
    //QMessageBox::critical(0, QObject::tr("Database Error"),m_te_selectionRevaille->time().toString("HH:mm:ss"));
}

void MaFenetre::lireHeurReveille()
{
    QString nomFichier(m_chemin+"heurReveille");
    QFile fichier(nomFichier);
   // //31
    fichier.open(QIODevice::ReadOnly);
    QString contenu;
    contenu=fichier.readAll();
  //  QMessageBox::critical(0, QObject::tr("Database Error"),contenu);
    QStringList lst=contenu.split(":");
    int h=lst.at(0).toInt();
    int m=lst.at(1).toInt();
    QTime timeAlarm(h,m);
    m_te_selectionRevaille->setTime(timeAlarm);
    fichier.close();
    //QMessageBox::critical(0, QObject::tr("Database Error"),m_te_selectionRevaille->time().toString("HH:mm:ss"));
}

void MaFenetre::ecrireActiverReveille()
{
    if(m_cb_alarme->isChecked())
    {
        QString nomFichier(m_chemin+ "heurReveille");
        QFile fichier(nomFichier);
       // QMessageBox::critical(0, QObject::tr("Database Error"),"");//31
        fichier.open(QIODevice::WriteOnly);
        QTextStream strm( &fichier );
        strm << m_te_selectionRevaille->text();
        //QMessageBox::critical(0, QObject::tr("Database Error"),m_te_selectionRevaille->text());
        fichier.close();

    }
    ecrireEtatReveille();   
}

//wifi
void MaFenetre::ecrireDernerCoor()
{
    QString nomFichier(m_nomFichierDernierCoord);
    QFile fichier(nomFichier);
   // QMessageBox::critical(0, QObject::tr("Database Error"),"");//31
    fichier.open(QIODevice::WriteOnly);
    QTextStream strm( &fichier );
    strm << m_dernierCoord;
    //QMessageBox::critical(0, QObject::tr("Database Error"),m_te_selectionRevaille->text());
    fichier.close();
}
//wifi
void MaFenetre::lireDernierCoord()
{
    QString nomFichier(m_nomFichierDernierCoord);
    QFile fichier(nomFichier);
   // //31
    fichier.open(QIODevice::ReadOnly);
    QString contenu;
    contenu=fichier.readAll();
  //  QMessageBox::critical(0, QObject::tr("Database Error"),contenu);
    m_dernierCoord=contenu;
    fichier.close();
    m_angleH=m_dernierCoord;
    m_lcdnAngleH->display(m_angleH.toInt());//1888
    m_sldH->setValue(m_angleH.toInt());

}

void MaFenetre::slotEnvoyerEtatAlerte()
{

}

//Slot pour le click sur le bouton de connexion
void MaFenetre::connection()
{
    //deux cas de figures �  gérer, soit on coche (connecte), soit on décoche (déconnecte)

    //on coche ­> connexion
    if(!m_estConnecter)
    {


        m_btClignote->setEnabled(true);
        m_btVitesse->setEnabled(true);
        m_btEspace->setEnabled(true);
        m_btPrise->setEnabled(true);
        m_btLumiere->setEnabled(true);
        m_btActiverAllumAutomatque->setEnabled(true);
        m_estConnecter=true;

        //creation getBaudRateFromString
        m_ard0=new Arduino(m_portArd0,m_comboVitesse->currentText());
        m_ard0->connection();
        connect(m_ard0,SIGNAL(recevoirDonnee(QString)),this,SLOT(setRecepton(QString)));
       m_ard1=new Arduino(m_portArd1,m_comboVitesse->currentText());
        m_ard1->connection();
        connect(m_ard1,SIGNAL(recevoirDonnee(QString)),this,SLOT(setRecepton(QString)));


        m_timer->start(1000);
        connect(m_timer,SIGNAL(timeout()),this,SLOT(temp()));

        m_btnconnexion->setText("Deconnecter");


        lireEvenementDuJourEtProch1();
       m_lcdnAngleH->setEnabled(true);
       m_sldH->setEnabled(true);
       m_btEnvoyerCoorH->setEnabled(true);
       m_btCharger->setEnabled(true);



    }
    else
    {

        m_btPrise->setEnabled(false);
        m_btLumiere->setEnabled(false);
        m_btActiverAllumAutomatque->setEnabled(false);
        m_estConnecter=false;
        m_btClignote->setEnabled(false);
        m_btVitesse->setEnabled(false);
        m_btEspace->setEnabled(false);
        //on se déconnecte de la carte Arduino
       //
        //**deconnection
        m_ard0->deConnection();
        m_ard1->deConnection();
        //puis on détruit l'objet port série devenu inutile
      //  delete port;
        m_btnconnexion->setText("Connecter");
        m_timer->stop();

        m_lcdnAngleH->setEnabled(false);
        m_sldH->setEnabled(false);
        m_btEnvoyerCoorH->setEnabled(false);
        m_btCharger->setEnabled(true);


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
       m_btClignote->setText("desactiver clignotement");
    }
    m_clignotementEstActivE=!m_clignotementEstActivE;
}

void MaFenetre::actiVOuDesactiVVitesse()
{
    if(m_ledVitesseEstActivE)
    {
        m_etatVitesse="d";
        m_btVitesse->setText("activer led vitesse");

    }
    else
    {
        m_etatVitesse="a";
       m_btVitesse->setText("desactiver led vitesse");
    }
    m_ledVitesseEstActivE=!m_ledVitesseEstActivE;
}

void MaFenetre::actiVOuDesactiVVitesseFnc()
{
    if(m_ledVitesseEstActivE)
    {
        m_etatVitesse="d";
        m_btVitesse->setText("activer led vitesse");

    }
    else
    {
        m_etatVitesse="a";
       m_btVitesse->setText("desactiver led vitesse");
    }
    m_ledVitesseEstActivE=!m_ledVitesseEstActivE;
}

void MaFenetre::actiVOuDesactiVVitesseAuto()
{
    m_activerAutoLedVitesse=m_chbActiverAutoLedVitesse->isChecked();
}

void MaFenetre::actiVOuDesactiVEspace()
{
    if(m_ledEspaceEstActivE)
    {
        m_etatEspace="d";
        m_btEspace->setText("activer led espace faible");

    }
    else
    {
        m_etatEspace="a";
       m_btEspace->setText("desactiver led espace faible");
    }
    m_ledEspaceEstActivE=!m_ledEspaceEstActivE;
}

void MaFenetre::temp()
{

    //pour la commade du wifi,lors du demarrageint;
    if(m_premierDemarage)
        m_C++;
    if(m_C==4)
    {
       envoyerCoordH();
       m_premierDemarage=false;
       m_C=0;
    }


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


   if(m_dateTempsActuel->currentDateTime().toString("HH:mm:ss")=="02:05:00" && m_activerAutoLedVitesse)
   {
       if(!m_ledVitesseEstActivE)
        actiVOuDesactiVVitesseFnc();//activation auto du led vitesse
   }



    QString a;
    if(m_cb_alarme->isChecked())
        a="a";
    else
        a="d";

    QString lancherAlarm;
    if(m_cb_alarme->isChecked())
    {
        if(m_dateTempsActuel->currentDateTime().toString("HH:mm:ss")==m_te_selectionRevaille->time().toString("HH:mm:ss"))
        {
            lancherAlarm="a";
            m_etindreAlrme="a";
        }
    }
    else
    {
        lancherAlarm="d";
    }

    //allume auto
    if(m_dateTempsActuel->currentDateTime().toString("HH:mm:ss")=="16:00:00")
        activerAllumAuto();
    if(m_dateTempsActuel->currentDateTime().toString("HH:mm:ss")=="20:00:00")
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
            m=pas*2;
        }
        else
            m_messageAEnvoyer=m_evenementDuJour;
    }
    if(m>=pas*2&&m<pas*3)
        m_messageAEnvoyer=m_evenement1;
    if(m>=pas*3&&m<pas*4)
        m_messageAEnvoyer=m_evenement2;
    if(m>=pas*4&&m<pas*5)
    {
        m_messageAEnvoyer=m_evenement3;
    }
    if(m==pas*5)
        m=0;
    if(m_estDebitInterne)
        lireDebit();
    lireEspceLibre();

    envoyerText("timeDate="+m_dateTempsActuel->currentDateTime().toString("HH:mm:ss")+"/"+a+"*"+etatUneHeur+"+"+lancherAlarm+"<"+m_etindreAlrme+">"+m_etatClignotement+"~"+m_messageAEnvoyer+"%"+m_debit+"\\"+m_peutDEspace+"{"+m_etatVitesse+"}"+m_etatEspace+"°");


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
    m_ard1->envoyerText("desactiverAllumAuto");
    m_btActiverAllumAutomatque->setText("activer allumage automatisue");

}

void MaFenetre::activerAllumAuto()
{
    m_ard1->envoyerText("activerAllumAuto");
    m_btActiverAllumAutomatque->setText("desactiver allumage automatisue");
}

void MaFenetre::actiVOueteindrePrise()
{

    if(m_priseActivE)
    {
        m_ard1->envoyerText("desactiverPrise");
        m_btPrise->setText("activer prise");

    }
    else
    {
        m_ard1->envoyerText("activerPrise");
        m_btPrise->setText("desactiver prise");
    }

    m_priseActivE=!m_priseActivE;
}

void MaFenetre::allumerOuEteindreLumiR()
{
    if(m_lumiereActvE)
    {
        m_ard1->envoyerText("eteindreLumiere");
        m_btLumiere->setText("allumer lumiere");

    }
    else
    {
        m_ard1->envoyerText("allumerLumiere");
        m_btLumiere->setText("eteindre lumiere");
    }
    m_lumiereActvE=!m_lumiereActvE;
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
    m_ard0->envoyerText(text);
}

void MaFenetre::setRecepton(QString txtRecu)
{


    if(txtRecu=="/dev/ttyACM1:b")
        m_etindreAlrme="d";
    if(txtRecu=="/dev/ttyACM1:a")
    {
       m_btActiverAllumAutomatque->setText("activer allumage automatisue");
        m_etatClignotement="d";
    }

    /*
    if(txtRecu=="/dev/ttyACM1:p")//p pour prise
    {
        if(m_priseActivE)
            m_btPrise->setText("activer prise");
        else
            m_btPrise->setText("desactiver prise");
        m_priseActivE=!m_priseActivE;

    }

    if(txtRecu=="/dev/ttyACM1:l")//l pour lumiere
    {
        if(m_lumiereActvE)
            m_btLumiere->setText("allumer lumiere");
        else
            m_btLumiere->setText("eteindre lumiere");
    }*/
    m_lumiereActvE=!m_lumiereActvE;
}

void MaFenetre::lireDebit()
{
    QString commandLine ("bwm-ng -I eth0 -o html");
       QProcess process;
       process.start (commandLine);
       process.waitForFinished ();
       QString result;
       if (process.exitCode () == 0)
           result = process.readAllStandardOutput();



       QStringList lst(result.split("span"));
          QString partieVitesse(lst.at(1));
           partieVitesse=partieVitesse.split(" KB").at(0);
           partieVitesse=partieVitesse.mid(22);
           partieVitesse=partieVitesse.split(".").at(0);


           int pui=1;
           int vitesse=0;
           vitesse =partieVitesse.at(partieVitesse.length()-1).digitValue();

           for(int c=partieVitesse.length()-2;c!=0;c--)
           {
               if(partieVitesse.at(c).isNumber())
               {
                   vitesse=vitesse + (partieVitesse.at(c).digitValue()* pow(10,pui));
                   pui++;
               }
           }

           if(vitesse<1024)
               m_debit= QString::number(vitesse)+"K";
           else
               m_debit=QString::number(vitesse/1024)+"M";

         //  qDebug () << m_debit;
}

void MaFenetre::lireEspceLibre()
{
        QString commandLine ("df -h");
       QProcess process;
       process.start (commandLine);
       process.waitForFinished ();
       QString result;
       if (process.exitCode () == 0)
           result = process.readAllStandardOutput();
        result=result.split("\n").at(1);
        if(result.indexOf("M")==-1)
            m_peutDEspace="f";
        else
            m_peutDEspace="v";



}
