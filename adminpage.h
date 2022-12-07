#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>
#include "addcustomer.h"
#include "additme.h"
#include "dbmanager.h"
#include "memberpurchase.h"
#include "membershipchange.h"


namespace Ui {
class adminpage;
}

class adminpage : public QDialog
{
    Q_OBJECT

public:
    explicit adminpage(QWidget *parent = nullptr);
    ~adminpage();

private slots:
    // all the of the button functionality is to change between different UI
    void on_AddOrDeleteItemButton_clicked();

    void on_CreatePurchaseButton_clicked();

    void on_AddOrDeleteCustomerButton_clicked();

    void on_ChangeMemberShipButton_clicked();

    void on_ViewCutomersButton_clicked();

private:
    Ui::adminpage *ui;
    addItme addItemUi;
    addCustomer addCustomerUi;
    memberPurchase memberPurchaseUi;
    membershipChange membershipChangeUi;

};

#endif // ADMINPAGE_H
