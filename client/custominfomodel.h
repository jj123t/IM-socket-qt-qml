#ifndef CUSTOMINFOMODEL_H
#define CUSTOMINFOMODEL_H

#include <QAbstractItemModel>
#include "MyWorkerThread.h"
#include "socket.h"
#include "buffer.h"
#include "custommodel.h"

class CustomInfoModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit CustomInfoModel(QObject *parent = nullptr);

    enum Role {
        InfoId,
        InfoUsername,
        InfoRecordText,
    };

    ~CustomInfoModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE QObject* getCustomModel(int index);
    Q_INVOKABLE int getMyId();
    Q_INVOKABLE int getSockfd();
    Q_INVOKABLE int judgeLoad(int id);

public slots:
    void addMessage(int id, const QString &RecordText);
    void sendMessage(const QString &messagetext);
    void setJudgeLoad(int id);
signals:
    void loginAccept();

private:
    struct Info {
        int id;
        QString username;
        QString recordText;
    };
    MyWorkerThread *receiveThread;
    Socket *sock;
    InetAddress *addr;
    int sockfd;
    Buffer *sendBuffer;
    QList<Info> m_infoList;
    QMap<int, int> mpJudgeLoad;
    int MyId;
    QMap<int, CustomModel*> chatData;
};

#endif // CUSTOMINFOMODEL_H
