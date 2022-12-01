#include "additme.h"
#include "ui_additme.h"

addItme::addItme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addItme)
{
    ui->setupUi(this);
}

addItme::~addItme()
{
    delete ui;
}
