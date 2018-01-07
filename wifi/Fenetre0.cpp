#include "Fenetre0.h"


MaFenetre::MaFenetre() : QWidget()
{
    m_angleH="90";
    m_angleV="90";

    m_dbMon="/home/pi/wifiCoord/dbWifi";
    m_gltPrincipal=new QGridLayout();
    m_gltConnexionArd=new QGridLayout();
    m_gltHaut=new QGridLayout();
    m_gltMilieu=new QGridLayout();
    m_gltBas=new QGridLayout();
    m_gltCommande=new QGridLayout();
    m_gltHorizontal=new QGridLayout();
    m_gltVeritcal=new QGridLayout();
    m_gltEnregistrement=new QGridLayout();

    m_lePort=new QLineEdit("/dev/ttyACM0");
    m_cbVitesse=new QComboBox();
    m_btConnexionArd=new QPushButton("connection");
    m_teInfo=new  QTextEdit();

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
    m_lcdnAngleV->setEnabled(false);
    m_sldV->setEnabled(false);
    m_btCharger->setEnabled(false);

    m_lbE=new QLabel("E");
    m_lbW=new QLabel("W");
    m_lbM=new QLabel("M");
    m_lbD=new QLabel("D");

     m_btEnvoyerCoorH=new QPushButton("envyer");
     m_btEnvoyerCoorV=new QPushButton("envyer");
     m_btEnvoyerCoorH->setEnabled(false);
     m_btEnvoyerCoorV->setEnabled(false);

    m_gltConnexionArd->addWidget(m_lePort,0,0);
     m_gltConnexionArd->addWidget(m_cbVitesse,0,1);
    m_gltConnexionArd->addWidget(m_btConnexionArd,0,2);

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

      m_gltPrincipal->addLayout(m_gltConnexionArd,0,0);
      m_gltPrincipal->addWidget(m_teInfo,1,0);
    m_gltPrincipal->addLayout(m_gltHaut,2,0);
    m_gltPrincipal->addLayout(m_gltMilieu,3,0);
    m_gltPrincipal->addLayout(m_gltBas,4,0);


    this->setLayout(m_gltPrincipal);

    //connexion ard
    //on parcourt la liste des ports

    m_cbVitesse->addItem("9600");
    m_cbVitesse->addItem("300");
    m_cbVitesse->addItem("1200");
    m_cbVitesse->addItem("2400");
    m_cbVitesse->addItem("4800");
    m_cbVitesse->addItem("19200");
    m_cbVitesse->addItem("38400");
    m_cbVitesse->addItem("57600");
    m_cbVitesse->addItem("115200");



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


    QObject::connect(m_btConnexionArd, SIGNAL(clicked()), this,SLOT(connexion()));
    QObject::connect(m_sldH, SIGNAL(valueChanged(int)), this,SLOT(changerValeurH(int)));
    QObject::connect(m_sldV, SIGNAL(valueChanged(int)), this,SLOT(changerValeurV(int)));
    QObject::connect(m_btEnregister, SIGNAL(clicked()), this,SLOT(enregister()));
      QObject::connect(m_btSupprimer, SIGNAL(clicked()), this,SLOT(supprimer()));
    QObject::connect(m_btVider, SIGNAL(clicked()), this,SLOT(vider()));
     QObject::connect(m_btCharger, SIGNAL(clicked()), this,SLOT(charger()));
     QObject::connect(m_btEnvoyerCoorH, SIGNAL(clicked()), this,SLOT(envoyerCoordH()));
     QObject::connect(m_btEnvoyerCoorV, SIGNAL(clicked()), this,SLOT(envoyerCoordV()));


    lireDb();
}

void MaFenetre::connexion()
{
    if(!m_estConnecT)
    {
        //on rgle le port utilis (slectionn dans la liste droulante)
        m_port=new QextSerialPort();
        m_port->setPortName(m_lePort->text());
        //on rgle la vitesse utilise
        //port->setBaudRate (getBaudRateFromString(m_cbVitesse->currentText()));
        m_port->setBaudRate(getBaudRateFromString(m_cbVitesse->currentText()));
        //quelques rglages pour que tout marche bien
       m_port->setParity(PAR_NONE);//parit
        m_port->setStopBits(STOP_1);//nombre de bits de stop
        m_port->setDataBits(DATA_8);//nombre de bits de donnes
        m_port->setFlowControl(FLOW_OFF);//pas de contrle de flux
        //on dmarre !
        m_port->open(QextSerialPort::ReadWrite);
       /* if(m_port->isOpen())
        {
*/
         //   m_teInfo->append("connexion reussit");
            m_btConnexionArd->setText("Deconnecter");
            m_estConnecT=true;

            //on fait la connexion pour pouvoir obtenir les vnements
            connect(m_port,SIGNAL(readyRead()), this, SLOT(readData()));
            m_btEnvoyerCoorH->setEnabled(true);
            m_btCharger->setEnabled(true);


       /* }
        else
        {
            m_teInfo->append("connxion echouE");
        }*/


    }
    else
    {
        //on se dconnecte de la carte Arduino
        m_port->close();
        //puis on dtruit l'objet port srie devenu inutile
        delete m_port;
        m_btConnexionArd->setText("Connecter");
        exit(0);
    }
}

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
    envoyer("check");
}

void MaFenetre::changerValeurH(int h)
{
    m_lcdnAngleH->display(h);
    m_angleH=QString::number(h);
}

 void MaFenetre::envoyerCoordH()
 {
     envoyer("h="+m_angleH);
 }

 void MaFenetre::changerValeurV(int v)
 {
     m_lcdnAngleV->display(v);
     m_angleV=QString::number(v);
 }

 void MaFenetre::envoyerCoordV()
 {
     envoyer("v="+m_angleV);
 }


//arduino

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

void  MaFenetre::envoyer(QString str)
{
    if(m_port != NULL)
         m_port->write(str.toAscii());
}


void MaFenetre::readData()
{

    QByteArray array = m_port->readAll();
    m_teInfo->insertPlainText(array);
    //QString strRecu;
}

