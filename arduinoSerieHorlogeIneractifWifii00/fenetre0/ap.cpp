#include "ap.h"

Ap::Ap()
{

}
Ap::Ap(QString nom,int h,int v)
{
    m_non=nom;
    m_angleH=h;
    m_angleV=v;
}

QString Ap::getNom()
{
    return m_non;
}

int Ap::getAngleH()
{
    return m_angleH;
}

int Ap::getAngleV()
{
    return m_angleV;
}
