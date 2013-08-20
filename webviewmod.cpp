#include "webviewmod.h"
#include <QtWebKit/QWebFrame>
#include <iostream>


WebViewMod::WebViewMod(QGraphicsProxyWidget *parent) :
    QGraphicsProxyWidget(parent)
{
    webView = QSharedPointer<QWebView>(new QWebView());
    webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    connect(webView.data(),SIGNAL(linkClicked(QUrl)),SLOT(handleLinkClicked(QUrl)));
    setWidget(webView.data());
}

void WebViewMod::setHtml(const QString &html, const QUrl &baseUrl)
{
    webView->setHtml(html, baseUrl);
}

void WebViewMod::setUrl(const QUrl &url)
{
    webView->setUrl(url);
}

QUrl WebViewMod::url() const
{
    return webView->url();
}


void WebViewMod::handleLinkClicked(const QUrl &linkUrl)
{
    if (webView->url().toString() != "http://www.programmingresearch.com/resources/video-demos/")
    {
        webView->setUrl(linkUrl);
        return;
    }

    QRegExp exception("");
    if (!exception.exactMatch(linkUrl.toString()))
    {
        webView->setUrl(linkUrl);
        std::cout << "AAA = " << linkUrl.toString().toStdString() << std::endl;
    }
    else
        emit linkClicked(linkUrl);
}
