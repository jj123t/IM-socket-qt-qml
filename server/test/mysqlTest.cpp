//
// Created by abc on 23-12-20.
//
//
// Created by abc on 23-12-20.
//

#include <bits/stdc++.h>
#include "mysql_driver.h"
#include "mysql_connection.h"
#include "cppconn/driver.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"
#include "cppconn/metadata.h"
#include "cppconn/exception.h"
#include "../src/include/Mysql.h"
#include <string>

using namespace std;
using namespace sql;

int main() {
    // 替换为你自己的数据库连接信息
    std::string host = "127.0.0.1";
    std::string user = "root";
    std::string password = "hec93448";
    std::string database = "abc";
    Mysql::init(host, user, password, database);
    Mysql::connect();
    Mysql::deleteChatRecord(1);
    return 0;
}
