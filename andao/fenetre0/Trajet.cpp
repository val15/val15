#include "Trajet.h"
Trajet::Trajet()
{

}

Trajet::Trajet(QString nom)
 {
    m_non=nom;

 }

QString Trajet::getNom()
{
    return m_non;
     m_fin=0;
     m_debut=0;
     m_finInv=0;
    m_debutInv=0;
}

void Trajet::ajouterPoint(long temp,QString action)
{
   m_lstTemp.append(QString::number(temp));

    m_lstAction.append(action);
}

int Trajet::getNbPoint()
{
    return m_lstTemp.size();
}



void Trajet::setFin(long fin)
{
    m_fin=fin;
}

void Trajet::setDebut(long debut)
{
    m_debut=debut;
}

long Trajet::getFin()
{
    return m_fin;
}

long Trajet::getDebut()
{
    return m_debut;
}

QString Trajet::getAction(int i)
{
    return m_lstAction.at(i);
}

long Trajet::getTempInv(int i)
{
    return m_lstTempInv.at(i).toLong();
}

QString Trajet::getActionInv(int i)
{
    return m_lstActionInv.at(i);
}

long Trajet::getTemp(int i)
{
    return m_lstTemp.at(i).toLong();
}



void Trajet::genererInv()
{
    m_debutInv=0;
    m_finInv=m_fin;

    for(int c=m_lstAction.size()-1;c>=0;c--)
    {
        m_lstTempInv.append(QString::number(m_fin-m_lstTemp.at(c).toLong()));
    }
    for(int c=m_lstAction.size()-1;c>=0;c--)
    {
        //System.out.println("actin a inv = "+ this.lstAction.get(c));
        if(m_lstAction.at(c)=="s")
        {
            if(m_lstAction.at(c-1)=="a")
                m_lstActionInv.append("r");
            if(m_lstAction.at(c-1)=="r")
                m_lstActionInv.append("a");
            if(m_lstAction.at(c-1)=="g")
                m_lstActionInv.append("d");
            if(m_lstAction.at(c-1)=="d")
                m_lstActionInv.append("g");

        }
        else
            m_lstActionInv.append("s");
    }
}

void Trajet::clear()
{
    if(this->getNbPoint()!=0)
    {
        m_lstAction.clear();
        m_lstTemp.clear();
        m_fin=0;
        m_debut=0;
        m_lstActionInv.clear();
        m_lstTempInv.clear();
        m_finInv=0;
        m_debutInv=0;

    }
}


