#include "managerdailyreport.h"
#include "ui_managerdailyreport.h"


managerDailyReport::managerDailyReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerDailyReport)
{
    ui->setupUi(this);
    // added the data base connection to additme
    DBManager conn;
    if(!conn.connOpend()){
        qDebug() << "Error: managerDailyReport connection with database failed";
    }
    else{
        qDebug() << "Connected to database.";

    }

   ShowDateComboBox();

}

managerDailyReport::~managerDailyReport()
{
    delete ui;
}

// function that will show all the itme in a drop box
void managerDailyReport::ShowDateComboBox(){
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);

    // only put the name out from the inventory
    list->prepare("select purchaseDate from dailySalesReport");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);
    ui->DatecomboBox->setModel(modal);
}



void managerDailyReport::on_AllDailyReport_clicked()
{
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();

    //if fails to connect to data base
    if(!conn.connOpend()){
        qDebug() << "Error: AllDailyReport connection with database failed ";
        return;
    }

    //Opens connection to to database
    conn.connOpend();

    QSqlQuery* qry = new QSqlQuery(conn.m_database);
    QString currentDay;

    currentDay = ui->DatecomboBox->currentText();

    //selects the list in the data base
    qry->prepare("select * from dailySalesReport where purchaseDate= ?");
    qry->addBindValue(currentDay);

    // error message if the item can't be added due to the data base
    if(qry->exec())
    {
        while(qry->next()){
            QMessageBox::about(this, "", "The daily report is printed, double check if error occured");

            //Tranfers data from Querry to model
            modal->setQuery(*qry);

            //data base customers get viewed on the ui table view
            ui->DailyReportView->setModel(modal);

            //closes connention to data base
            conn.connClose();
            //counts rows from the model
            qDebug() <<(modal->rowCount());
        }
    }
    else
    {
        QMessageBox::about(this, "Error", "Database not found double check path to database");
    }

}


void managerDailyReport::on_ShowExecutiveButton_clicked()
{
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QString type;

    //if fails to connect to data base
    if(!conn.connOpend()){
        qDebug() << "Error: regular connection with database failed ";
        return;
    }

    //Opens connection to to database
    conn.connOpend();

    QSqlQuery* qry = new QSqlQuery(conn.m_database);

    //selects the list in the data base
    qry->prepare("select name, customersType, purchaseDate, dailySalesReport.ID, item, price, quantity "
                "from Customers, dailySalesReport where Customers.ID = dailySalesReport.ID"
                " and customersType = \"Executive\";");

    // error message if the item can't be added due to the data base
    if(qry->exec())
    {
        while(qry->next()){
            QMessageBox::about(this, "", "The Executive daily report is printed, double check if error occured");

            //Tranfers data from Querry to model
            modal->setQuery(*qry);

            //data base customers get viewed on the ui table view
            ui->DailyReportView->setModel(modal);

            //closes connention to data base
            conn.connClose();
            //counts rows from the model
            qDebug() <<(modal->rowCount());
        }
    }
    else
    {
        QMessageBox::about(this, "Error", "Database not found double check path to database");
    }
}

void managerDailyReport::on_ShowRegularButton_clicked()
{
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QString type;

    //if fails to connect to data base
    if(!conn.connOpend()){
        qDebug() << "Error: regular connection with database failed ";
        return;
    }

    //Opens connection to to database
    conn.connOpend();

    QSqlQuery* qry = new QSqlQuery(conn.m_database);

    //selects the list in the data base
    qry->prepare("select name, customersType, purchaseDate, dailySalesReport.ID, item, price, quantity "
                "from Customers, dailySalesReport where Customers.ID = dailySalesReport.ID"
                " and customersType = \"Regular\";");

    // error message if the item can't be added due to the data base
    if(qry->exec())
    {
        while(qry->next()){
            QMessageBox::about(this, "", "The regular daily report is printed, double check if error occured");

            //Tranfers data from Querry to model
            modal->setQuery(*qry);

            //data base customers get viewed on the ui table view
            ui->DailyReportView->setModel(modal);

            //closes connention to data base
            conn.connClose();
            //counts rows from the model
            qDebug() <<(modal->rowCount());
        }
    }
    else
    {
        QMessageBox::about(this, "Error", "Database not found double check path to database");
    }

}

