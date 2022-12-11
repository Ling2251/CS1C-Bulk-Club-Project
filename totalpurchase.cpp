#include "totalpurchase.h"
#include "ui_totalpurchase.h"

totalPurchase::totalPurchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::totalPurchase)
{
    ui->setupUi(this);
}

totalPurchase::~totalPurchase()
{
    delete ui;
}
