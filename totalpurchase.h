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

private:
    Ui::totalPurchase *ui;
};

#endif // TOTALPURCHASE_H
