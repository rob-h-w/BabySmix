//    BabySmix - Ubuntu targetted baby game based on and inspired by Scott
//    Hanselman's much-loved Baby Smash! http://www.hanselman.com/babysmash/
//    Copyright (C) 2012  Rob Williamson
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#ifndef CONTAINER_H
#define CONTAINER_H

#include "qmlapplicationviewer.h"

#include <QVariant>

class QKeyEvent;
class QShowEvent;
class QEvent;

class Container : public QmlApplicationViewer
{
    Q_OBJECT

    Q_DISABLE_COPY(Container)
public:
    explicit Container(QWidget *parent = 0);
    ~Container();

private:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent (QKeyEvent *event);
    virtual QSize sizeHint() const;

    void updateSize();
    QMetaMethod onKeyPressedSlot(bool &ok) const;

private slots:
    void onStartup();
    void onExit();
    void onStatusChanged(QDeclarativeView::Status status);
};

#endif // CONTAINER_H
