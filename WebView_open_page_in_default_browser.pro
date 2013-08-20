#-------------------------------------------------
#
# Project created by QtCreator 2013-08-19T15:10:32
#
#-------------------------------------------------

QT       += core gui declarative network webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebView_open_page_in_default_browser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    webviewmod.cpp

HEADERS  += mainwindow.h \
    webviewmod.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    ../build-WebView_open_page_in_default_browser/main.qml
