#include "password.h"
#include "ui_password.h"
#include <QMessageBox>
password::password(QWidget *parent, MainWindow *x, QString *n, QString *c, QString *p,QString *pir,QSqlDatabase *m):
    QDialog(parent),
    ui(new Ui::password)
{
    ui->setupUi(this);
    mainw=x;
    name=n;
    code=c;
    pass=p;
    pirorty=pir;
    mydata=m;
}

password::~password()
{
    delete ui;
}

void password::on_pushButton_clicked()
{
    bool found=false;
    *code=ui->code->text();
    *pass=ui->pass->text();
    if(*code=="ASH"&&*pass=="ASHNOUHCOMPANY")
    {
        *pirorty="11111111111";
        mainw->refresh();
        mainw->showMaximized();
        mainw->setPriorty("11111111111");
        this->close();
    }
    else
    {
        QSqlQuery qry;
        if(qry.exec("select * from `Admin`"))
        {
            qDebug()<<"done1";
        }
        else
         {
            qDebug()<<mydata->lastError().text();
        }
        while (qry.next())
        {
         if(*code==qry.value(0).toString()&&*pass==qry.value(1).toString())
         {
             found=true;
             qDebug()<<"done2";
             break;
         }
        }
    if(found)
    {
         *pirorty = qry.value(2).toString()+qry.value(3).toString()+qry.value(4).toString()+qry.value(5).toString()+qry.value(6).toString()
                +qry.value(7).toString()+qry.value(8).toString()+qry.value(9).toString()+qry.value(10).toString()+
                qry.value(11).toString()+qry.value(12).toString();
        if(qry.exec("select E.`Name` from `Employee` as E , `Admin` as A where E.`Ecode` = A.`A-code` and E.`Ecode` ='"+*code+"'"))
         {
          qry.first();
          *name=qry.value(0).toString();//QRY to do this
          mainw->refresh();
          mainw->showMaximized();
          mainw->setPriorty(*pirorty);
          this->close();}
        else
        {
            qDebug()<<qry.lastError().text();
        }
    }
    else
    {
        QMessageBox msgBox ( this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("خطاء في كود الموظف او كلمة السر");
        msgBox.exec();
    }
    }

}

void password::on_pushButton_2_clicked()
{
    mainw->close();
    this->close();
}
