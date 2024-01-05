#ifndef SQLCONTACTMODEL_H
#define SQLCONTACTMODEL_H

#include <QSqlQueryModel>

class qsqlquerymodel: public QSqlQueryModel
{
public:
    qsqlquerymodel(QObject *parent = nullptr);
};

#endif // SQLCONTACTMODEL_H
