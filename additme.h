#ifndef ADDITME_H
#define ADDITME_H

#include <QDialog>
#include "dbmanager.h"
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class addItme;
}

class addItme : public QDialog
{
    Q_OBJECT

public:
    explicit addItme(QWidget *parent = nullptr);
    ~addItme();
    void ClearSreen();
private slots:
    void on_AddButton_clicked();

    void on_DeleteButton_clicked();


private:
    Ui::addItme *ui;
    // for error checking inputs.
    bool addOrDelet;
};

#endif // ADDITME_H
