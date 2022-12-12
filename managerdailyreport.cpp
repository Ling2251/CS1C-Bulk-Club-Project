#include "managerdailyreport.h"
#include "ui_managerdailyreport.h"


managerDailyReport::managerDailyReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerDailyReport)
{
    ui->setupUi(this);

}

managerDailyReport::~managerDailyReport()
{
    delete ui;
}


void managerDailyReport::on_pushButton_clicked()
{
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();

    //if fails to connect to data base
    if(!conn.connOpend()){
        qDebug() << "Error: connection with database failed ";
        return;
    }

    //Opens connection to to database
    conn.connOpend();

    QSqlQuery* qry = new QSqlQuery(conn.m_database);
    QString currentDay = "12/10/2021";

    //selects the list in the data base
    qry->prepare("select * from dailySalesReport where purchaseDate =='"+currentDay+"''");

    // error message if the item can't be added due to the data base
    if(qry->exec())
    {
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
    else
    {
        QMessageBox::about(this, "Error", "Database not found double check path to database");
    }

}

