//    BabySmix - Ubuntu targetted baby game based on and inspired by Scott
//    Hanselman's much-loved Baby Smash! http://www.hanselman.com/babysmash/
//    Copyright (C) 2012  Rob Williamson
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include "container.h"

#include <QKeyEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QStackedLayout>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QDeclarativeItem>
#include <QDeclarativeProperty>

#if defined(Q_WS_X11)
#   include <QX11Info>
#   include <X11/XKBlib.h>
#endif

#include <linux/input.h>

#if defined(Q_WS_X11) // Stupid X11 defines Status, breaking the QDeclarativeView::Status by causing the preprocessor to replace Status.
#   define OLD_STATUS = Status
#   undef Status
#endif
Container::Container(QWidget *parent) :
    QmlApplicationViewer(parent)
{
    connect(this, SIGNAL(statusChanged(QDeclarativeView::Status)), SLOT(onStatusChanged(QDeclarativeView::Status)));
    connect(QApplication::instance(), SIGNAL(aboutToQuit()), SLOT(onExit()));

    updateSize();

    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(
                  Qt::FramelessWindowHint
                | Qt::WindowStaysOnTopHint);

    QDeclarativeContext *context = rootContext();
    if (!context) {
        return;
    }

    context->setContextProperty("version", QCoreApplication::applicationVersion());
}
#if defined(Q_WS_X11)
#   define Status = OLD_STATUS
#   undef OLD_STATUS
#endif

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
        } // Intentional dropthrough.
    default:{
        if (event->isAutoRepeat()) {
            // Ignore autorepeats.
            break;
        }

        bool ok;
        QMetaMethod slot = onKeyPressedSlot(ok);
        if (ok) {
            slot.invoke(rootObject(),
                        Qt::AutoConnection,
                        Q_ARG(QVariant,
                              event->text()));
            event->accept();
        }
        break;
    }
    }

    QWidget::keyReleaseEvent(event);
}

QSize Container::sizeHint() const
{
    QDesktopWidget *desktop = QApplication::desktop();
    if (!desktop) {
        return QSize(0, 0);
    }

    int maxWidth = 0;
    int maxHeight = 0;
    const int count = desktop->screenCount();
    for (int i = 0; i < count; ++i) {
        maxWidth = qMax(maxWidth, desktop->screen(i)->geometry().width());
        maxHeight = qMax(maxHeight, desktop->screen(i)->geometry().height());
    }

    return QSize(maxWidth, maxHeight);
}

void Container::updateSize()
{
    // Resize the root widget.
    QDeclarativeContext *context = rootContext();
    if (!context) {
        return;
    }

    QSize size = sizeHint();
    context->setContextProperty("rootWidth", size.width());
    context->setContextProperty("rootHeight", size.height());
}

QMetaMethod Container::onKeyPressedSlot(bool &ok) const
{
    ok = false;
    QMetaMethod slot;
    // Get the root object.
    QDeclarativeItem *root = qobject_cast<QDeclarativeItem *>(rootObject());
    if (!root) {
        return slot;
    }

    const QMetaObject *meta = root->metaObject();
    if (!meta) {
        return slot;
    }

    const int index = meta->indexOfMethod("onKeyPressed(QVariant)");
    if (index == -1) {
        return slot;
    }

    slot = meta->method(index);

    ok = slot.methodType() == QMetaMethod::Slot;

    return slot;
}

void Container::onStartup()
{
#if defined(Q_WS_X11)
    Display *display = QX11Info::display();
    const QX11Info &info = x11Info();
    Qt::HANDLE winHandle = QX11Info::appRootWindow(info.screen());
    XGrabKeyboard(display, winHandle, true, GrabModeAsync, GrabModeAsync, CurrentTime);
#endif

    // Filling the screen doesn't function well in some X11 environments - explicitly set the size
    // using global context variables here.
    updateSize();
}

void Container::onExit()
{
#if defined(Q_WS_X11)
    Display *display = QX11Info::display();
    XUngrabKeyboard(display, CurrentTime);
#endif
}

#if defined(Q_WS_X11)
#   define OLD_STATUS = Status
#   undef Status
#endif
void Container::onStatusChanged(QDeclarativeView::Status status)
{
    switch (status) {
    case QDeclarativeView::Ready:
        updateSize();
        onStartup();
        break;
    default:
        break;
    }
}
#if defined(Q_WS_X11)
#   define Status = OLD_STATUS
#   undef OLD_STATUS
#endif
