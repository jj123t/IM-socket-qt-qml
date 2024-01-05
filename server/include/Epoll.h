
#ifndef CHAT_TOOL_EPOLL_H
#define CHAT_TOOL_EPOLL_H
#include <sys/epoll.h>
#include <vector>

class Channel;
class Epoll {
private:
    int epfd;
    struct epoll_event *events;
public:
    Epoll();
    ~Epoll();

    void updateChannel(Channel*);
    void deleteChannel(Channel*);

    std::vector<Channel*> poll(int timeout = -1);
};


#endif //CHAT_TOOL_EPOLL_H
