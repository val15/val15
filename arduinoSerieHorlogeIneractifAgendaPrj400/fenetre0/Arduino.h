#ifndef ARDUINO_H
#define ARDUINO_H
/*classe qui reprsente un arduino*/
#include <qextserialport.h>



class Arduino : public QObject
{
Q_OBJECT
    public:
    Arduino(QString nomDuPort,QString vitesse);
    void connection();
    void deConnection();
    void envoyerText(QString text);

    private:
    QString m_nomDuPort;
    QString m_vitesse;
    QextSerialPort *m_port;
    //une fonction pour recuperer la vitesse
    BaudRateType getBaudRateFromString(QString baudRate);
private slots:
    void readData();
signals:
    void recevoirDonnee(QString txt);
};

#endif // ARDUINO_H
