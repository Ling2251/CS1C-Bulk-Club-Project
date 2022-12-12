#ifndef SALESREPORT_H
#define SALESREPORT_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include "dbmanager.h"


namespace Ui {
class salesReport;
}

class salesReport : public QDialog
{
    Q_OBJECT

public:
    explicit salesReport(QWidget *parent = nullptr);
    ~salesReport();

private:
    Ui::salesReport *ui;
};

#endif // SALESREPORT_H
