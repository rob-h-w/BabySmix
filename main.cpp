
#include "container.h"

#include <QtGui/QApplication>

#if defined(Q_WS_X11)
#   include <QX11Info>
#   include <X11/XKBlib.h>
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if defined(Q_WS_X11)
    Display *display = QX11Info::display();
//    const QX11Info &info = x11Info();
//    Qt::HANDLE winHandle = QX11Info::appRootWindow(info.screen());
//    XGrabServer(display);
#endif

    Container viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/BabySmix/main.qml"));
    viewer.showFullScreen();
    //viewer.activateWindow();

    int returnValue = app.exec();

#if defined(Q_WS_X11)
//    XUngrabServer(display);
#endif

    return returnValue;
}
