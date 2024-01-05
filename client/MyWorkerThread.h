#ifndef MYWORKERTHREAD_H
#define MYWORKERTHREAD_H

#endif // MYWORKERTHREAD_H

#include "socket.h"

#include <unistd.h>
#include <iostream>
#include <QThread>

class MyWorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit MyWorkerThread(int clientSocket, QObject *parent = nullptr);

signals:
    void messageReceived(int send, const QString &messageText);

protected:
    void run() override;

private:
    int clientSocket;
};
