#ifndef FENETRE0_H
#define FENETRE0_H
/*#include <QApplication>
#include <QWidget>
#include <QPushButton>
# include <QPushButton>
#include <QLCDNumber>
#include <QSlider>*/


#include <QtGui>

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    public:
   // MaFenetre();//constructeur par defaut
    MaFenetre(int longueur,int hauteur);//constructeur par valeur
    private:
    //QPushButton *m_bt_apropo;//on ceer un atribu de type QPushButton s'est un pointeur
    QPushButton *m_bt_quiter;
    QPushButton *m_bt_rmz;

    //QLCDNumber *m_lcd;
    QSlider *m_slider;
    QProgressBar *m_pgrb;
};


#endif // FENETRE0_H
