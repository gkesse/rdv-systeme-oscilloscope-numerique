#pragma once

#include <QObject>
#include <QSerialPort>

typedef enum _connect_t
{
    DevNotConnected,
    DevTCPConnection,
    DevSerialConnection,
    DevBTConnection
} connect_t;

typedef struct _ConnectionData
{
    connect_t type;
    QString message;
    // QBluetoothAddress ba;
    QString port;
    QSerialPort::BaudRate baud;
    // QString tcphost;
    // int tcpport;
} ConnectionData;

class IoDevice : public QObject
{
    Q_OBJECT

public:
    explicit IoDevice(QObject *parent = nullptr);
    ~IoDevice();

    // static bool ParseConnection(QString str, ConnectionData &conn);
    // static QString ConnectionToString(const ConnectionData &conn);
    // static QString BTStateToString(QBluetoothSocket::SocketState state);

    bool open(ConnectionData cd);
    bool close(void);
    // bool isConnected();
    // bool send(const QByteArray &ba);

private slots:
    // void BTGotData();
    // void BTConnected();
    // void BTDisconnected();
    // void BTError(QBluetoothSocket::SocketError);

    void SERGotData();
    void SERError(QSerialPort::SerialPortError err);

    // void TCPGotData();
    // void TCPConnected();
    // void TCPDisconnected();
    // void TCPErr(QAbstractSocket::SocketError);

signals:
    void readyRead(QByteArray b);
    void connected();
    void disconnected();
    void error(QString errmsg);
    void connectionError();

private:
    ConnectionData connectiondata;

    QSerialPort deviceSER;
    //     QTcpSocket deviceTCP;
    // #if BTPOINTER == 0
    //     QBluetoothSocket deviceBT;
    // #else
    //     QBluetoothSocket *deviceBT;
    // #endif
};
