#include "product.h"
#include "ui_product.h"
#include <QSqlQuery>
product::product(QWidget *parent, QString o) :
    QWidget(parent),
    ui(new Ui::product)
{
    ui->setupUi(this);
    opnum=o;
    QSqlQuery qry;
    qry.exec("select `Order` from  `Order` where `Order-num` = "+opnum+";");//المجموع الكلي
    qry.first();
    ui->textBrowser->setText(qry.value(0).toString());
    qry.exec("select `Car-det` from  `Order` where `Order-num` = "+opnum+";");
    qry.first();
    ui->lineEdit->setText(qry.value(0).toString());
    qry.exec("select `stamp` from  `Order` where `Order-num` = "+opnum+";");
    qry.first();
    ui->lineEdit_2->setText(qry.value(0).toString());
    qry.exec("select  `Name` from `Order`,`Employee` where `Order-num` = "+opnum+" and `A-code` = `Ecode`;");
    qry.first();
    ui->salescode->setText(qry.value(0).toString());
    qry.exec("select `cur` from  `Order` where `Order-num` = "+opnum+";");
    qry.first();

    if(qry.value(0).toInt()==0)
    {
        ui->progressBar->setValue(1);
    }
    else if(qry.value(0).toInt()==1)
    {
        ui->progressBar->setValue(3);
    }
    else if(qry.value(0).toInt()==2)
    {
        ui->progressBar->setValue(5);
    }
    else if(qry.value(0).toInt()==3)
    {
        ui->progressBar->setValue(7);
    }
    else if(qry.value(0).toInt()==4)
    {
        ui->progressBar->setValue(8);
    }
}

product::~product()
{
    delete ui;
}

void product::on_pushButton_clicked()
{
    QSqlQuery qry;
    qry.exec("select `cur` from  `Order` where `Order-num` = "+opnum+";");
    qry.first();
    int x=qry.value(0).toInt();
    if(x<4)
    {
       qry.exec("UPDATE `jeanscar`.`order` SET `cur`= "+QString::number(x+1)+" WHERE `Order-num`="+opnum+";");

    }
    qry.exec("select `cur` from  `Order` where `Order-num` = "+opnum+";");
    qry.first();

    if(qry.value(0).toInt()==0)
    {
        ui->progressBar->setValue(1);
    }
    else if(qry.value(0).toInt()==1)
    {
        ui->progressBar->setValue(3);
    }
    else if(qry.value(0).toInt()==2)
    {
        ui->progressBar->setValue(5);
    }
    else if(qry.value(0).toInt()==3)
    {
        ui->progressBar->setValue(7);
    }
    else if(qry.value(0).toInt()==4)
    {
        ui->progressBar->setValue(8);
    }
}

void product::on_pushButton_2_clicked()
{
    QSqlQuery qry;
    qry.exec("select `cur` from  `Order` where `Order-num` = "+opnum+";");
    qry.first();
    int x=qry.value(0).toInt();
    if(x>0)
    {
       qry.exec("UPDATE `jeanscar`.`order` SET `cur`= "+QString::number(x-1)+" WHERE `Order-num`="+opnum+";");

    }
    qry.exec("select `cur` from  `Order` where `Order-num` = "+opnum+";");
    qry.first();

    if(qry.value(0).toInt()==0)
    {
        ui->progressBar->setValue(1);
    }
    else if(qry.value(0).toInt()==1)
    {
        ui->progressBar->setValue(3);
    }
    else if(qry.value(0).toInt()==2)
    {
        ui->progressBar->setValue(5);
    }
    else if(qry.value(0).toInt()==3)
    {
        ui->progressBar->setValue(7);
    }
    else if(qry.value(0).toInt()==4)
    {
        ui->progressBar->setValue(8);
    }
}
