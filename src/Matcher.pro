#-------------------------------------------------
#
# Project created by QtCreator 2016-11-06T22:19:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Matcher
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    question.cpp \
    testhandler.cpp \
    testview.cpp

HEADERS  += mainwindow.h \
    question.h \
    testhandler.h \
    testview.h

FORMS    += mainwindow.ui \
    testview.ui
