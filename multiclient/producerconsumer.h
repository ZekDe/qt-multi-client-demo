#ifndef PRODUCERCONSUMER_H
#define PRODUCERCONSUMER_H

#include <QThread>
#include <QDebug>
#include <QQueue>
#include <QMutex>

QQueue<int> buffer;
QMutex mutex;


class Producer : public QThread
{
public:
    void run() override
    {
        for (int i = 0; i < 10; ++i) {
            mutex.lock();
            buffer.enqueue(i);
            qDebug() << "Produced:" << i;
            mutex.unlock();
            QThread::msleep(100);
        }
    }
};

class Consumer : public QThread
{
public:
    void run() override
    {
        for (int i = 0; i < 10; ++i) {
            mutex.lock();
            if (!buffer.isEmpty()) {
                int value = buffer.dequeue();
                qDebug() << "Consumed:" << value;
            }
            mutex.unlock();
            QThread::msleep(100);
        }
    }
};



#endif // PRODUCERCONSUMER_H
