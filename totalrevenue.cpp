#include "totalrevenue.h"
#include "ui_totalrevenue.h"

totalRevenue::totalRevenue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::totalRevenue)
{
    ui->setupUi(this);

    //connect(ui->comboBox,   &QComboBox::activated, this, &totalRevenue::on_comboBox_activated);
    //connect(ui->TotalExecPushButton,   &QPushButton::clicked, this, &totalRevenue::on_TotalExecPushButton_clicked);

    ShowDateComboBox();

}

totalRevenue::~totalRevenue()
{
    delete ui;
}



// function that will show all the itme in a drop box
void totalRevenue::ShowDateComboBox(){
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);

    // only put the name out from the inventory
    list->prepare("select purchaseDate from dailySalesReport");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);
    ui->comboBox->setModel(modal);
}


/*
void totalRevenue::on_comboBox_activated(const QString &arg1)
{
    DBManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);

    // only put the name out from the inventory
    list->prepare("select purchaseDate from dailySalesReport");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);
    ui->comboBox->setModel(modal);
}
*/

void totalRevenue::on_TotalRevenuePushButton_clicked()
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
    QString currentDay;

    //_____________________________

    QString totalRevenueString;
    double Revenue;


    //_____________________________

    currentDay = ui->comboBox->currentText();

    //________________________
    Revenue = conn.GetTotalRevenue(currentDay);
    totalRevenueString = QString::number(Revenue, 'f', 2);
    //________________________

    //selects the list in the data base
    qry->prepare("select price from dailySalesReport where purchaseDate= ?");

    qry->addBindValue(currentDay);

    // error message if the item can't be added due to the data base
    if(qry->exec())
    {
        while(qry->next()){
            QMessageBox::about(this, "", "The daily report is printed, double check if error occured");

            //Tranfers data from Querry to model
            modal->setQuery(*qry);

            //data base customers get viewed on the ui table view
            ui->tableView->setModel(modal);
            ui->lineEdit->setText("$"+totalRevenueString);

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


void totalRevenue::on_TotalExecPushButton_clicked()
{
    DBManager conn;
    QSqlQueryModel * modal = new QSqlQueryModel();


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
            ui->tableView->setModel(modal);
           // ui->lineEdit->setText("$"+totalRevenueString);

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



//Button for Regular members shopped that day
void totalRevenue::on_TotalRegPushButton_clicked()
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
            QMessageBox::about(this, "", "The Executive daily report is printed, double check if error occured");

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










