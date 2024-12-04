#include <QApplication>
#include <QStyleFactory>
#include <QDebug>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Démarrage de l'application...";

    MainWindow w;
    w.show();

    return a.exec();
}
