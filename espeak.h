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
    
signals:
    
public slots:
    
private:
    void doSay(QString string);
    void say(QChar character);

private:
    static uint refcount;
};

#endif // ESPEAK_H
