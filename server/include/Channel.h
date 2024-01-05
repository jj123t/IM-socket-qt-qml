
#ifndef CHAT_TOOL_CHANNEL_H
#define CHAT_TOOL_CHANNEL_H
#include <sys/epoll.h>
#include <functional>

class EventLoop;
class Epoll;
class Channel {
private:
    EventLoop *loop;
    int fd;
    uint32_t events;
    uint32_t ready;
    bool inEpoll;
    std::function<void()> readCallback;
    std::function<void()> writeCallback;
public:
    Channel(EventLoop *_loop, int _fd);
    ~Channel();

    void handleEvent();
    void enableRead();

    int getFd();
    uint32_t getEvents();
    uint32_t getReady();
    bool getInEpoll();
    void setInEpoll(bool _in = true);
    void useET();

    void setReady(uint32_t);
    void setReadCallback(std::function<void()>);
};


#endif //CHAT_TOOL_CHANNEL_H
