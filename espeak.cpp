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
#include "espeak.h"
#include "speak_lib.h"

#include <QtCore>
#include <QLocale>

uint ESpeak::refcount = 0;

ESpeak::ESpeak(QObject *parent) :
    QObject(parent),
    queueLength(0)
{
    if (0 == refcount)
    {
        espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 100, 0, 0);
        espeak_VOICE voice;
        QString language = QLocale::system().languageToString(QLocale::system().language());
        QByteArray languageData = language.toAscii();
        languageData.prepend((char)0);
        languageData.append((char)0);
        QByteArray languages = QByteArray(1, (char)0);
        languageData += languages;
        voice.languages = languageData.data();
        voice.name = 0;
        voice.gender = 2;
        voice.age = 20;
        espeak_SetVoiceByProperties(&voice);
        espeak_SetParameter(espeakRATE, 175, false);
    }

    ++refcount;
}

ESpeak::~ESpeak()
{
    --refcount;

    if (0 == refcount)
    {
        cancel();
        espeak_Terminate();
    }
}

void ESpeak::say(QString string)
{
    if (0 != queueLength || isPlaying())
        return;

    queueLength++;
    QtConcurrent::run(this, &ESpeak::doSay, string);
}

void ESpeak::cancel()
{
    if (isPlaying())
    {
        espeak_Cancel();
    }

    queueLength = 0;
}

bool ESpeak::isPlaying()
{
    return (bool)espeak_IsPlaying();
}

void ESpeak::doSay(QString string)
{
    switch(string.length())
    {
    case 0:
        break;

    case 1:
        sayChar(string[0]);
        break;

    default:
        sayString(string);
        break;
    }

    queueLength--;
}

void ESpeak::sayChar(QChar character)
{
    espeak_Char(character.unicode());
}

void ESpeak::sayString(QString string)
{
    QByteArray data = string.toUtf8();
    data.append((char)0);
    uint uid = 0;
    espeak_Synth(
                data.constData(),
                data.length(),
                0,
                POS_CHARACTER,
                0,
                espeakCHARS_AUTO,
                &uid,
                0
                );
}
