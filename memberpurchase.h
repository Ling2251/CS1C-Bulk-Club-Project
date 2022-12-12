#ifndef MEMBERPURCHASE_H
#define MEMBERPURCHASE_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include "dbmanager.h"

namespace Ui {
class memberPurchase;
}

class memberPurchase : public QDialog
{
    Q_OBJECT

public:
    explicit memberPurchase(QWidget *parent = nullptr);
    ~memberPurchase();
    void ShowItemsInComboBox();   // Shows item names in item combo box
    void ShowItemsPriceComboBox();   // Shows item price in item combo box
    void ShowMembershipComboBox();// show the Membership of the customer
    void ClearSreen();
private slots:

    void on_AddPurchaseButton_clicked();

    void on_LoadPriceButton_clicked();

    void on_UpdateInventory_clicked(int itemNumber,QString item);

private:
    Ui::memberPurchase *ui;
    bool addOrDelet;
};

#endif // MEMBERPURCHASE_H
