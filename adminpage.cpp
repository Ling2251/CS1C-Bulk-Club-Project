#include "adminpage.h"
#include "ui_adminpage.h"
#include "qtablewidget.h"


adminpage::adminpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminpage)
{
    ui->setupUi(this);
}

adminpage::~adminpage()
{
    delete ui;
}

void adminpage::on_AddOrDeleteItemButton_clicked()
{
    addItemUi.show();
}


void adminpage::on_CreatePurchaseButton_clicked()
{
    memberPurchaseUi.show();
}


void adminpage::on_AddOrDeleteCustomerButton_clicked()
{
    addCustomerUi.show();
}


void adminpage::on_ChangeMemberShipButton_clicked()
{
    membershipChangeUi.show();
}


void adminpage::on_ViewCutomersButton_clicked()
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
    qry->prepare("select * from Customers");

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


void adminpage::on_ViewItemsButton_clicked()
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
    qry->prepare("select * from inventory");

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

