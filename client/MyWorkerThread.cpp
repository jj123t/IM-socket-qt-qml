#include "MyWorkerThread.h"

MyWorkerThread::MyWorkerThread(int clientSocket, QObject *parent)
    : QThread(parent), clientSocket(clientSocket) {}

void MyWorkerThread::run()
{
    char buffer[1024];
    ssize_t bytesRead;
    while (true) {
        bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) {
            std::cerr << "Server disconnected." << std::endl;
            close(clientSocket);
            break;
        }
        buffer[bytesRead] = '\0';
        std::cout << "Received from server: " << buffer << std::endl;

        int tId = 0;
        int curIndex = 0;
        while (buffer[curIndex] != '#') {
            tId = tId * 10 + (buffer[curIndex] - '0');
            curIndex++;
        }
        std::cout << QString::fromUtf8(buffer).mid(curIndex + 1, bytesRead - curIndex + 1).toStdString() << "\n";
        // 发射信号，通知信息已接收
        emit messageReceived(tId, QString::fromUtf8(buffer).mid(curIndex + 1, bytesRead - curIndex + 1));
    }
}
