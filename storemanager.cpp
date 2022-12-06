#include "storemanager.h"
#include "ui_storemanager.h"

storemanager::storemanager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::storemanager)
{
    ui->setupUi(this);
}

storemanager::~storemanager()
{
    delete ui;
}




void storemanager::on_DailtReportButton_clicked()
{

}


void storemanager::on_salesReporButton_clicked()
{

}


void storemanager::on_TotalReenueButton_clicked()
{

}


void storemanager::on_TotalPurchasesButton_clicked()
{

}


void storemanager::on_rebateButton_clicked()
{

}

