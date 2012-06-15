
#include "container.h"

#include <QtGui/QApplication>

#if defined(Q_WS_X11)
#   include <QX11Info>
#   include <X11/XKBlib.h>
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Container viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/BabySmix/main.qml"));
    viewer.setResizeMode(QDeclarativeView::SizeRootObjectToView);
    viewer.showFullScreen();

    return app.exec();
}
