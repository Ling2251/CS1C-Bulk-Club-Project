#include "totalrevenue.h"
#include "ui_totalrevenue.h"

totalRevenue::totalRevenue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::totalRevenue)
{
    ui->setupUi(this);
}

totalRevenue::~totalRevenue()
{
    delete ui;
}
