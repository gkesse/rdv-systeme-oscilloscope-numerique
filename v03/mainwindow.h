#pragma once

#include <QMainWindow>

#include "FrameParser.h"
#include "DTerminal.h"
#include "IoDevice.h"

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
    // void on_actionSave_data_triggered();
    // void on_actionClear_data_triggered();
    // void on_actionAbout_triggered();
    // void on_actionHowto_triggered();
    // void on_actionListSerialPorts_triggered();
    // void on_actionSaveConfiguration_triggered();
    // void on_actionLoadConfiguration_triggered();
    // void on_uipbConnect_clicked();
    // void on_uiAfterGlow_stateChanged(int state);
    void on_edtRefreshRate_valueChanged(int i);
    // void on_uiNanValue_valueChanged(int i);
    // void on_uiBufferSize_valueChanged(int i);

    void iodevread(QByteArray ba);
    void ioconnected();
    // void iodisconnected();
    // void ioerror(QString err);
    // void ioconnectionerror();

    // void dsrChanged(bool);
    // void aboutToClose();

    // void UiToIdle();
    // void UiWaitConnect();
    // void UiToConnected();

    // void on_uipbSend_clicked();
    // void on_actionList_Bluetooth_devices_triggered();
    void on_btnPreviousPage_clicked();
    void on_btnNextPage_clicked();
    // void on_pushButtonSelectSerial_clicked();
    // void on_pushButtonSelectBt_clicked();
    // void on_pushButton_4_clicked();
    // void on_uipbApplySettings_clicked();
    // void on_uirbScale1_clicked();
    // void on_uirbScale2_clicked();
    // void on_uirbScale4_clicked();
    // void on_uicb_scaling_stateChanged(int arg1);
    // void on_uile_scaling_a_textEdited(const QString &arg1);
    // void on_uile_scaling_b_textEdited(const QString &arg1);

    // void onUpdateTerminalTimer();
    // void on_uipbClearTerm_clicked();
    // void on_uipbAddScopeSettingBasic_clicked();

private:
    Ui::MainWindow *ui;
    DScopesQTWidget *dscopes;

    IoDevice iodev;

    int timer;
    // bool binary;
    // FrameParser3 fp;
    // DLineReader dlr;
    // DTerminal terminal;
    // int totreceiveddata;
    // int nanvalue;
    // unsigned buffersize;

    // QLabel *datarateLabel;
    // QLabel *displayrateLabel;
};
