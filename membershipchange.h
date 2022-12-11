#ifndef MEMBERSHIPCHANGE_H
#define MEMBERSHIPCHANGE_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QInputDialog>
#include <QIntValidator>
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
    void ClearSreen();

private slots:
    void on_ChangeButton_clicked();

private:
    Ui::membershipChange *ui;
    bool addOrDelet;
};

#endif // MEMBERSHIPCHANGE_H
