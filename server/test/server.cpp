
#include "EventLoop.h"
#include "Server.h"
#include "Mysql.h"

int main() {
    std::string host = "127.0.0.1";
    std::string user = "root";
    std::string password = "hec93448";
    std::string database = "abc";
    Mysql::init(host, user, password, database); // set database mysql
    Mysql::connect();
    EventLoop *loop = new EventLoop();
    Server *server = new Server(loop);
    loop->loop();
    return 0;
}