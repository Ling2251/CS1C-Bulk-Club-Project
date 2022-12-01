#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QtSql>
#include <QDebug>

class DBManager
{
public:
    DBManager();
    ~DBManager();

    // different functions
    QSqlQueryModel *loadEntries();
private:
    QSqlDatabase m_database;
};

#endif // DBMANAGER_H
