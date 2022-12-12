#include "rebatemember.h"
#include "ui_rebatemember.h"

rebateMember::rebateMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rebateMember)
{
    ui->setupUi(this);
}

rebateMember::~rebateMember()
{
    delete ui;
}
