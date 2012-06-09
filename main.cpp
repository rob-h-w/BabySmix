#include <QtGui/QApplication>
#include "container.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Container viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/BabySmix/main.qml"));
    viewer.showFullScreen();

    return app.exec();
}
