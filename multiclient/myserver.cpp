#include "myserver.h"
#include "worker.h"
#include <QThreadPool>
#

void Myserver::incomingConnection(qintptr socketDescriptor)
{
    Worker *thread = new Worker(socketDescriptor);
    connect(thread, &Worker::msgFromWorkerToMyServer, this, &Myserver::msgFromMyServerToMainWindow);
    connect(thread, &Worker::finished, thread, &Worker::deleteLater);

    thread->start();
}
