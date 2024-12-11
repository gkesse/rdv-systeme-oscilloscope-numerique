#include "ParseConnection.h"

bool ParseConnection(QString str, ConnectionData &conn)
{
    str = str.toUpper();
    QStringList parts = str.split(':');

    for (int i = 0; i < parts.size(); i++)
        parts[i] = parts[i].trimmed();

    if (parts[0] != "SER" && parts[0] != "TCP" && parts[0] != "BT")
    {
        conn.message = "Invalid connection string: the format is <BT|SER|TCP>:<param>[:<param>]";
        return false;
    }

    if (parts[0] == "BT")
    {
    }
    else if (parts[0] == "SER")
    {
        conn.port = "/dev/pts/8";
        conn.baud = QSerialPort::Baud4800;
        conn.type = DevSerialConnection;
        return true;
    }
    else if (parts[0] == "TCP")
    {
    }

    return false;
}
