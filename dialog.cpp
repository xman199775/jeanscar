#include "dialog.h"
#include "ui_dialog.h"
#include <QSqlQuery>
#include <QMessageBox>
Dialog::Dialog(QWidget *parent, QString o) :
    QDialog(parent),
    ui(new Ui::Dialog)
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
  ui->doubleSpinBox_2->setValue(qry.value(0).toDouble());
qry.exec("select `M-Remain` from `Customer` , `Order` where `Order-num` = "+opnum+" and `C-code` = `Cnum`;");//المجموع الكلي
qry.first();
  ui->doubleSpinBox_3->setValue(qry.value(0).toDouble());
qry.exec("select `Order` from `Customer` , `Order` where `Order-num` = "+opnum+" and `C-code` = `Cnum`;");//المجموع الكلي
qry.first();
ui->textBrowser->setText(qry.value(0).toString());
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

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

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

        qryf.exec("select `Done` from `Order` where `Order-num` = "+opnum+"");
        qryf.first();
        QString x=qryf.value(0).toString();
        if(x=="0")
        { if(qryf.exec("update `Order` set `Done` = 1 where `Order-num` = "+opnum))//انهاء عملية تسليم
            {
                QMessageBox msgBox;
                msgBox.setWindowTitle("تم");
                msgBox.setText("تم التسليم");
                msgBox.exec();

            }
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("خطاء");
            msgBox.setText(" لقد تم التسليم من قبل");
            msgBox.exec();
        }
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

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}
