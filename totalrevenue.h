#ifndef TOTALREVENUE_H
#define TOTALREVENUE_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include "dbmanager.h"

namespace Ui {
class totalRevenue;
}

class totalRevenue : public QDialog
{
    Q_OBJECT

public:
    explicit totalRevenue(QWidget *parent = nullptr);
    ~totalRevenue();

private:
    Ui::totalRevenue *ui;
};

#endif // TOTALREVENUE_H
