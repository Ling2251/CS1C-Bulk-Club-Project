#include "dbmanager.h"

DBManager::DBManager()
{
    // Connecting to database
    QSqlDatabase m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("../CS1C-Bulk-Club-Project/Database.db");
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

QSqlQueryModel *DBManager::loadEntries()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery qry;
    qry.prepare("select name, type, dailySalesReport.ID, purchaseDate, item, price, quantity "
                "from Customers, dailySalesReport where Customers.ID = dailySalesReport.ID;");

    if(!qry.exec())
    {
        qDebug() <<"error Loading values to db" << endl;

    }
    model->setQuery(qry);

    return model;
}

