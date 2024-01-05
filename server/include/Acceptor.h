
#ifndef CHAT_TOOL_ACCEPTOR_H
#define CHAT_TOOL_ACCEPTOR_H
#include <functional>

class EventLoop;
class Socket;
class Channel;
class Acceptor {
private:
    EventLoop *loop;
    Socket *sock;
    Channel *acceptChannel;
    std::function<void(Socket*)> newConnectionCallback;
public:
    Acceptor(EventLoop *_loop);
    ~Acceptor();
    void acceptConnection();
    void setNewConnectionCallback(std::function<void(Socket*)>);
};

#endif //CHAT_TOOL_ACCEPTOR_H
