#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DScopesQTWidget.h"
#include "DSettings.h"

#include <QSettings>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      timer(0)
//   fp(),
//   terminal(100),
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

    ui->stackedWidget->setCurrentIndex(0);
    ui->tabWidget->setCurrentIndex(0);
    dscopes = new DScopesQTWidget(0, 0, 640, 480, false);
    ui->layScope->addWidget(dscopes);
    resize(800, 640);
    loadSettings();
}

MainWindow::~MainWindow()
{
    saveSettings("settings.ini");
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    qDebug() << "MainWindow::timerEvent...";
}

bool MainWindow::loadSettings(const QString &fileName)
{
    QSettings *settings;

    if (fileName == "")
        settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, "ReadyDev", "ReadyScope");
    else
        settings = new QSettings(fileName, QSettings::IniFormat);

    if (settings->status() != QSettings::NoError)
        return false;

    int refreshRate = settings->value("RefreshRate", 10).toInt();

    if (refreshRate < ui->edtRefreshRate->minimum())
        refreshRate = ui->edtRefreshRate->minimum();
    if (refreshRate > ui->edtRefreshRate->maximum())
        refreshRate = ui->edtRefreshRate->maximum();

    ui->edtRefreshRate->setValue(refreshRate);
    on_edtRefreshRate_valueChanged(refreshRate);

    delete settings;
    return true;
}

bool MainWindow::saveSettings(const QString &fileName)
{
    if (fileName == "")
        return false;

    DSettings *settings;
    settings = new DSettings(fileName);

    if (settings->status() != QSettings::NoError)
        return false;

    settings->setValue("RefreshRate", ui->edtRefreshRate->value());

    delete settings;
    return true;
}

void MainWindow::on_edtRefreshRate_valueChanged(int i)
{
    if (timer)
    {
        killTimer(timer);
        timer = 0;
    }
    timer = startTimer(1000 / i);
}
