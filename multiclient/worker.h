#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QtGlobal>
#include <QObject>
#include <QString>

class QTcpSocket;

class Worker : public QThread
{
    Q_OBJECT
public:
    explicit Worker(qintptr socketDescriptor) : m_socketDescriptor(socketDescriptor) {}

    void run() override;

signals:
    void msgFromWorkerToMyServer(const QString &msg);

private:
    qintptr m_socketDescriptor;

};

#endif // WORKER_H
