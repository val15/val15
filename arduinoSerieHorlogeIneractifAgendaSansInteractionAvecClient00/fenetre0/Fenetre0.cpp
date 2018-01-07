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

    m_debit="0K";

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
    m_comboVitesse=new QComboBox; // Permet de choisir la vitesse de communication
    m_btnconnexion=new QPushButton("connection");// (D)Connecte la voie srie (bouton checkable)

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
    m_chbAlarme=new QCheckBox;
    m_lbReveil=new QLabel("reveile : ");

    m_layoutCommande=new QGridLayout;
    m_btPrise=new QPushButton("activer prise");
    m_btLumiere=new QPushButton("allumer lumiere");

    m_chbAllumAutomatque=new QCheckBox("allumage automatique a :");
    m_tieAllumAutomatque=new QTimeEdit;
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
    m_tieSelectionReveille=new QTimeEdit();

    m_btClignote->setEnabled(false);
    m_btVitesse->setEnabled(false);
    m_btEspace->setEnabled(false);
    m_chbAllumAutomatque->setEnabled(false);
    m_btPrise->setEnabled(false);
    m_btLumiere->setEnabled(false);
    m_btLumiere=new QPushButton("allumer lumiere");

    m_layoutAlarme->addWidget(m_lbReveil,0,0);
    m_layoutAlarme->addWidget(m_tieSelectionReveille,0,1);
    m_layoutAlarme->addWidget(m_chbAlarme,0,2);

     m_layoutCommande->addWidget(m_chbAllumAutomatque,0,0);
     m_layoutCommande->addWidget(m_tieAllumAutomatque,0,1);
     m_layoutCommande->addWidget(m_btLumiere,0,2);
     m_layoutCommande->addWidget(m_btPrise,0,3);



     //pour le calandrier
     m_layoutCalandrier=new QGridLayout();
     m_cldr=new MaClandrier();
     m_lbEvenementsDuJour=new QLabel();
     QLabel *lbRdvDuJour= new QLabel("les rendez-vous du jour");
     m_conteneurRvdDuJour=new QWidget;
     m_layoutRdvDuJour=new QGridLayout;
     m_areaConteneurRvdDuJour=new QScrollArea;
     m_areaConteneurRvdDuJour->setWidgetResizable(true);
     m_areaConteneurRvdDuJour->setWidget(m_conteneurRvdDuJour);

     m_conteneurRvdDuJour->setLayout(m_layoutRdvDuJour);
     m_btAjouterEvenement=new QPushButton("ajouter evenement");
     m_layoutCalandrier->addWidget(m_cldr,0,0);
     m_layoutCalandrier->addWidget(m_lbEvenementsDuJour,1,0);
     m_layoutCalandrier->addWidget(lbRdvDuJour,2,0);
     m_layoutCalandrier->addWidget(m_areaConteneurRvdDuJour,3,0);
     m_layoutCalandrier->addWidget(m_btAjouterEvenement,4,0);




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






    QObject::connect(m_pb_gereCalentdier  , SIGNAL(clicked()), this,SLOT(gererCalendrier()));

    //  QMessageBox::critical(0, QObject::tr("Database Error"),m_dateTempsActuel->currentDateTime().toString("mm:ss"));
    QObject::connect(m_btnconnexion , SIGNAL(clicked()), this,SLOT(connection()));
  //  QObject::connect(m_pb_allumerEtindreLed , SIGNAL(clicked()), this,SLOT(allumerEtindreLed()));
     QObject::connect(m_btClignote, SIGNAL(clicked()), this,SLOT(actiVOuDesactiVClignotement()));
      QObject::connect(m_btVitesse, SIGNAL(clicked()), this,SLOT(actiVOuDesactiVVitesse()));
      QObject::connect(m_chbActiverAutoLedVitesse, SIGNAL(clicked()), this,SLOT(actiVOuDesactiVVitesseAuto()));
      QObject::connect(m_btEspace, SIGNAL(clicked()), this,SLOT(actiVOuDesactiVEspace()));
     QObject::connect(m_btLumiere , SIGNAL(clicked()), this,SLOT(allumerOuEteindreLumiR()));
     QObject::connect(m_btPrise , SIGNAL(clicked()), this,SLOT(actiVOueteindrePrise()));
     QObject::connect(m_chbAllumAutomatque, SIGNAL(clicked()), this,SLOT(desativerActiverAllumeAuto()));
    QObject::connect(m_tieSelectionReveille , SIGNAL(editingFinished()), this,SLOT(ecrirConfig()));
    QObject::connect(m_chbAlarme , SIGNAL(clicked()), this,SLOT(ecrirConfig()));
    QObject::connect(m_tieAllumAutomatque , SIGNAL(editingFinished()), this,SLOT(ecrirConfig()));
    QObject::connect(m_chbAllumAutomatque , SIGNAL(clicked()), this,SLOT(ecrirConfig()));

    lireConfig();

    //lecture des dates
    lectureDesDatesImportantsDuMois(QDate::currentDate().year(),QDate::currentDate().month());
    lectureDesEvenementsDuJour(QDate::currentDate());

    //  connect(m_timerConnectionAutomatique,SIGNAL(timeout()),this,SLOT(connectionAutomatique()));
   connection();


   //lancement du serveur
   m_serveur=new Serveur(5115);
   QObject::connect(m_serveur,SIGNAL(emmetreMessage(QString)),this,SLOT(traiterMessagServeur(QString)));
   QObject::connect(m_serveur,SIGNAL(emmetreDeconnecionClient()),this,SLOT(deconnectionClient()));

   m_serveur->lancement();
}

void MaFenetre::traiterMessagServeur(QString msg)
{
    m_debit=msg;
   // qDebug() << m_debit << endl;
}

void MaFenetre::deconnectionClient()
{
    m_debit="0K";
}

//slote et fonction pour le wifi

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
    m_fcl=new fenetregererCalendrier(m_cheminEtNomDb);
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
}

void MaFenetre::lectureDesEvenementsDuJour()
{
    lectureDesEvenementsDuJour(QDate::currentDate());
}

//pour arduinoSerieHorlogeIneractif
void MaFenetre::lireEvenementDuJourEtProch1()
{
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
        /*QString sDernierDate=lstEvenement.at(lstEvenement.count()-1).at(0);

        QDate dernierDateEv(sDernierDate.split("-").at(0).toInt(),sDernierDate.split("-").at(1).toInt(),sDernierDate.split("-").at(2).toInt());
     *///   qDebug() << "dernier date : "<< dernierDateEv.toString("MM:dd") << endl;
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
                       //  indexAujourdui=c+1;
                     }

                     /*else if(lstEvenement.at(c).at(0).split("-").at(1)+"-"+lstEvenement.at(c).at(0).split("-").at(2)>=QDate::currentDate().toString("MM-dd") && v==0)//on dtermine o on doit commencer  conter: la date d'ojourhui
                     {

                        // indexAujourdui=c;
                        // v=1;
                     }*/

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
int MaFenetre::comparerDeuxDate(QString d0,QString d1)
{
    int m0=d0.split("-").at(0).toInt();
    int j0=d0.split("-").at(1).toInt();
    int m1=d1.split("-").at(0).toInt();
    int j1=d1.split("-").at(1).toInt();
    if(m0>m1)
        return 1;
    else if(m0<m1)
        return -1;
    else
    {
        if(d0>d1)
            return 1;
        else if(d0<d1)
            return -1;
        else
            return 0;
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

void MaFenetre::ajouterEvenement()
{
    QDialog *fenetreAjouter=new QDialog();
    fenetreAjouter->setModal(true);
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
    connect(m_btAjoutEnregister , SIGNAL(clicked()), this,SLOT(lectureDesDatesImportantsDuMois()));
    connect(m_btAjoutEnregister , SIGNAL(clicked()), this,SLOT(lectureDesEvenementsDuJour()));
    connect(m_btAjoutEnregister , SIGNAL(clicked()), this,SLOT(lireEvenementDuJourEtProch1()));
    connect(m_btAjoutEnregister , SIGNAL(clicked()), fenetreAjouter,SLOT(accept()));
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

         //lectureDesDatesImportantsDuMois();
       //lectureDesEvenementsDuJour();
         //lireEvenementDuJourEtProch1();


}



//lecture et eccriture des configs
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

     QString strConfig;//ce string contiedra les configuration
     strConfig+=m_heurReveil;
     strConfig+="\r\n";
     strConfig+=m_etatReveil;
     strConfig+="\r\n";
     strConfig+=m_heurAllumAutomatque;
     strConfig+="\r\n";
     strConfig+=m_etatAllumAutomatque;

     //ecriture dans le fichier
     QString nomFichier(m_chemin+m_nomFichierDeConfig);
     QFile fichier(nomFichier);
    // QMessageBox::critical(0, QObject::tr("Database Error"),"");//31
     fichier.open(QIODevice::WriteOnly);
     QTextStream strm( &fichier );
     strm << strConfig;
     //QMessageBox::critical(0, QObject::tr("Database Error"),m_te_selectionRevaille->text());
     fichier.close();
}






//Slot pour le click sur le bouton de connexion
void MaFenetre::connection()
{
    //deux cas de figures   grer, soit on coche (connecte), soit on dcoche (dconnecte)

    //on coche > connexion
    if(!m_estConnecter)
    {


        m_btClignote->setEnabled(true);
        m_btVitesse->setEnabled(true);
        m_btEspace->setEnabled(true);
        m_btPrise->setEnabled(true);
        m_btLumiere->setEnabled(true);
        m_chbAllumAutomatque->setEnabled(true);
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


        lireEvenementDuJourEtProch1();//a ne pas oublier




    }
    else
    {

        m_btPrise->setEnabled(false);
        m_btLumiere->setEnabled(false);
        m_chbActiverAutoLedVitesse->setEnabled(false);
        m_estConnecter=false;
        m_btClignote->setEnabled(false);
        m_btVitesse->setEnabled(false);
        m_btEspace->setEnabled(false);
        //on se dconnecte de la carte Arduino
       //
        //**deconnection
        m_ard0->deConnection();
        m_ard1->deConnection();
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
    qDebug() << "m= " << m <<" ;ev du jour " << m_messageAEnvoyer  << endl;


    if(m>=pas*6)
        m=0;
    if(m_estDebitInterne)
        lireDebit();
    lireEspceLibre();

    envoyerText("timeDate="+m_dateTempsActuel->currentDateTime().toString("HH:mm:ss")+"/"+a+"*"+etatUneHeur+"+"+lancherAlarm+"<"+m_etindreAlrme+">"+m_etatClignotement+"~"+m_messageAEnvoyer+"%"+m_debit+"\\"+m_peutDEspace+"{"+m_etatVitesse+"}"+m_etatEspace+"");


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
    //m_btActiverAllumAutomatque->setText("activer allumage automatisue");

}

void MaFenetre::activerAllumAuto()
{
    m_ard1->envoyerText("activerAllumAuto");
    //m_btActiverAllumAutomatque->setText("desactiver allumage automatisue");
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
       //m_btActiverAllumAutomatque->setText("activer allumage automatisue");
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