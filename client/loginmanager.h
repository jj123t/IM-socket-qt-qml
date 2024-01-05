#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include <QObject>

class LoginManager : public QObject
{
    Q_OBJECT

public:
    LoginManager(QObject *parent = nullptr);

signals:
    void mySignal();

public slots:
    void handleButtomPress();
};

#endif // LOGINMANAGER_H
