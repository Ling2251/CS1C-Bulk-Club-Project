#include "membershipchange.h"
#include "ui_membershipchange.h"

membershipChange::membershipChange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::membershipChange)
{
    ui->setupUi(this);

    // added the data base connection to additme
    DBManager conn;
    if(!conn.connOpend()){
        qDebug() << "Error: membershipChange connection with database failed";
    }
    else{
        qDebug() << "Connected to database.";

    }
}

membershipChange::~membershipChange()
{
    delete ui;
}

// clear the input if it has invailed inputs
void membershipChange::ClearSreen()
{
    ui->CustomerIDEdit->clear();
    ui->MembershipEdit->clear();
    ui->Month->clear();
    ui->Day->clear();
    ui->Year->clear();
}


void membershipChange::on_ChangeButton_clicked()
{
    // opned the data base
    DBManager conn;
    if(!conn.connOpend()){
        qDebug() << "Error: ChangeButton connection with database failed";
        return;
    }
    conn.connOpend();
    QSqlQuery qry;
    QString customerID,type, Month,Day,Year;

    //get the data in from the ui intput
    customerID   = ui->CustomerIDEdit->text();
    type         = ui->MembershipEdit->text();
    Month        = ui->Month->text();
    Day          = ui->Day->text();
    Year         = ui->Year->text();

    // error checking input
    if(customerID != "" && type != "" && type != "" && Month != "" && Day != "" && Year != ""){
        addOrDelet = true;
    }
    else{
        addOrDelet = false;
    }

    if(addOrDelet){
        // update the membership
        qry.prepare("update Customers set ID='"+customerID+"',customersType='"+type+"',expMonth='"+Month+"',expDay='"+Day+"',expYear='"+Year+"' where ID='"+customerID+"'");

        // error message if the item can't be updataed due to the data base
        if(qry.exec())
        {
            QMessageBox::about(this, "", "Membership has changed,please check if an error has occured");
            // close the connection to data base
            conn.connClose();
        }
        else
        {
            QMessageBox::about(this, "Error", "Database not found, please check path to database");
        }
    }
    else{
        QMessageBox::about(this, "Error", "Can't enter an empty input or invaild input to change the membership, please try agin");
        ClearSreen();
    }


}

