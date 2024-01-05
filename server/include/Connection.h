
#ifndef CHAT_TOOL_CONNECTION_H
#define CHAT_TOOL_CONNECTION_H
#include <functional>
#include <string>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>

class EventLoop;
class Socket;
class Channel;
class Buffer;
class Connection {
private:
    EventLoop *loop;
    Socket *sock;
    Channel *channel;
    std::function<void(int)> deleteConnectionCallback;
    Buffer *readBuffer;
    std::map<int, Connection*> *mp;

public:
    Connection(EventLoop *_loop, Socket *_sock, std::map<int, Connection*> *_mp);
    ~Connection();

    void echo(int sockfd);
    void setDeleteConnectionCallback(std::function<void(int)>);
    void send(int sockfd);
    void solveLogin(int sockfd, std::string &message);
    void solveQuery(int sockfd, std::string &message);
    void solveRecord(int sockfd, std::string &message);
    void solveFile(int sockfd, std::string &message);
};


#endif //CHAT_TOOL_CONNECTION_H
