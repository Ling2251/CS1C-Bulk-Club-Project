#include "memberpurchase.h"
#include "ui_memberpurchase.h"

memberPurchase::memberPurchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::memberPurchase)
{
    ui->setupUi(this);
}

memberPurchase::~memberPurchase()
{
    delete ui;
}
