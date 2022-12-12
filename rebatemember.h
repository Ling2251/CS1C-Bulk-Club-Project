#ifndef REBATEMEMBER_H
#define REBATEMEMBER_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include "dbmanager.h"

namespace Ui {
class rebateMember;
}

class rebateMember : public QDialog
{
    Q_OBJECT

public:
    explicit rebateMember(QWidget *parent = nullptr);
    ~rebateMember();

private:
    Ui::rebateMember *ui;
};

#endif // REBATEMEMBER_H
