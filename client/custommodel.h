#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include <QAbstractListModel>

class CustomModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Role {
        SenderRole,
        MessageTextRole
    };

    CustomModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

public slots:
    void addMessage(int send, const QString &messageText);

private:
    struct Message {
        int sender;
        QString messageText;
    };
    QList<Message> m_messages;
};

#endif // CUSTOMMODEL_H
