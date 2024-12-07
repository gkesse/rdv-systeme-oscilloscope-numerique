#include "IoDevice.h"

#include <QDebug>

IoDevice::IoDevice(QObject *parent)
    : QObject(parent),
      deviceSER(parent)
{
    connect(&deviceSER, SIGNAL(readyRead()), this, SLOT(SERGotData()));
    connect(&deviceSER, SIGNAL(errorOccurred(QSerialPort::SerialPortError)), this, SLOT(SERError(QSerialPort::SerialPortError)));

    // connect(&deviceTCP, SIGNAL(readyRead()), this, SLOT(TCPGotData()));
    // connect(&deviceTCP, SIGNAL(connected()), this, SLOT(TCPConnected()));
    // connect(&deviceTCP, SIGNAL(disconnected()), this, SLOT(TCPDisconnected()));
    // connect(&deviceTCP, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(TCPErr(QAbstractSocket::SocketError)));
}

IoDevice::~IoDevice()
{
}

bool IoDevice::open(ConnectionData cd)
{
    // if (isConnected())
    // {
    //     return false;
    // }

    connectiondata = cd;

    switch (cd.type)
    {
    case DevTCPConnection:
        // deviceTCP.connectToHost(cd.tcphost, cd.tcpport);
        break;
    case DevSerialConnection:
        deviceSER.setPortName(cd.port);
        deviceSER.setDataBits(QSerialPort::Data8);
        deviceSER.setFlowControl(QSerialPort::NoFlowControl);
        deviceSER.setParity(QSerialPort::NoParity);
        deviceSER.setStopBits(QSerialPort::OneStop);

        deviceSER.open(QIODevice::ReadWrite);

        if (!deviceSER.isOpen())
        {
            qDebug("IoDevice: Serial: cannot open. Check port:speed settings.\n");
            emit connectionError();
            return false;
        }
        else
        {
            qDebug("IoDevice: Serial: Open successful\n");
            emit connected();
            return true;
        }

        break;
    case DevBTConnection:
        // #if BTPOINTER == 0
        // #else
        //         if (deviceBT)
        //         {
        //             delete deviceBT;
        //             deviceBT = 0;
        //         }
        //         deviceBT = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);

        //         deviceBT->setPreferredSecurityFlags(QBluetooth::Security::NoSecurity);
        //         connect(deviceBT, SIGNAL(readyRead()), this, SLOT(BTGotData()));
        //         connect(deviceBT, SIGNAL(connected()), this, SLOT(BTConnected()));
        //         connect(deviceBT, SIGNAL(disconnected()), this, SLOT(BTDisconnected()));
        //         connect(deviceBT, SIGNAL(errorOccurred(QBluetoothSocket::SocketError)), this, SLOT(BTError(QBluetoothSocket::SocketError)));
        // #endif

        // #if BTPOINTER == 0
        // #ifdef Q_OS_ANDROID
        //         deviceBT.connectToService(cd.ba, QBluetoothUuid(QString("00001101-0000-1000-8000-00805f9b34fb"))); // Works on android but not linux
        // #else
        //         deviceBT.connectToService(cd.ba, QBluetoothUuid::SerialPort); // Works on linux, does not work on android
        // #endif
        // #else
        // #ifdef Q_OS_ANDROID
        //         deviceBT->connectToService(cd.ba, QBluetoothUuid(QString("00001101-0000-1000-8000-00805f9b34fb"))); // Works on android but not linux
        // #else
        //         deviceBT->connectToService(cd.ba, QBluetoothUuid::ServiceClassUuid::SerialPort); // Works on linux, does not work on android
        // #endif
        // #endif

        break;
    default:
        break;
    }

    return false;
}

bool IoDevice::close()
{
    switch (connectiondata.type)
    {
    case DevTCPConnection:
        // if (deviceTCP.state() != QAbstractSocket::UnconnectedState)
        // {
        //     deviceTCP.disconnectFromHost();
        //     if (deviceTCP.state() != QAbstractSocket::UnconnectedState)
        //     {
        //         if (!deviceTCP.waitForDisconnected())
        //         {
        //             printf("Could not disconnect from host\n");
        //             return false;
        //         }
        //     }
        // }
        break;
    case DevSerialConnection:
        if (deviceSER.isOpen())
            deviceSER.close();
        emit disconnected();
        break;
    case DevBTConnection:
        // #if BTPOINTER == 0
        //         if (deviceBT.state() != QAbstractSocket::UnconnectedState)
        //         {
        //             deviceBT.disconnectFromService();
        //             // No waitForDisconnected exists
        //         }
        // #else
        //         // if( deviceBT->state() != QAbstractSocket::UnconnectedState )
        //         if (deviceBT->state() != QBluetoothSocket::SocketState::UnconnectedState)
        //         {
        //             deviceBT->disconnectFromService();
        //             // No waitForDisconnected exists
        //         }
        // #endif
        break;
    case DevNotConnected:
        break;
    }
    return true;
}

void IoDevice::SERGotData()
{
    qDebug() << "IoDevice::SERGotData...";
}

void IoDevice::SERError(QSerialPort::SerialPortError err)
{
    if (err == QSerialPort::NoError)
    {
        return;
    }

    QString str = QString("IoDevice: serial error %1").arg(err);
    emit error(str);
    close();
}
