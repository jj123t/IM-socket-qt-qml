
#ifndef CHAT_TOOL_EVENTLOOP_H
#define CHAT_TOOL_EVENTLOOP_H
#include <functional>

class Epoll;
class Channel;
class ThreadPool;
class EventLoop {
private:
    Epoll *ep;
    bool quit;
public:
    EventLoop();
    ~EventLoop();

    void loop();
    void updateChannel(Channel*);

    void addThread(std::function<void()>);
};


#endif //CHAT_TOOL_EVENTLOOP_H
