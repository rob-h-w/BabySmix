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

!symbian: !win32: unix: isEmpty(MEEGO_VERSION_MAJOR): {
    desktopfile.files = $${TARGET}.desktop
    desktopfile.path = /usr/share/applications
    icon.files = $${TARGET}.svg
    icon.path = /usr/share/icons/hicolor/scalable/apps
# /usr/share/icons/hicolor/16x16/apps
# /usr/share/icons/hicolor/22x22/apps
# /usr/share/icons/hicolor/24x24/apps
# /usr/share/icons/hicolor/32x32/apps
}

include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()
