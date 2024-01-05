#ifndef CUSTOMINFORMATIONMODEL_H
#define CUSTOMINFORMATIONMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <iostream>
#include <unistd.h>
#include <QThread>

class CustomInformationModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Role {
        InfoId,
        InfoUsername,
        InfoRecordText
    };
    CustomInformationModel(QObject *parent = nullptr);
    ~CustomInformationModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    struct Info {
        int id;
        QString username;
        QString recordText;
    };
    QList<Info> m_infoList;
};

#endif // CUSTOMINFORMATIONMODEL_H
