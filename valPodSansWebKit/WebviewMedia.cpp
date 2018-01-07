#include "WebviewMedia.h"
WebviewMedia::WebviewMedia(QString url)
{
    m_url=url;
    m_vw_page=new QWebView ;
    m_glt_layoutPrincipale=new QGridLayout;
    m_glt_layoutPrincipale->addWidget(m_vw_page,0,0);
    setLayout(m_glt_layoutPrincipale);
    m_vw_page->load(m_url);
}
WebviewMedia::WebviewMedia()
{

}
