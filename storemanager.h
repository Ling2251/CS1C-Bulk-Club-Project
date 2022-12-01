#ifndef STOREMANAGER_H
#define STOREMANAGER_H

#include <QDialog>

namespace Ui {
class storemanager;
}

class storemanager : public QDialog
{
    Q_OBJECT

public:
    explicit storemanager(QWidget *parent = nullptr);
    ~storemanager();

private:
    Ui::storemanager *ui;
};

#endif // STOREMANAGER_H
