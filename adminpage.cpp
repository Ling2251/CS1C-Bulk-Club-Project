#include "adminpage.h"
#include "ui_adminpage.h"

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

