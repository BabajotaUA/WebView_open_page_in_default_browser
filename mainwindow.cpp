#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDeclarative/QDeclarativeError>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qmlRegisterType<WebViewMod>("webviewmod",1,0,"WebViewMod");
    ui->setupUi(this);

    auto appPath = QApplication::applicationDirPath();
    ui->declarativeView->engine()->addImportPath(appPath);
    ui->declarativeView->engine()->addPluginPath(appPath);

    ui->declarativeView->setSource(QUrl("main.qml"));
    QGraphicsObject* root = ui->declarativeView->rootObject();
    connect(root, SIGNAL(systemWebBrowserCall(QString)),SLOT(systemWebBrowserCalling(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::systemWebBrowserCalling(const QString &url)
{
    std::cout << "LINK IS CLICKED = " << url.toStdString() << std::endl;
}
