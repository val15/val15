/*
 Auteur : val15
 Date De Creation : 20/07/16

Role :
represente les coordonner d'un point d'acces

 */


#ifndef COORDWIFI_H
#define COORDWIFI_H
#include <QtGui>

class Ap
{
public :
    Ap();
    Ap(QString nom,int h,int v);
    QString getNom();
    int getAngleH();
    int getAngleV();


protected:


private:
    QString m_non;
    int m_angleH;
    int m_angleV;

};

#endif //COORDWIFI_H
