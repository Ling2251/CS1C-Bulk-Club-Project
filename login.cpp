#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_LoginPushButton_clicked()
{
    QString userLine = ui->UserLine->text();
    QString passwordLine = ui->PasswordLine->text();

    if(userLine == "admin" && passwordLine == "12345")
    {
        qDebug() << "Successfully logged in as Admin!";
        adminUi.show();
    }
    else if(userLine == "storemanager" && passwordLine == "12345"){
        qDebug() << "Successfully logged in as Store Manager!";
        storemanagerUi.show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username or password is not correct");
    }
}


void login::on_LoginClearButton_clicked()
{
    ui->UserLine->clear();
    ui->PasswordLine->clear();
}

