#include "rebatemember.h"
#include "ui_rebatemember.h"

rebateMember::rebateMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rebateMember)
{
    ui->setupUi(this);
    showExpMonth();
}

rebateMember::~rebateMember()
{
    delete ui;
}

void rebateMember::showExpMonth(){
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);

    // only put the name out from the inventory
    list->prepare("select expMonth from Customers;");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);
    ui->MonthcomboBox->setModel(modal);
}


void rebateMember::on_DisplayRebatButton_clicked()
{
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();

    //Opens connection to to database
    conn.connOpend();

    QSqlQuery* qry = new QSqlQuery(conn.m_database);

    //selects the list in the data base
    qry->prepare("select name, Customers.ID, customersType, \"$\" || printf(\"%.2f\", ifnull((sum(price * quantity)+120)*.02, 120*.02)) as \"Rebate amount\""
                 " from Customers left join dailySalesReport"
                " on Customers.ID = dailySalesReport.ID where customersType = \"Executive\" group by Customers.ID order by Customers.ID;");
    // error message if the item can't be added due to the data base
    if(qry->exec())
    {
        while(qry->next()){
            QMessageBox::about(this, "", "The rebat report is printed, double check if error occured");

            //Tranfers data from Querry to model
            modal->setQuery(*qry);

            //data base customers get viewed on the ui table view
            ui->RebattableView->setModel(modal);

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


void rebateMember::on_Enter_clicked()
{
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);
    QString expirMonth;

    expirMonth = ui->MonthcomboBox->currentText();

    list->prepare("select name, ID, customersType, expMonth, \"$65\" as \"Renew Price\" from Customers where customersType = \"Regular\" and expMonth = "+expirMonth+" UNION "
                "select name, ID, customersType, expMonth, \"$120\" as \"Renew Price\" from Customers where customersType = \"Executive\" and expMonth = "+expirMonth+";");


    // error message if the item can't be added due to the data base
    if(list->exec())
    {
        while(list->next()){
            QMessageBox::about(this, "", "The expired customer report is printed, double check if error occured");

            //Tranfers data from Querry to model
            modal->setQuery(*list);

            //data base customers get viewed on the ui table view
            ui->RebattableView->setModel(modal);

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

