#include <QApplication>
#include <QStyleFactory>
#include <QDebug>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Démarrage de l'application...";

    //     qputenv("QT_USE_ANDROID_NATIVE_STYLE", "0");

    //     QStringList style = QStyleFactory::keys();
    //     for (int i = 0; i < style.size(); i++)
    //     {
    //         qDebug("Style: %s", style[i].toStdString().c_str());
    //     }

    // #ifdef Q_OS_ANDROID
    //     a.setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Ceil);
    // #endif

    MainWindow w;
    w.show();

    return a.exec();
}
