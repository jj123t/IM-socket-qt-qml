#include "custominformationmodel.h"

CustomInformationModel::CustomInformationModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_infoList.push_back({2, "abc", "hello world"});
    m_infoList.push_back({3, "abc", "hello world"});
    m_infoList.push_back({4, "abc", "hello world"});
}

CustomInformationModel::~CustomInformationModel() {}

int CustomInformationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    else {
        return m_infoList.size();
    }
}

QVariant CustomInformationModel::data(const QModelIndex &index, int role) const
{
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
}

QHash<int, QByteArray> CustomInformationModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[InfoId] = "id";
    roles[InfoUsername] = "username";
    roles[InfoRecordText] = "recordText";
    return roles;
}

