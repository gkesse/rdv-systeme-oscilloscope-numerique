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

    connect(&iodev, SIGNAL(readyRead(QByteArray)), this, SLOT(iodevread(QByteArray)));
    connect(&iodev, SIGNAL(connected()), this, SLOT(ioconnected()));
    // connect(&iodev, SIGNAL(disconnected()), this, SLOT(iodisconnected()));
    // connect(&iodev, SIGNAL(error(QString)), this, SLOT(ioerror(QString)));
    // connect(&iodev, SIGNAL(connectionError()), this, SLOT(ioconnectionerror()));

    QStringList arg = qApp->arguments();
    qDebug() << arg;
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    dscopes->Render();
    dscopes->repaint();
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
    QSettings *settings;

    if (fileName == "")
        settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, "ReadyDev", "ReadyScope");
    else
        settings = new QSettings(fileName, QSettings::IniFormat);

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

void MainWindow::iodevread(QByteArray ba)
{
}

void MainWindow::ioconnected()
{
    qDebug() << "MainWindow::ioconnected...";
}

void MainWindow::on_btnPreviousPage_clicked()
{
    int current = ui->stackedWidget->currentIndex();
    if (current <= 0)
        return;
    ui->stackedWidget->setCurrentIndex(current - 1);
}

void MainWindow::on_btnNextPage_clicked()
{
    int current = ui->stackedWidget->currentIndex();
    if (current >= ui->stackedWidget->count() - 1)
        return;
    ui->stackedWidget->setCurrentIndex(current + 1);
}
