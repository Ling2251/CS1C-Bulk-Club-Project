#ifndef MANAGERDAILYREPORT_H
#define MANAGERDAILYREPORT_H


#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
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
    void ShowDateComboBox();

private slots:
    void on_AllDailyReport_clicked();

private:
    Ui::managerDailyReport *ui;
};

#endif // MANAGERDAILYREPORT_H
