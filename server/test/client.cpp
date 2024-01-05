#include <unistd.h>
#include <string.h>
#include <iostream>
#include <thread>
#include "../src/include/Buffer.h"
#include "../src/include/Socket.h"
#include <fstream>

int main() {
    Socket *sock = new Socket();
    InetAddress *addr = new InetAddress("127.0.0.1", 1234);
    sock->connect(addr);

    int sockfd = sock->getFd();
    char buffer[1025];
    std::ifstream in("image.png");
    while (!in.eof() ) {
        buffer[0] = 'f';
        in.getline(buffer + 1, 1024);
        write(sockfd, buffer, strlen(buffer));
        std::cout << buffer << std::endl;
        sleep(0.01);
        bzero(buffer, 1025);
    }
    while (true) {}
    return 0;
}