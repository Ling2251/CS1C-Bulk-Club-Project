#include "membershipchange.h"
#include "ui_membershipchange.h"

membershipChange::membershipChange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::membershipChange)
{
    ui->setupUi(this);
}

membershipChange::~membershipChange()
{
    delete ui;
}
