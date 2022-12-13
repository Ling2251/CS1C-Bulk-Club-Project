#include "totalpurchase.h"
#include "ui_totalpurchase.h"

totalPurchase::totalPurchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::totalPurchase)
{
    ui->setupUi(this);


    ItemsPurchaseComboBox();
    idPurchaseComboBox();

}

totalPurchase::~totalPurchase()
{
    delete ui;
}

void totalPurchase::on_customerShow_clicked()
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
    ui->tableView->setModel(modal);

    //closes connention to data base
    conn.connClose();
    //counts rows from the model
    qDebug() <<(modal->rowCount());
}


void totalPurchase::on_itemShow_clicked()
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
    qry->prepare("select purchaseDate,item,price,quantity from dailySalesReport");


    qry->exec();
    //Tranfers data from Querry to model
    modal->setQuery(*qry);

    //data base customers get viewed on the ui table view
    ui->tableView->setModel(modal);

    //closes connention to data base
    conn.connClose();
    //counts rows from the model
    qDebug() <<(modal->rowCount());
}

void totalPurchase::ItemsPurchaseComboBox()
{
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);

    // only put the name out from the inventory
    list->prepare("select item from dailySalesReport");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);
    ui->ItemPurchaseCombox->setModel(modal);
}

void totalPurchase::idPurchaseComboBox()
{
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);

    // only put the name out from the inventory
    list->prepare("select ID from dailySalesReport");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);
    ui->IDcomBox->setModel(modal);
}

void totalPurchase::on_enterItemPushBtn_clicked()
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
    QString currentItem;

    currentItem = ui->ItemPurchaseCombox->currentText();

    //selects the list in the data base
    qry->prepare("select * from dailySalesReport where item= ?");
    qry->addBindValue(currentItem);

    // error message if the item can't be added due to the data base
    if(qry->exec())
    {
        while(qry->next()){
            QMessageBox::about(this, "", "The daily report is printed, double check if error occured");

            //Tranfers data from Querry to model
            modal->setQuery(*qry);

            //data base customers get viewed on the ui table view
            ui->tableView->setModel(modal);

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



void totalPurchase::on_enterNamePushBtn_clicked()
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
    QString currentID;

    currentID = ui->IDcomBox->currentText();

    //selects the list in the data base
    qry->prepare("select * from dailySalesReport where ID= ?");
    qry->addBindValue(currentID);

    // error message if the item can't be added due to the data base
    if(qry->exec())
    {
        while(qry->next()){
            QMessageBox::about(this, "", "The daily report is printed, double check if error occured");

            //Tranfers data from Querry to model
            modal->setQuery(*qry);

            //data base customers get viewed on the ui table view
            ui->tableView->setModel(modal);

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

