#ifndef SOCKET_H
#define SOCKET_H


#include "util.h"

#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>


class InetAddress {
private:
    struct sockaddr_in addr;
public:
    InetAddress();
    InetAddress(const char* _ip, uint16_t _port);
    ~InetAddress();

    void setInetAddr(sockaddr_in _addr);
    sockaddr_in getAddr();
    char* getIp();
    uint16_t getPort();
};

class Socket
{
private:
    int fd;
public:
    Socket();
    Socket(int _fd);
    ~Socket();

    void bind(InetAddress*);
    void listen();
    void setnonblocking();

    int accept(InetAddress*);
    void connect(InetAddress*);

    int getFd();
};



#endif // SOCKET_H
