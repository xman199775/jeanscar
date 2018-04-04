#include "taqrer_salar.h"
#include "ui_taqrer_salar.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <qtrpt.h>
#include <QDir>
#include <QVector>
struct row
{
  QString date="";
  double  borrow=0;
  double  discount=0;
  int attendes=0;
};
QVector <row> rows;
Taqrer_salar::Taqrer_salar(QWidget *parent, QString ecode, QString month, QString year) :
    QMainWindow(parent),
    ui(new Ui::Taqrer_salar)
{
    ui->setupUi(this);
    this->ecode = ecode;
    this->month = month;
    this->year = year;
    ui->ecode->setText(ecode);
    QSqlQuery qry;
    qry.exec("select `Name` from `Employee` where `Ecode` = '"+ecode+"';");
    qry.first();
    ui->ename->setText(qry.value(0).toString());
    QDate d;
    d.setDate(year.toInt() , month.toInt(), 1);
    ui->taqrerdate->setDate(d);
    this->setModel5asm();
    setRest();
}


void Taqrer_salar::setModel5asm(){

    QSqlQueryModel *model1 = new QSqlQueryModel;
    QString x;
    QSqlQuery qry;
    ui->table->setModel(model1);
    model1->setQuery("SELECT m.`A-code` as 'كود المشرف', e1.`Name` as 'اسم المشرف', m.`E-code` as 'كود الموظف', e2.`Name` as 'الاسم', m.`Amount` as 'الكمية', m.`New_salary` as 'المرتب الجديد', m.`Date` as 'التاريخ', m.`Notes` as 'الملاحظات' FROM `Modify-salary` as m, `Employee` as e1 , `Employee` as e2 where m.`E-code` = e2.`Ecode` and m.`A-code` = e1.`Ecode` and m.`E-code` = '"+ecode+"' and month(`Date`)  = "+month+" and year(`Date`) = "+year+" and m.`Type` = 'd'");/*الخصم*/
    if(qry.exec("select sum(`Amount`) from `Modify-salary` where `E-code` = '"+ecode+"' and `Type` = 'd'      and month(`Date`) = "+month+" and year(`Date`) = "+year+"")){
        qry.first();
        ui->sumlabel->setText(qry.value(0).toString());
    }
    else
        ui->sumlabel->setText("0");
}

void Taqrer_salar::setRest(){
    QString x;
    QSqlQuery qry;
    qry.exec("select  `Clear-salary`,`Amount`  from `Salary` , `Employee` where `E-code` = '"+ecode+"'  and `Ecode` = `E-code`   and month(`Date`) = "+month+" and year(`Date`) = "+year+"");//المرتب الاساسي والمرتب اللي هيقبض
    qry.first();
    x = qry.value(0).toString();

    ui->clearsalary->setText(x);
    x = qry.value(1).toString();
    ui->salarylabel->setText(x);
    qry.exec("select count(`A-code`) from `Order` where `A-code` = '"+ecode+"' and month(`Order-time`) = "+month+" and year(`Order-time`) = "+year+"");
    qry.first();
    x = qry.value(0).toString();
    ui->opnum->setText(x);
    if (qry.exec("select `Amount` from `Produce` where `E-code` = '"+ecode+"'  and month(`Date`) = "+month+" and year(`Date`) = "+year+";"))// الانتاج
    {
        qry.first();
        x = qry.value(0).toString();
        if (x == "")
            x = "0";
        ui->producelabel->setText(x);
    }
    else
    {
        ui->producelabel->setText("0");
    }

}

void Taqrer_salar::setModelGyab(){
    QSqlQueryModel *model1 = new QSqlQueryModel;
    QString x;
    QSqlQuery qry;
    model1->setQuery(" select `E-code` as 'كود الموظف' , `Name` as 'الاسم' , `Date` as 'التاريخ'  from `Attendence` , `Employee` where `E-code` = `Ecode` and `Ecode` = '"+ecode+"' and month(`Date`) = "+month+" and year(`Date`) = "+year+"");//الغياب
    ui->table->setModel(model1);
    if(qry.exec("select count(`E-code`) from `Attendence` where `E-code` = '"+ecode+"' and month(`Date`) = "+month+" and year(`Date`) = "+year+"")) // عدد مرات الغياب
    { qry.first();
        x=qry.value(0).toString();
        ui->sumlabel->setText(x);
    }
    else
    {
        ui->sumlabel->setText("0");
    }
}

void Taqrer_salar::setModelNotes(){
    QSqlQueryModel *model1 = new QSqlQueryModel;
    QString x;
    QSqlQuery qry;
    model1->setQuery("SELECT `Note`.`A-code` as  ' كود المشرف', e1.`Name` as 'اسم المشرف', `Note`.`E-code` as 'كود الموظف', e2.`Name` as 'اسم الموظف', `Note`.`Date` as 'التاريخ', `Note`.`Notes` as 'الملاحظات' FROM `Note` , `Employee` as e1 , `Employee` as e2 where `E-code` = '"+ecode+"' and `Note`.`A-code` = e1.`Ecode` and `Note`.`E-code` = e2.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+"");//الملاحظات
    ui->table->setModel(model1);
    ui->sumlabel->setText("0");
}

void Taqrer_salar::setModelSolfa(){
    QSqlQueryModel *model1 = new QSqlQueryModel;
    QString x;
    QSqlQuery qry;
    model1->setQuery("SELECT m.`A-code` as 'كود المشرف', e1.`Name` as 'اسم المشرف', m.`E-code` as 'كود الموظف', e2.`Name` as 'الاسم', m.`Amount` as 'الكمية', m.`New_salary` as 'المرتب الجديد', m.`Date` as 'التاريخ', m.`Notes` as 'الملاحظات' FROM `Modify-salary` as m, `Employee` as e1 , `Employee` as e2 where m.`E-code` = e2.`Ecode` and m.`A-code` = e1.`Ecode` and m.`E-code` = '"+ecode+"' and month(`Date`)  = "+month+" and year(`Date`) = "+year+" and m.`Type` = 's'");/*الخصم*/
    ui->table->setModel(model1);
    if(qry.exec("select sum(`Amount`) from `Modify-salary` where `E-code` = '"+ecode+"' and `Type` = 's'      and month(`Date`) = "+month+" and year(`Date`) = "+year+""))//الخصم
    {
        qry.first();
        x=qry.value(0).toString();
        ui->sumlabel->setText(x);
    }
    else
    {
        ui->sumlabel->setText("0");
    }
}

void Taqrer_salar::setModelTa5eer(){
    QSqlQueryModel *model1 = new QSqlQueryModel;
    QString x;
    QSqlQuery qry;
    model1->setQuery("select `E-code` as 'كود الموظف' , `Name` as 'الاسم', `Amount` as 'المبلغ' , `Date` as 'التاريخ'  from `Delay-time` , `Employee` where `E-code` = `Ecode` and `E-code` = '"+ecode+"' and month(`Date`) = "+month+" and year(`Date`) = "+year+""); // التأخير
    ui->table->setModel(model1);
    if(qry.exec("select sum(`Amount`)  from  `Delay-time` where `E-code` = '"+ecode+"' and month(`Date`) = "+month+" and year(`Date`) = "+year+"")) // عدد ساعات التأخير
    {
        qry.first();
        x = qry.value(0).toString();
        ui->sumlabel->setText(x);
    }
    else
    {
        ui->sumlabel->setText("0");
    }
}

void Taqrer_salar::setModelZyada(){
    QSqlQueryModel *model1 = new QSqlQueryModel;
    QString x;
    QSqlQuery qry;
    model1->setQuery("SELECT m.`A-code` as 'كود المشرف', e1.`Name` as 'اسم المشرف', m.`E-code` as 'كود الموظف', e2.`Name` as 'الاسم', m.`Amount` as 'الكمية' , m.`New_salary` as 'المرتب الجديد', m.`Date` as 'التاريخ', m.`Notes`  as 'الملاحظات' FROM `Modify-salary` as m, `Employee` as e1 , `Employee` as e2 where m.`E-code` = e2.`Ecode` and m.`A-code` = e1.`Ecode` and m.`E-code` = '"+ecode+"' and month(`Date`)  = "+month+" and year(`Date`) = "+year+" and m.`Type` = 'z'");/*الزياده*/
    ui->table->setModel(model1);
    if(qry.exec("select sum(`Amount`) from `Modify-salary` where `E-code` = '"+ecode+"' and `Type` = 'z'      and month(`Date`) = "+month+" and year(`Date`) = "+year+""))//الزيادة
    {qry.first();
        x=qry.value(0).toString();
        ui->sumlabel->setText(x);
    }
    else
    {
        ui->sumlabel->setText("0");
    }
}

Taqrer_salar::~Taqrer_salar()
{
    delete ui;
}

void Taqrer_salar::on_taqretype_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "خصم"){
        setModel5asm();
    }
    else if (arg1 == "سلفه"){
        setModelSolfa();
    }
    else if (arg1 == "زياده"){
        setModelZyada();
    }
    else if (arg1 == "تآخير") {
        setModelTa5eer();
    }
    else if (arg1 == "ملاحظات") {
        setModelNotes();
    }
    else{
        setModelGyab();
    }
    setRest();
}

void Taqrer_salar::on_taqrerdate_editingFinished()
{
    month = QString::number(ui->taqrerdate->date().month());
    year = QString::number(ui->taqrerdate->date().year());
    QString arg1 = ui->taqretype->currentText();
    if (arg1 == "خصم"){
        setModel5asm();
    }
    else if (arg1 == "سلفه"){
        setModelSolfa();
    }
    else if (arg1 == "زياده"){
        setModelZyada();
    }
    else if (arg1 == "تآخير") {
        setModelTa5eer();
    }
    else if (arg1 == "ملاحظات") {
        setModelNotes();
    }
    else{
        setModelGyab();
    }
    setRest();
}

void Taqrer_salar::setValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage)
{

    QLocale  Arabic = QLocale(QLocale::Arabic, QLocale::Egypt);
    Q_UNUSED(reportPage);
    if (paramName == "month")
    {
        paramValue = Arabic.toString(ui->taqrerdate->date(),"MMMM");
    }
    if (paramName == "year")
    {
        paramValue = Arabic.toString(ui->taqrerdate->date(),"yyyy");
    }
    if (paramName == "name")
    {
        QSqlQuery qry;
        qry.exec("Select `Name` from employee where Ecode = '"+ecode+"' ");
        qry.first();
        paramValue =qry.value(0).toString();
    }
    if (paramName == "salary")
    {
        QSqlQuery qry;
        qry.exec("Select `Clear-salary` from employee where Ecode = '"+ecode+"' ");
        qry.first();
        paramValue =qry.value(0).toString();
    }
    if (paramName == "borrow")
    {
        paramValue =rows.at(recNo).borrow;
    }
    if (paramName == "date")
    {
        paramValue =rows.at(recNo).date;
    }
    if (paramName == "attends")
    {
        paramValue =rows.at(recNo).attendes;
    }
    if (paramName == "discount")
    {
        paramValue =rows.at(recNo).discount;
    }

}

void Taqrer_salar::on_pushButton_2_clicked()
{
    rows.clear();
    QSqlQuery qry;
    qry.exec("SELECT `Amount` ,`Date` FROM jeanscar.`modify-salary` where `Type` = 'd' and `E-code`= '"+ecode+"' and month(`Date`) = "+month+" and year(`Date`) = "+year+";");
    while(qry.next())
    {
        row temp;
        temp.discount=qry.value(0).toDouble();
        temp.date=qry.value(1).toString();
        rows.append(temp);
    }
    qry.exec("SELECT `Amount` ,`Date` FROM jeanscar.`modify-salary` where `Type` = 's' and `E-code`= '"+ecode+"' and month(`Date`) = "+month+" and year(`Date`) = "+year+";");
    while(qry.next())
    {
        row temp;
        temp.borrow=qry.value(0).toDouble();
        temp.date=qry.value(1).toString();
        rows.append(temp);
    }
    qry.exec("SELECT `Date` FROM jeanscar.`attendence` where `E-code`= '"+ecode+"' and month(`Date`) = "+month+" and year(`Date`) = "+year);
    while(qry.next())
    {
        row temp;
        temp.attendes=1;
        temp.date=qry.value(0).toString();
        rows.append(temp);
    }
    auto report = new QtRPT(this);
    QDir dir(qApp->applicationDirPath());
    report->loadReport(dir.absolutePath()+"/reportwithdetails.xml");
    report->recordCount << rows.size();
    QObject::connect(report, SIGNAL(setValue(const int, const QString, QVariant&, const int)),
                     this, SLOT(setValue(const int, const QString, QVariant&, const int)));
    //report->setSqlQuery("select e.`Ecode` as ecode, m.month , e.`Name`, e.`Clear-salary`, ( select   sum(`Amount`) as dis from `Modify-salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'd' ) as dis, ( select  sum(`Amount`) as solfa from `Modify-salary`  where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 's' ) as solfa, ( select   sum(`Amount`) as zyada from `Modify-salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'z' ) as zyada , (select `Amount`  from `Salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+") as 'salary' from `employee` as e , `month`as m where m.id="+month);
    report->printExec(true);
}
