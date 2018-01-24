#include "dialog1.h"
#include "ui_dialog1.h"
#include <QSqlQuery>
#include <QMessageBox>
Dialog1::Dialog1(QWidget *parent, QString o) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    opnum=o;
    QSqlQuery qry;
    qry.exec("select `Name` from `Customer` , `Order` where `Order-num` = "+opnum+" and `C-code` = `Cnum`;"); // اسمه
    qry.first();
    ui->lineEdit->setText(qry.value(0).toString());
    qry.exec("select `Number` from `Customer` , `Order` where `Order-num` = "+opnum+" and `C-code` = `Cnum`;");//رقمه
    qry.first();
    ui->lineEdit_2->setText(qry.value(0).toString());
    qry.exec("select `M-Pay` from `Customer` , `Order` where `Order-num` = "+opnum+" and `C-code` = `Cnum`;");//دفع كام
    qry.first();
    ui->doubleSpinBox->setValue(qry.value(0).toDouble());
    qry.exec("select `Total-price` from `Customer` , `Order` where `Order-num` = "+opnum+" and `C-code` = `Cnum`;");//باقي كام
    qry.first();
    ui->doubleSpinBox_3->setValue(qry.value(0).toDouble());
    qry.exec("select `M-Remain` from `Customer` , `Order` where `Order-num` = "+opnum+" and `C-code` = `Cnum`;");//المجموع الكلي
    qry.first();
    ui->doubleSpinBox_2->setValue(qry.value(0).toDouble());
    qry.exec("select `Order` from `Customer` , `Order` where `Order-num` = "+opnum+" and `C-code` = `Cnum`;");//المجموع الكلي
    qry.first();
    ui->lineEdit_4->setText(qry.value(0).toString());
    qry.exec("select `Delvtime` from `Customer` , `Order` where `Order-num` = "+opnum+" and `C-code` = `Cnum`;");//المجموع الكلي
    qry.first();
    ui->dateEdit->setDateTime(qry.value(0).toDateTime());
    qry.exec("select `time` from `Customer` , `Order` where `Order-num` = "+opnum+" and `C-code` = `Cnum`;");//المجموع الكلي
    qry.first();
    if(qry.value(0).toString()=="a")
    {
        ui->lineEdit_3->setText("5:11");
    }
    else if(qry.value(0).toString()=="b")
    {
        ui->lineEdit_3->setText("8:2");
    }
    else if(qry.value(0).toString()=="c")
    {
        ui->lineEdit_3->setText("11:5");
    }
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_clicked()
{

    QString  order =ui->lineEdit_4->text(),
            all=QString::number(ui->doubleSpinBox_3->value()),
            remain=QString::number(ui->doubleSpinBox_2->value()),
            pay=QString::number(ui->doubleSpinBox->value());

    bool found=false;
    QSqlQuery qryf;
    qryf.exec("select `Order-num` from `JeansCar`.`Order`");//اكواد عمليات الشراء
    while (qryf.next())
    {
        if(opnum==qryf.value(0).toString())
        {
            found=true;
            break;
        }
    }
    if(found)
    {
        qryf.exec("UPDATE `jeanscar`.`order` SET `Total-price`="+all+", `M-Remain`="+remain+", `M-Pay`="+pay+",`Order`='"+order+"' WHERE `Order-num`='"+opnum+"';");//اكواد عمليات ال
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("لا توجد عملية تسليم بهذا الكود");
        msgBox.exec();
    }
    this->close();
}

void Dialog1::on_pushButton_2_clicked()
{
    this->close();
}

void Dialog1::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->doubleSpinBox_2->setValue(ui->doubleSpinBox_3->value()-ui->doubleSpinBox->value());
}

void Dialog1::on_doubleSpinBox_3_valueChanged(double arg1)
{
    ui->doubleSpinBox_2->setValue(ui->doubleSpinBox_3->value()-ui->doubleSpinBox->value());
}
