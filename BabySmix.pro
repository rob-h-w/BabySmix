#-------------------------------------------------
#
# Project created by QtCreator 2012-04-30T23:59:11
#
#-------------------------------------------------

QT       += core gui

folder_01.source = qml/BabySmix
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

TARGET = BabySmix
TEMPLATE = app


SOURCES += main.cpp\
        container.cpp

HEADERS  += container.h

include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()
