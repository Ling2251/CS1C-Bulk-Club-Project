#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    /*QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/78418/CS1C-Bulk-Club-Project/Database.db");

    if(!mydb.open())
    {
        ui->label->setText("Fail to open the database");
    }
    else
    {
        ui->label->setText("connected..........");
    }*/



}

login::~login()
{
    delete ui;
}
