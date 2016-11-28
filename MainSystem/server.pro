#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T12:33:01
#
#-------------------------------------------------

# John Walter and Evan Schulte
# ECE 3220 - Final Project

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newpatientwindow.cpp \
    editpatientwindow.cpp

HEADERS  += mainwindow.h \
    newpatientwindow.h \
    editpatientwindow.h

FORMS    += mainwindow.ui \
    newpatientwindow.ui \
    editpatientwindow.ui
