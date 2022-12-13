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
    void ShowDateComboBox();


    //double GetTotalRevenue(QString date);

private slots:


   // void on_comboBox_activated(const QString &arg1);

    void on_TotalRevenuePushButton_clicked();

    //void on_TotatMembersPushButton_clicked();

    void on_TotalExecPushButton_clicked();

    void on_TotalRegPushButton_clicked();





private:
    Ui::totalRevenue *ui;
};

#endif // TOTALREVENUE_H
