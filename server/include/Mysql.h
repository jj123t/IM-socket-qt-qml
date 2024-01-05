
#ifndef CHAT_TOOL_MYSQL_H
#define CHAT_TOOL_MYSQL_H

#include <iostream>
#include <vector>
#include <string>
#include "mysql_driver.h"
#include "mysql_connection.h"
#include "cppconn/driver.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"
#include "cppconn/metadata.h"
#include "cppconn/exception.h"
#include <ctime>

struct UserInfo {
    int userId;
    std::string username;
    std::string password;
    int sockfd = -1;
};
struct Friend {
    int id;
    std::string username;
    std::string text = "hello i am abc";
};
struct ChatRecord {
    int senderId;
    int receiverId;
    std::string message;
    std::string timestamp;
};
class Mysql {
private:
    static sql::mysql::MySQL_Driver* driver_;
    static sql::Connection* con_;
    static std::string host_;
    static std::string user_;
    static std::string password_;
    static std::string database_;
public:
    static void init(const std::string& host, const std::string& user, const std::string& password, const std::string& database);

    static bool connect();
    static void addUser(const std::string& username, const std::string& password, int sockfd = -1);
    static UserInfo getUserInfo(int userId);
    static bool checkUser(int id, const std::string& password);
    static void deleteUserInfo(int userId);
    static void setUserSockfd(int userId, int sockfd);
    static void setUserUsername(int userId, const std::string& newUsername);
    static int getUserSockfd(int userId);
    static std::string getUserUsername(int userId);
    static void addChatRecord(int senderId, int receiverId, const std::string& message);
    static void deleteChatRecord(int id);
    static std::vector<ChatRecord> getChatRecords(int sid, int rid);
    static std::vector<Friend> getFriends(int userId);
};


#endif //CHAT_TOOL_MYSQL_H
