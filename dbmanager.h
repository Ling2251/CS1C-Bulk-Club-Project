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

    QSqlDatabase m_database;
    // close the data base connection and will remove the data base to a defual connection
    void connClose(){
        m_database.close();
        m_database.removeDatabase(QSqlDatabase::defaultConnection);
    };

    // opened the data base here so other cpp/h can have accses to it
    bool connOpend(){
        m_database = QSqlDatabase::addDatabase("QSQLITE");
        m_database.setDatabaseName("../CS1C-Bulk-Club-Project/Database.db");
        if(!m_database.open())
        {
           qDebug() << "Error: connection with database failed";
           return false;
        }
        else{
           qDebug() << "Database: connection ok";
           return true;
        }
    };

    QSqlQueryModel *ShowInfoForOneItem(QString item);

    QSqlQueryModel *ShowInfoForOneMember(QString name);

private:
};

#endif // DBMANAGER_H
