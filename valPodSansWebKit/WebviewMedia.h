#ifndef WEBVIEWMEDIA_H
#define WEBVIEWMEDIA_H
/*
 Auteur : val15
 Date De Creation : 02/11/13

Role :
un QWebView pour visionner le media

 */

#include <QtWebKit>
#include <QtGui>


class WebviewMedia : public QWidget
{
    Q_OBJECT
public :
    WebviewMedia();
    WebviewMedia(QString url);
protected:


private:
    QString m_url;
    QWebView *m_vw_page;
    QGridLayout *m_glt_layoutPrincipale;



};



#endif // WEBVIEWMEDIA_H
