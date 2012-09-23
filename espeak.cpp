#include "espeak.h"
#include "speak_lib.h"

#include <QLocale>

uint ESpeak::refcount = 0;

ESpeak::ESpeak(QObject *parent) :
    QObject(parent)
{
    if (0 == refcount)
    {
        espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 100, 0, 0);
        espeak_VOICE voice;
        QString language = QLocale::system().bcp47Name();
        QByteArray languageData = language.toAscii();
        QByteArray languages = QByteArray(1, (char)0);
        languageData += languages;
        voice.languages = languageData.data();
        espeak_SetVoiceByProperties(&voice);
        espeak_SetParameter(espeakRATE, 100, false);
    }

    ++refcount;
}

ESpeak::~ESpeak()
{
    --refcount;

    if (0 == refcount)
    {
        if (espeak_IsPlaying())
        {
            espeak_Cancel();
        }

        espeak_Terminate();
    }
}

void ESpeak::say(QString string)
{
    switch(string.length())
    {
    case 0: // Nothing to say.
        return;

    case 1: // Say the character name.
        say(string[0]);
        return;
    }

    // Say the string here.
    const QByteArray data = string.toUtf8();
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

void ESpeak::say(QChar character)
{
    espeak_Char(character.unicode());
}
