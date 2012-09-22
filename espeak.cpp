#include "espeak.h"
#include "speak_lib.h"

#include <QLocale>

ESpeak::ESpeak(QObject *parent) :
    QObject(parent)
{
    espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 100, 0, 0);
    espeak_VOICE voice;
    QString language = QLocale::system().bcp47Name();
    voice.languages = language.toAscii().data();
    espeak_SetVoiceByProperties(&voice);
}
