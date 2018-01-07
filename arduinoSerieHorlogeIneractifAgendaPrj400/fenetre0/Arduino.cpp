#include "Arduino.h"
Arduino::Arduino(QString nomDuPort,QString vitesse)
{
    m_nomDuPort=nomDuPort;
    m_vitesse=vitesse;
}

void Arduino::connection()
{
    m_port = new QextSerialPort();
    //on essaie de faire la connexion avec la carte Arduino
    //on commence par crer l'objet port srie

    //on rgle le port utilis (slectionn dans la liste droulante)
    m_port->setPortName(m_nomDuPort);
    m_port->setBaudRate(getBaudRateFromString(m_vitesse));
    //quelques rglages pour que tout marche bien
   m_port->setParity(PAR_NONE);//parit
    m_port->setStopBits(STOP_1);//nombre de bits de stop
    m_port->setDataBits(DATA_8);//nombre de bits de donnes
    m_port->setFlowControl(FLOW_OFF);//pas de contrle de flux
    //on dmarre !
    m_port->open(QextSerialPort::ReadWrite);
    //change le message du bouton
    //on fait la connexion pour pouvoir obtenir les vnements
    QObject::connect(m_port,SIGNAL(readyRead()), this, SLOT(readData()));
}

void Arduino::deConnection()
{
    m_port->close();
}

void Arduino::envoyerText(QString text)
{
    if(m_port != NULL)
            m_port->write(text.toUtf8());
}

void Arduino::readData()
{
    QByteArray array = m_port->readAll();

    QString str;
    str=array;
    emit recevoirDonnee(m_nomDuPort+":"+str);
}


BaudRateType Arduino::getBaudRateFromString(QString baudRate)//pour determiner la vitesse
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
