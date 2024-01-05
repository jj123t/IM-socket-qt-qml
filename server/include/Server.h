
#ifndef CHAT_TOOL_SERVER_H
#define CHAT_TOOL_SERVER_H
#include <map>
#include <vector>
#include <string>
#include <functional>

class EventLoop;
class Socket;
class Acceptor;
class Connection;
class ThreadPool;
class Buffer;
class Server {
private:
    EventLoop *mainReactor;
    Acceptor *acceptor;
    std::map<int, Connection*> connections;
    std::vector<EventLoop*> subReactors;
    ThreadPool *thpool;

public:
    Server(EventLoop*);
    ~Server();

    void handleReadEvent(int);
    void newConnection(Socket *sock);
    void deleteConnection(int sockfd);
};


#endif //CHAT_TOOL_SERVER_H
