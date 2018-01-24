#include "choose_employee.h"
#include "ui_choose_employee.h"
#include <QSqlQuery>
choose_employee::choose_employee(QWidget *parent, QLineEdit *l) :
    QDialog(parent),
    ui(new Ui::choose_employee)
{
    ui->setupUi(this);
    my_label = l;
    QSqlQuery qry;
    qry.exec("select `Ecode`, `Name` from `Employee`;");
    QString x;
    while (qry.next()) {
        x = qry.value(0).toString() + ", " + qry.value(1).toString();
        ui->employees->addItem(x);
    }
}

choose_employee::~choose_employee()
{
    delete ui;
}

void choose_employee::on_employees_doubleClicked(const QModelIndex &index)
{
    QString ecode = "", tmp = "";
    tmp = ui->employees->currentItem()->text();
    for (int i = 0 ; i < tmp.size() && tmp[i] != ',' ; i++)
        ecode += tmp[i];
    my_label->setText(ecode);
    this->close();
}
