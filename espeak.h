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
    
signals:
    
public slots:
    
};

#endif // ESPEAK_H
