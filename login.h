#ifndef LOGIN_H
#define LOGIN_H

#include<QMainWindow>
#include<QtSql>
#include<QDebug>
#include<QMessageBox>
#include<QFileInfo>
#include <QDialog>
#include"mainwindow.h"
#include "adminpage.h"
#include "storemanager.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:

    void on_LoginPushButton_clicked();

    void on_LoginClearButton_clicked();

private:
    Ui::login *ui;
    QMainWindow w;
    adminpage adminUi;
    storemanager storemanagerUi;
};

#endif // LOGIN_H
