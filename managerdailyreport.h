#ifndef MANAGERDAILYREPORT_H
#define MANAGERDAILYREPORT_H

#include <QDialog>
#include "dbmanager.h"

namespace Ui {
class managerDailyReport;
}

class managerDailyReport : public QDialog
{
    Q_OBJECT

public:
    explicit managerDailyReport(QWidget *parent = nullptr);
    ~managerDailyReport();

private:
    Ui::managerDailyReport *ui;
};

#endif // MANAGERDAILYREPORT_H