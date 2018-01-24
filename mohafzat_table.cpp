#include "mohafzat_table.h"
#include "ui_mohafzat_table.h"
#include <QMessageBox>
#include <QDate>
mohafzat_table::mohafzat_table(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mohafzat_table)
{
    ui->setupUi(this);
    ui->date_moh->setDate(QDate::currentDate());
    ui->moh_date_search->setDate(QDate::currentDate());
}

mohafzat_table::~mohafzat_table()
{
    delete ui;
}

void mohafzat_table::on_pushButton_clicked()
{
    QString date, name, number, m_name, time, car, tmp;
    QLocale english(QLocale::English, QLocale::UnitedStates);
    date = english.toString(ui->date_moh->date(),"yyyy-MM-dd");
    name = ui->c_name->text();
    number = ui->c_num->text();
    m_name = ui->moh_name->currentText();
    time = ui->time_moh->time().toString();
    car = ui->car_detail->text();
    QSqlQuery qry;
    qry.exec("select `Date` from `Mohafzat` where `Date` = '"+date+"'");
    qry.first();
    tmp = qry.value(0).toString();
    QMessageBox mb;
    if (tmp == "" && ui->date_moh->date().dayOfWeek() != 7){
        qry.exec("INSERT INTO `Mohafzat` (`Date`, `C_Name`, `Number`, `Car`, `M_name`, `Time`)VALUES('"+date+"', '"+name+"', '"+number+"', '"+car+"', '"+m_name+"', '"+time+"');");
        mb.setWindowTitle("تم");
        mb.setText("تم حجز هذا الميعاد");
    }
    else if (ui->date_moh->date().dayOfWeek() == 7 ){
        mb.setWindowTitle("خطأ");
        mb.setText("يوم الآحد اإجازة لا يمكن الحجز فيه");
    }
    else{
        mb.setWindowTitle("خطأ");
        mb.setText("هذا الميعاد محجوز");
    }
    mb.exec();
}

void mohafzat_table::on_pushButton_2_clicked()
{
    QLocale english(QLocale::English, QLocale::UnitedStates);
    QString date = english.toString(ui->moh_date_search->date(), "yyyy-MM-dd"), tmp;
    QSqlQuery qry;
    qry.exec("select `Date` from `Mohafzat` where `Date` = '"+date+"'");
    qry.first();
    tmp = qry.value(0).toString();
    QMessageBox mb;
    QSqlQueryModel *model = new QSqlQueryModel;
    if (tmp == "" && ui->date_moh->date().dayOfWeek() != 7){
        mb.setWindowTitle("إخطار");
        mb.setText("هذا الميعاد متاح للحجز");
    }
    else if (ui->date_moh->date().dayOfWeek() == 7 ){
        mb.setWindowTitle("خطأ");
        mb.setText("يوم الآحد اإجازة لا يوجد به حجوزات");
    }
    else{
        mb.setWindowTitle("إخطار");
        mb.setText("هذا الميعاد محجوز مسبقا");
        model->setQuery("SELECT `Mohafzat`.`Date` as 'تاريخ التعاقد', `Mohafzat`.`C_Name` as 'اسم العميل', `Mohafzat`.`Number` as 'رقم تليفون العميل', `Mohafzat`.`Car` as 'مواصفات السيارة', `Mohafzat`.`M_name` as 'المحافظة', `Mohafzat`.`Time` as 'وقت الوصول' FROM `JeansCar`.`Mohafzat` where `Date` = '"+date+"';");
        ui->moh_table->setModel(model);
    }
    mb.exec();
}
