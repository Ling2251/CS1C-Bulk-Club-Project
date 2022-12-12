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

QSqlQueryModel *DBManager::ShowInfoForOneItem(QString item)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery qry;

    qry.prepare("SELECT name, quantity as \"total quantity sold\", \"$\" || printf(\"%.2f\",(price * quantity)*1.0775) "
                "as \"Total revenue\" from Inventory where name = \""+item+"\";");

     if(!qry.exec())
     {
         qDebug() <<"error Loading values to db" << endl;
     }

    model->setQuery(qry);
    return model;
}

QSqlQueryModel *DBManager::ShowInfoForOneMember(QString name)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery qry;


     qry.prepare("SELECT name, type, Customers.ID, \"$\" || printf(\"%.2f\", ifnull(sum(price * quantity)*1.0775, 0))"
                " as \"Total revenue (7.75%)\" from Customers left JOIN dailySalesReport on Customers.ID = dailySalesReport.ID "
                "where name = \""+name+"\";");

     if(!qry.exec())
     {
         qDebug() <<"error Loading values to db" << endl;
     }

    model->setQuery(qry);
    return model;

}





