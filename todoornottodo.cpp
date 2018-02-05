#include "todoornottodo.h"
#include "ui_todoornottodo.h"
#include <QMessageBox>
todoornottodo::todoornottodo(QString m,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::todoornottodo)
{
    ui->setupUi(this);
    ui->message->setText(m);
}

todoornottodo::~todoornottodo()
{
    delete ui;
}

void todoornottodo::on_doIt_clicked()
{
    switch(Case){
        case 1:{
        QSqlQuery qry;
        bool found=false;
        QSqlQuery qryf;
        qryf.exec("select `Order-num` from `JeansCar`.`Order`");//اكواد عمليات الشراء
        while (qryf.next())
        {
            if(opcode==qryf.value(0).toString())
            {
                found=true;
                break;
            }
        }
        if(found)
        {
            qry.exec("update `Order` set `Bouns` = 1 where `Order-num` = "+opcode+"");
            QMessageBox msgBox ( this);
            msgBox.setWindowTitle("تم");
            msgBox.setText("تم الالغاء");
            msgBox.exec();
        }
        else
        {
            QMessageBox msgBox ( this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText("لا توجد عملية تسليم بهذا الكود");
            msgBox.exec();
        }
            break;}
        case 2:{
        QSqlQuery qry;
        bool found=false;
        QSqlQuery qryf;
        qryf.exec("select `Order-num` from `JeansCar`.`Order`");//اكواد عمليات الشراء
        while (qryf.next())
        {
            if(opcode==qryf.value(0).toString())
            {
                found=true;
                break;
            }
        }
        if(found)
        {
            qry.exec("delete from `Order` where `Order-num` = "+opcode+"");
            QMessageBox msgBox ( this);
            msgBox.setWindowTitle("تم");
            msgBox.setText("تم الحذف");
            msgBox.exec();
        }
        else
        {
            QMessageBox msgBox ( this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText("لا توجد عملية تسليم بهذا الكود");
            msgBox.exec();
        }
            break;}
    case 3:{
        bool found=false;
        QSqlQuery qryf;
        qryf.exec("SELECT * FROM JeansCar.Admin;");//نبحث عن الادمن
        while (qryf.next())
        {
            if(ecode==qryf.value(0).toString())
            {
                found=true;
                break;
            }
        }
        if(found)
        {
            QSqlQuery qry;
            if(qry.exec("delete from `Admin` where `A-code` = '"+ecode+"'"))//هيحذف ادمن
            {
                QMessageBox msgBox ( this);
                msgBox.setWindowTitle("تم");
                msgBox.setText("تم حذف المستخدم بنجاح");
                msgBox.exec();
            }
            else
            {
                QMessageBox msgBox ( this);
                msgBox.setWindowTitle("خطاء");
                msgBox.setText(qry.lastError().text());
                msgBox.exec();

            }
        }
        else
        {
            QMessageBox msgBox ( this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText(" لا يوجد مستخدم بهذا الكود");
            msgBox.exec();
        }
            break;}
    case 4:{
        bool found=false;
        QSqlQuery qryf;
        if(qryf.exec("SELECT Ecode FROM JeansCar.Employee;"))//نبحث عن الموظف
        {
            while (qryf.next())
            {
                if(ecode==qryf.value(0).toString())
                {
                    found=true;
                    break;
                }
            }
            if(found)
            {
                QSqlQuery qry;
                if(qry.exec("delete from `Employee` where `Ecode` = '"+ecode+"'"))//حذف موظف
                {
                    QMessageBox msgBox ( this);
                    msgBox.setWindowTitle("تم");
                    msgBox.setText("تم حذف موظف");
                    msgBox.exec();
                }
                else
                {
                    QMessageBox msgBox ( this);
                    msgBox.setWindowTitle("خطاء");
                    msgBox.setText(qry.lastError().text());
                    msgBox.exec();
                }

            }
            else
            {
                QMessageBox msgBox ( this);
                msgBox.setWindowTitle("خطاء");
                msgBox.setText("هذا الكود غير موجود  الرجاء التاكد من الكود");
                msgBox.exec();
            }
        }
        else
        {                QMessageBox msgBox ( this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText(qryf.lastError().text());
            msgBox.exec();
        }
            break;}
    }
    this->close();
}

void todoornottodo::on_cancel_clicked()
{
    this->close();
}
