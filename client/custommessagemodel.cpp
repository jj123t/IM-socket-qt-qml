#include "custommessagemodel.h"

#include <iostream>
#include <unistd.h>
#include <QThread>

CustomMessageModel::CustomMessageModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

CustomMessageModel::~CustomMessageModel()
{

}

int CustomMessageModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_messages.size();
}

QVariant CustomMessageModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_messages.size())
        return QVariant();
    int userId = index.row(); // Assuming row represents userId
    const Message &message = m_messages[userId];
    switch (role) {
    case SenderRole:
        return message.sender;
    case MessageTextRole:
        return message.messageText;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> CustomMessageModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[SenderRole] = "sender";
    roles[MessageTextRole] = "messageText";
    return roles;
}

void CustomMessageModel::addMessage(int id, int sender, const QString &message) {
    if (!chatData[id]) {
        chatData[id] = new CustomModel();
    }
    chatData[id]->addMessage(sender, message);
}

//void CustomMessageModel::addMessage(int send, const QString &messageText)
//{
//    beginInsertRows(QModelIndex(), rowCount(), rowCount());

//    if (messageText[0] == '$') {
//        if (messageText[1] == '1') {
//            emit loginAccept();
//        }
//    }
//    else {
// //        QVariantMap messageMap;
// //        messageMap["sender"] = send;
// //        messageMap["messageText"] = messageText;
//        m_messages.append({send, messageText});
//    }
//    endInsertRows();
//}

QObject* CustomMessageModel::getCustomModel(int index) {
    return chatData[index];
}

