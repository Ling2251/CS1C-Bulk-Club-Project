#ifndef STOREMANAGER_H
#define STOREMANAGER_H

#include <QDialog>
#include"managerdailyreport.h"
#include "salesreport.h"
#include "dbmanager.h"
#include "totalrevenue.h"
#include "totalpurchase.h"
#include "rebatemember.h"

namespace Ui {
class storemanager;
}

class storemanager : public QDialog
{
    Q_OBJECT

public:
    explicit storemanager(QWidget *parent = nullptr);
    ~storemanager();

private slots:


    void on_DailtReportButton_clicked();

    void on_salesReporButton_clicked();

    void on_TotalReenueButton_clicked();

    void on_TotalPurchasesButton_clicked();

    void on_rebateButton_clicked();

private:
    Ui::storemanager *ui;
    managerDailyReport managerDailyReportUi;
    salesReport salesReportUi;
    totalRevenue totalRevenueUi;
    totalPurchase totalPurchaseUi;
    rebateMember rebateMemberUi;


};

#endif // STOREMANAGER_H
