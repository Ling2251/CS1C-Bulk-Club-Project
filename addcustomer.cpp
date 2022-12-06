#include "addcustomer.h"
#include "ui_addcustomer.h"

addCustomer::addCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCustomer)
{
    ui->setupUi(this);

    // added the data base connection to additme
    DBManager conn;
    if(!conn.connOpend()){
        qDebug() << "Error: connection with database failed";
    }
    else{
        qDebug() << "Connected to database.";

    }
}

addCustomer::~addCustomer()
{
    delete ui;
}


void addCustomer::on_AddCustomerButton_clicked()
{
    // opned the data base
    DBManager conn;
    if(!conn.connOpend()){
        qDebug() << "Error: connection with database failed";
        return;
    }
    conn.connOpend();
    QSqlQuery qry;
    QString customerName,customerID,type,Month,Day,Year;

    //get the data in from the ui intput
    customerName   = ui->CustomerName->text();
    customerID     = ui->CutpmerID->text();
    type           = ui->CustomerType->text();
    Month          = ui->Month->text();
    Day            = ui->Day->text();
    Year           = ui->Year->text();


    // add the item
    qry.prepare("insert into Customers (name, ID, customersType, expMonth, expDay,expYear) values ('"+customerName+"', '"+customerID+"', '"+type+"', '"+Month+"','"+Day+"','"+Year+"')");

    // error message if the item can't be added due to the data base
    if(qry.exec())
    {
        QMessageBox::about(this, "", "The item was added. double check if error occured");
        // close the connection to data base
        conn.connClose();
    }
    else
    {
        QMessageBox::about(this, "Error", "Database not found double check path to database");
    }
}

