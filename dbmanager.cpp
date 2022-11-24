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

DBManager::~DBManager(){}

QSqlQueryModel *DBManager::ShowInfoForOneItem(QString item)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery qry;

    qry.prepare("SELECT item, quantity as \"total quantity sold\", \"$\" || printf(\"%.2f\",(price * quantity)*1.0775) "
                "as \"Total revenue\" from inventory where item = \""+item+"\";");

     if(!qry.exec())
     {
         qDebug() <<"error Loading values to db" << endl;
     }

    model->setQuery(qry);
    return model;
}
