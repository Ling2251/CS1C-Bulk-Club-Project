#include "managerdailyreport.h"
#include "ui_managerdailyreport.h"


managerDailyReport::managerDailyReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerDailyReport)
{
    ui->setupUi(this);

}

managerDailyReport::~managerDailyReport()
{
    delete ui;
}

