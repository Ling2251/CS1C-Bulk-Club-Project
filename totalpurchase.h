#ifndef TOTALPURCHASE_H
#define TOTALPURCHASE_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include "dbmanager.h"

namespace Ui {
class totalPurchase;
}

class totalPurchase : public QDialog
{
    Q_OBJECT

public:
    explicit totalPurchase(QWidget *parent = nullptr);
    ~totalPurchase();

    void ItemsPurchaseComboBox();

    void idPurchaseComboBox();

private slots:
    void on_customerShow_clicked();

    void on_itemShow_clicked();


private:
    Ui::totalPurchase *ui;
};

#endif // TOTALPURCHASE_H
