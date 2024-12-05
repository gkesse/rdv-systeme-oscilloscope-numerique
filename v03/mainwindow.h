#pragma once

#include <QMainWindow>

#include "FrameParser.h"
#include "DTerminal.h"

class DScopesQTWidget;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void timerEvent(QTimerEvent *event);

private:
    bool loadSettings(const QString &fileName = "");
    bool saveSettings(const QString &fileName = "");

private slots:
    void on_edtRefreshRate_valueChanged(int i);

private:
    Ui::MainWindow *ui;
    int timer;
    // FrameParser fp;
    // DTerminal terminal;
    // int totreceiveddata;
    // int nanvalue;
    // unsigned buffersize;
    // double scaling_a;
    // double scaling_b;
    // bool scaling_enabled;
    // bool binary;
    // double pt;
    // double lastplot;
    DScopesQTWidget *dscopes;
};
