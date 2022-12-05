#ifndef MEMBERSHIPCHANGE_H
#define MEMBERSHIPCHANGE_H

#include <QDialog>

namespace Ui {
class membershipChange;
}

class membershipChange : public QDialog
{
    Q_OBJECT

public:
    explicit membershipChange(QWidget *parent = nullptr);
    ~membershipChange();

private:
    Ui::membershipChange *ui;
};

#endif // MEMBERSHIPCHANGE_H
