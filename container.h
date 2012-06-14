#ifndef CONTAINER_H
#define CONTAINER_H

#include "qmlapplicationviewer.h"

class QKeyEvent;
class QShowEvent;
class QEvent;

class Container : public QmlApplicationViewer
{
    Q_OBJECT

    Q_DISABLE_COPY(Container)
public:
    explicit Container(QWidget *parent = 0);
    ~Container();

private:
    bool eventFilter(QObject *, QEvent *event);
    virtual bool event(QEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent (QKeyEvent *event);

private slots:
    void onStartup();
    void onExit();
};

#endif // CONTAINER_H
