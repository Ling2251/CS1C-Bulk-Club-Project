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

double DBManager::GetTotalRevenue(QString date)
{
    double totalRevenue = 0;
    QSqlQuery qry;

    // PROCESSING - Depending on the date, the qry variable executes the specified query statement. Then totalRevenue obtains
    // the value of the total revenue from the date
    if(date == "")
    {
        qry.prepare("select printf(\"%.2f\",sum(price * quantity)*1.0775) as \"Total revenue\" from dailySalesReport;");
        qry.exec();
        if(qry.next())
        {
            totalRevenue = qry.value(0).toDouble(); // Storing the value from the table into totalRevenue variable
        }
    }
    else
    {
        qry.prepare("select printf(\"%.2f\", sum(price * quantity)*1.0775) "
                    "as \"Total revenue\" from dailySalesReport where purchaseDate = \""+date+"\";");
        qry.exec();
        if(qry.next())
        {
            totalRevenue = qry.value(0).toDouble();
        }
    }
    return totalRevenue;
}
DBManager::~DBManager(){}






