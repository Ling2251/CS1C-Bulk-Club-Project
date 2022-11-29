#include "dbmanager.h"

DBManager::DBManager()
{
    // Connecting to database
    QSqlDatabase m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("C:/Users/zhao2/OneDrive/Desktop/school file/CS 1C/Qt Projects/CS1C-Bulk-Club-Project/Database.db");
    if(!m_database.open())
    {
       qDebug() << "Error: connection with database failed";
    }
    else{
       qDebug() << "Database: connection ok";
    }
}

DBManager::~DBManager(){
    //close database
    m_database.close();
    qDebug() << "database connection closed\n";
}


