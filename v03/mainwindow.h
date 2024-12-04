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

private:
    Ui::MainWindow *ui;
    // FrameParser fp;
    // DTerminal terminal;
    // int timer;
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
