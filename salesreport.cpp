#include "salesreport.h"
#include "ui_salesreport.h"

salesReport::salesReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::salesReport)
{
    ui->setupUi(this);
    DBManager conn;
}

salesReport::~salesReport()
{
    delete ui;
}

void salesReport::on_saleReportButton_clicked()
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

    //selects the list in the data base
    qry->prepare("select * from dailySalesReport");

    qry->exec();
    //Tranfers data from Querry to model
    modal->setQuery(*qry);

    //data base customers get viewed on the ui table view
    ui->SaleReportView->setModel(modal);

    //closes connention to data base
    conn.connClose();
    //counts rows from the model
    qDebug() <<(modal->rowCount());
}

