#ifndef CUSTOMMESSAGEMODEL_H
#define CUSTOMMESSAGEMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <iostream>
#include <unistd.h>
#include <QThread>
#include "custommodel.h"

class CustomMessageModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Role {
        SenderRole,
        MessageTextRole
    };

    CustomMessageModel(QObject *parent = nullptr);
    ~CustomMessageModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE QObject* getCustomModel(int index);

public slots:
    void addMessage(int id, int sender, const QString &message);

private:
    struct Message {
        int sender;
        QString messageText;
    };
    QList<Message> m_messages;
    QMap<int, CustomModel*> chatData;
};

#endif // CUSTOMMESSAGEMODEL_H
