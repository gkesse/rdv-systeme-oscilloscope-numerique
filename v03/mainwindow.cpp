#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DScopesQTWidget.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
//   fp(),
//   terminal(100),
//   timer(0),
//   totreceiveddata(0),
//   nanvalue(0),
//   buffersize(100000),
//   scaling_a(1.0),
//   scaling_b(0.0),
//   scaling_enabled(false),
//   binary(false),
//   pt(0.0),
//   lastplot(0.0)
{
    ui->setupUi(this);

#ifdef DEVELMODE
    qDebug() << "Démarrage de l'application [WITH_DEVEL_MODE]...";
#else
    qDebug() << "Démarrage de l'application [NO_DEVEL_MODE]...";
#endif

    dscopes = new DScopesQTWidget(0, 0, 640, 480, false);
    ui->layScope->addWidget(dscopes);

    resize(800, 640);
}

MainWindow::~MainWindow()
{
    delete ui;
}
