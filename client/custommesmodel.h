#ifndef CUSTOMMESMODEL_H
#define CUSTOMMESMODEL_H

#include <QAbstractListModel>
#include <QAbstractListModel>
#include <QList>
#include <iostream>
#include <unistd.h>
#include <QThread>
#include "custommodel.h"
class CustomMesModel : public QObject
{
    Q_OBJECT
public:
    explicit CustomMesModel(QObject *parent = nullptr);
    Q_INVOKABLE QObject* getCustomModel(int index);
private:
    QMap<int, CustomModel*> chatData;
};

#endif // CUSTOMMESMODEL_H
