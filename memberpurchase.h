#ifndef MEMBERPURCHASE_H
#define MEMBERPURCHASE_H

#include <QDialog>

namespace Ui {
class memberPurchase;
}

class memberPurchase : public QDialog
{
    Q_OBJECT

public:
    explicit memberPurchase(QWidget *parent = nullptr);
    ~memberPurchase();

private:
    Ui::memberPurchase *ui;
};

#endif // MEMBERPURCHASE_H
