#ifndef ADDITME_H
#define ADDITME_H

#include <QDialog>

namespace Ui {
class addItme;
}

class addItme : public QDialog
{
    Q_OBJECT

public:
    explicit addItme(QWidget *parent = nullptr);
    ~addItme();

private:
    Ui::addItme *ui;
};

#endif // ADDITME_H
