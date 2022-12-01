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
