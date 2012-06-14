#include "container.h"

#include <QKeyEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

#if defined(Q_WS_X11)
#   include <QX11Info>
#   include <X11/XKBlib.h>
#endif

#include <linux/input.h>

Container::Container(QWidget *parent) :
    QmlApplicationViewer(parent)
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(
              //  Qt::CustomizeWindowHint
               Qt::FramelessWindowHint
              //| Qt::X11BypassWindowManagerHint
              //| Qt::BypassGraphicsProxyWidget
              | Qt::WindowStaysOnTopHint);

    setWindowState(windowState() | Qt::WindowActive);
    activateWindow();
    grabKeyboard();
    grabMouse();
}

Container::~Container()
{
}

bool Container::eventFilter(QObject *, QEvent *event)
{
    event->accept();
    return true;
}

bool Container::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::WindowActivate:
        onStartup();
        event->accept();
        return true;
        break;
    case QEvent::WindowDeactivate:
        onExit();
        event->accept();
        return true;
        break;
    default:
        break;
    }

    return QWidget::event(event);
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

void Container::onStartup()
{
#if defined(Q_WS_X11)
    Display *display = QX11Info::display();
    const QX11Info &info = x11Info();
    Qt::HANDLE winHandle = QX11Info::appRootWindow(info.screen());
//    XGrabServer(display);
    XGrabKeyboard(display, winHandle, true, GrabModeAsync, GrabModeAsync, CurrentTime);
#endif
}

void Container::onExit()
{
#if defined(Q_WS_X11)
    Display *display = QX11Info::display();
//    XUngrabServer(display);
    XUngrabKeyboard(display, CurrentTime);
#endif
}
