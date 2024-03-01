#include "worker.h"
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <QThread>



void Worker::run()
{
    QTcpSocket socket;
    socket.setReadBufferSize(17*1024);
    socket.setSocketOption(QAbstractSocket::KeepAliveOption, 1);

    auto msg = [this](const QString &m) {
        emit msgFromWorkerToMyServer(m);
    };

    if (!socket.setSocketDescriptor(m_socketDescriptor))
    {
        msg("Error: " + socket.errorString());
        return;
    }

    msg("Client connected: " + socket.peerAddress().toString());

    auto readyReadHandler = [&socket, &msg]()
    {
        if(!socket.bytesAvailable())
            return;

        QByteArray data = socket.readAll();
        msg(QString::fromUtf8(data));

        if(QString::fromUtf8(data) == "close")
        {
            socket.write("socket closed\n");
            socket.disconnectFromHost();
        }
        if(QString::fromUtf8(data) == "16k")
        {
            QByteArray _16k(15 * 1024, 65);
            socket.write(_16k);
            socket.flush();
            socket.waitForBytesWritten();
        }



    };

    connect(&socket, &QTcpSocket::readyRead, readyReadHandler);


    socket.waitForDisconnected();
    msg("Client disconnected");
    socket.close();

}

