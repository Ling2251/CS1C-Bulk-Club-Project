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

void addItme::on_AddButton_clicked()
{


}


void addItme::on_DeleteButton_clicked()
{

}



