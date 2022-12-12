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
        qDebug() << "Error: addCustomer connection with database failed";
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
        qDebug() << "Error: AddCustomerButton connection with database failed";
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

    // error checking input
    if(customerName != "" && customerID != "" && type != "" && Month != "" && Day != "" && Year != ""){
        addOrDelet = true;
    }
    else{
        addOrDelet = false;
    }

    if(addOrDelet){
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
    else{
         QMessageBox::about(this, "Error", "Can't enter an empty input to add customer, please try agin");
         ClearSreen();
    }


}

void addCustomer::ClearSreen()
{
    ui->CustomerName->clear();
    ui->CutpmerID->clear();
    ui->CustomerType->clear();
    ui->Month->clear();
    ui->Day->clear();
    ui->Year->clear();
}

void addCustomer::on_DeleteCustomerButton_clicked()
{
    //NOTE ONLY NAME IS NEEDED TO DELETE THE MEMBER


    //opening data base
    DBManager conn;
    if(!conn.connOpend()){
        qDebug() << "Error: connection with database failed ";
        return;
    }

    conn.connOpend();
    QSqlQuery qry;
    QString customerName;

    //get the data in from the ui intput
    customerName   = ui->CustomerName->text();

    // error checking input
    if(customerName != ""){
        addOrDelet = true;
    }
    else{
        addOrDelet = false;
    }

    if(addOrDelet){
        // delete the item
        qry.prepare("Delete from Customers where name='"+customerName+"'");

        // error message if the item can't be added due to the data base
        if(qry.exec())
        {
            QMessageBox::about(this, "", "The customer has been deleted. double check to see that it was deleted");
            //Closes conncection to data base
            conn.connClose();
        }
        else
        {
            QMessageBox::about(this, "Error", "Database not found double check path to database");
        }
    }
    else{
        QMessageBox::about(this, "Error", "Can't enter an empty input or invaild input to delet customer, please try agin");
        ClearSreen();
    }
}

