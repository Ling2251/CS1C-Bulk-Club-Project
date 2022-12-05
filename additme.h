#ifndef ADDITME_H
#define ADDITME_H

#include <QDialog>
#include "dbmanager.h"
#include <QtSql>
#include <QSqlQuery>

namespace Ui {
class addItme;
}

class addItme : public QDialog
{
    Q_OBJECT

public:
    explicit addItme(QWidget *parent = nullptr);
    ~addItme();

private slots:
    void on_AddButton_clicked();

    void on_DeleteButton_clicked();


private:
    Ui::addItme *ui;
};

#endif // ADDITME_H
