#include "custommesmodel.h"

CustomMesModel::CustomMesModel(QObject *parent)
    : QObject(parent)
{
}

    QObject* CustomMesModel::getCustomModel(int index) {
        return chatData[index];
    }

