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
    managerDailyReportUi.show();
}


void storemanager::on_salesReporButton_clicked()
{
    salesReportUi.show();
}

void storemanager::on_TotalReenueButton_clicked()
{
    totalRevenueUi.show();
}

void storemanager::on_TotalPurchasesButton_clicked()
{
    totalPurchaseUi.show();
}

void storemanager::on_rebateButton_clicked()
{
    rebateMemberUi.show();
}

