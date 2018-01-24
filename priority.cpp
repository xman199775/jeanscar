#include "priority.h"
#include "ui_priority.h"

Priority::Priority(QWidget *parent, QString *s) :
    QDialog(parent),
    ui(new Ui::Priority)
{
    ui->setupUi(this);
    data = s;
}

Priority::~Priority()
{
    delete ui;
}

void Priority::on_pushButton_clicked()
{
    add(ui->add_employee);
    add(ui->salary);
    add(ui->Stock);
    add(ui->Manger);
    add(ui->Deliver_salary);
    add(ui->Custmers);
    add(ui->Edit_Order);
    add(ui->Ware);
    add(ui->Open);
    add(ui->Accounting);
    add(ui->Deliver);
    this->close();
}
void Priority::add(QCheckBox *b){
    if(b->isChecked())
        data->append("1");
    else
        data->append("0");
}
