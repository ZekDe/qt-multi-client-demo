#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QCoreApplication>



class Myserver : public QTcpServer
{
    Q_OBJECT
public:
    Myserver(QObject *parent = nullptr) : QTcpServer(parent) {}
protected:
    void incomingConnection(qintptr socketDescriptor) override;

signals:
    void msgFromMyServerToMainWindow(const QString &msg);
};

#endif // MYSERVER_H
