
//#include "sqlconversationmodel.h"
//#include <QDateTime>
//#include <QDebug>
//#include <QSqlError>
//#include <QSqlRecord>
//#include <QSqlQuery>

//static const char *conversationsTableName = "Conversations";

//static void createTable()
//{
//    if (QSqlDatabase::database().tables().contains(conversationsTableName)) {
//        // The table already exists; we don't need to do anything.
//        return;
//    }

//    QSqlQuery query;
//    if (!query.exec(
//        "CREATE TABLE IF NOT EXISTS 'Conversations' ("
//        "'author' TEXT NOT NULL,"
//        "'recipient' TEXT NOT NULL,"
//        "'timestamp' TEXT NOT NULL,"
//        "'message' TEXT NOT NULL,"
//        "FOREIGN KEY('author') REFERENCES Contacts ( name ),"
//        "FOREIGN KEY('recipient') REFERENCES Contacts ( name )"
//        ")")) {
//        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
//    }

//    query.exec("INSERT INTO Conversations VALUES('Me', 'Ernest Hemingway', '2016-01-07T14:36:06', 'Hello!')");
//    query.exec("INSERT INTO Conversations VALUES('Ernest Hemingway', 'Me', '2016-01-07T14:36:16', 'Good afternoon.')");
//    query.exec("INSERT INTO Conversations VALUES('Me', 'Albert Einstein', '2016-01-01T11:24:53', 'Hi!')");
//    query.exec("INSERT INTO Conversations VALUES('Albert Einstein', 'Me', '2016-01-07T14:36:16', 'Good morning.')");
//    query.exec("INSERT INTO Conversations VALUES('Hans Gude', 'Me', '2015-11-20T06:30:02', 'God morgen. Har du fått mitt maleri?')");
//    query.exec("INSERT INTO Conversations VALUES('Me', 'Hans Gude', '2015-11-20T08:21:03', 'God morgen, Hans. Ja, det er veldig fint. Tusen takk! "
//               "Hvor mange timer har du brukt på den?')");
//}
