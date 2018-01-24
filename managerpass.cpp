#include "managerpass.h"
#include "ui_managerpass.h"
#include <QMessageBox>
managerpass::managerpass(QWidget *parent, QString *n, QString *c, QString *p) :
    QDialog(parent),
    ui(new Ui::managerpass)
{
    ui->setupUi(this);
    name=n;
    code=c;
    pass=p;
}

managerpass::~managerpass()
{
    delete ui;
}

void managerpass::on_pushButton_clicked()
{
    QString c=*code;
    QString p=*pass;
    *code=ui->code->text();
    *pass=ui->pass->text();
    if(!(*code=="ASH"&&*pass=="ASHNOUHCOMPANY"))
    {
        QMessageBox msgBox;
         msgBox.setWindowTitle("خطاء");
         msgBox.setText("خطا كود المدير او كلمة السر");
         msgBox.exec();
         *code=c;
         *pass=p;
    }
    /*else if()
     {}*/
    else
    {
        this->close();
    }
}

void managerpass::on_pushButton_2_clicked()
{
    this->close();
}
