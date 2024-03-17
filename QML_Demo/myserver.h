#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QCoreApplication>

class QString;

class Myserver : public QTcpServer
{
    Q_OBJECT
    Q_PROPERTY(QString msg READ msg WRITE setMsg NOTIFY msgChanged FINAL)

public:
    Myserver(QObject *parent = nullptr) : QTcpServer(parent) {}
    QString msg() const;
    void setMsg(const QString &newMsg);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

signals:
    void msgFromMyServerToMainWindow(const QString &msg);
    void msgChanged();

private slots:


private:
    QString m_msg;
};

#endif // MYSERVER_H
