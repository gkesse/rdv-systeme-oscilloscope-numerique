#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#ifdef DEVELMODE
    qDebug() << "Démarrage de l'application [WITH_DEVEL_MODE]...";
#else
    qDebug() << "Démarrage de l'application [NO_DEVEL_MODE]...";
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}
