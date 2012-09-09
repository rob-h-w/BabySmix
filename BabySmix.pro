#-------------------------------------------------
#
# Project created by QtCreator 2012-04-30T23:59:11
#
#-------------------------------------------------
#
#    BabySmix - Ubuntu targetted baby game based on and inspired by Scott
#    Hanselman's much-loved Baby Smash! http://www.hanselman.com/babysmash/
#    Copyright (C) 2012  Rob Williamson
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.

VER_MAJ = 1
VER_MIN = 0
VER_PAT = 0
VERSION = $${VER_MAJ}.$${VER_MIN}.$${VER_PAT}
DEFINES += APP_VERSION=\\\"$${VERSION}\\\"

QT       += core gui
CONFIG   += x11

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
