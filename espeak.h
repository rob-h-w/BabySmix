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
