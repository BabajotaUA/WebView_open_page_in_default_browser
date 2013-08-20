#ifndef WEBVIEWMOD_H
#define WEBVIEWMOD_H

#include <QGraphicsProxyWidget>
#include <QtWebKit/QWebView>
#include <QtCore/QSharedPointer>

class WebViewMod : public QGraphicsProxyWidget
{
    Q_PROPERTY(QString html WRITE setHtml)
    Q_PROPERTY(QUrl url READ url WRITE setUrl)


    Q_OBJECT
public:
    explicit WebViewMod(QGraphicsProxyWidget *parent = 0);
    virtual ~WebViewMod() { webView.clear(); }

    void setHtml(const QString& html, const QUrl& baseUrl = QUrl());
    void setUrl(const QUrl &url);
    QUrl url() const;

signals:
    void linkClicked(const QUrl &linkUrl);

private slots:
    void handleLinkClicked(const QUrl &linkUrl);

private:
    QSharedPointer<QWebView> webView;
};

#endif // WEBVIEWMOD_H
