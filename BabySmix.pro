#-------------------------------------------------
#
# Project created by QtCreator 2012-04-30T23:59:11
#
#-------------------------------------------------

VER_MAJ = 1
VER_MIN = 0
VER_PAT = 0
VERSION = $${VER_MAJ}.$${VER_MIN}.$${VER_PAT}
DEFINES += APP_VERSION=\\\"$${VERSION}\\\"

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
