#ifndef MEMBERSHIPCHANGE_H
#define MEMBERSHIPCHANGE_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include "dbmanager.h"

namespace Ui {
class membershipChange;
}

class membershipChange : public QDialog
{
    Q_OBJECT

public:
    explicit membershipChange(QWidget *parent = nullptr);
    ~membershipChange();

private slots:
    void on_ChangeButton_clicked();

private:
    Ui::membershipChange *ui;
};

#endif // MEMBERSHIPCHANGE_H
