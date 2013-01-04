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
        QByteArray languages = QByteArray(1, (char)0);
        languageData += languages;
//        voice.languages = languageData.data();
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
