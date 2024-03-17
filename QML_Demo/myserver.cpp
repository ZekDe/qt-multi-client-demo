#include "myserver.h"
#include "worker.h"
#include <QThreadPool>


void Myserver::incomingConnection(qintptr socketDescriptor)
{
    Worker *thread = new Worker(socketDescriptor);
    // connect(thread, &Worker::msgFromWorkerToMyServer, this, &Myserver::msgFromMyServerToMainWindow);

    connect(thread, &Worker::msgFromWorkerToMyServer, this, &Myserver::setMsg);
    connect(thread, &Worker::finished, thread, &Worker::deleteLater);

    thread->start();
}

QString Myserver::msg() const
{
    return m_msg;
}

void Myserver::setMsg(const QString &newMsg)
{
    if (m_msg == newMsg)
        return;
    m_msg = newMsg;
    emit msgChanged();
}
