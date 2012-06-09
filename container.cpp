#include "container.h"

#include <QKeyEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

#include <linux/input.h>

Container::Container(QWidget *parent) :
    QmlApplicationViewer(parent)
{
    setAttribute(Qt::WA_TranslucentBackground, false);
    setWindowFlags(
                  Qt::CustomizeWindowHint
                | Qt::FramelessWindowHint
                | Qt::BypassGraphicsProxyWidget
                | Qt::WindowStaysOnTopHint);

    setWindowModality(Qt::ApplicationModal);
    setWindowState(windowState() | Qt::WindowActive);
    grabKeyboard();
    grabMouse();
}

Container::~Container()
{
}

void Container::keyPressEvent(QKeyEvent *event)
{
    event->accept();
    QWidget::keyPressEvent(event);
}

void Container::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_F4:
        if (event->modifiers() & Qt::AltModifier) {
            exit(0);
        }
    default:{
        if (event->isAutoRepeat()) {
            break;
        }
        qDebug() << event->text();
        event->accept();
        break;
    }
    }

    QWidget::keyReleaseEvent(event);
}

bool Container::eventFilter(QObject *, QEvent *event)
{
    event->accept();
    return true;
}
