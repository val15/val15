#include "maclandrier.h"

MaClandrier::MaClandrier()
{
}

void MaClandrier::colorerEnBleu(const QDate& date)
{
    QTextCharFormat format;
    format.setBackground(Qt::blue);
    setDateTextFormat(date, format);
}

void MaClandrier::colorerEnJaune(const QDate& date)
{
    QTextCharFormat format;
    format.setBackground(Qt::yellow);
    setDateTextFormat(date, format);
}

void MaClandrier::colorerNormalepourLesAutres(const int mois)
{
    int nbJourDuMois[12];
    nbJourDuMois[0]=31;
    nbJourDuMois[1]=28;
    nbJourDuMois[2]=31;
    nbJourDuMois[3]=30;
    nbJourDuMois[4]=31;
    nbJourDuMois[5]=30;
    nbJourDuMois[6]=31;
    nbJourDuMois[7]=31;
    nbJourDuMois[8]=30;
    nbJourDuMois[9]=31;
    nbJourDuMois[10]=30;
    nbJourDuMois[11]=31;
    for(int c=1;c<=nbJourDuMois[mois-1];c++)
    {
        QDate d0(QDate::currentDate().year(),QDate::currentDate().month(),c);
        QTextCharFormat format;
        format.setBackground(Qt::white);
        setDateTextFormat(d0, format);
    }

}
