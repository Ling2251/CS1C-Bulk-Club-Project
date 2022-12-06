#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/78418/Desktop/key.png");
    ui->label_loginImage->setPixmap(pix);
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
<<<<<<< HEAD
    else if(userLine == "storemanager" && passwordLine == "12345"){
        qDebug() << "Successfully logged in as Store Manager!";
=======
    else if(userLine == "manager" && passwordLine == "12345"){
        qDebug() << "Log in as Store manager!";
>>>>>>> a3b6285ce5a1c33437a9dd75ad5d78e9f10ec28f
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

