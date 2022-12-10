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
    void ClearSreen();

private slots:
    void on_AddCustomerButton_clicked();

    void on_DeleteCustomerButton_clicked();

private:
    Ui::addCustomer *ui;
    // for error checking inputs.
    bool addOrDelet;
};

#endif // ADDCUSTOMER_H
