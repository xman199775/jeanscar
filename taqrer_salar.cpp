#include "taqrer_salar.h"
#include "ui_taqrer_salar.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>
//#include <qtrpt.h>
#include <QDir>
#include <QVector>
#include <QDebug>
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
    QSqlTableModel *table= new  QSqlTableModel;
    table->setTable("`modify-salary`");
    QLocale english = QLocale(QLocale::English, QLocale::UnitedStates);
    QString date = english.toString(ui->taqrerdate->date(),"MM");
    QString year = english.toString(ui->taqrerdate->date(),"yyyy");
    table->setFilter("`E-code` = '"+ecode+"' and month(`Date`) = "+date+" and year(Date) = "+year+"  and `Type` = 'd'");//"' and  and and ");
    table->select();
    table->setHeaderData(0, Qt::Horizontal, tr("كود المشرف"));
    table->setHeaderData(1, Qt::Horizontal, tr("كود الموظف"));
    table->setHeaderData(2, Qt::Horizontal, tr("القيمة"));
    table->setHeaderData(3, Qt::Horizontal, tr("التاريخ"));
    table->setHeaderData(4, Qt::Horizontal, tr("ملاحظات"));
    table->setHeaderData(5, Qt::Horizontal, tr("النوع"));
    table->setHeaderData(6, Qt::Horizontal, tr("المرتب بعد الخصم"));
    ui->table->setModel(table);
 /*الخصم*/
    QSqlQuery qry;
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
    QSqlTableModel *table= new  QSqlTableModel;
    table->setTable("attendence");
    QLocale english = QLocale(QLocale::English, QLocale::UnitedStates);
    QString date = english.toString(ui->taqrerdate->date(),"MM");
    QString year = english.toString(ui->taqrerdate->date(),"yyyy");
    table->setFilter("`E-code` = '"+ecode+"' and month(Date) = "+date+" and year(`Date`) = "+year+"");
    table->select();
    table->setHeaderData(0, Qt::Horizontal, tr("كود الموظف"));
    table->setHeaderData(1, Qt::Horizontal, tr("التاريخ"));

    ui->table->setModel(table);
 /*الخصم*/
    QSqlQuery qry;

    if(qry.exec("select count(`E-code`) from `Attendence` where `E-code` = '"+ecode+"' and month(`Date`) = "+month+" and year(`Date`) = "+year+"")) // عدد مرات الغياب
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

void Taqrer_salar::setModelNotes(){
    QString x;
    QSqlTableModel *table= new  QSqlTableModel;
    table->setTable("note");
    QLocale english = QLocale(QLocale::English, QLocale::UnitedStates);
    QString date = english.toString(ui->taqrerdate->date(),"MM");
    QString year = english.toString(ui->taqrerdate->date(),"yyyy");
    table->setFilter("`E-code` = '"+ecode+"' and month(`Date`) = "+date+" and year(`Date`) = "+year+" ");
    table->select();
    table->setHeaderData(0, Qt::Horizontal, tr("كود المشرف"));
    table->setHeaderData(1, Qt::Horizontal, tr("كود الموظف"));
    table->setHeaderData(2, Qt::Horizontal, tr("التاريخ"));
    table->setHeaderData(3, Qt::Horizontal, tr("الملاحظه"));
    ui->table->setModel(table);
    ui->sumlabel->setText("0");
}

void Taqrer_salar::setModelSolfa(){
    QString x;
    QSqlTableModel *table= new  QSqlTableModel;
    table->setTable("`modify-salary`");
    QLocale english = QLocale(QLocale::English, QLocale::UnitedStates);
    QString date = english.toString(ui->taqrerdate->date(),"MM");
    table->setFilter("`E-code` = '"+ecode+"' and month(Date) = "+date+" and year(Date) and Type = 's'");
    table->select();
    table->setHeaderData(0, Qt::Horizontal, tr("كود المشرف"));
    table->setHeaderData(1, Qt::Horizontal, tr("كود الموظف"));
    table->setHeaderData(2, Qt::Horizontal, tr("القيمة"));
    table->setHeaderData(3, Qt::Horizontal, tr("التاريخ"));
    table->setHeaderData(4, Qt::Horizontal, tr("ملاحظات"));
    table->setHeaderData(5, Qt::Horizontal, tr("النوع"));
    table->setHeaderData(6, Qt::Horizontal, tr("المرتب بعد السلفه"));
    ui->table->setModel(table);
 /*الخصم*/
    QSqlQuery qry;
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
    QString x;
    QSqlQuery qry;

    QSqlTableModel *table= new  QSqlTableModel;
    table->setTable("`delay-time`");
    QLocale english = QLocale(QLocale::English, QLocale::UnitedStates);
    QString date = english.toString(ui->taqrerdate->date(),"MM");
    QString year = english.toString(ui->taqrerdate->date(),"yyyy");
    table->setFilter("`E-code` = '"+ecode+"' and  month(Date) = "+date+" and year(Date) = "+year+"");
    table->select();
    table->setHeaderData(0, Qt::Horizontal, tr("كود الموظف"));
    table->setHeaderData(1, Qt::Horizontal, tr("عدد ساعات التأخير"));
    table->setHeaderData(2, Qt::Horizontal, tr("التاريخ"));
    ui->table->setModel(table);
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
    QString x;
    QSqlTableModel *table= new  QSqlTableModel;
    table->setTable("`modify-salary`");
    QLocale english = QLocale(QLocale::English, QLocale::UnitedStates);
    QString date = english.toString(ui->taqrerdate->date(),"MM");
    QString year = english.toString(ui->taqrerdate->date(),"yyyy");
    table->setFilter("`E-code` = '"+ecode+"' and  month(Date) = "+date+" and year(`Date`) = "+year+" and Type = 'z'");
    table->select();
    table->setHeaderData(0, Qt::Horizontal, tr("كود المشرف"));
    table->setHeaderData(1, Qt::Horizontal, tr("كود الموظف"));
    table->setHeaderData(2, Qt::Horizontal, tr("القيمة"));
    table->setHeaderData(3, Qt::Horizontal, tr("التاريخ"));
    table->setHeaderData(4, Qt::Horizontal, tr("ملاحظات"));
    table->setHeaderData(5, Qt::Horizontal, tr("النوع"));
    table->setHeaderData(6, Qt::Horizontal, tr("المرتب بعد الزياده"));
    ui->table->setModel(table);
 /*الخصم*/
    QSqlQuery qry;
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

void Taqrer_salar::setModelOver(){
    QString x;
    QSqlQuery qry;
    QSqlTableModel *table= new  QSqlTableModel;
    table->setTable("OverTime");
    QLocale english = QLocale(QLocale::English, QLocale::UnitedStates);
    QString date = english.toString(ui->taqrerdate->date(),"MM");
    QString year = english.toString(ui->taqrerdate->date(),"yyyy");
    table->setFilter("`Ecode` = '"+ecode+"' and month(Date) = "+date+" and year(`Date`) = "+year+"");
    table->select();
    table->setHeaderData(0, Qt::Horizontal, tr("كود الموظف"));
    table->setHeaderData(1, Qt::Horizontal, tr("القيمة"));
    table->setHeaderData(2, Qt::Horizontal, tr("التاريخ"));
    ui->table->setModel(table);
    if(qry.exec("select sum(`Amount`)  from  `OverTime` where `Ecode` = '"+ecode+"' and month(`Date`) = "+month+" and year(`Date`) = "+year+"")) // عدد ساعات التأخير
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

void Taqrer_salar::setProduce(){
    QString x;
    QSqlTableModel *table= new  QSqlTableModel;
    table->setTable("`produce`");
    QLocale english = QLocale(QLocale::English, QLocale::UnitedStates);
    QString date = english.toString(ui->taqrerdate->date(),"MM");
    QString year = english.toString(ui->taqrerdate->date(),"yyyy");
    table->setFilter("`E-code` = '"+ecode+"' and  month(Date) = "+date+" and year(`Date`) = "+year+" ");
    table->select();
    table->setHeaderData(0, Qt::Horizontal, tr("كود المشرف"));
    table->setHeaderData(1, Qt::Horizontal, tr("كود الموظف"));
    table->setHeaderData(2, Qt::Horizontal, tr("القيمة"));
    table->setHeaderData(3, Qt::Horizontal, tr("التاريخ"));
    ui->table->setModel(table);
 /*الخصم*/
    QSqlQuery qry;
    if(qry.exec("select sum(`Amount`) from `produce` where `E-code` = '"+ecode+"'  and month(`Date`) = "+month+" and year(`Date`) = "+year+""))//الزيادة
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
    else if (arg1 == "ساعات إضافيه"){
        setModelOver();
    }
    else if (arg1 == "إنتاج"){
        setProduce();
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
    else if (arg1 == "ساعات إضافيه"){
        setModelOver();
    }
    else if (arg1 == "إنتاج"){
        setProduce();
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
        paramValue = rows.at(recNo).borrow;
    }
    if (paramName == "date")
    {
        paramValue = rows.at(recNo).date;
    }
    if (paramName == "attends")
    {
        paramValue = rows.at(recNo).attendes;
    }
    if (paramName == "discount")
    {
        paramValue = rows.at(recNo).discount;
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
    /*auto report = new QtRPT(this);
    QDir dir(qApp->applicationDirPath());
    report->loadReport(dir.absolutePath()+"/reportwithdetails.xml");
    report->recordCount << rows.size();
    QObject::connect(report, SIGNAL(setValue(const int, const QString, QVariant&, const int)),
                     this, SLOT(setValue(const int, const QString, QVariant&, const int)));
    //report->setSqlQuery("select e.`Ecode` as ecode, m.month , e.`Name`, e.`Clear-salary`, ( select   sum(`Amount`) as dis from `Modify-salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'd' ) as dis, ( select  sum(`Amount`) as solfa from `Modify-salary`  where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 's' ) as solfa, ( select   sum(`Amount`) as zyada from `Modify-salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'z' ) as zyada , (select `Amount`  from `Salary` where `E-code` = e.`Ecode` and month(`Date`) = "+month+" and year(`Date`) = "+year+") as 'salary' from `employee` as e , `month`as m where m.id="+month);
    report->printExec(true);
*/}

void Taqrer_salar::on_pushButton_clicked()
{
    QLocale english = QLocale(QLocale::English, QLocale::UnitedStates);
    QString date = english.toString(ui->taqrerdate->date(),"MM");
    QString year = english.toString(ui->taqrerdate->date(),"yyyy");
    QSqlQuery qry;
    QMessageBox::StandardButton x;
    x = QMessageBox::question(this,"تأكيد التسليم","هل تريد تسليم المرتب؟",QMessageBox::Ok|QMessageBox::Cancel);
    if(x == QMessageBox::Ok){
        QMessageBox mb(this);
        qry.exec("Select `Done` from `Salary` where `E-code` = '"+ecode+"' and month(`Date`) = "+date+" and  year(`Date`) = "+year+" ");
        qry.first();
        if (qry.value(0) == "1"){
            mb.setWindowTitle("تم");
            mb.setText("تم تسليم المرتب من قبل!");
            mb.exec();
            return;
        }
        bool done = qry.exec("update `Salary` set `Done` = '1' where `E-code` = '"+ecode+"' and month(`Date`) = "+date+" and  year(`Date`) = "+year+"");
        if (done){
            mb.setWindowTitle("تم");
            mb.setText("تم تسليم المرتب.");
        }
        else{
            mb.setWindowTitle("خطأ");
            mb.setText("لم يتم التسليم!");
        }
            mb.exec();
    }
}

void Taqrer_salar::on_table_doubleClicked(const QModelIndex &index)
{
    QString code, date, type;
    QAbstractItemModel *model = ui->table->model();
    QLocale english = QLocale(QLocale::English, QLocale::UnitedStates);

    QSqlQuery qry;
    type = ui->taqretype->currentText();
    if(index.column()==0)
    {
        if(type == "خصم" || type == "سلفه" || type == "زياده")
        {
            code =  model->index(index.row(),1).data().toString();
            date = model->index(index.row(),3).data().toString();
            QMessageBox::StandardButton x;
            x = QMessageBox::question(this,"تأكيد الحذف","هل تريد حذف هذا البيان",QMessageBox::Ok|QMessageBox::Cancel);
            if(x == QMessageBox::Ok){
                bool done = qry.exec("delete from `modify-salary` where `E-code` = '"+code+"' and `Date` = '"+date+"';");
                QMessageBox mb(this);
                if (done){
                    mb.setWindowTitle("تم");
                    mb.setText("تم حذف البيان.");
                }
                else{
                    mb.setWindowTitle("خطأ");
                    mb.setText("لم يتم الحذف!");
                }
                mb.exec();
            }
            if (type == "خصم")
                setModel5asm();
            else if (type == "سلفه")
                setModelSolfa();
            else
                setModelZyada();

        }
        else if (type == "تآخير")
        {
            code =  model->index(index.row(),0).data().toString();
            date = model->index(index.row(),2).data().toString();
            QMessageBox::StandardButton x;
            x = QMessageBox::question(this,"تأكيد الحذف","هل تريد حذف هذا البيان",QMessageBox::Ok|QMessageBox::Cancel);
            if(x == QMessageBox::Ok)
            {
                bool done = qry.exec("delete from `delay-time` where `E-code` = '"+code+"' and `Date` = '"+date+"';");
                QMessageBox mb(this);
                if (done){
                    mb.setWindowTitle("تم");
                    mb.setText("تم حذف البيان.");
                }
                else{
                    mb.setWindowTitle("خطأ");
                    mb.setText("لم يتم الحذف!");
                }
                mb.exec();
            }
            setModelTa5eer();
        }
        else if (type == "غياب")
        {
            code =  model->index(index.row(),0).data().toString();
            date = model->index(index.row(),1).data().toString();
            QMessageBox::StandardButton x;
            x = QMessageBox::question(this,"تأكيد الحذف","هل تريد حذف هذا البيان",QMessageBox::Ok|QMessageBox::Cancel);
            if(x == QMessageBox::Ok)
            {
                bool done = qry.exec("delete from `attendence` where `E-code` = '"+code+"' and `Date` = '"+date+"';");
                QMessageBox mb(this);
                if (done){
                    mb.setWindowTitle("تم");
                    mb.setText("تم حذف البيان.");
                }
                else{
                    mb.setWindowTitle("خطأ");
                    mb.setText("لم يتم الحذف!");
                }
                mb.exec();
            }
            setModelGyab();
        }
        else if (type == "ساعات إضافيه")
        {
            code =  model->index(index.row(),0).data().toString();
            date = model->index(index.row(),2).data().toString();
            QMessageBox::StandardButton x;
            x = QMessageBox::question(this,"تأكيد الحذف","هل تريد حذف هذا البيان",QMessageBox::Ok|QMessageBox::Cancel);
            if(x == QMessageBox::Ok)
            {
                bool done = qry.exec("delete from `overtime` where `Ecode` = '"+code+"' and `Date` = '"+date+"';");
                QMessageBox mb(this);
                if (done){
                    mb.setWindowTitle("تم");
                    mb.setText("تم حذف البيان.");
                }
                else{
                    mb.setWindowTitle("خطأ");
                    mb.setText("لم يتم الحذف!");
                }
                mb.exec();
            }
            setModelOver();
        }
        else if (type == "ملاحظات")
        {
            code =  model->index(index.row(),0).data().toString();
            date = model->index(index.row(),2).data().toString();
            QMessageBox::StandardButton x;
            x = QMessageBox::question(this,"تأكيد الحذف","هل تريد حذف هذا البيان",QMessageBox::Ok|QMessageBox::Cancel);
            if(x == QMessageBox::Ok)
            {
                bool done = qry.exec("delete from `note` where `E-code` = '"+code+"' and `Date` = '"+date+"';");
                QMessageBox mb(this);
                if (done){
                    mb.setWindowTitle("تم");
                    mb.setText("تم حذف البيان.");
                }
                else{
                    mb.setWindowTitle("خطأ");
                    mb.setText("لم يتم الحذف!");
                }
                mb.exec();
            }
            setModelNotes();
        }
        else if (type == "إنتاج"){
            code =  model->index(index.row(),1).data().toString();
            date = model->index(index.row(),3).data().toString();
            QMessageBox::StandardButton x;
            x = QMessageBox::question(this,"تأكيد الحذف","هل تريد حذف هذا البيان",QMessageBox::Ok|QMessageBox::Cancel);
            if(x == QMessageBox::Ok)
            {
                bool done = qry.exec("delete from `produce` where `E-code` = '"+code+"' and `Date` = '"+date+"';");
                QMessageBox mb(this);
                if (done){
                    mb.setWindowTitle("تم");
                    mb.setText("تم حذف البيان.");
                }
                else{
                    mb.setWindowTitle("خطأ");
                    mb.setText("لم يتم الحذف!");
                }
                mb.exec();
            }
            setProduce();

        }
    }
}

