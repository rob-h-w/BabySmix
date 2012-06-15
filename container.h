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
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent (QKeyEvent *event);
    virtual QSize sizeHint() const;

    void updateSize();

private slots:
    void onStartup();
    void onExit();
    void onStatusChanged(QDeclarativeView::Status status);
};

#endif // CONTAINER_H
