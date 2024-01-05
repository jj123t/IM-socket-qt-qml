#include "custominfomodel.h"
#include <iostream>

CustomInfoModel::CustomInfoModel(QObject *parent)
    : QAbstractListModel(parent)
{
    sock = new Socket();
    addr = new InetAddress("127.0.0.1", 1234);
    sock->connect(addr);
    sendBuffer = new Buffer();
    sockfd = sock->getFd();
    receiveThread = new MyWorkerThread(sockfd);
    connect(receiveThread, &MyWorkerThread::messageReceived, this, &CustomInfoModel::addMessage);
    receiveThread->start(); // 启动线程
}

CustomInfoModel::~CustomInfoModel() {
    m_infoList.clear();
    receiveThread->quit();  // 请求线程退出
    receiveThread->wait();  // 等待线程退出
    delete addr;
    delete sock;
    delete receiveThread;
}

int CustomInfoModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_infoList.size();
}

QVariant CustomInfoModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (!index.isValid()) {
        return QVariant();
    }
    const Info &info = m_infoList.at(index.row());
    switch (role) {
    case InfoId:
        return info.id;
    case InfoUsername:
        return info.username;
    case InfoRecordText:
        return info.recordText;
    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> CustomInfoModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[InfoId] = "id";
    roles[InfoUsername] = "username";
    roles[InfoRecordText] = "RecordText";
    return roles;
}

void CustomInfoModel::addMessage(int id, const QString &Text)
{
    if (Text[0] == '$') {
        if (Text[1] == '1') {
            MyId = Text.mid(2, Text.size() - 2).toInt();
            emit loginAccept();
        }
    }
    else if (Text[0] == '#') {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        if (!chatData[id]) {
            chatData[id] = new CustomModel();
        }
        QString username = "";
        int curIndex = 1;
        while (Text[curIndex] != '#') {
            username += Text[curIndex];
            curIndex++;
        }
        m_infoList.push_back({id, username, Text.mid(curIndex + 1, Text.size() - curIndex - 1)});
        endInsertRows();
    }
    else if (Text[0] == '@') {
        if (!chatData[id]) {
            chatData[id] = new CustomModel();
        }
        int sendByMe = Text[1].digitValue();
        std::cout << "the sendByMe is :" <<  sendByMe << "\n";
        chatData[id]->addMessage(sendByMe, Text.mid(2, Text.size() - 2));
    }
}

void CustomInfoModel::sendMessage(const QString &messageText)
{
    sendBuffer->setBuf(messageText.toUtf8());
    ssize_t write_bytes = write(sockfd, sendBuffer->c_str(), sendBuffer->size());
    if(write_bytes == -1){
        printf("socket already disconnected, can't write any more!\n");
    }
}


QObject* CustomInfoModel::getCustomModel(int index) {
    return chatData[index];
}

int CustomInfoModel::getMyId() {
    return MyId;
}

int CustomInfoModel::getSockfd() {
    return sockfd;
}

int CustomInfoModel::judgeLoad(int id) {
    return mpJudgeLoad[id];
}

void CustomInfoModel::setJudgeLoad(int id) {
    mpJudgeLoad[id] = 1;
}
