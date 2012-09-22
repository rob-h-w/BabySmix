#ifndef ESPEAK_H
#define ESPEAK_H

#include <QObject>

/**
  Wraps the espeak library.
  */
class ESpeak : public QObject
{
    Q_OBJECT
    static uint refcount;
public:
    explicit ESpeak(QObject *parent = 0);
    ~ESpeak();

    void say(QChar character);
    Q_INVOKABLE void say(QString character);
    
signals:
    
public slots:
    
};

#endif // ESPEAK_H
