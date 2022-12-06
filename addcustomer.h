#ifndef ADDCUSTOMER_H
#define ADDCUSTOMER_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include "dbmanager.h"

namespace Ui {
class addCustomer;
}

class addCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit addCustomer(QWidget *parent = nullptr);
    ~addCustomer();

private:
    Ui::addCustomer *ui;
};

#endif // ADDCUSTOMER_H
