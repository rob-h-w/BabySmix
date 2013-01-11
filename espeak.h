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
#ifndef ESPEAK_H
#define ESPEAK_H

#include <QObject>

/**
  Wraps the espeak library.
  */
class ESpeak : public QObject
{
    Q_OBJECT
public:
    explicit ESpeak(QObject *parent = 0);
    ~ESpeak();

    Q_INVOKABLE void say(QString string);
    Q_INVOKABLE void cancel();
    Q_INVOKABLE bool isPlaying();
    
signals:
    
public slots:
    
private:
    void doSay(QString string);
    void sayChar(QChar character);
    void sayString(QString string);

private:
    static uint refcount;

private:
    uint queueLength;
};

#endif // ESPEAK_H
