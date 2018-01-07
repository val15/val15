#include "WidgetMedia.h"


WidgetMedia::WidgetMedia(QString id,QString titre,QString date,QString emplacement,QString cathegorie,QString etat)
{
    //WidgetMedia::setWindowIcon(QIcon("/home/val15/valPod/jouer"));
    //WidgetMedia::setWindowTitle("media");
    m_cheminWeb="/var/www/html/valPod/";
    m_db="/var/www/html/valPod/valPodDB";
    m_id=id;
    m_titre=titre;
 //   QMessageBox::critical(0, QObject::tr("titre lecture"),titre);
    m_date=date;
    m_cheminRelationEtNom="media/"+titre;//il faut prendre le chemin relatif par rapport à l'emplacement actuel
    m_cheminEtNomDuFichier=emplacement+titre;
    m_cathegorie=cathegorie;
    m_etat=etat;
  //  m_wg_conteneur=new QWidget;
    //m_scl_area->setWidget(this);

   setFixedSize(700,80);
   m_GRPBox=new QGroupBox(this);
   m_GRPBox->setFixedSize(700,80);
    m_glt_layoutPrincipale=new QGridLayout;
    m_GRPBox->setLayout(m_glt_layoutPrincipale);
    m_glt_layoutLabel=new QGridLayout;
    m_lb_titre=new QLabel(m_titre);
    m_lb_date=new QLabel(m_date);
    m_lb_emplacement=new QLabel(emplacement);
    m_lb_etat=new QLabel(m_etat);

    m_glt_layoutLabel->addWidget(m_lb_titre,0,0);
    m_glt_layoutLabel->addWidget(m_lb_date,0,1);
    m_glt_layoutLabel->addWidget(m_lb_etat,0,2);
    m_glt_layoutPrincipale->addWidget(m_lb_emplacement,1,0);
    m_glt_layoutBouton=new QGridLayout;
    m_bt_suprimer=new QPushButton("supprimer");
    m_bt_suprimerDuDisqueDure=new QPushButton("supprimer du disque dure");

    m_glt_layoutBouton->addWidget(m_bt_suprimer,0,0);
    m_glt_layoutBouton->addWidget(m_bt_suprimerDuDisqueDure,0,1);
    m_glt_layoutPrincipale->addLayout(m_glt_layoutBouton,2,0);
    m_glt_layoutPrincipale->addLayout(m_glt_layoutLabel,0,0);


   // setWidget(m_wg_conteneur);
   // setWidgetResizable(false);
    connect(m_bt_suprimer, SIGNAL(clicked()), this,SLOT(supprimer()));
    connect(m_bt_suprimerDuDisqueDure, SIGNAL(clicked()), this,SLOT(supprimerDefinitif()));

    creerpage();

}


void WidgetMedia::supprimerFonct()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_db);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }
       QSqlQuery query;
    query.prepare("delete from media where media.id = :id");
    query.bindValue(":id",m_id);
    query.exec();
    query.clear();
    db.close();

    QFile pageASupprimer(m_nomDuFichierWeb);
    pageASupprimer.remove();
}

void WidgetMedia::supprimer()
{
        //close();


        emit singSupprimer();
}


void WidgetMedia::supprimerDefinitif()
{
    int reponse = QMessageBox::question(this, "Interrogatoire","Voulez vous reelment supprimer definitivement le media ?", QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        //close();
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
           db.setDatabaseName(m_db);
           if(!db.open())
           {
               QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
           }
           QSqlQuery query;
        query.prepare("delete from media where media.id = :id");
        query.bindValue(":id",m_id);
        query.exec();
        query.clear();
        db.close();

        QFile pageASupprimer(m_nomDuFichierWeb);
        pageASupprimer.remove();

        QFile fichierASuppimer(m_cheminEtNomDuFichier);
       // QMessageBox::critical(0, QObject::tr("ficheir : "),m_cheminEtNomDuFichier);
        fichierASuppimer.remove();

        emit singSupprimer();
    }
}

 void WidgetMedia::creerpage()
 {
    // QMessageBox::critical(0, QObject::tr("Database Error"),m_titre);
     QString page;
     if(m_cathegorie=="audio")
         page="<!DOCTYPE html><html><head><meta charset=\"utf-8\" /><title>"+m_titre+"</title></head><body><audio autoplay id=\"a"+m_id+"\" controls><source src=\""+m_cheminRelationEtNom+"\"></source>Veuiller mettre votre navigateur �  jour</audio></br><div align=\"center\"><button class=\"control\" onclick=\"repdrendre('a"+m_id+"')\">Repdrendre</button><button class=\"control\" id=\"btPlay\" onclick=\"play('a"+m_id+"',this)\">Play</button><button class=\"control\" onclick=\"resume('a"+m_id+"')\">Stop</button><button class=\"control\" onclick=\"enregistrer('a"+m_id+"')\">Enregistrer</button></div><script>window.onload = function (){repdrendre('a"+m_id+"')}; var btPlay=document.getElementById('btPlay');function repdrendre(idPlayer){var player = document.querySelector('#' + idPlayer);player.currentTime = localStorage.getItem('tempa"+m_id+"');player.play();btPlay.textContent = 'Pause';}function play(idPlayer, control){var player = document.querySelector('#' + idPlayer);if (player.paused){player.currentTime=player.currentTime-1; player.play();control.textContent = 'Pause';}else{player.pause();control.textContent = 'Play';}}function resume(idPlayer){var player = document.querySelector('#' + idPlayer);player.currentTime = 0;player.pause();}function enregistrer(idPlayer){var player = document.querySelector('#' + idPlayer);var temp =player.currentTime-1;localStorage.setItem('tempa"+m_id+"', temp);}document.addEventListener('keydown', function(e) {if(e.keyCode==\"32\"){play('a"+m_id+"',btPlay);}}, false);var larg = (window.innerWidth);var player=document.getElementById(\'a"+m_id+"\'); player.style.top = \"10px\";player.style.width = larg-50+\"px\";</script></body></html>";
     else
         page="<!DOCTYPE html><html><head><meta charset=\"utf-8\" /><title>"+m_titre+"</title></head><body><video autoplay  id=\"a"+m_id+"\" controls ><source src=\""+m_cheminRelationEtNom+"\"></source>Veuiller mettre votre navigateur �  jour</video></br><div align=\"center\"><button class=\"control\" onclick=\"repdrendre('a"+m_id+"')\">Repdrendre</button><button class=\"control\" id=\"btPlay\" onclick=\"play('a"+m_id+"',this)\">Play</button><button class=\"control\" onclick=\"resume('a"+m_id+"')\">Stop</button><button class=\"control\" onclick=\"enregistrer('a"+m_id+"')\">Enregistrer</button></div><script>window.onload = function (){repdrendre('a"+m_id+"')}; var btPlay=document.getElementById('btPlay');function repdrendre(idPlayer){var player = document.querySelector('#' + idPlayer);player.currentTime = localStorage.getItem('tempa"+m_id+"');player.play();btPlay.textContent = 'Pause';}function play(idPlayer, control){var player = document.querySelector('#' + idPlayer);if (player.paused){player.currentTime=player.currentTime-1;player.play();control.textContent = 'Pause';}else{player.pause();control.textContent = 'Play';}}function resume(idPlayer){var player = document.querySelector('#' + idPlayer);player.currentTime = 0;player.pause();}function enregistrer(idPlayer){var player = document.querySelector('#' + idPlayer);var temp =player.currentTime-1;localStorage.setItem('tempa"+m_id+"', temp);}document.addEventListener('keydown', function(e) {if(e.keyCode==\"32\"){play('a"+m_id+"',btPlay);}}, false);var larg = (window.innerWidth);var haut = (window.innerHeight);var player=document.getElementById(\'a"+m_id+"\'); player.style.top = \"10px\";player.style.width = larg-50+\"px\";player.style.height =  haut-50+\"px\";  </script></body></html>";
     m_nomDuFichierWeb=m_cheminWeb+m_id+"=>"+m_titre+ +".html";
     QFile file( m_nomDuFichierWeb);
     file.open(QIODevice::WriteOnly);
     QTextStream stream ( &file );
     stream << page;
     file.close();
 }
