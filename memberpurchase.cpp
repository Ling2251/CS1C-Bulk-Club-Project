#include "memberpurchase.h"
#include "ui_memberpurchase.h"

memberPurchase::memberPurchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::memberPurchase)
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
    // display the item name in the item drop box
    ShowItemsInComboBox();

}

memberPurchase::~memberPurchase()
{
    delete ui;
}

// function that will show all the itme in a drop box
void memberPurchase::ShowItemsInComboBox(){
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);

    // only put the name out from the inventory
    list->prepare("select name from Inventory");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);
    ui->ItemComboBox->setModel(modal);
}

// function that will show the price of the item
void memberPurchase::ShowItemsPriceComboBox(){

    DBManager conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);
    QString itemName;

    itemName   = ui->ItemComboBox->currentText();

    // need to check if the item name's pirce is the same as the pirce that is showing
    list->exec("select price from Inventory where name=='"+itemName+"'");
    modal->setQuery(*list);
    ui->PriceComboBox->setModel(modal);
}

// the main function that created the purchase
void memberPurchase::on_AddPurchaseButton_clicked()
{
    // opned the data base
    DBManager conn;
    if(!conn.connOpend()){
        qDebug() << "Error: connection with database failed";
        return;
    }

    conn.connOpend();

    QSqlQuery qry;
    int itemNumber;
    double price;
    QString customerID,type, purchaseDate,item;

    //get the data in from the ui intput
    customerID   = ui->CoustomerID->text();
    type         = ui->CoustomerType->text();
    purchaseDate = ui->PurchaseDate->text();
    item         = ui->ItemComboBox->currentText();
    price        = ui->PriceComboBox->currentText().toDouble();
    itemNumber   = ui->itemNum->text().toInt();

    // get the total price with the number of item purchase
    price = price * itemNumber;

     // add the item
    qry.prepare("insert into dailySalesReport (purchaseDate, ID, item, price, quantity) VALUES (?, ?, ?, ?, ?);");
    qry.addBindValue(purchaseDate);
    qry.addBindValue(customerID);
    qry.addBindValue(item);
    qry.addBindValue(price);
    qry.addBindValue(itemNumber);

    // error message if the purchase can't be added due to the data base
    if(qry.exec())
    {
        QMessageBox::about(this, "", "The purchase was added, double check if error occured");
        addOrDelet = true;
        on_UpdateInventory_clicked(itemNumber,item);
        // close the connection to data base
        conn.connClose();
    }
    else
    {
        QMessageBox::about(this, "Error", "Database not found double check path to database");
    }


}

// function that delet the purchase
void memberPurchase::on_DeletPurchaseButton_clicked()
{


    addOrDelet = false;
}


// after load the item need an button to updat the price to that item
void memberPurchase::on_LoadPriceButton_clicked()
{
    // opned the data base
    DBManager conn;

    conn.connOpend();
    ShowItemsPriceComboBox();
    conn.connClose();
}

// after creating a purchase need to updat the inventory number
// since the user has buy item form it
void memberPurchase::on_UpdateInventory_clicked(int itemNumber,QString item)
{
    // opned the data base
    DBManager conn;

    QSqlQuery qry;

    // edit/updated the inventroy for the number of Item is sell
    // base on if it's creating a purchase or delete a purchase
    if(addOrDelet){
        qry.prepare("update Inventory set quantity= (quantity - ?)where name='"+item+"'");
   }
   else{
        qry.prepare("update Inventory set quantity= (quantity + ?)where name='"+item+"'");
    }
   qry.addBindValue(itemNumber);

    // error message if the purchase can't be added due to the data base
    if(qry.exec())
    {
       QMessageBox::about(this, "", "The quantiy of the item was edit, double check if error occured");
       // close the connection to data base
       conn.connClose();
    }
    else
    {
       QMessageBox::about(this, "Error", "Database not found double check path to database");
    }
}

