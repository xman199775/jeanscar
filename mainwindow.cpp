#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "dialog.h"
#include "dialog1.h"
#include "product.h"
#include <table.h>
#include <choose_employee.h>
//#include <qtrpt.h>
#include <QDir>
#include <settings.h>
MainWindow::MainWindow(QWidget *parent, QString *n, QString *c, QString *pa,QString *pir,QSqlDatabase *m) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    curtime=new QTime;
    curdate=new QDate;
    name=n;
    code=c;
    pass=pa;
    priority_check=pir;
    mydata = m;
    *curtime = QTime::currentTime();
    *curdate=QDate::currentDate();
    timestr = curtime->toString("hh:mm:ss ap");
    datestr =curdate->toString("yyyy-MM-dd");
    ui->clock->setText(timestr);
    ui->date->setText(datestr);
    ui->searchdate->setDate(*curdate);
    ui->adminline->setText(*name);
    ui->admincodeline->setText(*code);
    ui->dealdate->setDate(*curdate);
    ui->delverdatenew->setDate(*curdate);
    ui->salaryReportdate->setDate(*curdate);
    ui->el5smdate->setDate(*curdate);
    ui->increasedate->setDate(*curdate);
    ui->solfadate->setDate(*curdate);
    ui->yearjob->setDate(*curdate);
    ui->dayreportdate->setDate(*curdate);
    ui->salarydate->setDate(*curdate);
    ui->admindate->setDate(*curdate);
    ui->dateEdit->setDate(*curdate);
    ui->dateEdit_2->setDate(*curdate);
    ui->dayreportdate->setDate(*curdate);
    ui->sdate->setDate(*curdate);
    ui->ssdate->setDate(*curdate);
    ui->deldate->setDate(*curdate);
    ui->delevertime->setDate(*curdate);
    ui->dateEdit_3->setDate(*curdate);
    ui->daily_re->setDate(*curdate);

    reportSalary=NULL;
    english = QLocale(QLocale::English, QLocale::UnitedStates);
    pd = new QPrintDialog;
    p = new QPrinter;
    ui->pushButton_39->hide();
    ui->pushButton_41->hide();
    ui->pushButton_42->hide();
    todo = new todoornottodo("");
    print = nullptr;
    a = NULL;
    update_flat_color();
}
void MainWindow::update_flat_color(){
    QSqlQuery qry;
    QString sql;
    sql = "select * from `Flat_colors`;";
    qry.exec(sql);
    ui->flat_color->clear();
    while (qry.next()) {
        ui->flat_color->addItem(qry.value(0).toString());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete curdate;
    delete curtime;
    delete todo;
}

void MainWindow::refresh()
{
    ui->adminline->setText(*name);
    ui->admincodeline->setText(*code);
}

void MainWindow::updatedate()
{
    *curtime = QTime::currentTime();
    *curdate=QDate::currentDate();
    timestr = curtime->toString("hh:mm:ss ap");
    datestr =curdate->toString("dd-MM-yyyy");
    ui->clock->setText(timestr);
    ui->date->setText(datestr);
    ui->dealdate->setDate(*curdate);
}

void MainWindow::on_pushButton_18_clicked()//تسليم2
{
    QString date=english.toString(ui->delverdatenew->date(),"yyyy-MM-dd");
    QSqlQuery qry;
    qry.exec("select `Order-num` , `Car-det` from `Order` where `Delvtime` = '"+date+"'");// هنا التسليمات بتاريخ date واول فترة
    // كود + موديل العربية
    ui->delverlist->clear();
    while (qry.next()) {

        QString x = qry.value(0).toString()+": "+qry.value(1).toString();
        ui->delverlist->addItem(x);
    }
}

void MainWindow::on_pushButton_6_clicked()//اضافة موظف
{
    
    QString id=ui->employeecode->text()
            ,ename=ui->emplyeename->text()
            ,nid=ui->employeeid->text()
            ,state=ui->statuse->text()
            ,phone=ui->phone->text()
            ,homephone=ui->homephone->text()
            ,addressincard=ui->adressinidcard->text()
            ,address=ui->adress->text()
            ,Major=ui->depart->text()
            ,cirt=ui->cirtficate->text()
            ,curjob=ui->currentjob->text()
            ,antherexp=ui->anotherexp->text()
            ,note=ui->notes->text()
            ,birthdate=english.toString(ui->birthday->date(),"yyyy-MM-dd")
            ,cirdate=english.toString(ui->gardudate->date(),"yyyy-MM-dd")
            ,yearofjob=english.toString(ui->yearjob->date(),"yyyy-MM-dd")
            ,arrivetime=english.toString(ui->arrivetime->time(),"hh:mm:ss")
            ,leavetime=english.toString(ui->leavetime->time(),"hh:mm:ss")
            ,salary=QString::number(ui->salary->value())
            ,lastsalary=QString::number(ui->lastsalary->value())
            ,numofhouer=QString::number(ui->numofhour->value())
            ,numofyear=QString::number(ui->numofyearworking->value())
            ,max=QString::number(ui->max->value());
    if(id==""||ename==""||nid==""||phone==""||addressincard==""||birthdate=="")
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("حقول فارغة الرجاء التاكد من ملئ جميع الحقول الزرقاء");
        msgBox.exec();
    }
    else
    {
        char mo2men;
        if(ui->mo2mn3leh->isChecked())
        {
            mo2men='y';
        }
        else
        {
            mo2men='n';
        }
        char week;
        if(ui->weekly->isChecked())
        {
            week='y';
        }
        else
        {
            week='n';
        }
        bool found=false;
        QSqlQuery qryf;
        if(qryf.exec("SELECT Ecode FROM JeansCar.Employee;"))//نبحث عن الموظف
        {
            while (qryf.next())
            {
                if(id==qryf.value(0).toString())
                {
                    found=true;
                    break;
                }
            }
            if(!found)
            {QSqlQuery qry;
                if(qry.exec("INSERT INTO `JeansCar`.`Employee` (`Ecode`, `Name`, `Nation-id`, `Social-status`, `BirthDate`, `Number`, `Add-nid`, `Add-ano`, `Clear-salary`, `Last_salaray`, `Hours`, `Leave-time`, `Arrive-time`, `Major`, `Year_grad`, `Year_of_job`, `Home_Num`, `Certifcate`, `Curr_job`, `N_of_work_in_years`, `Another_exper`, `Insurance`,`Weakly`,`Note`,`Min`) VALUES ('"+id+"', '"+ename+"', '"+nid+"', '"+state+"', '"+birthdate+"', '"+phone+"','"+addressincard+"','"+ address +"','"+salary+"','"+lastsalary+"','"+numofhouer+"','"+leavetime+"','"+arrivetime+"','"+Major+"','"+cirdate+"','"+yearofjob+"','"+homephone+"','"+cirt+"','"+curjob+"', '"+numofyear+"', '"+antherexp+"', '"+mo2men+"','"+week+"','"+note+"',"+max+");"))
                {
                    QMessageBox msgBox (this);
                    msgBox.setWindowTitle("تم ");
                    msgBox.setText(" تم اضافة الموظف بنجاح");
                    msgBox.exec();
                }
                else
                {
                    QMessageBox msgBox (this);
                    msgBox.setWindowTitle("خطاء");
                    msgBox.setText(qry.lastError().text());
                    msgBox.exec();
                }
            }
            else
            {
                QMessageBox msgBox (this);
                msgBox.setWindowTitle("خطاء");
                msgBox.setText("هذا الكود معطي لموظف اخر الرجاء التاكد من الكود");
                msgBox.exec();
            }
        }
        else
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText(qryf.lastError().text());
            msgBox.exec();
        }
    }
}

void MainWindow::on_pushButton_8_clicked()//حذف موظف
{
    QString ecode=ui->deleteecode->text(), mes =(QString) "هل أنت متأكد أنك تريد حذف الموظف  "+(QString)" "+ecode+(QString)" "+(QString)"؟";
    if(todo != NULL)
        todo->close();
    if (ecode == ""){
        QMessageBox mb;
        mb.setWindowTitle("خطأ");
        mb.setText("الرجاء إدخال بيانات للمتابعه");
        mb.exec();
    }else{
        todo = new todoornottodo(mes);
        todo->ecode = ecode;
        todo->Case = 4;
        todo->show();
    }
}

void MainWindow::on_pushButton_23_clicked()//تعديل موظف واظهار تقرير لبياناته الاساسية
{
    bool found=false;
    QSqlQuery qryf;
    if(qryf.exec("SELECT Ecode FROM JeansCar.Employee;"))//نبحث عن الموظف
    { while (qryf.next())
        {
            if(ui->editemplyeecode->text()==qryf.value(0).toString())
            {
                found=true;
                break;
            }
        }
        if(found)
        {
            re=new report(0,ui->editemplyeecode->text());
            re->show();}
        else
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText("هذا الكود غير موجود  الرجاء التاكد من الكود");
            msgBox.exec();
        }
    }
    else
    {   QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText(qryf.lastError().text());
        msgBox.exec();
    }
    
}

void MainWindow::on_pushButton_24_clicked()//تحضير المرتبات
{
    QString date=english.toString(ui->salarydate->date(),"yyyy-MM-dd")
            ,ecode;
    bool found=false;
    QSqlQuery qryf;
    QSqlQuery qry;
    QSqlQuery qryd;
    qryd.exec("select `Date` from `Salary`");
    while (qryd.next())
    {
        if(qryd.value(0).toString()==date)
        {
            found=true;
            break;
        }
    }

    if(!found)
    {
        if(qryf.exec("SELECT Ecode FROM JeansCar.Employee;"))//نبحث عن الموظف
        {
            while (qryf.next())
            {
                ecode=qryf.value(0).toString();
                if(qry.exec("INSERT INTO `JeansCar`.`Salary` (`E-code`, `Date`, `Amount`, `Done`) select '"+ecode+"', '"+date+"', `Clear-salary` , 0 from `Employee` WHERE `Ecode` = '"+ecode+"';"))
                {


                }
                else
                {
                    QMessageBox msgBox (this);
                    msgBox.setWindowTitle("خطاء");
                    msgBox.setText(qry.lastError().text());
                    msgBox.exec();
                    found=true;
                    break;
                }
            }
            if(!found)
            {
                QMessageBox msgBox (this);
                msgBox.setWindowTitle("تم");
                msgBox.setText("تم تحضير المرتب");
                msgBox.exec();
            }
        }

        else
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText(qryf.lastError().text());
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("تم تحضير الشهر من قبل");
        msgBox.exec();
    }
}

void MainWindow::on_pushButton_13_clicked()//اضافة مستخدم
{
    QString ecode=ui->addecode->text()
            ,password=ui->addpassword->text()
            ,password2=ui->addpasswordagian->text();

    if (priority_check == NULL){
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("الرجاء اختيار الصلاحية");
        msgBox.exec();
        return;
    }
    QString a[11];
    for(int i = 0 ; i < 11 ; ++i)
        a[i] = (*priority_check)[i];
    if(ecode==""||password=="")
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("الرجاء ملئ كل الحقول");
        msgBox.exec();

    }
    else
    {
        bool found=false;
        bool found2=false;
        QSqlQuery qryf;
        qryf.exec("SELECT Ecode FROM JeansCar.Employee;");//نبحث عن الموظف
        while (qryf.next())
        {
            if(ecode==qryf.value(0).toString())
            {
                found=true;
                break;
            }
        }
        qryf.exec("SELECT A-code FROM JeansCar.Admin;");//نبحث عن المستخدم
        while (qryf.next())
        {
            if(ecode==qryf.value(0).toString())
            {
                found2=true;
                break;
            }
        }
        if(found2)
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText("هذا المستخدم موجود مسبقا");
            msgBox.exec();
        }
        else
        {
            if(found)
            {
                if(password==password2)
                {
                    QSqlQuery qry;
                    if(qry.exec("INSERT INTO `Admin` (`A-code`, `Pass`, `Add_employee`, `Salary`, `Stock`, `Manager`, `Deliver_salary`, `Custmers`, `Edit_Order`, `Ware`, `Open`, `Accounting`, `Deliver`) VALUES ('"+ecode+"', '"+password+"', '"+a[0]+"', '"+a[1]+"', '"+a[2]+"', '"+a[3]+"', '"+a[4]+"', '"+a[5]+"', '"+a[6]+"', '"+a[7]+"', '"+a[8]+"', '"+a[9]+"', '"+a[10]+"');" ))//هيضيف ادمن
                    {
                        QMessageBox msgBox (this);
                        msgBox.setWindowTitle("تم");
                        msgBox.setText("تم اضافة المستخدم بنجاح");
                        msgBox.exec();
                        priority_check = new QString;
                    }
                    else
                    {
                        QMessageBox msgBox (this);
                        msgBox.setWindowTitle("خطاء");
                        msgBox.setText(qry.lastError().text());
                        msgBox.exec();

                    }
                }
                else
                {
                    QMessageBox msgBox (this);
                    msgBox.setWindowTitle("خطاء");
                    msgBox.setText(" كلمة السر غير متاطبقة");
                    msgBox.exec();
                }
            }
            else
            {
                QMessageBox msgBox (this);
                msgBox.setWindowTitle("خطاء");
                msgBox.setText(" لا يوجد موظف بهذا الكود");
                msgBox.exec();
            }
        }
    }
}

void MainWindow::on_pushButton_14_clicked()//حذف مستخدم
{
    QString ecode=ui->deletecode->text();
    if(todo != NULL)
        todo->close();
    if (ecode == ""){
        QMessageBox mb;
        mb.setWindowTitle("خطأ");
        mb.setText("الرجاء إدخال بيانات للمتابعه");
        mb.exec();
    }else{
        todo = new todoornottodo((QString)"هل أنت متأكد أنك تريد حذف المستخدم"+(QString)" " +ecode+(QString)" "+(QString)"؟");
        todo->Case = 3;
        todo->ecode = ecode;
        todo->show();
    }
}

void MainWindow::on_pushButton_3_clicked() //البحث عن مستخدم محدد
{
    QSqlQueryModel *model1=new QSqlQueryModel;
    QString ecode=ui->reoportusercode->text()
            ,month=english.toString(ui->admindate->date(),"MM")
            ,year=english.toString(ui->admindate->date(),"yyyy");;

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
        model1->setQuery("select `Drag`.`E-code` as 'كود الموظف', `Employee`.`Name` as 'اسم الموظف', `Admin`.`Pass` as 'كلمة السر', `Admin`.`Priorty` as 'الصلاحية', `Drag`.`C-type` as 'كود البضاعة', `Drag`.`C-color` as 'لون البضاعة', `Drag`.`Price` as 'سعر السحب', `Drag`.`Quantity` as 'كمية السحب', `Drag`.`Notes` as 'سبب السحب', `Drag`.`Date` as 'تاريخ السحب' from `Drag` , `Admin` , `Employee` where  `Ecode` = `E-code` and `Ecode` = `A-code` and `Ecode` = '"+ecode+"'  and month(`Date`) = "+month+" and year(`Date`) = "+year+"  ");
        ui->admintable->setModel(model1);
    }
    else
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText(" لا يوجد مستخدم بهذا الكود");
        msgBox.exec();
    }

}

void MainWindow::on_pushButton_12_clicked()//البحث عن كل المستخدمين
{
    QSqlQueryModel *model1=new QSqlQueryModel;
    model1->setQuery("SELECT `Admin`.`A-code` as 'كود المستخدم',`Admin`.`Pass` as 'كلمة السر' , `Admin`.`Add_employee` as 'إضافه موظف', `Admin`.`Salary` as '    الموظفين /الراتب    ',`Admin`.`Stock` as 'مخزن رئيسي',`Admin`.`Manager` as 'مدير النظام',`Admin`.`Deliver_salary` as 'توزيع الرواتب',`Admin`.`Custmers` as 'العملاء',`Admin`.`Edit_Order` as 'تعديل عملية شراء',`Admin`.`Ware` as 'المخزن',`Admin`.`Open` as 'التشغيل',`Admin`.`Accounting` as 'الحسابات',`Admin`.`Deliver` as 'تسليم' FROM JeansCar.Admin;");//تقرير عن المستخدمين
    ui->admintable->setModel(model1);
}

void MainWindow::on_pushButton_20_clicked()//تعديل مستخدم
{
    QString ecode=ui->editecode->text()
            ,password2=ui->newpassword->text();

    char p;
    QString a[11];
    for(int i = 0 ; i < 11 ; ++i)
        a[i] = (*priority_check)[i];
    if(ecode==""||password2=="")
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("الرجاء ملئ كل الحقول");
        msgBox.exec();

    }
    else
    {
        bool found2=false;
        QSqlQuery qryf;
        qryf.exec("SELECT * FROM JeansCar.Admin;");//نبحث عن الموظف
        while (qryf.next())
        {
            if(ecode==qryf.value(0).toString())
            {
                found2=true;
                break;
            }

        }
        if(!found2)
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText("هذا المستخدم غير موجود");
            msgBox.exec();
        }
        else
        {
            if(qryf.exec("update `Admin` set `Pass` = '"+password2+"' ,`Add_employee` = '"+a[0]+"', `Salary` = '"+a[1]+"', `Stock`= '"+a[2]+"', `Manager`= '"+a[3]+"', `Deliver_salary` = '"+a[4]+"', `Custmers` = '"+a[5]+"', `Edit_Order` = '"+a[6]+"', `Ware` = '"+a[7]+"', `Open` = '"+a[8]+"', `Accounting` = '"+a[9]+"', `Deliver` = '"+a[10]+"' where `A-code` = '"+ecode+"'"))//تعديل موظف
            {
                QMessageBox msgBox (this);
                msgBox.setWindowTitle("تم");
                msgBox.setText("تم تعديل بيانات المستخدم");
                msgBox.exec();
            }
            else
            {
                qDebug()<<qryf.lastError().text();
            }
        }
    }
}

void MainWindow::on_pushButton_10_clicked()//خصم
{
    QString ecode = ui->ecode5sm->text()
            ,salary5sm=QString::number(ui->valu5sm->value())
            ,salarystr
            ,date=english.toString(ui->el5smdate->date(),"yyyy-MM-dd")
            ,reason=ui->reson5sm->text()
            ,month=english.toString(ui->el5smdate->date(),"MM")
            ,year=english.toString(ui->el5smdate->date(),"yyyy")
            ,time=english.toString((*curtime),"hh:mm:ss");
    if((ui->valu5sm->value())<0)
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText(" لا يمكن ادخال قيمة سالبة");
        msgBox.exec();
    }
    else
    {

        bool found=false;
        double salary,salary2;
        QSqlQuery qryf;
        qryf.exec("SELECT Ecode FROM JeansCar.Employee;");//نبحث عن الموظف
        while (qryf.next())
        {
            if(ecode==qryf.value(0).toString())
            {
                found=true;
                break;
            }
        }
        if(found)
        { QSqlQuery qryb;
            qryb.exec("select `Done` from `Salary`  where `E-code` = '"+ecode+"'  and year(`Date`) = "+year+" and month(`Date`) = "+month+"");
            qryb.first();
            bool done= qryb.value(0).toBool();
            if(!done)
            {
                QSqlQuery qry;
                if(qry.exec("select `Amount` from `JeansCar`.`Salary` where `E-code` = '"+ecode+"' and month(`Date`) ='"+month+"'and year(`Date`) ='"+year+"'"))//مرتب
                {
                    qry.first();
                    salary=(qry.value(0).toDouble())-(ui->valu5sm->value());
                    qry.exec("select `Min` from Employee where Ecode ='"+ecode+"'");
                    qry.first();
                    salary2=qry.value(0).toDouble();
                    if(salary2<=salary)
                    {
                        salarystr=QString::number(salary);
                        if(qryf.exec("INSERT INTO `Modify-salary` (`A-code`, `E-code`, `Amount`, `Date`,  `Type` ,`Notes`, `New_salary`)VALUES    ('" +*code+"', '"+ecode+"', "+salary5sm+", '"+date+" "+time+"', 'd', '"+reason+"', "+salarystr+");"))
                        {
                            if( qry.exec("update `Salary` set `Amount` ="+salarystr+" where `E-code` = '"+ecode+"'  and month(`Date`) = "+month+" and year(`Date`) = "+year+""))//تعديل المرتب
                            {
                                QMessageBox msgBox (this);
                                msgBox.setWindowTitle("تم");
                                msgBox.setText("تم الخصم ");
                                msgBox.exec();
                            }

                        }
                        else
                        {
                            qDebug()<<qryf.lastError().text();
                        }
                    }
                    else
                    {
                        QMessageBox msgBox (this);
                        msgBox.setWindowTitle("خطاء");
                        msgBox.setText(" عذرا وصل هذا المرتب للحد الادني");
                        msgBox.exec();

                    }
                }

                else
                {
                    QMessageBox msgBox (this);
                    msgBox.setWindowTitle("خطاء");
                    msgBox.setText(" لا يوجد مرتب لهذا الشخص بهذالتاريخ تاكد من تحضير المرتبات");
                    msgBox.exec();
                }

            }
            else
            {
                QMessageBox msgBox (this);
                msgBox.setWindowTitle("خطاء");
                msgBox.setText(" لا يمكن التعديل علي مرتب قد تم صرفه");
                msgBox.exec();
            }
        }

        else
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText(" لا يوجد مستخدم بهذا الكود");
            msgBox.exec();
        }


    }
}

void MainWindow::on_pushButton_7_clicked()//سلفة
{
    QString ecode = ui->ecodesolfa->text()
            ,salarysolfa=QString::number(ui->salarys0lfa->value())
            ,salarystr
            ,lastsalarystr
            ,reason=ui->solfanotes->text()
            ,month=english.toString(ui->solfadate->date(),"MM")
            , date=english.toString(ui->solfadate->date(),"yyyy-MM-dd")
            ,year=english.toString(ui->solfadate->date(),"yyyy")
            ,time=english.toString((*curtime),"hh:mm:ss");
    bool found=false;
    double salary,salary2;

    if((ui->salarys0lfa->value())<0)
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText(" لا يمكن ادخال قيمة سالبة");
        msgBox.exec();
    }
    else
    {
        QSqlQuery qryf;
        qryf.exec("select `Ecode`from `Employee`");//نبحث عن الموظف
        while (qryf.next())
        {
            if(ecode==qryf.value(0).toString())
            {
                found=true;
                break;
            }
        }


        if(found)
        {  QSqlQuery qryb;
            qryb.exec("select `Done` from `Salary`  where `E-code` = '"+ecode+"'  and year(`Date`) = "+year+" and month(`Date`) = "+month+"");
            qryb.first();
            bool done= qryb.value(0).toBool();
            if(!done)
            {
                QSqlQuery qry;
                qry.exec("select `Amount` from `JeansCar`.`Salary` where `E-code` = '"+ecode+"' and month(`Date`) ='"+month+"'and year(`Date`) ='"+year+"'");//مرتب
                qry.first();
                salary=(qry.value(0).toDouble())-(ui->salarys0lfa->value());
                qry.exec("select `Min` from Employee where Ecode ='"+ecode+"'");
                qry.first();
                salary2=qry.value(0).toDouble();
                if(salary2<=salary)
                {
                    salarystr=QString::number(salary);
                    if(  qry.exec("INSERT INTO `Modify-salary` (`A-code`, `E-code`, `Amount`, `Date`, `Type`,`Notes`,  `New_salary`)VALUES('" +*code+"', '"+ecode+"', "+salarysolfa+", '"+date+" "+time+"', 's', '"+reason+"', "+salarystr+");"))
                    {
                        if(qry.exec("update `Salary` set `Amount` ="+salarystr+" where `E-code` = '"+ecode+"'  and month(`Date`) = "+month+" and year(`Date`) = "+year+""))//تعديل المرتب
                        {

                            QMessageBox msgBox (this);
                            msgBox.setWindowTitle("تم");
                            msgBox.setText("تم خصم السلفة");
                            msgBox.exec();

                        }
                    }

                    else
                    {
                        qDebug()<<qry.lastError().text();
                    }
                }
                else
                {
                    QMessageBox msgBox (this);
                    msgBox.setWindowTitle("خطاء");
                    msgBox.setText(" عذرا لقد وصل المترب للحد الادني");
                    msgBox.exec();
                }
            }
            else
            {
                QMessageBox msgBox (this);
                msgBox.setWindowTitle("خطاء");
                msgBox.setText(" لا يمكن التعديل علي مرتب قد تم صرفه");
                msgBox.exec();
            }
        }
        else
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText(" لا يوجد مستخدم بهذا الكود");
            msgBox.exec();
        }



    }
}

void MainWindow::on_salarys0lfa_editingFinished()//سلفة 1
{
    QString ecode = ui->ecodesolfa->text()
            ,salarysolfa=QString::number(ui->salarys0lfa->value())
            ,salarystr
            ,lastsalarystr
            ,reason=ui->solfanotes->text()
            ,month=english.toString(ui->solfadate->date(),"MM")
            , date=english.toString(ui->solfadate->date(),"yyyy-MM-dd")
            ,year=english.toString(ui->solfadate->date(),"yyyy");
    bool found=false;
    double salary;
    double lastsalary=0;
    if((ui->salarys0lfa->value())<0)
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText(" لا يمكن ادخال قيمة سالبة");
        msgBox.exec();
    }
    else
    {
        QSqlQuery qryf;
        qryf.exec("select `Ecode`from `Employee`");//نبحث عن الموظف
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
            qry.exec("select `Amount` from `JeansCar`.`Salary` where `E-code` = '"+ecode+"' and month(`Date`) ='"+month+"'and year(`Date`) ='"+year+"'");//مرتب
            qry.first();
            salary=(qry.value(0).toDouble())-(ui->salarys0lfa->value());
            lastsalary+=ui->salarys0lfa->value();
            salarystr=QString::number(salary);
            lastsalarystr=QString::number(lastsalary);
            qry.exec("select sum(`Amount`) , count(`E-code`) from `Modify-salary` where `E-code` = '"+ecode+"' and `Type` = 's' and month(`Date`) = "+month+" and year(`Date`) = "+year+" ");

            qry.first();
            ui->allsolfa->setValue(qry.value(0).toDouble());
        }


    }
}

void MainWindow::on_ecodesolfa_editingFinished()//سلفة2
{
    QString ecode = ui->ecodesolfa->text()
            ,salarysolfa=QString::number(ui->salarys0lfa->value())
            ,salarystr
            ,lastsalarystr
            ,reason=ui->solfanotes->text()
            ,month=english.toString(ui->solfadate->date(),"MM")
            , date=english.toString(ui->solfadate->date(),"yyyy-MM-dd")
            ,year=english.toString(ui->solfadate->date(),"yyyy");
    bool found=false;
    double salary;
    double lastsalary=0;
    if((ui->salarys0lfa->value())<0)
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText(" لا يمكن ادخال قيمة سالبة");
        msgBox.exec();
    }
    else
    {
        QSqlQuery qryf;
        qryf.exec("select `Ecode`from `Employee`");//نبحث عن الموظف
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
            qry.exec("select `Amount` from `JeansCar`.`Salary` where `E-code` = '"+ecode+"' and month(`Date`) ='"+month+"'and year(`Date`) ='"+year+"'");//مرتب
            qry.first();
            salary=(qry.value(0).toDouble())-(ui->salarys0lfa->value());
            //ui->salary2->setValue(salary);
            lastsalary+=ui->salarys0lfa->value();
            salarystr=QString::number(salary);
            lastsalarystr=QString::number(lastsalary);
            qry.exec("select sum(`Amount`) , count(`E-code`) from `Modify-salary` where `E-code` = '"+ecode+"' and `Type` = 's' and month(`Date`) = "+month+" and year(`Date`) = "+year+" ");

            qry.first();
            ui->allsolfa->setValue(qry.value(0).toDouble());
        }


    }
}

void MainWindow::on_solfadate_editingFinished()//سلفة3
{
    QString ecode = ui->ecodesolfa->text()
            ,salarysolfa=QString::number(ui->salarys0lfa->value())
            ,salarystr
            ,lastsalarystr
            ,reason=ui->solfanotes->text()
            ,month=english.toString(ui->solfadate->date(),"MM")
            , date=english.toString(ui->solfadate->date(),"yyyy-MM-dd")
            ,year=english.toString(ui->solfadate->date(),"yyyy");
    bool found=false;
    double salary;
    double lastsalary=0;
    if((ui->salarys0lfa->value())<0)
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText(" لا يمكن ادخال قيمة سالبة");
        msgBox.exec();
    }
    else
    {
        QSqlQuery qryf;
        qryf.exec("select `Ecode`from `Employee`");//نبحث عن الموظف
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
            qry.exec("select `Amount` from `JeansCar`.`Salary` where `E-code` = '"+ecode+"' and month(`Date`) ='"+month+"'and year(`Date`) ='"+year+"'");//مرتب
            qry.first();
            salary=(qry.value(0).toDouble())-(ui->salarys0lfa->value());
            //ui->salary2->setValue(salary);
            lastsalary+=ui->salarys0lfa->value();
            salarystr=QString::number(salary);
            lastsalarystr=QString::number(lastsalary);
            qry.exec("select sum(`Amount`) , count(`E-code`) from `Modify-salary` where `E-code` = '"+ecode+"' and `Type` = 's' and month(`Date`) = "+month+" and year(`Date`) = "+year+" ");

            qry.first();
            ui->allsolfa->setValue(qry.value(0).toDouble());
        }


    }
}

void MainWindow::on_pushButton_9_clicked()//زيادة
{
    QString ecode=ui->increasecode->text(),
            increasesalary=QString::number(ui->increasevalue->value())
            ,salarystr
            ,reason=ui->notes->text()
            ,month=english.toString(ui->increasedate->date(),"MM")
            ,date=english.toString(ui->increasedate->date(),"yyyy-MM-dd")
            ,year=english.toString(ui->increasedate->date(),"yyyy")
            ,time=english.toString((*curtime),"hh:mm:ss");
    if((ui->increasevalue->value())<0)
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText(" لا يمكن ادخال قيمة سالبة");
        msgBox.exec();
    }
    else
    {
        bool found=false;
        double salary;
        QSqlQuery qryf;
        qryf.exec("SELECT Ecode FROM JeansCar.Employee;");//نبحث عن الموظف
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
            QSqlQuery qryb;
            qryb.exec("select `Done` from `Salary`  where `E-code` = '"+ecode+"'  and year(`Date`) = "+year+" and month(`Date`) = "+month+"");
            qryb.first();
            bool done= qryb.value(0).toBool();
            if(!done)
            {
                QSqlQuery qry;
                qry.exec("select `Amount` from `JeansCar`.`Salary` where `E-code` = '"+ecode+"' and month(`Date`) ='"+month+"'and year(`Date`) ='"+year+"'");//مرتب
                qry.first();
                salary=(qry.value(0).toDouble())+(ui->increasevalue->value());
                ui->salary->setValue(salary);
                salarystr=QString::number(salary);
                if(qry.exec("INSERT INTO `Modify-salary` (`A-code`, `E-code`, `Amount`, `Date`, `Type`,`Notes`,  `New_salary`)VALUES('"+*code+"', '"+ecode+"', "+increasesalary+", '"+date+" "+time+"', 'z', '"+reason+"', "+salarystr+");"))//تسجيل زيادة
                {
                    if(qry.exec("update `Salary` set `Amount` ="+salarystr+" where `E-code` = '"+ecode+"'  and month(`Date`) = "+month+" and year(`Date`) = "+year+""))//تعديل المرتب
                    {
                        QMessageBox msgBox (this);
                        msgBox.setWindowTitle("تم");
                        msgBox.setText("تم الزيادة ");
                        msgBox.exec();

                    }
                    else
                    {
                        QMessageBox msgBox (this);
                        msgBox.setWindowTitle("خطاء");
                        msgBox.setText(qry.lastError().text());
                        msgBox.exec();
                    }
                }
                else
                {
                    QMessageBox msgBox (this);
                    msgBox.setWindowTitle("خطاء");
                    msgBox.setText(qry.lastError().text());
                    msgBox.exec();
                }

            }    else
            {
                QMessageBox msgBox (this);
                msgBox.setWindowTitle("خطاء");
                msgBox.setText(" لا يمكن التعديل علي مرتب قد تم صرفه");
                msgBox.exec();
            }
        }
        else
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText(" لا يوجد مستخدم بهذا الكود");
            msgBox.exec();
        }
    }
}

void MainWindow::on_pushButton_11_clicked()//ملاحظات يومية
{
    QString ecode=ui->employeecodea7wal->text()
            ,numofhour=QString::number(ui->numofhourlate->value())
            ,prdouce=QString::number(ui->prouduce->value())
            ,month=english.toString(ui->dayreportdate->date(),"MM")
            ,date=english.toString(ui->dayreportdate->date(),"yyyy-MM-dd")
            ,year=english.toString(ui->dayreportdate->date(),"yyyy")
            ,time=english.toString((*curtime),"hh:mm:ss")
            ,note=ui->daleynote->text()
            ,salarystr;
    bool found=false;
    double salary,newsalary;
    QSqlQuery qryf;
    qryf.exec("SELECT Ecode FROM JeansCar.Employee;");//نبحث عن الموظف
    while (qryf.next())
    {
        if(ecode==qryf.value(0).toString())
        {
            found=true;
            break;
        }
    }
    if(found)
    {if(ui->prouduce->value()!=0)
        {
            if(qryf.exec("INSERT INTO `Produce` (`A-code`, `E-code`, `Amount`, `Date`) VALUES ('"+*code+"', '"+ecode+"',  "+prdouce+" , '"+date+" "+time+"');"))//انتاج
            {

            }
            else
            {
                found=false;
            }
        }
        if(ui->numofhourlate->value()!=0)
        {
            if(qryf.exec("INSERT INTO `Delay-time` (`E-code`, `Amount`, `Date`) VALUES ('"+ecode+"', "+numofhour+" , '"+date+" "+time+"');"))// تأخير
            {

            }
            else
            {
                found=false;
            }


        }
        if(note!="")
        {
            if(qryf.exec("INSERT INTO `Note` (`A-code`, `E-code`, `Date`, `Notes`) VALUES('"+*code+"', '"+ecode+"', '"+date+" "+time+"', '"+note+"');"))//ملاحظات
            {

            }
            else
            {
                found=false;
            }
        }
        if(ui->attends->isChecked())
        {
            if(qryf.exec("INSERT INTO `Attendence` (`E-code`, `Date`) VALUES ('"+ecode+"', '"+date+"');")) // تحضير ولا خليها في الاخر
            {
                qryf.exec("select `Clear-salary` from `Employee` where `Ecode` = '"+ecode+"'");
                qryf.first();
                salary=qryf.value(0).toDouble();
                salary=(salary/30);
                qryf.exec("select `Amount` from `Salary` where `E-code` = '"+ecode+"' and month(`Date`) = "+month+" and year(`Date`) = "+year+"");
                qryf.first();
                newsalary=(qryf.value(0).toDouble()-salary);
                qryf.exec("update `Salary` set `Amount` = "+QString::number(newsalary)+" where `E-code` = '"+ecode+"' and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Done` = 0");
                qryf.exec("INSERT INTO `Modify-salary` (`A-code`, `E-code`, `Amount`, `Date`, `Notes`, `Type`, `New_salary`)VALUES('"+*code+"', '"+ecode+"', "+QString::number(salary)+", '"+date+" "+"time'"+", 'غياب ', 'a', "+QString::number(newsalary)+");");
            }
            else
            {
                found=false;
            }
        }
        if(!found)
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText("لقد قمت بادخال هذا من قبل");
            msgBox.exec();

        }
        else
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("تم");
            msgBox.setText("تم بنجاح");
            msgBox.exec();
        }

    }
    else
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText(" لا يوجد مستخدم بهذا الكود");
        msgBox.exec();
    }

}

void MainWindow::on_price1_editingFinished()//عملية شراء1
{
    double price=ui->price1->value()+ui->price2->value()+ui->price3->value();
    ui->totalprice->setValue(price);
}

void MainWindow::on_price2_editingFinished()//عملية شراء2
{
    double price=ui->price1->value()+ui->price2->value()+ui->price3->value();
    ui->totalprice->setValue(price);
}

void MainWindow::on_price3_editingFinished()//عملية شراء3
{
    double price=ui->price1->value()+ui->price2->value()+ui->price3->value();
    ui->totalprice->setValue(price);
}

void MainWindow::on_recived_editingFinished()//عملية شراء4
{
    double price=ui->price1->value()+ui->price2->value()+ui->price3->value()
            ,pay=ui->recived->value();
    ui->remain->setValue((price-pay));
    ui->totalprice->setValue(price);
}

void MainWindow::on_pushButton_2_clicked()//اضافة عميل
{
    QString customername=ui->customername->text()
            ,customerphone=ui->customerphone->text()
            ,customerid;
    QSqlQueryModel *model1=new QSqlQueryModel;
    bool found = false;
    QSqlQuery qry;
    qry.exec("select `Number` from `JeansCar`.`Customer`");//هاتلي كل ارقام التليفون المتسجلة
    while(qry.next())
    {
        if(customerphone==qry.value(0).toString())
        {
            found=true;
        }
    }

    if(!found)
    {
        if(qry.exec("INSERT INTO `Customer` (`Name`,`Number`)VALUES('"+customername+"', '"+customerphone+"');"))//اضافة عميل
        {
            qry.exec("select `Cnum` from `JeansCar`.`Customer` where `Number` = '"+customerphone+"'");//هات الكودالرقم تيلفونه فوق
            qry.first();
            customerid=qry.value(0).toString();
            ui->customercode->setText(customerid);
            model1->setQuery("select `Order`.`Order-num` as 'كود العملية',`Order`.`A-code` as 'كود المستخدم',`Order`.`C-code` as 'كود العميل', `Order`.`Car-det` as 'تفاصيل السيارة',`Order`.`Total-price` as 'السعر الكلي' ,`Order`.`M-Pay` as 'دفع' , `Order`.`M-Remain` as 'المتبقي' ,`Order`.`Order-time` as 'وقت الطلب', `Order`.`Delvtime` as 'وقت التسليم',`Order`.`Order` as 'الطلب /السعر مفصل',`Order`.`Done` as 'تم التسليم',`Order`.`Bouns` as 'اضافية',`Customer`.`Cnum` as 'كودالعميل', `Customer`.`Name` as 'اسم العميل',`Customer`.`Number` as 'رقم الهاتف'  from `JeansCar`.`Customer` , `JeansCar`.`Order` where `Cnum` = `C-code` and `Cnum` = '"+customerid+"'");//تقريركامل تماما عنه
            ui->customertable->setModel(model1);
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("تم");
            msgBox.setText("تم اضافة عميل  بنجاح");
            msgBox.exec();
        }
        else
        {

        }

    }
    else          //العميل موجود مسبقا
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("تكرار زيارة");
        msgBox.setText("هذا العميل قام بزيارتنا مسبقا");
        msgBox.exec();
        qry.exec("select `Name` from `JeansCar`.`Customer` where `Number` = '"+customerphone+"'");//الاسم
        qry.first();
        customername=qry.value(0).toString();
        ui->customername->setText(customername);
        qry.exec("select `Cnum` from `JeansCar`.`Customer` where `Number` = '"+customerphone+"'");//هات الكودالرقم تيلفونه فوق
        qry.first();
        customerid=qry.value(0).toString();
        ui->customercode->setText(customerid);
        model1->setQuery("select `Order`.`Order-num` as 'كود العملية',`Order`.`A-code` as 'كود المستخدم',`Order`.`C-code` as 'كود العميل', `Order`.`Car-det` as 'تفاصيل السيارة',`Order`.`Total-price` as 'السعر الكلي' ,`Order`.`M-Pay` as 'دفع' , `Order`.`M-Remain` as 'المتبقي' ,`Order`.`Order-time` as 'وقت الطلب', `Order`.`Delvtime` as 'وقت التسليم',`Order`.`Order` as 'الطلب /السعر مفصل',`Order`.`Done` as 'تم التسليم',`Order`.`Bouns` as 'اضافية',`Customer`.`Cnum` as 'كودالعميل', `Customer`.`Name` as 'اسم العميل',`Customer`.`Number` as 'رقم الهاتف'  from `JeansCar`.`Customer` , `JeansCar`.`Order` where `Cnum` = `C-code` and `Cnum` = '"+customerid+"'");//تقريركامل تماما عنه
        ui->customertable->setModel(model1);

    }
    qry.exec("select max(`Order-num`) from `Order`");
    qry.first();
    ui->opreationcode->setText(QString::number(qry.value(0).toInt()+1));

}

void MainWindow::on_pushButton_17_clicked()//بحث التاريخ
{
    int x=ui->searchdate->date().dayOfWeek()-1;
    if(x==6)
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("يوم الاحد اجازة");
        msgBox.exec();

    }
    else
    {
        table *t = new table(0, ui->searchdate->date());
        t->show();
    }
}

void MainWindow::on_pushButton_clicked()//اضافه عملية شراء
{
    QMessageBox::StandardButton x;
    x=QMessageBox::question(this,"اضافة العملية","سيتم اضافة العملية",QMessageBox::Ok|QMessageBox::Cancel);
    if(x==QMessageBox::Ok)
    {
        double price=ui->price1->value()+ui->price2->value()+ui->price3->value()
                ,pay=ui->recived->value();
        ui->remain->setValue((price-pay));
        ui->totalprice->setValue(price);
        QString opcode=ui->opreationcode->text()
                ,customerid=ui->customercode->text()
                ,dealdate=english.toString(ui->dealdate->date(),"yyyy-MM-dd")
                ,deleverdate=english.toString(ui->delevertime->date(),"yyyy-MM-dd")
                ,carmodel=ui->carmodel->text()+ui->cartype->text()
                ,order=ui->order1->text()+"   "+ui->order2->text()+"   "+ui->order3->text()+"  الخيط :"+ui->el5edtype->text()+"   اللون : "+ui->el5edcolor->text()
                ,stamp=ui->stamp->text()
                ,totalstr,recievedstr,remainstr
                ,time,
                flat = QString::number(ui->flat->isChecked()),
                wheel = QString::number(ui->wheel->isChecked()),
                flat_color = ui->flat_color->currentText();
        double  total=ui->totalprice->value()
                ,recieved=ui->recived->value()
                ,remain=ui->remain->value();
        totalstr = QString::number(total);
        recievedstr=QString::number(recieved);
        remainstr=QString::number(remain);
        QSqlQuery qry;
        bool ok=true;
        int x=ui->dealdate->date().dayOfWeek()-1;
        qry.exec("select sum(`flat`), sum(`wheel`)from `Order`where `Delvtime` = '"+deleverdate+"';");
        qry.first();
        int flats = qry.value(0).toInt(), wheels = qry.value(1).toInt();
        qry.exec("select `Flats`, `Wheels` from `Settings`;");
        qry.first();
        int nFlats = qry.value(0).toInt(), nWheels = qry.value(1).toInt();
        if(flat == "0")
            flat_color = "لا يوجد";
        if(x==6)
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText("يوم الاحد اجازة");
            msgBox.exec();

        }
        else if (flats == nFlats && flat == "1"){
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطأ");
            msgBox.setText("هذا اليوم عدد الدواسات فيه ممتلئ");
            msgBox.exec();
        }
        else if (wheels == nWheels && wheel == "1") {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطأ");
            msgBox.setText("هذا اليوم عدد الطارات فيه ممتلئ");
            msgBox.exec();
        }
        else
        {
            if(ui->comboBox->currentText()=="5:11")
            {
                time="a";
                if(qry.exec("select `H11`,`H11a`,`H11b` , `H11c` , `H11d` , `H11e` from `Sec` where `Date` = '"+deleverdate+"'"))
                {
                    qry.first();
                    if(qry.value(0).toInt() != 0 && qry.value(1).toInt() != 0 && qry.value(2).toInt()!= 0 && qry.value(3).toInt() != 0 && qry.value(4).toInt() != 0 && qry.value(5).toInt()!= 0)
                    {
                        ok=false;
                    }

                }
                else
                {
                    ok=false;
                }
            }
            else if(ui->comboBox->currentText()=="8:2")
            {
                time="b";
                if(qry.exec("select `H2`,`H2a`,`H2b` , `H2c` , `H2d` , `H2e` from `Sec` where `Date` = '"+deleverdate+"'"))
                {
                    qry.first();
                    if(qry.value(0).toInt() != 0 && qry.value(1).toInt() != 0 && qry.value(2).toInt()!= 0 && qry.value(3).toInt() != 0 && qry.value(4).toInt() != 0 && qry.value(5).toInt()!= 0)
                    {
                        ok=false;
                    }

                }
                else
                {
                    ok=false;
                }
            }
            else if(ui->comboBox->currentText()=="11:5")
            {
                time="c";
                if(qry.exec("select `H5`,`H5a`,`H5b` ,`H5c` ,`H5d` , `H5e` from `Sec` where `Date` = '"+deleverdate+"'"))
                {
                    qry.first();
                    if(qry.value(0).toInt() != 0 && qry.value(1).toInt() != 0 && qry.value(2).toInt()!= 0 && qry.value(3).toInt() != 0 && qry.value(4).toInt() != 0 && qry.value(5).toInt()!= 0)
                    {
                        ok=false;
                    }

                }
                else
                {
                    ok=false;
                }
            }

            if(ok)
            {
                if(qry.exec("INSERT INTO `Order` ( `A-code`, `C-code`, `Car-det`, `Total-price`, `M-Pay`, `M-Remain`, `Order-time`, `Delvtime`, `Order`, `Done`,`time`,`stamp`, `flat`, `wheel`, `flat_color`, `Warn`)VALUES( '"+*code+"', '"+customerid+"', '"+carmodel+"', '"+totalstr+"' , '"+recievedstr+"', '"+remainstr+"', '"+dealdate+"', '"+deleverdate+"',  '"+order+"', 0 ,'"+time+"','"+stamp+"', '"+flat+"', '"+wheel+"', '"+flat_color+"', "+QString::number(ui->warin->value())+");"))//ضيف عملية شراء
                {
                    if(ui->comboBox->currentText()=="5:11")
                    {
                        if(qry.exec("select `H11`,`H11a`,`H11b` , `H11c` , `H11d` , `H11e` from `Sec` where `Date` = '"+deleverdate+"'"))
                        {
                            qry.first();
                            if(qry.value(0).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H11`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H11` = "+opcode+" ;");
                            }
                            else if(qry.value(1).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H11a`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H11a` = "+opcode+" ;");
                            }
                            else if(qry.value(2).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H11b`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H11b` = "+opcode+" ;");
                            }
                            else if(qry.value(3).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H11c`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H11c` = "+opcode+" ;");
                            }
                            else if(qry.value(4).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H11d`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H11d` = "+opcode+" ;");
                            }
                            else if(qry.value(5).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H11e`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H11e` = "+opcode+" ;");
                            }
                        }


                    }
                    else if(ui->comboBox->currentText()=="8:2")
                    {
                        if(qry.exec("select `H2`,`H2a`,`H2b` , `H2c` , `H2d` , `H2e` from `Sec` where `Date` = '"+deleverdate+"'"))
                        {
                            qry.first();
                            if(qry.value(0).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H2`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H2` = "+opcode+" ;");
                            }
                            else if(qry.value(1).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H2a`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H2a` = "+opcode+" ;");
                            }
                            else if(qry.value(2).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H2b`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H2b` = "+opcode+" ;");
                            }
                            else if(qry.value(3).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H2c`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H2c` = "+opcode+" ;");
                            }
                            else if(qry.value(4).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H2d`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H2d` = "+opcode+" ;");
                            }
                            else if(qry.value(5).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H2e`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H2e` = "+opcode+" ;");
                            }
                        }
                    }
                    else if(ui->comboBox->currentText()=="11:5")
                    {
                        if(qry.exec("select `H5`,`H5a`,`H5b` ,`H5c` ,`H5d` , `H5e` from `Sec` where `Date` = '"+deleverdate+"'"))
                        {
                            qry.first();
                            if(qry.value(0).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H5`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H5` = "+opcode+" ;");
                            }
                            else if(qry.value(1).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H5a`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H5a` = "+opcode+" ;");
                            }
                            else if(qry.value(2).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H5b`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H5b` = "+opcode+" ;");
                            }
                            else if(qry.value(3).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H5c`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H5c` = "+opcode+" ;");
                            }
                            else if(qry.value(4).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H5d`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H5d` = "+opcode+" ;");
                            }
                            else if(qry.value(5).toInt()==0)
                            {
                                qry.exec("insert into `Sec` (`Date` , `H5e`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H5e` = "+opcode+" ;");
                            }
                        }
                    }
                    ui->customercode->setText("");
                    ui->customername->setText("");
                    ui->customerphone->setText("");
                    ui->opreationcode->setText("");
                    ui->cartype->setText("");
                    ui->carmodel->setText("");
                    ui->stamp->setText("");
                    ui->order1->setText("");
                    ui->order2->setText("");
                    ui->order3->setText("");
                    ui->price1->setValue(0);
                    ui->price2->setValue(0);
                    ui->price3->setValue(0);
                    ui->el5edcolor->setText("");
                    ui->el5edtype->setText("");
                    ui->recived->setValue(0);
                    ui->remain->setValue(0);
                    ui->totalprice->setValue(0);
                    ui->flat->setCheckState(Qt::CheckState::Unchecked);
                    ui->wheel->setCheckState(Qt::CheckState::Unchecked);

                    QMessageBox::StandardButton y;
                    y = QMessageBox::question(this, "طباعة العملية" , "هل تريد طباعة هذه العملية ؟" , QMessageBox::Ok|QMessageBox::Cancel);
                    if (y == QMessageBox::Ok){
                        if (print != nullptr)
                            delete print;
                        print = new Print(generate_html_op(opcode));
                        print->show();
                    }
                    QMessageBox msgBox (this);
                    msgBox.setWindowTitle("تم");
                    msgBox.setText("تم حفظ العملية بنجاح ");
                    msgBox.exec();
                }
                else
                {
                    qDebug()<<qry.lastError().text();
                }
                qry.exec("select max(`Order-num`) from `Order`");
                qry.first();
                ui->opreationcode->setText(QString::number(qry.value(0).toInt()+1));
            }
            else
            {
                QMessageBox msgBox (this);
                msgBox.setWindowTitle("خطاء");
                msgBox.setText("هذا الوقت ممتلئ");
                msgBox.exec();
            }    }
    }
}
void MainWindow::on_pushButton_15_clicked()//بحث عملية تسليم
{
    QSqlQueryModel *model1=new QSqlQueryModel;
    QString opcode=ui->delevercode->text()
            ,customercode=ui->delevercustomer->text()
            ,customename=ui->delevercustomername->text()
            ,customerphone=ui->delevercustomerphone->text();

    if(opcode!="")
    {
        model1->setQuery("select `Order`.`Order-num` as 'كود العملية',`Order`.`A-code` as 'كود المستخدم',`Order`.`C-code` as 'كود العميل', `Order`.`Car-det` as 'تفاصيل السيارة',`Order`.`Total-price` as 'السعر الكلي' ,`Order`.`M-Pay` as 'دفع' , `Order`.`M-Remain` as 'المتبقي' ,`Order`.`Order-time` as 'وقت الطلب', `Order`.`Delvtime` as 'وقت التسليم',`Order`.`Order` as 'الطلب /السعر مفصل',`Order`.`Done` as 'تم التسليم',`Order`.`Bouns` as 'اضافية',`Customer`.`Cnum` as 'كودالعميل', `Customer`.`Name` as 'اسم العميل',`Customer`.`Number` as 'رقم الهاتف',`Order`.`flat` as 'دواسة' , `wheel` as 'طارة' , `flat_color` as 'لون الدواسة' , `Warn` as 'الضمان' from `Customer` ,`Order` where `Order-num` =  "+opcode+" and `C-code` = `Cnum`");//معلومات كاملة عن عملية الشراء
        ui->delevertable->setModel(model1);
    }
    else if(customerphone!="")
    {
        model1->setQuery("select `Order`.`Order-num` as 'كود العملية',`Order`.`A-code` as 'كود المستخدم',`Order`.`C-code` as 'كود العميل', `Order`.`Car-det` as 'تفاصيل السيارة',`Order`.`Total-price` as 'السعر الكلي' ,`Order`.`M-Pay` as 'دفع' , `Order`.`M-Remain` as 'المتبقي' ,`Order`.`Order-time` as 'وقت الطلب', `Order`.`Delvtime` as 'وقت التسليم',`Order`.`Order` as 'الطلب /السعر مفصل',`Order`.`Done` as 'تم التسليم',`Order`.`Bouns` as 'اضافية',`Customer`.`Cnum` as 'كودالعميل', `Customer`.`Name` as 'اسم العميل',`Customer`.`Number` as 'رقم الهاتف',`Order`.`flat` as 'دواسة' , `wheel` as 'طارة' , `flat_color` as 'لون الدواسة' , `Warn` as 'الضمان'   from `Customer` , `Order` where `Number` = '"+customerphone+"' and `C-code` = `Cnum`");//معلومات كاملة عن عملية الشراء
        ui->delevertable->setModel(model1);
    }
    else if(customename!="")
    {
        model1->setQuery("select `Order`.`Order-num` as 'كود العملية',`Order`.`A-code` as 'كود المستخدم',`Order`.`C-code` as 'كود العميل', `Order`.`Car-det` as 'تفاصيل السيارة',`Order`.`Total-price` as 'السعر الكلي' ,`Order`.`M-Pay` as 'دفع' , `Order`.`M-Remain` as 'المتبقي' ,`Order`.`Order-time` as 'وقت الطلب', `Order`.`Delvtime` as 'وقت التسليم',`Order`.`Order` as 'الطلب /السعر مفصل',`Order`.`Done` as 'تم التسليم',`Order`.`Bouns` as 'اضافية',`Customer`.`Cnum` as 'كودالعميل', `Customer`.`Name` as 'اسم العميل',`Customer`.`Number` as 'رقم الهاتف',`Order`.`flat` as 'دواسة' , `wheel` as 'طارة' , `flat_color` as 'لون الدواسة' , `Warn` as 'الضمان'   from `Customer` , `Order` where `Name` like '%"+customename+"%' and `C-code` = `Cnum` ");//معلومات كاملة عن عملية الشراء
        ui->delevertable->setModel(model1);
    }
    else if(customercode!="")
    {
        model1->setQuery("select `Order`.`Order-num` as 'كود العملية',`Order`.`A-code` as 'كود المستخدم',`Order`.`C-code` as 'كود العميل', `Order`.`Car-det` as 'تفاصيل السيارة',`Order`.`Total-price` as 'السعر الكلي' ,`Order`.`M-Pay` as 'دفع' , `Order`.`M-Remain` as 'المتبقي' ,`Order`.`Order-time` as 'وقت الطلب', `Order`.`Delvtime` as 'وقت التسليم',`Order`.`Order` as 'الطلب /السعر مفصل',`Order`.`Done` as 'تم التسليم',`Order`.`Bouns` as 'اضافية',`Customer`.`Cnum` as 'كودالعميل', `Customer`.`Name` as 'اسم العميل',`Customer`.`Number` as 'رقم الهاتف',`Order`.`flat` as 'دواسة' , `wheel` as 'طارة' , `flat_color` as 'لون الدواسة' , `Warn` as 'الضمان'   from `Customer` , `Order` where `Cnum` = '"+customercode+"' and `Cnum` = `C-code`  ");//معلومات كاملة عن عملية الشراء
        ui->delevertable->setModel(model1);

    }

}

void MainWindow::on_pushButton_16_clicked()//انهاء عملية تسليم
{
    QString opcode=ui->delevercode1->text();
    Dialog *f=new Dialog(0,opcode);
    f->show();

}

void MainWindow::on_pushButton_25_clicked()//حذف عملية تسليم
{

    QString opcode=ui->deleteopcode->text();
    if(todo != NULL)
        todo->close();
    if (opcode == ""){
        QMessageBox mb;
        mb.setWindowTitle("خطأ");
        mb.setText("الرجاء إدخال بيانات للمتابعه");
        mb.exec();
    }else{
        todo = new todoornottodo((QString)"هل أنت متأكد أنك تريد حذف عملية رقم "+(QString)" "+opcode+(QString)" "+(QString)"؟");
        todo->Case = 2;
        todo->opcode = opcode;
        todo->show();
    }
}

void MainWindow::on_pushButton_19_clicked()//الغاءعملية تسليم
{
    QString opcode = ui->deleteopcode->text();
    if(todo != NULL)
        todo->close();
    if (opcode == ""){
        QMessageBox mb;
        mb.setWindowTitle("خطأ");
        mb.setText("الرجاء إدخال بيانات للمتابعه");
        mb.exec();
    }else{
        todo = new todoornottodo((QString)"هل أنت متأكد أنك تريد إلغاء عملية رقم "+(QString)" "+opcode+(QString)" "+(QString)"؟");
        todo->Case = 1;
        todo->opcode = opcode;
        todo->show();
    }
}

void MainWindow::on_pushButton_5_clicked()//بحث بضاعة
{
    QString gcode=ui->goodcode->text()
            ,color=ui->goodcolor->text();
    QSqlQueryModel *model1=new QSqlQueryModel;
    model1->setQuery("SELECT  `Ware`.`Ctype` as 'الكود',`Ware`.`Ccolor` as 'اللون',`Ware`.`Name` as 'الاسم',`Ware`.`Quantity` as 'الكمية' from `Ware`  where `Ctype` = '"+gcode+"' and `Ccolor` = '"+color+"' ") ;
    ui->goodtabel->setModel(model1);
}

void MainWindow::on_pushButton_27_clicked()//تنشيط
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("SELECT `Order`.`Order-num` as 'كود العملية',`Order`.`Car-det` as 'تفاصيل السيارة',`Order`.`Delvtime` as 'وقت التسليم',`Order`.`Order` as 'الطلب /السعر مفصل' , `Customer`.`Name` as 'اسم العميل' ,`Customer`.`Number` as 'الهاتف' from `Order` ,`Customer`  where `Customer`.`Cnum`=`Order`.`C-code` and `Bouns` = 1 and `Done` = 0");
    ui->bouns->setModel(model);
    QSqlQueryModel *model2=new QSqlQueryModel;
    model2->setQuery("SELECT `Order`.`Order-num` as 'كود العملية',`Order`.`Car-det` as 'تفاصيل السيارة',`Order`.`Delvtime` as 'وقت التسليم',`Order`.`Order` as 'الطلب /السعر مفصل', `Customer`.`Name` as 'اسم العميل' ,`Customer`.`Number` as 'الهاتف' from `Order` ,`Customer`  where `Customer`.`Cnum`=`Order`.`C-code` and `Bouns` = 1 and `Done` = 1");
    ui->bounsedone->setModel(model2);
}

void MainWindow::on_pushButton_26_clicked()//اضافي
{

    QString opcode=ui->deleteopcode->text();
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
        qry.exec("update `Order` set `Done` = 1 where `Order-num` = "+opcode+"");
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("تم");
        msgBox.setText("تم التسليم");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("لا توجد عملية تسليم بهذا الكود");
        msgBox.exec();
    }
}

void MainWindow::on_pushButton_40_clicked()//اضافةبضاعة
{
    QString code=ui->addgoodcode->text()
            ,color=ui->addgoodcolor->text()
            ,price=QString::number(ui->addprice->value())
            ,qty=QString::number(ui->addquantatity->value())
            ,type=ui->addtype->text();
    bool found=false;
    QSqlQuery qryf;
    qryf.exec("SELECT `Ware`.`Ctype`, `Ware`.`Ccolor` FROM `JeansCar`.`Ware` ");//اكوادالبضاعة
    while (qryf.next())
    {
        if(code==qryf.value(0).toString()&&color==qryf.value(1).toString())
        {
            found=true;
            break;
        }
    }
    if(found)
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("يوجد مخزون اخر بهذا الكود");
        msgBox.exec();
    }
    else
    {
        QSqlQuery qry ;
        if(qry.exec("INSERT INTO `JeansCar`.`Ware` (`Ctype`, `Ccolor`, `Name`, `Price`, `Quantity`) VALUES ('"+code+"', '"+color+"', '"+type+"', "+price+","+qty+");"))//بضاعة جديدة مخزن صغير
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("تم");
            msgBox.setText("تم اضافة البضاعة");
            msgBox.exec();
        }
        else
        {
            qDebug()<<qry.lastError().text();
        }
    }


}

void MainWindow::on_pushButton_4_clicked()//سحب بضاعة
{
    QString goodcode=ui->s7bcode->text()
            ,goodcolor=ui->s7bcolor->text()
            ,Quantity=QString::number(ui->quantity->value())
            ,reason=ui->s7breason->text()
            ,date=english.toString(*curdate,"yyyy-MM-dd")
            ,time=english.toString(*curtime,"hh:mm:ss");
    double price;
    bool found=false;
    QSqlQuery qryf;
    qryf.exec("SELECT `Ware`.`Ctype`, `Ware`.`Ccolor` FROM `JeansCar`.`Ware` ");//اكوادالبضاعة
    while (qryf.next())
    {
        if((goodcode==qryf.value(0).toString())&&(goodcolor==qryf.value(1).toString()))
        {
            found=true;
            break;
        }
    }

    if(found)
    {
        QSqlQuery qry;
        double quantity=ui->quantity->value()
                ,curquantity;
        qry.exec("select `Quantity` from `Ware` where `Ctype` = '"+goodcode+"' and `Ccolor` = '"+goodcolor+"'");
        qry.first();
        curquantity=qry.value(0).toDouble();
        if(quantity<=curquantity)
        {qryf.exec("SELECT `Ware`.`Price` FROM `JeansCar`.`Ware` where `Ctype` = '"+goodcode+"' and `Ccolor` = '"+goodcolor+"' ");//سعر البضاعة
            qryf.first();
            price=qryf.value(0).toDouble();
            price=price*(ui->quantity->value());
            curquantity=curquantity-quantity;
            QString curquantitystr=QString::number(curquantity);
            QString pricestr=QString::number(price);
            qry.exec("update `Ware` set  `Quantity` = "+curquantitystr+" where `Ctype` = '"+goodcode+"' and `Ccolor` = '"+goodcolor+"'");
            if(qry.exec("INSERT INTO `Drag` (`E-code`, `C-type`, `C-color`, `Price`, `Quantity`, `Notes`, `Date`)VALUES('"+*code+"', '"+goodcode+"', '"+goodcolor+"',"+pricestr+","+Quantity+", '"+reason+"','"+date+" "+time+"');"))

            {}
            else
            {
                qDebug()<<qry.lastError().text();
            } QMessageBox msgBox (this);
            msgBox.setWindowTitle("تم");
            msgBox.setText("تم سحب بضاعة");
            msgBox.exec();
        }
        else
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText("كمية غير متاحة المتاح "+QString ::number(curquantity)+"فقط");
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("لا يوجد اي مخزون بهذا الكود");
        msgBox.exec();
    }

}

void MainWindow::on_pushButton_28_clicked()//مخزن كبير اضافة
{
    QString scode
            ,sdate=english.toString(ui->sdate->date(),"yyyy-MM-dd")
            ,sqty=QString::number(ui->sqty->value())
            ,sprice=QString::number(ui->sprice->value())
            ,scopmany=ui->scompany->text()
            ,sname=ui->sname->text();
    QSqlQuery qry;
    if( qry.exec("INSERT INTO `Stock` ( `Name`, `Quantity`, `Price`, `Source`, `Date`)VALUES( '"+sname+"', "+sqty+", "+sprice+", '"+scopmany+"', '"+sdate+"');"))
    {   QMessageBox msgBox (this);
        msgBox.setWindowTitle("تم");
        msgBox.setText("تم اضافة المخزون");
        msgBox.exec();
    }
    else{
        qDebug()<<qry.lastError().text();
    }
}

void MainWindow::on_pushButton_29_clicked()//البحث****
{
    QString  scode=ui->sscode->text()
            ,sdate=english.toString(ui->ssdate->date(),"yyyy-MM-dd")
            ,scopmany=ui->sscompany->text()
            ,sname=ui->ssname->text();
    QSqlQueryModel *model= new  QSqlQueryModel;
    QSqlQuery qry;
    if(scode!="")
    {
        model->setQuery("select `Stock`.`Scode` as 'كود البضاعة',`Stock`.`Name`as 'اسم البضاعة' ,`Stock`.`Quantity` as 'الكمية',`Stock`.`Price`as 'السعر',`Stock`.`Source`as 'المورد',`Stock`.`Date` as 'تاريخ دخول البضاعة' from `Stock` where `Scode` = "+scode+"");
        ui->stock->setModel(model);
    }
    else if(scopmany!="")
    {
        model->setQuery("select `Stock`.`Scode` as 'كود البضاعة',`Stock`.`Name`as 'اسم البضاعة' ,`Stock`.`Quantity` as 'الكمية',`Stock`.`Price`as 'السعر',`Stock`.`Source`as 'المورد',`Stock`.`Date` as 'تاريخ دخول البضاعة' from `Stock` where `Source` like '%"+scopmany+"%'");
        ui->stock->setModel(model);
    }
    else if(sname!="")
    {
        qry.exec("select `Stock`.`Scode` as 'كود البضاعة',`Stock`.`Name`as 'اسم البضاعة' ,`Stock`.`Quantity` as 'الكمية',`Stock`.`Price`as 'السعر',`Stock`.`Source`as 'المورد',`Stock`.`Date` as 'تاريخ دخول البضاعة' from `Stock` where `Name` like '%"+sname+"%'");
        model->setQuery("select `Stock`.`Scode` as 'كود البضاعة',`Stock`.`Name`as 'اسم البضاعة' ,`Stock`.`Quantity` as 'الكمية',`Stock`.`Price`as 'السعر',`Stock`.`Source`as 'المورد',`Stock`.`Date` as 'تاريخ دخول البضاعة' from `Stock` where `Name` like '%"+sname+"%'");
        ui->stock->setModel(model);
    }
    else
    {
        model->setQuery("select `Stock`.`Scode` as 'كود البضاعة',`Stock`.`Name`as 'اسم البضاعة' ,`Stock`.`Quantity` as 'الكمية',`Stock`.`Price`as 'السعر',`Stock`.`Source`as 'المورد',`Stock`.`Date` as 'تاريخ دخول البضاعة' from `Stock` where `Date` = '"+sdate+"'");
        ui->stock->setModel(model);
    }
}

void MainWindow::on_pushButton_30_clicked()//سحب مخزن كبير
{
    QString sqty=QString::number(ui->sssqty->value())
            ,scode=ui->ssscode->text();
    double qty;
    bool found=false;
    QSqlQuery qryf;
    qryf.exec("select `Scode` from `Stock`");//اكوادالبضاعة
    while (qryf.next())
    {
        if(scode==qryf.value(0).toString())
        {
            found=true;
            break;
        }
        qDebug()<< scode<< "  "<<qryf.value(0).toString();
    }

    if(found)
    {
        QSqlQuery qry;
        qry.exec("select `Quantity` from `Stock` where `Scode` = "+scode+" ");
        qry.first();
        qty=qry.value(0).toDouble();
        QString newqty=QString::number(qty-(ui->sssqty->value()));
        if(ui->sssqty->value()<qty)
        {
            qry.exec("update `Stock` set `Quantity` = "+newqty+";");
        }
        else
        {

            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText("كمية غير متاحة المتاح "+QString ::number(qty)+"فقط");
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("لا توجد اي مخزون بهذا الكود");
        msgBox.exec();
    }
}

void MainWindow::on_pushButton_31_clicked()//اضافة يومية
{
    QString date=english.toString(*curdate,"yyyy-MM-dd")
            ,time=english.toString(*curtime,"hh:mm:ss")
            ,money=QString::number(ui->money->value())
            ,type
            ,reson=ui->dailyreason->text();
    if(ui->radioButton->isChecked())
    {
        type="n";
    }
    else if(ui->radioButton_2->isChecked())
    {
        type="y";
    }
    QSqlQuery qry;
    if( qry.exec("INSERT INTO `Daily` (`E-code`, `Amount`, `Reason`, `Date`, `Income`, `Done`)VALUES('"+*code+"', "+money+", '"+reson+"', '"+date+" "+time+"', '"+type+"', 'y');"))
    {
        QMessageBox mb(this);
        mb.setWindowTitle("تم");
        mb.setText("تمت الاإضافة بنجاح.");
        mb.exec();
    }
    else
    {
        QMessageBox mb(this);
        mb.setWindowTitle("خطأ");
        mb.setText(qry.lastError().text());
        mb.exec();
        qDebug() << qry.lastError().text();
    }

}

void MainWindow::on_pushButton_32_clicked()//اليومية
{
    QSqlTableModel *table= new  QSqlTableModel;
    table->setTable("Daily");
    QString date = english.toString(ui->daily_re->date(),"yyyy-MM-dd");
    table->setFilter("Date = '"+date+"'");
    table->select();
    table->setHeaderData(0, Qt::Horizontal, tr("كود اليومية"));
    table->setHeaderData(1, Qt::Horizontal, tr("كود المستخدم"));
    table->setHeaderData(2, Qt::Horizontal, tr("القيمة"));
    table->setHeaderData(3, Qt::Horizontal, tr("السبب"));
    table->setHeaderData(4, Qt::Horizontal, tr("التاريخ"));
    table->setHeaderData(5, Qt::Horizontal, tr("داخل"));
    table->setHeaderData(6, Qt::Horizontal, tr("حسابات شركة"));
    ui->dailymtable->setModel(table);
}

void MainWindow::on_pushButton_33_clicked()//الشهري
{
    QString month=english.toString(ui->dateEdit->date(),"MM")
            ,year=english.toString(ui->dateEdit->date(),"yyyy");
    QSqlQueryModel *model= new QSqlQueryModel;
    QSqlQueryModel *model2= new QSqlQueryModel;
    QSqlQuery qry;
    model->setQuery("SELECT `Daily`.`Dcode` as 'كود اليومية',`Daily`.`E-code` as 'كود المستخدم', `Daily`.`Amount`as 'المبلغ',`Daily`.`Date` as 'التاريخ',`Daily`.`Income` as 'داخل/صادر',`Daily`.`Reason` as 'السبب',`Daily`.`Done`  as 'تمت رؤيته'  FROM JeansCar.Daily where month(`Date`) = "+month+ " and year(`Date`) = "+year+" and `Done` = 'y';");
    model2->setQuery("SELECT `Daily`.`Dcode` as 'كود اليومية',`Daily`.`E-code` as 'كود المستخدم', `Daily`.`Amount`as 'المبلغ',`Daily`.`Date` as 'التاريخ',`Daily`.`Income` as 'داخل/صادر',`Daily`.`Reason` as 'السبب',`Daily`.`Done`  as 'تمت رؤيته' FROM JeansCar.Daily where month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Done` <> '0' and `Done` <> 'y'");
    ui->monthly->setModel(model);
    ui->monthlyout->setModel(model2);
    qry.exec("select sum(`Amount`) from `Daily`  where `Income` = 'n' and `Done` = 'y'  and month(`Date`) = "+month+" and year(`Date`) = "+year+";");
    qry.first();
    ui->inout->setText(qry.value(0).toString());
    double inout = qry.value(0).toDouble();
    qry.exec("select sum(`Amount`) from `Daily`  where `Income` = 'y' and `Done` = 'y'  and month(`Date`) = "+month+" and year(`Date`) = "+year+";");
    qry.first();
    ui->inin->setText(qry.value(0).toString());
    double inin=qry.value(0).toDouble();
    double inreb7=inin-inout;
    ui->inreb7->setText(QString::number(inreb7));
    qry.exec("select sum(`Amount`) from `Daily`  where `Income` = 'n' and `Done` = 'n'  and month(`Date`) = "+month+" and year(`Date`) = "+year+";");
    qry.first();
    ui->outout->setText(qry.value(0).toString());
    double outout=qry.value(0).toDouble();
    qry.exec("select sum(`Amount`) from `Daily`  where `Income` = 'y' and `Done` = 'n'  and month(`Date`) = "+month+" and year(`Date`) = "+year+";");
    qry.first();
    ui->outin->setText(qry.value(0).toString());
    double outin=qry.value(0).toDouble();
    double outreb7=outin-outout;
    ui->outreb7->setText(QString::number(outreb7));
}

void MainWindow::on_pushButton_35_clicked()//تقرير اليومية
{
    QString ddate=english.toString(ui->dateEdit_2->date(),"yyyy-MM-dd");
    QSqlQueryModel *model= new QSqlQueryModel;
    QSqlQueryModel *model2= new QSqlQueryModel;
    QSqlQuery qry;
    model->setQuery("SELECT `Daily`.`Dcode` as 'كود اليومية',`Daily`.`E-code` as 'كود المستخدم', `Daily`.`Amount`as 'المبلغ',`Daily`.`Date` as 'التاريخ',`Daily`.`Income` as 'داخل',`Daily`.`Reason` as 'السبب',`Daily`.`Done`  as 'تمت رؤيته'  FROM JeansCar.Daily where date(`Date`) = '"+ddate+"' and `Done` = 'y';");
    model2->setQuery("SELECT `Daily`.`Dcode` as 'كود اليومية',`Daily`.`E-code` as 'كود المستخدم', `Daily`.`Amount`as 'المبلغ',`Daily`.`Date` as 'التاريخ',`Daily`.`Income` as 'داخل',`Daily`.`Reason` as 'السبب',`Daily`.`Done`  as 'تمت رؤيته' FROM JeansCar.Daily where date(`Date`)= '"+ddate+"'  and `Done` <> '0' and `Done` <> 'y'");
    ui->dayin->setModel(model);
    ui->dayout->setModel(model2);
    qry.exec("select sum(`Amount`)  from `Daily`  where `Income` = 'n' and `Done` = 'y'  and `Date` = '"+ddate+"';");
    qry.first();
    ui->dinout->setText(qry.value(0).toString());
    qry.exec("select sum(`Amount`)  from `Daily`  where `Income` = 'y' and `Done` = 'y'  and `Date` = '"+ddate+"';");
    qry.first();
    ui->dinin->setText(qry.value(0).toString());
    qry.exec("select sum(`Amount`)  from `Daily`  where `Income` = 'n' and `Done` = 'n'  and `Date` = '"+ddate+"';");
    qry.first();
    ui->doutout->setText(qry.value(0).toString());
    qry.exec("select sum(`Amount`)  from `Daily`  where `Income` = 'y' and `Done` = 'n'  and `Date` = '"+ddate+"';");
    qry.first();
    ui->doutin->setText(qry.value(0).toString());
    qDebug()<<ddate;
    qDebug()<<qry.value(0).toString();

}

void MainWindow::on_pushButton_34_clicked()
{
    QString date=english.toString(ui->dateEdit_3->date(),"yyyy-MM-dd");
    int x=ui->dateEdit_3->date().dayOfWeek()-1;
    if(x==6)
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("يوم الاحد اجازة");
        msgBox.exec();

    }
    else
    {
        table *f = new table(0,ui->searchdate->date());
        f->show();
    }

}

void MainWindow::on_delevercode_2_editingFinished()//تسليم1
{
    ui->delevername->setText("");
    ui->pay->setText("");
    ui->remain_2->setText("");
    ui->total->setText("");
    QString opcode=ui->delevercode_2->text();
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
        qry.exec("select `Name` from `JeansCar`.`Order` ,`JeansCar`.`Customer` where `C-code`= `Cnum` and  `Order-num` ="+opcode+"");
        qry.first();
        ui->delevername->setText(qry.value(0).toString());
        qry.exec("select `M-pay` from `JeansCar`.`Order`  where `Order-num` ="+opcode+"");
        qry.first();
        ui->pay->setText(qry.value(0).toString());
        qry.exec("select `M-Remain` from `JeansCar`.`Order`  where `Order-num` ="+opcode+"");
        qry.first();
        ui->remain_2->setText(qry.value(0).toString());
        qry.exec("select `Total-price` from `JeansCar`.`Order`  where `Order-num` ="+opcode+"");
        qry.first();
        ui->total->setText(qry.value(0).toString());

    }
}

void MainWindow::on_pushButton_36_clicked()//تسليم
{
    QString opnum=ui->delevercode_2->text();
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
                QMessageBox msgBox (this);
                msgBox.setWindowTitle("تم");
                msgBox.setText("تم التسليم");
                msgBox.exec();

            }
        }
        else
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText(" لقد تم التسليم من قبل");
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox (this);
        msgBox.setWindowTitle("خطاء");
        msgBox.setText("لا توجد عملية تسليم بهذا الكود");
        msgBox.exec();
    }
}

void MainWindow::on_pushButton_37_clicked() // update delv time
{
    QString deleverdate = english.toString(ui->deldate->date(),"yyyy-MM-dd") ;
    char time;
    QString dcode = ui->opcode->text()
    ,opcode = ui->opcode->text();
    bool found = false;
    QSqlQuery qryf;
    qryf.exec("select `Order-num` from `JeansCar`.`Order`");//اكواد عمليات الشراء
    while (qryf.next())
    {
        if( dcode==qryf.value(0).toString())
        {
            found=true;
            break;
        }
    }
    if(found)
    {
        QSqlQuery qry;
        bool ok = true, duplicate = false;
        if(ui->deltime->currentText()=="11:5")
        {
            time='a';
            if(qry.exec("select `H11`,`H11a`,`H11b` ,`H11c` ,`H11d` ,`H11e` from `Sec` where `Date` = '"+deleverdate+"'"))
            {
                qry.first();
                if(qry.value(0).toInt()!=0&&qry.value(1).toInt()!=0&&qry.value(2).toInt()!=0 && qry.value(3).toInt()!=0&&qry.value(4).toInt()!=0&&qry.value(5).toInt()!=0)
                {
                    ok=false;
                } else if(qry.value(0).toString() == opcode || qry.value(1).toString() == opcode || qry.value(2).toString() == opcode
                        || qry.value(3).toString() == opcode || qry.value(4).toString() == opcode || qry.value(5).toString() == opcode)
                    duplicate = true;

            }
            else
            {
                ok=false;
            }
        }
        else if(ui->deltime->currentText()=="8:2")
        {
            time='b';
            if(qry.exec("select `H2`,`H2a`,`H2b` ,`H2c` ,`H2d` ,`H2e` from `Sec` where `Date` = '"+deleverdate+"'"))
            {
                qry.first();
                if(qry.value(0).toInt()!=0&&qry.value(1).toInt()!=0&&qry.value(2).toInt()!=0 && qry.value(3).toInt()!=0&&qry.value(4).toInt()!=0&&qry.value(5).toInt()!=0)
                {
                    ok=false;
                }else if(qry.value(0).toString() == opcode || qry.value(1).toString() == opcode || qry.value(2).toString() == opcode
                         || qry.value(3).toString() == opcode || qry.value(4).toString() == opcode || qry.value(5).toString() == opcode)
                    duplicate = true;

            }
            else
            {
                ok=false;
            }
        }
        else if(ui->deltime->currentText()=="5:11")
        {
            time='c';
            if(qry.exec("select `H5`,`H5a`,`H5b` ,`H5c` ,`H5d` ,`H5e` from `Sec` where `Date` = '"+deleverdate+"'"))
            {
                qry.first();
                if(qry.value(0).toInt()!=0&&qry.value(1).toInt()!=0&&qry.value(2).toInt()!=0 && qry.value(3).toInt()!=0&&qry.value(4).toInt()!=0&&qry.value(5).toInt()!=0)
                {
                    ok=false;
                }else if(qry.value(0).toString() == opcode || qry.value(1).toString() == opcode || qry.value(2).toString() == opcode
                         || qry.value(3).toString() == opcode || qry.value(4).toString() == opcode || qry.value(5).toString() == opcode)
                    duplicate = true;

            }
            else
            {
                ok=false;
            }
        }
        QMessageBox mb;
        if (ok && !duplicate){
            switch (time) {
                case 'a':
                    if(qry.exec("select `H11`,`H11a`,`H11b` ,`H11c` ,`H11d` ,`H11e` from `Sec` where `Date` = '"+deleverdate+"'"))
                    {
                        qry.first();
                        if(qry.value(0).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H11`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H11` = "+opcode+" ;");
                        }
                        else if(qry.value(1).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H11a`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H11a` = "+opcode+" ;");
                        }
                        else if(qry.value(2).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H11b`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H11b` = "+opcode+" ;");
                        }
                        else if(qry.value(3).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H11c`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H11c` = "+opcode+" ;");
                        }
                        else if(qry.value(4).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H11d`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H11d` = "+opcode+" ;");
                        }
                        else if(qry.value(5).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H11e`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H11e` = "+opcode+" ;");
                        }
                        qry.exec("update `Order` set `Moagal` = 1 , `time`='a' where `Order-num` = "+dcode+";");
                    }
                    break;
                case 'b':
                    if(qry.exec("select `H2`,`H2a`,`H2b` ,`H2c` ,`H2d` ,`H2e` from `Sec` where `Date` = '"+deleverdate+"'"))
                    {
                        qry.first();
                        if(qry.value(0).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H2`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H2` = "+opcode+" ;");
                        }
                        else if(qry.value(1).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H2a`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H2a` = "+opcode+" ;");
                        }
                        else if(qry.value(2).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H2b`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H2b` = "+opcode+" ;");
                        }
                        else if(qry.value(3).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H2c`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H2c` = "+opcode+" ;");
                        }
                        else if(qry.value(4).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H2d`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H2d` = "+opcode+" ;");
                        }
                        else if(qry.value(5).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H2e`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H2e` = "+opcode+" ;");
                        }
                        qry.exec("update `Order` set `Moagal` = 1 , `time`='b' where `Order-num` = "+dcode+";");
                    }
                    break;
                case 'c':
                    if(qry.exec("select `H5`,`H5a`,`H5b` ,`H5c` ,`H5d` ,`H5e` from `Sec` where `Date` = '"+deleverdate+"'"))
                    {
                        qry.first();
                        if(qry.value(0).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H5`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H5` = "+opcode+" ;");
                        }
                        else if(qry.value(1).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H5a`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H5a` = "+opcode+" ;");
                        }
                        else if(qry.value(2).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H5b`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H5b` = "+opcode+" ;");
                        }
                        else if(qry.value(3).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H5c`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H5c` = "+opcode+" ;");
                        }
                        else if(qry.value(4).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H5d`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H5d` = "+opcode+" ;");
                        }
                        else if(qry.value(5).toInt()==0)
                        {
                            qry.exec("insert into `Sec` (`Date` , `H5e`) values('"+deleverdate+"' , "+opcode+" ) on duplicate key update `H5e` = "+opcode+" ;");
                        }
                        qry.exec("update `Order` set `Moagal` = 1 , `time`='c' where `Order-num` = "+dcode+";");

                    }
                    break;
                default:
                    break;
            }
            qry.exec("update `Order` set `Delvtime` = '"+deleverdate+"' where `Order-num` = "+dcode+";");
            mb.setWindowTitle("تم ");
            mb.setText(" تم التعديل ");
            mb.exec();
        } else if(duplicate){
            mb.setWindowTitle("خطأ");
            mb.setText("لا يمكن تأجيل العملية لنفس الوقت");
            mb.exec();
        }
        else{
            mb.setWindowTitle("خطأ");
            mb.setText("هذا الوقت به عملية اخري");
            mb.exec();
        }
    }
    else
    {
        QMessageBox mb;
        mb.setWindowTitle("خطأ");
        mb.setText("لايوجد عملية تسليم بهذا الكود");
        mb.exec();
    }

}

void MainWindow::on_pushButton_38_clicked()
{
    ui->f82->clear();
    ui->f115->clear();
    ui->f511->clear();
    QString date = english.toString(ui->dateEdit_3->date(),"yyyy-MM-dd");
    QSqlQuery qry;
    qry.exec("select `Order-num` , `Car-det` from `Order` where `Delvtime` = '"+date+"' and `time` = 'a' and `Done` = 0");// هنا التسليمات بتاريخ date واول فترة
    // كود + موديل العربية

    while (qry.next()) {

        QString x=qry.value(0).toString()+": "+qry.value(1).toString();
        ui->f511->addItem(x);
    }
    qry.exec("select `Order-num` , `Car-det` from `Order` where `Delvtime` = '"+date+"' and `time` = 'b' and `Done` = 0");// هنا التسليمات بتاريخ date ورابع فترة
    // كود + موديل العربية

    while (qry.next()) {

        QString x=qry.value(0).toString()+": "+qry.value(1).toString();
        ui->f82->addItem(x);
    }
    qry.exec("select `Order-num` , `Car-det` from `Order` where `Delvtime` = '"+date+"' and `time` = 'c' and `Done` = 0");// هنا التسليمات بتاريخ date وتالت فترة
    // كود + موديل العربية

    while (qry.next()) {

        QString x=qry.value(0).toString()+": "+qry.value(1).toString();
        ui->f115->addItem(x);
    }
}

void MainWindow::on_f511_doubleClicked(const QModelIndex &index)
{
    QString x="",y="";
    y=ui->f511->currentItem()->text();
    for (int i=0;i<y.size();i++)
    {
        if(y[i]==':')
        {
            break;
        }
        x+=y[i];
    }
    product *p=new product(0,x);
    p->show();
}

void MainWindow::on_f82_doubleClicked(const QModelIndex &index)
{
    QString x="",y="";
    y=ui->f82->currentItem()->text();
    for (int i=0;i<y.size();i++)
    {
        if(y[i]==':')
        {
            break;
        }
        x+=y[i];
    }
    product *p=new product(0,x);
    p->show();
}

void MainWindow::on_f115_doubleClicked(const QModelIndex &index)
{
    QString x="",y="";
    y=ui->f115->currentItem()->text();
    for (int i=0;i<y.size();i++)
    {
        if(y[i]==':')
        {
            break;
        }
        x+=y[i];
    }
    product *p=new product(0,x);
    p->show();
}

void MainWindow::on_pushButton_39_clicked()
{
    if(pd->exec() == QPrintDialog::Accepted)
    {
        // print
        // p is printer
    }
    else
    {
        QMessageBox msg;
        msg.setWindowTitle("طباعة");
        msg.setText("لم تتم الطباعة");
        msg.exec();
    }

}

void MainWindow::on_pushButton_41_clicked()
{
    if(pd->exec() == QPrintDialog::Accepted)
    {
        // print
        // p is printer
    }
    else
    {
        QMessageBox msg;
        msg.setWindowTitle("طباعة");
        msg.setText("لم تتم الطباعة");
        msg.exec();
    }
}

void MainWindow::on_pushButton_42_clicked()
{
    if(pd->exec() == QPrintDialog::Accepted)
    {
        //ui->admintable->print(p);
    }
    else
    {
        QMessageBox msg;
        msg.setWindowTitle("طباعة");
        msg.setText("لم تتم الطباعة");
        msg.exec();
    }
}


void MainWindow::on_pushButton_43_clicked()
{
    Settings *s = new Settings();
    s -> show();
}

void MainWindow::on_pushButton_44_clicked()
{
    QString customername = ui->customername->text()
            ,customerphone = ui->customerphone->text()
            ,customerid;
    QSqlQueryModel *model1 = new QSqlQueryModel;
    if (customername == "" && customerphone == "")
        model1->setQuery("select `Customer`.`Cnum` as 'كودالعميل', `Customer`.`Name` as 'اسم العميل',`Customer`.`Number` as 'رقم الهاتف'  from `JeansCar`.`Customer` ");
    else if (customername == "")
        model1->setQuery("select `Customer`.`Cnum` as 'كودالعميل', `Customer`.`Name` as 'اسم العميل',`Customer`.`Number` as 'رقم الهاتف'  from `JeansCar`.`Customer`  where   `Number` = '"+customerphone+"';");
    else if (customerphone == "")
        model1->setQuery("select `Customer`.`Cnum` as 'كودالعميل', `Customer`.`Name` as 'اسم العميل',`Customer`.`Number` as 'رقم الهاتف'  from `JeansCar`.`Customer`  where   `Name` like '%"+customername+"%';");
    else
        model1->setQuery("select `Customer`.`Cnum` as 'كودالعميل', `Customer`.`Name` as 'اسم العميل',`Customer`.`Number` as 'رقم الهاتف'  from `JeansCar`.`Customer`  where   `Name` like '%"+customername+"%' and `Number` = '"+customerphone+"';");
    ui->customertable->setModel(model1);
}

void MainWindow::on_pushButton_45_clicked()
{
    mohafzat_table*  moh = new mohafzat_table;
    moh->show();
}

void MainWindow::on_pushButton_89_clicked()
{
    QString opcode=ui->delevercode1->text();
    Dialog1 *f=new Dialog1(0,opcode);
    f->show();
}

void MainWindow::on_pushButton_46_clicked()//تقرير عن مخزن
{
    QSqlQueryModel *model1 = new QSqlQueryModel;
    model1->setQuery("SELECT  `Ware`.`Ctype` as 'الكود',`Ware`.`Ccolor` as 'اللون',`Ware`.`Name` as 'الاسم',`Ware`.`Quantity` as 'الكمية' from `Ware` ") ;
    ui->goodtabel->setModel(model1);
}

void MainWindow::on_pushButton_48_clicked()// حذف بضاعه مخزن صغير
{
    QString gcode = ui->goodcode_2->text()
            , color = ui->goodcolor_2->text();
    QSqlQuery qry;
    QMessageBox::StandardButton x;
    x = QMessageBox::question(this,"حذف البضاعه","هل انت متأكد انك تريد حذف البضاعه "+gcode+"," +color+"؟",QMessageBox::Ok|QMessageBox::Cancel);
    if(x == QMessageBox::Ok){
        bool found=false;
        QSqlQuery qryf;
        qryf.exec("SELECT `Ware`.`Ctype`, `Ware`.`Ccolor` FROM `JeansCar`.`Ware` ");//اكوادالبضاعة
        while (qryf.next())
        {
            if((gcode == qryf.value(0).toString()) && (color == qryf.value(1).toString()))
            {
                found = true;
                break;
            }
        }

        if(found){
            qry.exec("delete  from `Ware`  where `Ctype` = '"+gcode+"' and `Ccolor` = '"+color+"' ") ;
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("تم");
            msgBox.setText("تم الحذف");
            msgBox.exec();
        }
        else
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText("لا يوجد اي مخزون بهذا الكود");
            msgBox.exec();
        }
    }

}

void MainWindow::on_pushButton_47_clicked()//تقرير مخزن كبير
{
    QSqlQueryModel *model= new  QSqlQueryModel;
    model->setQuery(" select `Stock`.`Scode` as 'كود البضاعة',`Stock`.`Name`as 'اسم البضاعة' ,`Stock`.`Quantity` as 'الكمية',`Stock`.`Price`as 'السعر',`Stock`.`Source`as 'المورد',`Stock`.`Date` as 'تاريخ دخول البضاعة' FROM `Stock`;");
    ui->stock->setModel(model);
}

void MainWindow::on_pushButton_49_clicked()
{
    QString code = ui->ssscod_delete->text();
    QSqlQuery qry;
    QMessageBox::StandardButton x;
    x = QMessageBox::question(this,"حذف البضاعه","هل انت متأكد انك تريد حذف البضاعه "+code+"؟",QMessageBox::Ok|QMessageBox::Cancel);
    if(x == QMessageBox::Ok){
        bool found=false;
        QSqlQuery qryf;
        qryf.exec("SELECT `Scode` FROM `Stock` ");//اكوادالبضاعة
        while (qryf.next())
        {
            if((code == qryf.value(0).toString()) )
            {
                found = true;
                break;
            }
        }

        if(found){
            qry.exec("delete  from `Stock`  where `Scode` = '"+code+"' ") ;
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("تم");
            msgBox.setText("تم الحذف");
            msgBox.exec();
        }
        else
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText("لا يوجد اي مخزون بهذا الكود");
            msgBox.exec();
        }
    }

}

void MainWindow::on_delverlist_doubleClicked(const QModelIndex &index)
{
    QString opnum="",y="";
    y=ui->delverlist->currentItem()->text();
    QMessageBox::StandardButton msg;
    msg=QMessageBox::question(this,"تسليم",y+"سيتم تسليم",QMessageBox::Ok|QMessageBox::Cancel);
    if(msg==QMessageBox::Ok)
    {
        for (int i=0;i<y.size();i++)
        {
            if(y[i]==':')
            {
                break;
            }
            opnum += y[i];
        }
        QSqlQuery qryf;
        qryf.exec("select `Done` from `Order` where `Order-num` = "+opnum+"");
        qryf.first();
        QString x=qryf.value(0).toString();
        if(x=="0")
        { if(qryf.exec("update `Order` set `Done` = 1 where `Order-num` = "+opnum))//انهاء عملية تسليم
            {
                QMessageBox msgBox (this);
                msgBox.setWindowTitle("تم");
                msgBox.setText("تم التسليم");
                msgBox.exec();

            }
        }
        else
        {
            QMessageBox msgBox (this);
            msgBox.setWindowTitle("خطاء");
            msgBox.setText(" لقد تم التسليم من قبل");
            msgBox.exec();
        }
    }

}

void MainWindow::on_pushButton_50_clicked()
{
    choose_employee *c;
    QString s = ui->label_choose->currentText();
    if (s == "احوال يومية")
        c = new choose_employee(0, ui->employeecodea7wal);
    else if (s == "خصم")
        c = new choose_employee(0, ui->ecode5sm);
    else if (s == "سلفه")
        c = new choose_employee(0, ui->ecodesolfa);
    else
        c = new choose_employee(0, ui->increasecode);
    c->show();
}

void MainWindow::on_pushButton_52_clicked()
{
    choose_employee *c;
    QString s = ui->curr_edit->currentText();
    if (s == "اضافة مستخدم")
        c = new choose_employee(0, ui->addecode);
    else if (s == "حذف مستخدم")
        c = new choose_employee(0, ui->deletecode);
    else if (s == "حذف موظف")
        c = new choose_employee(0, ui->deleteecode);
    else if (s == "تعديل موظف")
        c = new choose_employee(0, ui->editemplyeecode);
    else if (s == "تقرير عن مستخدم")
        c = new choose_employee(0, ui->reoportusercode);
    else
        c = new choose_employee(0, ui->editecode);
    c->show();
}

void MainWindow::on_pushButton_53_clicked()
{
    QString customername = ui->cname_new->text()
            ,customerphone = ui->cphone_edit->text()
            ;
    bool found = false;
    QSqlQuery qry;
    qry.exec("select `Number` from `JeansCar`.`Customer`");
    while(qry.next()){
        if(customerphone == qry.value(0).toString()){
            found = true;
            break;
        }
    }
    QMessageBox mb(this);
    if(!found){
        mb.setWindowTitle("خطأ");
        mb.setText("لا يوجد عميل بهذا الرقم");
    }
    else{
        if(qry.exec("update `customer` set `Name`= '"+ customername +"' where `Number` = '" +customerphone+"'" ))
        {
            mb.setWindowTitle("تم");
            mb.setText("تم تعديل على العميل");

        }
    }
    mb.exec();
}

void MainWindow::on_editgoodcode_cursorPositionChanged(int arg1, int arg2)
{
    QString goodcode, goodcolor;
    goodcode = ui->editgoodcode->text();
    goodcolor = ui->editgoodcolor->text();
    ui->editgoodcode->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->editgoodcolor->setStyleSheet("background-color: rgb(255, 255, 255);");
    bool found = 0;
    QSqlQuery qry;
    qry.exec("SELECT `Ware`.`Ctype`, `Ware`.`Ccolor` FROM `JeansCar`.`Ware`");
    while (qry.next()) {
        if (goodcode == qry.value(0).toString() && goodcolor == qry.value(1).toString()){
            found = 1;
            break;
        }
    }
    if (!found){
        ui->editgoodcode->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(255, 0, 0);");
        ui->editgoodcolor->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(255, 0, 0);");
    }
    else{
        ui->editgoodcode->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->editgoodcolor->setStyleSheet("background-color: rgb(255, 255, 255);");
        qry.exec("select `Name`, `Price`, `Quantity` from ware where `Ctype` = '" + goodcode + "' and `Ccolor` = '"+goodcolor+"'");
        qry.first();
        ui->editprice->setValue(qry.value(1).toDouble());
        ui->edittype->setText(qry.value(0).toString());
        ui->editquantatity->setValue(qry.value(2).toDouble());
    }
}

void MainWindow::on_editgoodcolor_cursorPositionChanged(int arg1, int arg2)
{
    QString goodcode, goodcolor;
    goodcode = ui->editgoodcode->text();
    goodcolor = ui->editgoodcolor->text();
    ui->editgoodcode->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->editgoodcolor->setStyleSheet("background-color: rgb(255, 255, 255);");
    bool found = 0;
    QSqlQuery qry;
    qry.exec("SELECT `Ware`.`Ctype`, `Ware`.`Ccolor` FROM `JeansCar`.`Ware`");
    while (qry.next()) {
        if (goodcode == qry.value(0).toString() && goodcolor == qry.value(1).toString()){
            found = 1;
            break;
        }
    }
    if (!found){
        ui->editgoodcode->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(255, 0, 0);");
        ui->editgoodcolor->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(255, 0, 0);");
    }
    else{
        ui->editgoodcode->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->editgoodcolor->setStyleSheet("background-color: rgb(255, 255, 255);");
        qry.exec("select `Name`, `Price`, `Quantity` from ware where `Ctype` = '" + goodcode + "' and `Ccolor` = '"+goodcolor+"'");
        qry.first();
        ui->editprice->setValue(qry.value(1).toDouble());
        ui->edittype->setText(qry.value(0).toString());
        ui->editquantatity->setValue(qry.value(2).toDouble());
    }

}

void MainWindow::on_pushButton_54_clicked()
{
    QString goodcode, goodcolor, name;
    double price, quant;
    name = ui->edittype->text();
    price = ui->editprice->value();
    quant = ui->editquantatity->value();
    goodcode = ui->editgoodcode->text();
    goodcolor = ui->editgoodcolor->text();
    ui->editgoodcode->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->editgoodcolor->setStyleSheet("background-color: rgb(255, 255, 255);");
    bool found = 0;
    QSqlQuery qry;
    qry.exec("SELECT `Ware`.`Ctype`, `Ware`.`Ccolor` FROM `JeansCar`.`Ware`");
    while (qry.next()) {
        if (goodcode == qry.value(0).toString() && goodcolor == qry.value(1).toString()){
            found = 1;
            break;
        }
    }
    QMessageBox mb(this);
    if (!found){
        mb.setWindowTitle("خطأ");
        mb.setText("لا يوجد بضاعه بهذا الكود ");
    }
    else{
        if (qry.exec("update `Ware` set `Name` = '"+name+"' , `Price` = "+QString::number(price)+" , `Quantity` = "+QString::number(quant)+" where `Ctype` = '" + goodcode + "' and `Ccolor` = '"+goodcolor+"'")){
            mb.setWindowTitle("تم");
            mb.setText("تم التعديل بنجاح");
        }else {
            mb.setWindowTitle("خطأ");
            mb.setText("لم يتم التعديل");
        }
    }
    mb.exec();
}

void MainWindow::on_pushButton_55_clicked()
{
    ui->edit_scode->setStyleSheet("background-color: rgb(255, 255, 255);");
    QString goodcode, name,source, date;
    double quant, price;
    name = ui->edit_sname->text();
    quant = ui->edit_sqty->value();
    price = ui->edit_sprice->value();
    source = ui->edit_scompany->text();
    goodcode = ui->edit_scode->text();
    date = english.toString(ui->edit_sdate->date(),"yyyy-MM-dd");
    bool found = 0;
    QSqlQuery qry;
    qry.exec("select `Scode` from `Stock`;");
    while (qry.next()) {
        if (goodcode == qry.value(0).toString()){
            found = 1;
            break;
        }
    }
    QMessageBox mb(this);
    if (!found){
        mb.setWindowTitle("خطأ");
        mb.setText("لا يوجد بضاعه بهذا الكود ");
    }
    else{
        if (qry.exec("update `Stock` set `Name` = '"+name+"', `Quantity` = "+QString::number(quant)+" , `Price` = "+QString::number(price)+" , `Source` = '"+source+"', `Date` = '"+date+"'   where `Scode` = '"+goodcode+"';")){
            mb.setWindowTitle("تم");
            mb.setText("تم التعديل بنجاح");
        }
        else {
            mb.setWindowTitle("خطأ");
            mb.setText("لم يتم التعديل ");
        }
    }
    mb.exec();
}

void MainWindow::on_edit_scode_cursorPositionChanged(int arg1, int arg2)
{
    QString goodcode;
    goodcode = ui->edit_scode->text();
    ui->edit_scode->setStyleSheet("background-color: rgb(255, 255, 255);");
    bool found = 0;
    QSqlQuery qry;
    qry.exec("select `Scode` from `Stock`;");
    while (qry.next()) {
        if (goodcode == qry.value(0).toString()){
            found = 1;
            break;
        }
    }
    if (!found){
        ui->edit_scode->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(255, 0, 0);");
    }
    else{
        ui->edit_scode->setStyleSheet("background-color: rgb(255, 255, 255);");
        qry.exec("select `Name`, `Quantity`, `Price`, `Source`, `Date` from `Stock` where `Scode` = '" + goodcode + "'");
        qry.first();
        ui->edit_sname->setText(qry.value(0).toString());
        ui->edit_sqty->setValue(qry.value(1).toDouble());
        ui->edit_sprice->setValue(qry.value(2).toDouble());
        ui->edit_scompany->setText(qry.value(3).toString());
        ui->edit_sdate->setDate(qry.value(4).toDate());
    }
}

void MainWindow::on_pushButton_56_clicked()
{
    QString  month=english.toString(ui->salaryReportdate->date(),"MM")
            ,year=english.toString(ui->salaryReportdate->date(),"yyyy");

    QSqlQueryModel *model=new  QSqlQueryModel();
    model->setQuery("select e.`Ecode` as 'الكود' , e.`Name` as 'الاسم', e.`Clear-salary` as 'الراتب الاساسي' , ( select   sum(`Amount`) as dis from `Modify-salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'd' ) as 'اجمالي الخصم' , ( select  sum(`Amount`) as solfa from `Modify-salary`  where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 's' ) as 'اجمالي السلفة' , ( select   sum(`Amount`) as zyada from `Modify-salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'z' ) as 'اجمالي الزيادة' , (select `Amount`  from `Salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+") as 'الراتب المستحق' from `employee` as e");
    ui->salaryReportTable->setModel(model);
}

void MainWindow::on_salaryReportPrint_clicked()
{
    /*
    QString  month=english.toString(ui->salaryReportdate->date(),"MM")
            ,year=english.toString(ui->salaryReportdate->date(),"yyyy");
    auto report = new QtRPT(this);
    QDir dir(qApp->applicationDirPath());
    report->loadReport(dir.absolutePath()+"/reporall.xml");
    report->setSqlQuery("select e.`Ecode` as ecode, m.month , e.`Name`, e.`Clear-salary`, ( select   sum(`Amount`) as dis from `Modify-salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'd' ) as dis, ( select  sum(`Amount`) as solfa from `Modify-salary`  where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 's' ) as solfa, ( select   sum(`Amount`) as zyada from `Modify-salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'z' ) as zyada , (select `Amount`  from `Salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+") as 'salary' from `employee` as e , `month`as m where m.id="+month);
    report->printExec(true);
    */
    QString  month=english.toString(ui->salaryReportdate->date(),"MM")
            ,year=english.toString(ui->salaryReportdate->date(),"yyyy");
    print = new Print(generate_html_all_salary(month, year));
    print->exec();
}
QString MainWindow::generate_html_all_salary(QString month, QString year){
    QString sql = "select e.`Ecode` as ecode, e.`Name`, e.`Clear-salary`,"
               " ( select  sum(`Amount`) as dis from `Modify-salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'd' ) as dis,"
               " ( select  sum(`Amount`) as solfa from `Modify-salary`  where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 's' ) as solfa,"
               " ( select  sum(`Amount`) as zyada from `Modify-salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'z' ) as zyada ,"
               " ( select `Amount`  from `Salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+") as 'salary'"
               " from `employee` as e ";
    QSqlQuery qry;
    qry.exec(sql);
    QString html = "\uFEFF<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                   "<html><head><meta name=\"qrichtext\" content=\"1\" /><title>Jeans Car</title><style type=\"text/css\">\n"
                   "p, li { white-space: pre-wrap; }\n"
                   "</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
                   "<p align=\"center\" style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600;\">تقرير مرتبات   "+ QString::number(month.toInt()) +" / "+ QString::number(year.toInt()) +"</span></p>\n"
                   "<p align=\"center\" style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/logo/logo23.png\" width=\"100\" height=\"100\" /> </p>\n"
                   "<table  width=\"750\" align=\"center\" border=\"0.5\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;\" cellspacing=\"2\" cellpadding=\"0\">\n"
                   "<tr>\n"
                   "<td >\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'-webkit-standard'; font-size:medium; font-weight:600; color:#000000;\">المرتب المستحق</span></p></td>\n"
                   "<td >\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'-webkit-standard'; font-size:medium; font-weight:600; color:#000000;\">مقدار الزياده</span> </p></td>\n"
                   "<td >\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'-webkit-standard'; font-size:medium; font-weight:600; color:#000000;\">مقدار السلفه</span> </p></td>\n"
                   "<td  >\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'-webkit-standard'; font-size:medium; font-weight:600; color:#000000;\">مقدار الخصم</span> </p></td>\n"
                   "<td >\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">المرتب الأساسي </span></p></td>\n"
                   "<td >\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">إسم الموظف</span></p></td>\n"
                   "<td >\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">كود الموظف </span></p></td>"
                   "<td >\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">م</span></p></td></tr>\n"
                   ;
    int i = 1;
    while(qry.next()){
        html += "<tr>\n"
                "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(6).toString()+" </p></td>\n"
                "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(5).toString()+" </p></td>\n"
                "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(4).toString()+" </p></td>\n"
                "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(3).toString()+"</p></td>\n"
                "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(2).toString()+" </p></td>\n"
                "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(1).toString()+"</p></td>\n"
                "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(0).toString()+" </p></td>"
                "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+QString::number(i++)+" </p></td>"
                "</tr>";
    }
    html += "</table></body></html>";
    return html;
}

void MainWindow::on_salaryReportTable_doubleClicked(const QModelIndex &index)
{

    QString  month=english.toString(ui->salaryReportdate->date(),"MM")
            ,year=english.toString(ui->salaryReportdate->date(),"yyyy");
    if (reportSalary != NULL)
    {
        delete reportSalary;
    }

    if(index.column() == 0)
    {
        reportSalary = new Taqrer_salar(0,index.data().toString(),month,year);
        reportSalary->show();
    }
}

void MainWindow::on_pushButton_21_clicked()
{
    if(pri != NULL)
        delete pri;
    priority_check = new QString;
    pri = new Priority(this, this->priority_check);
    pri->show();
}
void MainWindow::setPriorty(QString s){
    priority_check = new QString(s);
    for (int i = 0 , j = 0 ; i < 11 ; i++,j++){
        if(s[i] == '0'){
            ui->tabWidget->removeTab(j);
            j--;
        }
    }
}

void MainWindow::on_pushButton_22_clicked()
{
    if(pri != NULL)
        delete pri;
    priority_check = new QString;
    pri = new Priority(this, this->priority_check);
    pri->show();
}

void MainWindow::on_Accounting_clicked()
{
    if (a != NULL)
        delete a;
    a = new Accounting(0);
    a->show();
}

void MainWindow::on_customertable_doubleClicked(const QModelIndex &index)
{
    QString data = index.data().toString(), name, phone;
    QSqlQuery qry;
    if (index.column() == 0){
        qry.exec("select `Name`, `Number` from `Customer` where `Cnum` = "+data+"");
        qry.first();
        name = qry.value(0).toString();
        phone = qry.value(1).toString();
    }
    else if (index.column() == 1) {
        qry.exec("select `Number` from `Customer` where `Name` = '"+data+"'");
        qry.first();
        name = data;
        phone = qry.value(0).toString();
    }
    else if (index.column() == 2) {
        qry.exec("select `Name` from `Customer` where `Number` = '"+data+"'");
        qry.first();
        name = qry.value(0).toString();
        phone = data;
    }
    ui->customerphone->setText(phone);
    ui->customername->setText(name);
}

void MainWindow::on_actionSettings_triggered()
{
    Settings *s = new Settings();
    s->show();
}
QString MainWindow::generate_html_op(QString opcode){
    QSqlQuery qry;
    qry.exec("select `Customer`.`Name`, `employee`.`Name` ,  `Order-time`, `Delvtime`, `time`, `Car-det`, `Order`,  `flat_color`, `wheel` , `Warn`, `flat` from `Order`,`Customer`, `employee`where `Order-num` = "+opcode+" and `A-code` = `Ecode` and `C-code` = `Cnum`;");
    qry.first();
          QString html = "\uFEFF<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                   "<html><head><meta name=\"qrichtext\" content=\"1\" /><title>Jeans Car</title><style type=\"text/css\">\n"
                   "p, li { white-space: pre-wrap; }\n"
                   "</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
                   "<p align=\"center\" style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600;\">عمليه شراء</span></p>\n"
                   "<p align=\"center\" style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/logo/logo23.png\" width=\"100\" height=\"100\" /> </p>\n"
                   "<p align=\"center\" style=\" margin-top:12px; margin-bottom:4px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:small; font-weight:600;\">Jeans Car for farsh and cut and all these stuff</span> </p>\n"
                   "<table border=\"1\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:70px;\" align=\"center\" cellspacing=\"2\" cellpadding=\"0\">\n"
                   "<tr>\n"
                   "<td>\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+opcode+" </p></td>\n"
                   "<td>\n"
                   "<p align=\"right\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">رقم العملية </p></td></tr>\n"
                   "<tr>\n"
                   "<td>\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(0).toString()+" </p></td>\n"
                   "<td>\n"
                   "<p align=\"right\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">اسم العميل </p></td></tr>\n"
                   "<tr>\n"
                   "<td>\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(1).toString()+" </p></td>\n"
                   "<td>\n"
                   "<p align=\"right\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">اسم المتعاقد </p></td></tr>\n"
                   "<tr>\n"
                   "<td>\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(2).toString()+" </p></td>\n"
                   "<td>\n"
                   "<p align=\"right\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">تاريخ التعاقد </p></td></tr>\n"
                   "<tr>\n"
                   "<td>\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(3).toString()+" </p></td>\n"
                   "<td>\n"
                   "<p align=\"right\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">تاريخ التسليم </p></td></tr>\n"
                   "<tr>\n"
                   "<td>\n";
          QString time;
          if(qry.value(4).toString() == "a"){
              time = "من ١١ صباحا إالى ٥ مساء";
          }
          else if (qry.value(4).toString() == "b")
              time = "من ٢ مساء إلى ٨ مساء ";
          else
              time = "من ٥ مساء إلى ١١ مساء ";
          html+=
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+time+"</p></td>\n"
                   "<td>\n"
                   "<p align=\"right\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">وقت التسليم </p></td></tr>\n"
                   "<tr>\n"
                   "<td>\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(5).toString()+"</p></td>\n"
                   "<td>\n"
                   "<p align=\"right\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">مواصفات السيارة </p></td></tr>\n"
                   "<tr>\n"
                   "<td>\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(9).toString()+" </p></td>\n"
                   "<td>\n"
                   "<p align=\"right\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">ضمان </p></td></tr>\n"
                   "<tr>\n"
                   "<td>\n"
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+qry.value(6).toString()+" </p></td>\n"
                   "<td>\n"
                   "<p align=\"right\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">الطلب </p></td></tr>\n"
                   "<tr>\n"
                   "<td>\n";
          QString flat;
          if (qry.value(10).toString() == "1")
              flat = qry.value(7).toString();
          else
              flat = "لا يوجد";
          html+=
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+flat+"</p></td>\n"
                   "<td>\n"
                   "<p align=\"right\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">دواسة </p></td></tr>\n"
                   "<tr>\n"
                   "<td>\n";
                   QString wheel;
                   if (qry.value(8).toString() == "1")
                       wheel = "نعم";
                   else
                       wheel = "لا يوجد";
                   html +=
                   "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+wheel+" </p></td>\n"
                   "<td>\n"
                   "<p align=\"right\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">طاره </p></td></tr>\n"
                   "</table>\n"
                   "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>";
    return html;
}

void MainWindow::on_print_op_clicked()
{
    print = new Print(generate_html_op(ui->op_code_print->text()));
    print->exec();
}

void MainWindow::on_pushButton_51_clicked()
{
    print = new Print(generate_html_delevers(english.toString(ui->delverdatenew->date())));
    print->exec();
}
QString MainWindow::generate_html_delevers(QString date){
    QSqlQuery qry;
    qry.exec("select `Order-num` , `Order`, `wheel` ,`flat` ,`flat_color` , `Name` , `Number` from `Order`, `customer` where `C-code`= `Cnum` and `Delvtime` = '"+date+"'");// هنا التسليمات بتاريخ date واول فترة
    qry.first();
          QString html = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">"
                  "<html><head><meta name=\"qrichtext\" content=\"1\" /><title>Jeans Car</title><style type=\"text/css\">"
                  "p, li { white-space: pre-wrap; }"
                  "</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">"
                  "<p align=\"center\" style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:18pt; font-weight:600;\">تسليمات </span></p>"
                  "<p align=\"center\" style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/logo/logo23.png\" width=\"100\" height=\"100\" /><span style=\" font-family:'.SF NS Text'; font-size:13pt;\"></span></p>"
                  "<table border=\"1\" style=\" margin-top:0px; margin-bottom:0px; margin-left:10px; margin-right:10px;\" cellspacing=\"2\" cellpadding=\"10\">"
                  "<tr>"
                  "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'-webkit-standard'; font-size:13pt; font-weight:600; color:#000000;\"> لون </span></p></td>"
                  "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'-webkit-standard'; font-size:13pt; font-weight:600; color:#000000;\">طارة </span><span style=\" font-family:'.SF NS Text'; font-size:13pt;\"></span></p></td>"
                  "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'-webkit-standard'; font-size:13pt; font-weight:600; color:#000000;\"> دواسة </span><span style=\" font-family:'.SF NS Text'; font-size:13pt;\"></span></p></td>"
                  "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'-webkit-standard'; font-size:13pt; font-weight:600; color:#000000;\"> الطلب </span><span style=\" font-family:'.SF NS Text'; font-size:13pt;\"></span></p></td>"
                  "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:600;\"> رقم الهاتف </span></p></td>"
                  "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:600;\"> إسم العميل </span></p></td>"
                  "<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:600;\"> كود العملية </span></p></td></tr>"
                  "<tr>";
/*
                  +"<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  +"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt;\">"3500 +"</span></p></td>"
                  +"<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  +"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt;\">"0 +"</span></p></td>"
                  +"<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  +"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt;\">"0 +"</span></p></td>"
                  +"<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  +"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt;\">"500 +"</span></p></td>"
                  +"<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  +"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt;\">"3000 +"</span></p></td>"
                  +"<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  +"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt;\">"King Of Phantoms +"</span></p></td>"
                  +"<td style=\" padding-left:5; padding-right:5; padding-top:5; padding-bottom:5;\">"
                  +"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt;\">"1234 +"</span></p></td></tr></table></body></html>"";
   */       return html;
}
