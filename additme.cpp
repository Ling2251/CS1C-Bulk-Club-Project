#include "additme.h"
#include "ui_additme.h"


addItme::addItme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addItme)
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

addItme::~addItme()
{
    delete ui;
}

void addItme::on_AddButton_clicked()
{
    // opned the data base
    DBManager conn;
    if(!conn.connOpend()){
        qDebug() << "Error: connection with database failed";
        return;
    }
    conn.connOpend();
    QSqlQuery qry;
    QString itemName,itemNumber,itemPrice;

    //get the data in from the ui intput
    itemName   = ui->ItemName->text();
    itemPrice  = ui->ItemPrice->text();
    itemNumber = ui->ItemNumber->text();

    // add the item
    qry.prepare("insert into Inventory (name, price, quantity) values ('"+itemName+"', '"+itemPrice+"', '"+itemNumber+"')");

    // error message if the item can't be added due to the data base
    if(qry.exec())
    {
        QMessageBox::about(this, "", "The item was added, double check if error occured");
        // close the connection to data base
        conn.connClose();
    }
    else
    {
        QMessageBox::about(this, "Error", "Database not found double check path to database");
    }

}


void addItme::on_DeleteButton_clicked()
{
    /*
     * Not working ad it should for example if theres an item with 88 quantity, you cant take just 2 off and
     * it would update to 86, you have to take the whole amount off, still needs to be tweaked
     */

    // opned the data base
    DBManager conn;
    if(!conn.connOpend()){
        qDebug() << "Error: connection with database failed";
        return;
    }
    conn.connOpend();
    QSqlQuery qry;
    QString itemName,itemNumber;

    //get the data in from the ui intput
    itemName   = ui->ItemName->text();
    itemNumber = ui->ItemNumber->text();

    // delete the item
    qry.prepare("Delete from inventory where quantity='"+itemName+"'");
    qry.prepare("Delete from inventory where quantity='"+itemNumber+"'");



    // error message if the item can't be added due to the data base
    if(qry.exec())
    {
        QMessageBox::about(this, "", "The item(s) was/were deleted, double check if error occured");
        // close the connection to data base
        conn.connClose();
    }
    else
    {
        QMessageBox::about(this, "Error", "Database not found double check path to database");
    }

}



