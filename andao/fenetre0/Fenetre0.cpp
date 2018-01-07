#include "Fenetre0.h"
#include "Fichier.h"

MaFenetre::MaFenetre() : QWidget()
{
    m_sensLecture=0;
    m_tr0=Trajet("tr0");


    m_vtimerTrj=0;
    m_vtimerTrjLectur=0;
    m_compteur=0;
    m_estConnecter=false;
    m_enregistrementEnCour=false;
    m_lectureEnCour=false;
    m_activerCompteur=false;
    m_lbIpServeur=new QLabel("adesse ip : ");
    m_leAdresseIp=new QLineEdit("192.168.115.107");
    m_btLancementServeur=new QPushButton("lancer le serveur");
    m_lePort=new QLineEdit("/dev/ttyACM0"); //Permet de choisir le port série
    m_comboVitesse=new QComboBox; // Permet de choisir la vitesse de communication
    m_btnconnexion=new QPushButton("connection");// (Dé)Connecte la voie série (bouton “checkable”)
    m_leEmission=new QLineEdit;// Nous écrirons ici le texte �  envoyer
    m_leEmission->setEnabled(false);
    m_boxInformation=new QTextEdit;// Ici apparaitra le texte �  recevoir
    m_boxInformation->setEnabled(true);
    m_boxInformation->setReadOnly(true);
    m_layoutGenerale=new QGridLayout;
    m_layoutServeur=new QGridLayout;
    m_layoutHaut=new QGridLayout;
    m_layoutEmission=new QGridLayout;
    QLabel *m_lb_port=new QLabel("Port");
    QLabel *m_lb_vitesse=new QLabel("Vitesse");
    QLabel *m_lb_emission=new QLabel("Emission : ");
    QLabel *m_lb_information=new QLabel("Information : ");
    m_pb_envoyer=new QPushButton("envoyer");
    m_pb_envoyer->setEnabled(false);
    m_lbInfo=new QLabel("information");
    m_btEnregister=new QPushButton("enregister");
    m_btPlay=new QPushButton(">");
    m_btPlayInv=new QPushButton("<");
    m_layoutEnregistrement=new QGridLayout;
    m_btEnregister->setEnabled(false);
    m_btPlay->setEnabled(false);
    m_btPlayInv->setEnabled(false);
    m_layoutEnregistrement->addWidget(m_btEnregister,0,0);
    m_layoutEnregistrement->addWidget(m_btPlay,0,1);
    m_layoutEnregistrement->addWidget(m_btPlayInv,0,2);
    m_lbTemps=new QLabel("compteur : ");
    m_lcdTemps=new QLCDNumber;
    //m_lcdTemps->setReadOnly(true);
    m_btMaz=new QPushButton("maz");
    m_layoutTemps=new QGridLayout;
    m_lbTemps->setEnabled(false);
    m_lcdTemps->setEnabled(false);
    m_btMaz->setEnabled(false);
    m_layoutTemps->addWidget(m_lbTemps,0,0);
    m_layoutTemps->addWidget(m_lcdTemps,0,1);
    m_layoutTemps->addWidget(m_btMaz,0,2);
    m_lbNomTrj=new QLabel("mon");
    m_leTrjEnregistrE=new QLineEdit;
    m_btEregistrerTrjEnregistrE=new QPushButton("eneregister");
    m_layoutTrjEnregistrEHaut=new QGridLayout;
    m_lbTrj=new QLabel("trajet : ");
    m_cbTrj=new  QComboBox();
    m_btPlayTrjEnregistrE=new QPushButton(">");
    m_btPlayInvTrjEnregistrE=new  QPushButton("<");
    m_layoutTrjEnregistrEBas=new QGridLayout;
    m_leTrjEnregistrE->setEnabled(false);
    m_btEregistrerTrjEnregistrE->setEnabled(false);
    m_cbTrj->setEnabled(false);
    m_btPlayTrjEnregistrE->setEnabled(false);
    m_btPlayInvTrjEnregistrE->setEnabled(false);

    m_layoutTrjEnregistrEHaut->addWidget(m_lbNomTrj,0,0);
    m_layoutTrjEnregistrEHaut->addWidget(m_leTrjEnregistrE,0,1);
    m_layoutTrjEnregistrEHaut->addWidget(m_btEregistrerTrjEnregistrE,0,2);
    m_layoutTrjEnregistrEBas->addWidget(m_lbTrj,0,0);
    m_layoutTrjEnregistrEBas->addWidget(m_cbTrj,0,1);
    m_layoutTrjEnregistrEBas->addWidget(m_btPlayTrjEnregistrE,0,2);
    m_layoutTrjEnregistrEBas->addWidget(m_btPlayInvTrjEnregistrE,0,3);

    m_layoutEmission->addWidget(m_leEmission,0,0);
     m_layoutEmission->addWidget(m_pb_envoyer,0,1);
    m_layoutHaut->addWidget(m_lb_port,0,0);
    m_layoutHaut->addWidget(m_lePort,0,1);
    m_layoutHaut->addWidget(m_lb_vitesse,0,2);
    m_layoutHaut->addWidget(m_comboVitesse,0,3);
     m_layoutHaut->addWidget(m_btnconnexion,0,5);

    m_layoutServeur->addWidget(m_lbIpServeur,0,0);
    m_layoutServeur->addWidget(m_leAdresseIp,0,1);
    m_layoutServeur->addWidget(m_btLancementServeur,0,2);


     m_layoutGenerale->addLayout(m_layoutServeur,0,0);
    m_layoutGenerale->addLayout(m_layoutHaut,1,0);
    m_layoutGenerale->addWidget(m_lb_emission,2,0);
    m_layoutGenerale->addLayout(m_layoutEmission,3,0);
    m_layoutGenerale->addWidget(m_lb_information,4,0);
    m_layoutGenerale->addWidget(m_boxInformation,5,0);
    m_layoutGenerale->addLayout(m_layoutEnregistrement,6,0);
    m_layoutGenerale->addLayout(m_layoutTrjEnregistrEHaut,7,0);
    m_layoutGenerale->addLayout(m_layoutTrjEnregistrEBas,8,0);
    m_layoutGenerale->addLayout(m_layoutTemps,9,0);
    m_layoutGenerale->addWidget(m_lbInfo,10,0);


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


    m_timerTrjEnregistrement=new QTimer;
    m_timerTrjEnregistrement->setInterval(1);

    m_timerTrjLecture=new QTimer;
     m_timerTrjLecture->setInterval(1);

     m_timerCompteur=new QTimer;
      m_timerCompteur->setInterval(1);


  /*  m_timerConnectionAutomatique=new QTimer;
    m_timerConnectionAutomatique->start(3);*/
    //pour arduinoSerieHorlogeIneractif

  //  lireEvenementDuJourEtProch1();



  //  QMessageBox::critical(0, QObject::tr("Database Error"),m_dateTempsActuel->currentDateTime().toString("mm:ss"));
    QObject::connect(m_btnconnexion , SIGNAL(clicked()), this,SLOT(connection()));
    QObject::connect(m_btEnregister , SIGNAL(clicked()), this,SLOT(lancerEnregistrement()));
    QObject::connect(m_leTrjEnregistrE , SIGNAL(textChanged(QString)), this,SLOT(modifNomEreregister()));
    QObject::connect(m_btEregistrerTrjEnregistrE , SIGNAL(clicked()), this,SLOT(enregisterTrj()));
    QObject::connect(m_btMaz, SIGNAL(clicked()), this,SLOT(mazTemps()));

    QObject::connect(m_btPlay , SIGNAL(clicked()), this,SLOT(playTrj()));
    QObject::connect(m_btPlayInv , SIGNAL(clicked()), this,SLOT(playTrjInv()));
    QObject::connect(m_btPlayTrjEnregistrE , SIGNAL(clicked()), this,SLOT(playTrjEnregistrE()));
    QObject::connect(m_btPlayInvTrjEnregistrE , SIGNAL(clicked()), this,SLOT(playInvTrjEnregistrE()));


    QObject::connect(m_timerTrjEnregistrement , SIGNAL(timeout()), this,SLOT(incrementerTmptrj()));
    QObject::connect(m_timerTrjLecture , SIGNAL(timeout()), this,SLOT(tretementTrjLecture()));
    QObject::connect(m_timerTrjEnregistrement,SIGNAL(timeout()),this,SLOT(ecrireTrj()));
    QObject::connect(m_timerCompteur,SIGNAL(timeout()),this,SLOT(incrementerCompteur()));

    QObject::connect(m_btLancementServeur,SIGNAL(clicked()),this,SLOT(lancerServeur()));

    //  connect(m_timerConnectionAutomatique,SIGNAL(timeout()),this,SLOT(connectionAutomatique()));
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

void MaFenetre::lancerServeur()
{

    m_adresseIp=m_leAdresseIp->text();
    m_serveur=new Serveur(m_adresseIp,1515);
    QObject::connect(m_serveur,SIGNAL(emmetreMessage(QString)),this,SLOT(afficherInfo(QString)));


    m_serveur->lancement();

}

//Slot pour le click sur le bouton de connexion
void MaFenetre::connection()
{
    //deux cas de figures �  gérer, soit on coche (connecte), soit on décoche (déconnecte)

    //on coche ­> connexion
    if(!m_estConnecter)
    {
        lireTemps();
        m_leEmission->setEnabled(true);
        m_estConnecter=true;
        m_btEnregister->setEnabled(true);
        m_cbTrj->setEnabled(true);
        m_btPlayTrjEnregistrE->setEnabled(true);
        m_btPlayInvTrjEnregistrE->setEnabled(true);
        m_lbTemps->setEnabled(true);
        m_lcdTemps->setEnabled(true);
        m_btMaz->setEnabled(true);
        m_timerCompteur->start();
        port = new QextSerialPort();
        //on essaie de faire la connexion avec la carte Arduino
        //on commence par créer l'objet port série

        //on règle le port utilisé (sélectionné dans la liste déroulante)
        port->setPortName( m_lePort->text());
        //on règle la vitesse utilisée
        //port->setBaudRate (getBaudRateFromString(m_comboVitesse->­currentText()));
        port->setBaudRate(getBaudRateFromString(m_comboVitesse->currentText()));
        //quelques règlages pour que tout marche bien
       port->setParity(PAR_NONE);//parité
        port->setStopBits(STOP_1);//nombre de bits de stop
        port->setDataBits(DATA_8);//nombre de bits de données
        port->setFlowControl(FLOW_OFF);//pas de contrôle de flux
        //on démarre !
        port->open(QextSerialPort::ReadWrite);
        //change le message du bouton


        m_btnconnexion->setText("Deconnecter");
        m_pb_envoyer->setEnabled(true);
        lireListeTrj();

        //on fait la connexion pour pouvoir obtenir les évènements
        connect(port,SIGNAL(readyRead()), this, SLOT(readData()));
      //  connect(m_boxEmission,SIGNAL(textChanged()),this,SLOT(sendData()));
        connect(m_pb_envoyer,SIGNAL(clicked()),this,SLOT(enoyer()));
       // m_timer->start(1000);//**important pour gere le temps

        //connect(m_timer4,SIGNAL(timeout()),this,SLOT(temp4()));



    }
    else
    {
        m_leEmission->setEnabled(false);
        m_estConnecter=false;
        m_btEnregister->setEnabled(false);
        m_btPlay->setEnabled(false);
        m_btPlayInv->setEnabled(false);
        m_cbTrj->setEnabled(false);
        m_lbTemps->setEnabled(false);
        m_lcdTemps->setEnabled(false);
        m_btMaz->setEnabled(false);
        m_timerCompteur->start();
        m_btEregistrerTrjEnregistrE->setEnabled(false);
        m_leTrjEnregistrE->setEnabled(false);
        //on se déconnecte de la carte Arduino
        port->close();
        //puis on détruit l'objet port série devenu inutile
      //  delete port;
        m_btnconnexion->setText("Connecter");
        m_pb_envoyer->setEnabled(false);

    }

}

void MaFenetre::enoyer()
{
    //envoyerText("dateTime="+m_dateTempsActuel->currentDateTime().toString("H:m:s"));
    //envoyerText("tt");
    envoyerText(m_leEmission->text());
    m_leEmission->clear();

}

BaudRateType  MaFenetre::getBaudRateFromString(QString baudRate)//pour determiner la vitesse
{
    int vitesse = baudRate.toInt();
        switch(vitesse)
        {
            case(300):return BAUD300;
            case(1200):return BAUD1200;
            case(2400):return BAUD2400;
            case(4800):return BAUD4800;
            case(9600):return BAUD9600;
            case(19200):return BAUD19200;
            case(38400):return BAUD38400;
            case(57600):return BAUD57600;
            case(115200):return BAUD115200;
            default:return BAUD9600;
        }
}


void MaFenetre::sendData()
{
    //On récupère le dernier caractère tapé
    QString caractere =  m_leEmission->text();
    //si le port est instancié (donc ouvert a priori)
    if(port != NULL)
         port->write(caractere.toAscii());

   // QMessageBox::critical(0, QObject::tr("Database Error"),caractere);//31
}

void MaFenetre::readData()
{
    QByteArray array = port->readAll();
    m_boxInformation->insertPlainText(array);
    QString str,caractere;
    str=array;
    if(str=="0")
    {
        caractere =  "allumer";
    }
    else if(str=="1")
    {
        caractere =  "etindre";
    }
     //si le port est instancié (donc ouvert a priori)
   /* if(port != NULL)
       port->write(caractere.toAscii());*/
}

void MaFenetre::envoyerText(QString text)
{
    if(port != NULL)
         port->write(text.toAscii());
}


void MaFenetre::keyPressEvent(QKeyEvent *event)
{

    if(m_estConnecter)
    {

        if(event->text()=="z")
        {
            m_activerCompteur=true;
            port->write("a");
            m_lbInfo->setText("envoi : a");
            if(m_enregistrementEnCour)
                m_tr0.ajouterPoint(m_vtimerTrj,"a");
        }
        if(event->text()=="q")
        {
            m_activerCompteur=true;
            port->write("g");
            m_lbInfo->setText("envoi : q");
            if(m_enregistrementEnCour)
                m_tr0.ajouterPoint(m_vtimerTrj,"g");
        }

        if(event->text()=="d")
        {
            m_activerCompteur=true;
            port->write("d");
            m_lbInfo->setText("envoi : d");
            if(m_enregistrementEnCour)
                m_tr0.ajouterPoint(m_vtimerTrj,"d");
        }

        if(event->text()=="s")
        {
            m_activerCompteur=true;
            port->write("r");
            m_lbInfo->setText("envoi : r");
            if(m_enregistrementEnCour)
                m_tr0.ajouterPoint(m_vtimerTrj,"r");
        }

        if(event->text()=="w")
        {
            port->write("w");
            m_lbInfo->setText("envoi : w");
            if(m_enregistrementEnCour)
                m_tr0.ajouterPoint(m_vtimerTrj,"w");
        }

        if(event->text()=="x")
        {
            port->write("x");
            m_lbInfo->setText("envoi : x");
            if(m_enregistrementEnCour)
                m_tr0.ajouterPoint(m_vtimerTrj,"x");
        }

        if(event->text()=="c")
        {
            port->write("c");
            m_lbInfo->setText("envoi : c");
            if(m_enregistrementEnCour)
                m_tr0.ajouterPoint(m_vtimerTrj,"c");
        }

        if(event->text()=="r")
        {
            port->write("v");
            m_lbInfo->setText("envoi : v");
            if(m_enregistrementEnCour)
                m_tr0.ajouterPoint(m_vtimerTrj,"v");
        }

        if(event->text()=="f")
        {
            port->write("b");
            m_lbInfo->setText("envoi : b");
            if(m_enregistrementEnCour)
                m_tr0.ajouterPoint(m_vtimerTrj,"b");
        }
    }
    else
        m_lbInfo->setText("pas connecter");

}

void MaFenetre::keyReleaseEvent(QKeyEvent *event)
{
    if(m_estConnecter)
    {
        m_actionEnCour=event->text();
        if(event->text()=="z" || event->text()=="d" || event->text()=="q" || event->text()=="s")
         {
            m_activerCompteur=false;
            port->write("s");
            m_lbInfo->setText("envoi : s");
            if(m_enregistrementEnCour)
                m_tr0.ajouterPoint(m_vtimerTrj,"s");
        }
        if(event->text()=="f" || event->text()=="r")
        {

            port->write("n");
            m_lbInfo->setText("envoi : n");
            if(m_enregistrementEnCour)
                m_tr0.ajouterPoint(m_vtimerTrj,"n");
        }
    }
    else
        m_lbInfo->setText("pas connecter");
}

void MaFenetre::lancerEnregistrement()
{
    m_enregistrementEnCour=!m_enregistrementEnCour;
    if(m_enregistrementEnCour)
    {
        //lancer l'eregistement
        m_btPlay->setEnabled(false);
        m_btPlayInv->setEnabled(false);
        m_cbTrj->setEnabled(false);
        m_btPlayTrjEnregistrE->setEnabled(false);
        m_btPlayInvTrjEnregistrE->setEnabled(false);
        m_btEnregister->setText("stoper");
        m_tr0.clear();
        m_timerTrjEnregistrement->start();
    }
    else
    {
        m_btPlay->setEnabled(true);
        m_btPlayInv->setEnabled(true);
        m_leTrjEnregistrE->setEnabled(true);
        m_cbTrj->setEnabled(true);
        m_btPlayTrjEnregistrE->setEnabled(true);
        m_btPlayInvTrjEnregistrE->setEnabled(true);
        m_btEnregister->setText("enregister");
        m_tr0.setFin(m_vtimerTrj);
       m_timerTrjEnregistrement->stop();
        m_vtimerTrj=0;
      //  m_lbInfo->setText(QString::number(m_tr0.getTemp(1)) + " : " +m_tr0.getAction(1));
        //test
        /*for(int c=0;c<m_tr0.getNbPoint();c++)
            m_boxReception->append(QString::number(m_tr0.getTemp(c)) + " : " +m_tr0.getAction(c));
    */
        m_tr0.genererInv();
    }
}

void MaFenetre::playTrj()
{
    if(!m_lectureEnCour)
    {
        m_lectureEnCour=true;
        m_btPlay->setEnabled(false);
        m_btPlayInv->setEnabled(false);
        m_timerTrjLecture->start();
        m_sensLecture=1;
    }
}

void MaFenetre::playTrjInv()
{
    if(!m_lectureEnCour)
    {
        m_lectureEnCour=true;
        m_btPlay->setEnabled(false);
        m_btPlayInv->setEnabled(false);
        m_timerTrjLecture->start();
        m_sensLecture=2;
    }
}

void MaFenetre::tretementTrjLecture()
{
    m_vtimerTrjLectur++;
    if(m_sensLecture==1)
    {
        for(int c=0;c<m_tr0.getNbPoint();c++)
        {
            if(m_tr0.getTemp(c)==m_vtimerTrjLectur)
            {
                envoyerText(m_tr0.getAction(c));
                m_lbInfo->setText("lecture en cour");
            }
            if(m_tr0.getFin()==m_vtimerTrjLectur)
            {
                m_timerTrjLecture->stop();
                m_vtimerTrjLectur=0;
                m_lectureEnCour=false;
                m_sensLecture=0;
                m_btPlay->setEnabled(true);
                m_btPlayInv->setEnabled(true);
                m_btPlayTrjEnregistrE->setEnabled(true);
                m_btPlayInvTrjEnregistrE->setEnabled(true);
                m_lbInfo->setText("lecture fini");
            }

        }
    }
    if(m_sensLecture==2)
    {
        for(int c=0;c<m_tr0.getNbPoint();c++)
        {
            if(m_tr0.getTempInv(c)==m_vtimerTrjLectur)
            {
                envoyerText(m_tr0.getActionInv(c));
                m_lbInfo->setText("lecture en cour");
            }
            if(m_tr0.getFin()==m_vtimerTrjLectur)
            {
                m_timerTrjLecture->stop();
                m_vtimerTrjLectur=0;
                m_lectureEnCour=false;
                m_sensLecture=0;
                m_btPlay->setEnabled(true);
                m_btPlayInv->setEnabled(true);
                m_btPlayTrjEnregistrE->setEnabled(true);
                m_btPlayInvTrjEnregistrE->setEnabled(true);
                m_lbInfo->setText("lecture fini");
            }

        }
    }
    if(m_sensLecture==3)
    {
        for(int c=0;c<m_trTrj.getNbPoint();c++)
        {
            if(m_trTrj.getTemp(c)==m_vtimerTrjLectur)
            {
                envoyerText(m_trTrj.getAction(c));
                m_lbInfo->setText("lecture en cour");

            }
            if(m_trTrj.getFin()==m_vtimerTrjLectur)
            {

                m_timerTrjLecture->stop();
                m_vtimerTrjLectur=0;
                m_lectureEnCour=false;
                m_sensLecture=0;
                m_btPlay->setEnabled(true);
                m_btPlayInv->setEnabled(true);
                m_btPlayTrjEnregistrE->setEnabled(true);
                m_btPlayInvTrjEnregistrE->setEnabled(true);
                m_lbInfo->setText("lecture fini");
            }

        }
    }
    if(m_sensLecture==4)
    {
        for(int c=0;c<m_trTrj.getNbPoint();c++)
        {
            if(m_trTrj.getTempInv(c)==m_vtimerTrjLectur)
            {
                envoyerText(m_trTrj.getActionInv(c));
                m_lbInfo->setText("lecture en cour");
            }
            if(m_trTrj.getFin()==m_vtimerTrjLectur)
            {
                m_timerTrjLecture->stop();
                m_vtimerTrjLectur=0;
                m_lectureEnCour=false;
                m_sensLecture=0;
                m_btPlay->setEnabled(true);
                m_btPlayInv->setEnabled(true);
                m_btPlayTrjEnregistrE->setEnabled(true);
                m_btPlayInvTrjEnregistrE->setEnabled(true);
                m_lbInfo->setText("lecture fini");
            }

        }
    }



}



void MaFenetre::modifNomEreregister()
{
    if(m_leTrjEnregistrE->text()=="")
        m_btEregistrerTrjEnregistrE->setEnabled(true);
    else
        m_btEregistrerTrjEnregistrE->setEnabled(true);
}


void MaFenetre::enregisterTrj()
{

        Fichier f0("trj/"+m_leTrjEnregistrE->text());
        f0.ecrire(m_leTrjEnregistrE->text());
        for(int c=0;c<m_tr0.getNbPoint();c++)
        {

                f0.ecrireAlLaFinAvecUnALaLigneAvant(QString::number(m_tr0.getTemp(c))+":"+m_tr0.getAction(c));
        }
        f0.ecrireAlLaFinAvecUnALaLigneAvant("fin:"+QString::number(m_tr0.getFin()));

        m_leTrjEnregistrE->clear();
        lireListeTrj();
}

void MaFenetre::lireListeTrj()
{
    QFileInfo fi("trj/");
    QString chemin=fi.absolutePath();

         QStringList files = QDir( chemin ).entryList();
         if(!files.isEmpty())
         {
             foreach( QString file, files )
             {

                 if(file!=".." && file!="." )
                 {
                    m_cbTrj->addItem(file);
                 }
             }
         }

}

void MaFenetre::lireUnTrj(QString nomFichier)
{
       m_trTrj=Trajet(nomFichier);
       //m_tr0.ajouterPoint(m_vtimerTrj,"n");
       Fichier f0trj(nomFichier);
       QString contenu=f0trj.litreToutLeFichier();
       QStringList lstContenu=contenu.split("\n");
       for(int c=1;c<lstContenu.size()-1;c++)
       {
           m_trTrj.ajouterPoint(lstContenu.at(c).split(":").at(0).toLong(),lstContenu.at(c).split(":").at(1));
       }
      m_trTrj.setFin(lstContenu.at(lstContenu.size()-1).split(":").at(1).toLong());
       m_trTrj.genererInv();
     /*  for(int c=0;c<m_trTrj.getNbPoint();c++)
       {
          m_boxReception->append(QString::number(m_trTrj.getTemp(c)) + " : " +m_trTrj.getAction(c));

       }
      m_boxReception->append(QString::number(m_trTrj.getFin()));*/

}

void MaFenetre::playTrjEnregistrE()
{
    //m_boxReception->append("lecture");
    lireUnTrj("trj/"+m_cbTrj->currentText());

    if(!m_lectureEnCour)
    {
        m_lectureEnCour=true;
        m_btPlay->setEnabled(false);
        m_btPlayInv->setEnabled(false);
        m_btPlayTrjEnregistrE->setEnabled(false);
        m_btPlayInvTrjEnregistrE->setEnabled(false);
        m_timerTrjLecture->start();
        m_sensLecture=3;
    }
}

void MaFenetre::playInvTrjEnregistrE()
{
    lireUnTrj("trj/"+m_cbTrj->currentText());
    if(!m_lectureEnCour)
    {
        m_lectureEnCour=true;
        m_btPlay->setEnabled(false);
        m_btPlayInv->setEnabled(false);
        m_btPlayTrjEnregistrE->setEnabled(false);
        m_btPlayInvTrjEnregistrE->setEnabled(false);
        m_timerTrjEnregistrement->start();
        m_sensLecture=4;
    }
}

void MaFenetre::mazTemps()
{
    m_compteur=0;
    m_lcdTemps->display(QString::number(m_compteur).toDouble());
    Fichier ftmp("tmps");
    ftmp.ecrire(QString::number(m_compteur));
}


void MaFenetre::incrementerTmptrj()
{
    m_vtimerTrj++;
}

void MaFenetre::incrementerCompteur()
{
    if(m_activerCompteur)
    {
        m_compteur++;
        m_lcdTemps->display(QString::number(m_compteur).toDouble());
        Fichier ftmp("tmps");
        ftmp.ecrire(QString::number(m_compteur));
    }

}

void MaFenetre::lireTemps()
{
    Fichier ftmp("tmps");
     m_compteur=ftmp.litreToutLeFichier().toLong();
      m_lcdTemps->display(QString::number(m_compteur).toDouble());
}


void MaFenetre::afficherInfo(QString info)
{
    m_boxInformation->append(info);
    int max=m_boxInformation->verticalScrollBar()->maximum();
    m_boxInformation->verticalScrollBar()->setMaximum(max);
}
