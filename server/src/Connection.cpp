
#include "Connection.h"
#include "Socket.h"
#include "Channel.h"
#include "Buffer.h"
#include "Mysql.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <map>
#include <iostream>
#include <fstream>

Connection::Connection(EventLoop *_loop, Socket *_sock, std::map<int, Connection*> *_mp) : loop(_loop), sock(_sock), channel(nullptr), readBuffer(nullptr), mp(_mp) {
    channel = new Channel(loop, sock->getFd());
    channel->enableRead();
    channel->useET();
    std::function<void()> cb = std::bind(&Connection::echo, this, sock->getFd());
    channel->setReadCallback(cb);
    readBuffer = new Buffer();
}

Connection::~Connection(){
    delete channel;
    delete sock;
    delete readBuffer;
}

void Connection::setDeleteConnectionCallback(std::function<void(int)> _cb){
    deleteConnectionCallback = _cb;
}

void Connection::solveLogin(int sockfd, std::string &message) {
    message = message.substr(1, message.size() - 1); // delete '$'
    size_t pos = message.find('#');
    std::string stringId = message.substr(0, pos); // userId
    int id = std::stoi(stringId);
    message = message.substr(pos + 1, message.size() - pos - 1);
    pos = message.find('#');
    std::string password = message.substr(0, pos);
    message = message.substr(pos + 1, message.size() - pos + 1);
    std::cout << "the query id and password is :" << id << "  and " << password << " and " << sockfd << std::endl;
    Mysql::setUserSockfd(id, sockfd);
    readBuffer->setBuf("0#$" + std::to_string(Mysql::checkUser(id, password)) + stringId);
    send(sockfd);
    readBuffer->clear();
    auto list = Mysql::getFriends(id);
    for (auto x : list) {
        std::cout << " the friend's username" + x.username << "\n";
        readBuffer->setBuf(std::to_string(x.id) + "##" + x.username + "#" + x.text);
        send(sockfd);
        readBuffer->clear();
    }
}

void Connection::solveQuery(int sockfd, std::string &message) {
    message = message.substr(1, message.size() - 1); // delete '@'
    size_t pos = message.find('#');
    std::string fromId = message.substr(0, pos);    // get fromId
    message = message.substr(pos + 1, message.size() - pos - 1);
    pos = message.find('#');
    std::string toId = message.substr(0, pos);  // get toId;
    message = message.substr(pos + 1, message.size() - pos - 1);
    readBuffer->setBuf(fromId + "#@0" + message);
    std::cout << " the id is :" << fromId << " and " << toId << std::endl;
    Mysql::addChatRecord(std::stoi(fromId), std::stoi(toId), message); // add message to database
    int toSockfd = Mysql::getUserSockfd(std::stoi(toId));
    auto &res = (*mp)[toSockfd];
    res->readBuffer = readBuffer;
    res->send(toSockfd);
    res->readBuffer->clear();
}

void Connection::solveRecord(int sockfd, std::string &message) {
    message = message.substr(1, message.size() - 1);
    size_t pos = message.find('#');
    int sid = std::stoi(message.substr(0, pos));
    int rid = std::stoi(message.substr(pos + 1, message.size() - pos - 1));
    auto vt = Mysql::getChatRecords(sid, rid);
    for (auto x : vt) {
        std::cout << "the record is " << x.senderId << " " << x.receiverId << " " << x.message << "\n";
        if (x.senderId == sid) {
            readBuffer->setBuf(std::to_string(x.receiverId) + "#@1" + x.message);
        }
        else {
            readBuffer->setBuf(std::to_string(x.senderId) + "#@0" + x.message);
        }
        auto &res = (*mp)[sockfd];
        res->readBuffer = readBuffer;
        res->send(sockfd);
        res->readBuffer->clear();
    }
}

void Connection::solveFile(int sockfd, std::string &message) {
    std::ofstream out;
    out.open("abc.png", std::ios::app | std::ios::out);
    if (out.is_open()) {
        out << (message.substr(1, message.size()));
        out.close();
    }
    readBuffer->clear();
}

void Connection::echo(int sockfd){
    char buf[1024];     //这个buf大小无所谓
    while(true){    //由于使用非阻塞IO，读取客户端buffer，一次读取buf大小数据，直到全部读取完毕
        bzero(&buf, sizeof(buf));
        ssize_t bytes_read = read(sockfd, buf, sizeof(buf));
        if (bytes_read > 0) {
            readBuffer->append(buf, bytes_read);
        } else if (bytes_read == -1 && errno == EINTR) {  //客户端正常中断、继续读取
            printf("continue reading\n");
            continue;
        } else if (bytes_read == -1 && ((errno == EAGAIN) || (errno == EWOULDBLOCK))) {//非阻塞IO，这个条件表示数据全部读取完毕
            printf("message from client fd %d: %s\n", sockfd, readBuffer->c_str());
            std::string message = readBuffer->c_str();
            if (message[0] == '$') { // query login
                solveLogin(sockfd, message);
            } else if (message[0] == '@') { // query retrans
                solveQuery(sockfd, message);
            } else if (message[0] == '#') {
                solveRecord(sockfd, message);
            } else if (message[0] == 'f') {
                solveFile(sockfd, message);
            }
            readBuffer->clear();
            break;
        } else if (bytes_read == 0) {  //EOF，客户端断开连接
            printf("EOF, client fd %d disconnected\n", sockfd);
            deleteConnectionCallback(sockfd);           //多线程会有bug
            break;
        } else {
            printf("Connection reset by peer\n");
            deleteConnectionCallback(sockfd);          //会有bug，注释后单线程无bug
            break;
        }
    }
}

void Connection::send(int sockfd){
    char buf[readBuffer->size()];
    strcpy(buf, readBuffer->c_str());
    int  data_size = readBuffer->size();
    int data_left = data_size;
    while (data_left > 0)
    {
        ssize_t bytes_write = write(sockfd, buf + data_size - data_left, data_left);
        if (bytes_write == -1 && errno == EAGAIN) {
            break;
        }
        data_left -= bytes_write;
    }
}