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

void ESpeak::say(QChar character)
{
    espeak_Char(character.unicode());
}

void ESpeak::say(QString character)
{
    switch(character.length())
    {
    case 0:
        return;

    case 1:
        say(character[0]);
        return;
    }

    // TODO: say the string here.
    const QByteArray data = character.toUtf8();
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
