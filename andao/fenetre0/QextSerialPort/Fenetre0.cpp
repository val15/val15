#include "Fenetre0.h"
/*MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(400,300);//definition de sa taille
    m_bt_apropo = new QPushButton("Pimp mon bouton !", this);// Construction du bouton, this pour indique la classe mere qui n'est autre que MaFenetre elle meme
    m_bt_apropo->setFont(QFont("Comic Sans MS", 14));//on indique la police utilise
    m_bt_apropo->setCursor(Qt::PointingHandCursor);//on indique l'iconne quand on pointe sur le boton
    //m_bt_apropo->setIcon(QIcon("smile.png"));
    m_bt_apropo->move(60, 50);//on indique la position du bouton
}*/

MaFenetre::MaFenetre(int longueur,int hauteur) : QWidget()
{
    setFixedSize(longueur, hauteur);//definition de sa taille
    /*m_bt_apropo = new QPushButton("à propo de Qt!", this);// Construction du bouton, this pour indique la classe mere qui n'est autre que MaFenetre elle meme
    m_bt_apropo->setFont(QFont("Comic Sans MS", 10));
    m_bt_apropo->setCursor(Qt::PointingHandCursor);//PointingHandCursor est une constante predefinie de Qt
    //m_bouton->setIcon(QIcon("smile.png"));
    m_bt_apropo->move(longueur-150, 0);*/
    m_bt_quiter = new QPushButton("Quiter",this);
    m_bt_quiter->move(longueur-100,hauteur-50);
    m_bt_quiter->setCursor(Qt::PointingHandCursor);
    m_bt_rmz=new QPushButton("remise à 0",this);
    m_bt_rmz->move(25,225);
    /*m_lcd=new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);//on modifie l'affichage du lcd
    m_lcd->move(50, 100);*/
    m_slider = new QSlider(Qt::Horizontal, this);//on change la position du slider en horizontal
    m_slider->setGeometry(10, 200, 150, 20);
    m_pgrb=new QProgressBar(this);
    m_pgrb->setGeometry(10, 150, 150, 20);



    //connect() est une méthode de la classe QObject,Comme notre classe MaFenetre hérite de QObject, elle possède elle aussi cette méthode
    QObject::connect(m_bt_quiter, SIGNAL(clicked()), qApp, SLOT(quit()));//m_bouton2 est un pointeur ver l'objet qui emmet le signal le signal, SIGNAL(clicked()) est un macro qui dit qui est le signal ressue,qApp est un pointeur qui pointe ver l'objet Un pointeur vers l'objet qui contient (C a D) le slot récepteur QApplication,SLOT(quit()) est un macro qui indique le nom du slot qui doit s'exécuter lorsque le signal se produit
    //QObject::connect(m_bt_apropo, SIGNAL(clicked()), qApp, SLOT(aboutQt()));
    //QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));//Qt fait automatiquement la relation entre les daux parametre du signal et du slote
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_pgrb, SLOT(setValue(int)));
    QObject::connect(m_bt_rmz, SIGNAL(clicked()), m_pgrb, SLOT(reset()));
}





