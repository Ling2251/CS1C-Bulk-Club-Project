#include "dbmanager.h"

DBManager::DBManager()
{
    // Connecting to database
    if(!m_database.open())
    {
       qDebug() << "Error: DBManager connection with database failed";
    }
    else{
       qDebug() << "Database: connection ok";
    }
}

DBManager::~DBManager(){}





