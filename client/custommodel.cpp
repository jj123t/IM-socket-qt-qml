#include "custommodel.h"

CustomModel::CustomModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int CustomModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_messages.size();
}

QVariant CustomModel::data(const QModelIndex &index, int role) const
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

QHash<int, QByteArray> CustomModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[SenderRole] = "sender";
    roles[MessageTextRole] = "messageText";
    return roles;
}

void CustomModel::addMessage(int send, const QString &messageText)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_messages.append({send, messageText});
    endInsertRows();
}


