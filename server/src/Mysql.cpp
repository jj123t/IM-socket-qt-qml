
#include "Mysql.h"

sql::mysql::MySQL_Driver* Mysql::driver_ = nullptr;
sql::Connection* Mysql::con_ = nullptr;
std::string Mysql::host_;
std::string Mysql::user_;
std::string Mysql::password_;
std::string Mysql::database_;

void Mysql::init(const std::string& host, const std::string& user, const std::string& password, const std::string& database) {
    host_ = host;
    user_ = user;
    password_ = password;
    database_ = database;
}

bool Mysql::connect() {
    try {
        driver_ =  sql::mysql::get_driver_instance();
        con_ = driver_->connect(host_, user_, password_);
        con_->setSchema(database_);
        return true;
    } catch (sql::SQLException& e) {
        return false;
    }
}

void Mysql::addUser(const std::string& username, const std::string& password, int sockfd) {
    try {
        sql::PreparedStatement* pstmt = con_->prepareStatement("INSERT INTO UserInfo (username, password, sockfd) VALUES (?, ?, ?)");
        pstmt->setString(1, username);
        pstmt->setString(2, password);
        pstmt->setInt(3, sockfd);
        pstmt->executeUpdate();
        delete pstmt;
    } catch (sql::SQLException& e) {
    }
}

UserInfo Mysql::getUserInfo(int userId) {
    UserInfo userInfo;
    try {
        sql::PreparedStatement* pstmt = con_->prepareStatement("SELECT * FROM UserInfo WHERE id = ?");
        pstmt->setInt(1, userId);
        sql::ResultSet* res = pstmt->executeQuery();
        if (res->next()) {
            userInfo.userId = res->getInt("id");
            userInfo.username = res->getString("username");
            userInfo.password = res->getString("password");
            userInfo.sockfd = res->getInt("sockfd");
        }
        delete res;
        delete pstmt;
    } catch (sql::SQLException& e) {
    }
    return userInfo;
}
void Mysql::deleteUserInfo(int userId) {
    try {
        sql::PreparedStatement* pstmt = con_->prepareStatement("delete from UserInfo where id = (?)");
        pstmt->setInt(1, userId);
        pstmt->executeUpdate();
        pstmt = con_->prepareStatement("ALTER TABLE UserInfo AUTO_INCREMENT = 1");
        pstmt->executeUpdate();
        delete pstmt;
    } catch (sql::SQLException& e) {
    }
}
bool Mysql::checkUser(int id, const std::string &password) {
    UserInfo userInfo;
    try {
        sql::PreparedStatement* pstmt = con_->prepareStatement("SELECT password FROM UserInfo WHERE id = ?");
        pstmt->setInt(1, id);
        sql::ResultSet* res = pstmt->executeQuery();
        while (res->next()) {
            userInfo.password = res->getString("password");
        }
        delete res;
        delete pstmt;
    } catch (sql::SQLException& e) {
    }
    return userInfo.password == password;
}

void Mysql::setUserSockfd(int userId, int sockfd) {
    try {
        sql::PreparedStatement* pstmt = con_->prepareStatement("UPDATE UserInfo set sockfd = ? WHERE id = ?");
        pstmt->setInt(1, sockfd);
        pstmt->setInt(2, userId);
        pstmt->executeUpdate();
        delete pstmt;
    } catch (sql::SQLException& e) {
    }
}

void Mysql::setUserUsername(int userId, const std::string &newUsername) {
    try {
        sql::PreparedStatement* pstmt = con_->prepareStatement("UPDATE UserInfo set username = ? WHERE id = ?");
        pstmt->setString(1, newUsername);
        pstmt->setInt(2, userId);
        pstmt->executeUpdate();
        delete pstmt;
    } catch (sql::SQLException& e) {
    }
}

int Mysql::getUserSockfd(int userId) {
    int sockfd;
    try {
        sql::PreparedStatement* pstmt = con_->prepareStatement("SELECT sockfd FROM UserInfo WHERE id = ?");
        pstmt->setInt(1, userId);
        sql::ResultSet* res = pstmt->executeQuery();
        if (res->next()) {
            sockfd = res->getInt("sockfd");
        }
        delete res;
        delete pstmt;
    } catch (sql::SQLException& e) {
    }
    return sockfd;
}

std::string Mysql::getUserUsername(int userId) {
    std::string username;
    try {
        sql::PreparedStatement* pstmt = con_->prepareStatement("SELECT username FROM UserInfo WHERE id = ?");
        pstmt->setInt(1, userId);
        sql::ResultSet* res = pstmt->executeQuery();
        if (res->next()) {
            username = res->getString("username");
        }
        delete res;
        delete pstmt;
    } catch (sql::SQLException& e) {
    }
    return username;
}

void Mysql::addChatRecord(int senderId, int receiverId, const std::string& message) {
    try {
        sql::PreparedStatement* pstmt = con_->prepareStatement("INSERT INTO ChatRecord (senderId, receiverId, message, timestamp) VALUES (?, ?, ?, ?)");
        pstmt->setInt(1, senderId);
        pstmt->setInt(2, receiverId);
        pstmt->setString(3, message);

        time_t now = time(nullptr);
        tm* curr_tm = localtime(&now);  // 返回的结构体存储位置未知，不知何时释放，因此推荐使用安全版本。
        char time[80] = {0};
        strftime(time, 80, "%Y-%m-%d %H:%M:%S", curr_tm);

        std::cout << time << "\n";
        pstmt->setDateTime(4, time);

        pstmt->executeUpdate();
        delete pstmt;
    } catch (sql::SQLException& e) {
        std::cout << "MySQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ", SQLState: " << e.getSQLState() << ")\n";
    }
}

std::vector<ChatRecord> Mysql::getChatRecords(int sid, int rid) {
    std::vector<ChatRecord> chatRecords;
    try {
        sql::PreparedStatement* pstmt = con_->prepareStatement("SELECT * FROM ChatRecord WHERE (senderId = ? and receiverId = ?) or (senderId = ? and receiverId = ?)");
        pstmt->setInt(1, sid);
        pstmt->setInt(2, rid);
        pstmt->setInt(3, rid);
        pstmt->setInt(4, sid);
        sql::ResultSet* res = pstmt->executeQuery();
        while (res->next()) {
            ChatRecord record;
            record.senderId = res->getInt("senderId");
            record.receiverId = res->getInt("receiverId");
            record.message = res->getString("message");
            record.timestamp = res->getString("timestamp");
            chatRecords.push_back(record);
        }
        delete res;
        delete pstmt;
    } catch (sql::SQLException& e) {
    }
    return chatRecords;
}

std::vector<Friend> Mysql::getFriends(int userId) {
    std::vector<Friend> vt;
    try {
        sql::PreparedStatement* pstmt = con_->prepareStatement("SELECT rId FROM FriendList WHERE sId = ? ");
        pstmt->setInt(1, userId);
        sql::ResultSet* res = pstmt->executeQuery();
        while (res->next()) {
            Friend aFriend;
            aFriend.id = res->getInt("rId");
            aFriend.username = Mysql::getUserUsername(aFriend.id);
            vt.push_back(aFriend);
        }
        delete res;
        delete pstmt;
    } catch (sql::SQLException& e) {
    }
    return vt;
}

void Mysql::deleteChatRecord(int id) {
    try {
        sql::PreparedStatement* pstmt = con_->prepareStatement("delete from ChatRecord where id = (?)");
        pstmt->setInt(1, id);
        pstmt->executeUpdate();
        pstmt = con_->prepareStatement("ALTER TABLE ChatRecord AUTO_INCREMENT = 1");
        pstmt->executeUpdate();
        delete pstmt;
    } catch (sql::SQLException& e) {
    }
}
