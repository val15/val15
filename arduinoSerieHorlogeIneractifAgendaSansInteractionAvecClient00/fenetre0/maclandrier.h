#ifndef MACLANDRIER_H
#define MACLANDRIER_H
#include <QtWidgets>

/*
 Auteur : val15
 Date De Creation : 17/12/16

Role :
herite de QCalendarWidget pour poivoir utiliser paintCell

 */

class MaClandrier: public QCalendarWidget
{
public :
    MaClandrier();
    void colorerEnBleu(const QDate& date);
    void colorerEnJaune(const QDate& date);
    void colorerNormalepourLesAutres(const int mois);
protected:


private:


};

#endif // MACLANDRIER_H
