#include "accounting.h"
#include "ui_accounting.h"
#include <QDate>
#include <QtSql>
#include <QDebug>
Accounting::Accounting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Accounting)
{
    ui->setupUi(this);
    ui->Acc_date->setDate(QDate::currentDate());
    english = english = QLocale(QLocale::English, QLocale::UnitedStates);
    calculate_ware();
    calculate_orders();
    calculate_employee();
    calculate_daily();
    calculate_total();
}

Accounting::~Accounting()
{
    delete ui;
}
void Accounting::set_data(QLineEdit *l, QString s){
    if(s != "")
        l->setText(s);
}
void Accounting::calculate_employee(){
    QString month, year;
    month = english.toString(ui->Acc_date->date(), ("M"));
    year = english.toString(ui->Acc_date->date(), "yyyy");
    QSqlQuery qry;
    qry.exec("select sum(`Amount`)  from `Modify-salary` where month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'd';");
    qry.first();
    set_data(ui->E_Diss_amount, qry.value(0).toString());

    qry.exec("select sum(`Amount`) from `Modify-salary` where month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 's';");
    qry.first();
    set_data(ui->E_bro_amount, qry.value(0).toString());

    qry.exec("select sum(`Amount`)  from `Modify-salary` where month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'z';");
    qry.first();
    set_data(ui->E_bouns_amount, qry.value(0).toString());

    qry.exec("select sum(`Amount`)  from `Modify-salary` where month(`Date`) = "+month+" and year(`Date`) = "+year+" and `Type` = 'a';");
    qry.first();
    set_data(ui->E_diss_attend_amount, qry.value(0).toString());

    qry.exec("select sum(`Clear-salary`)  from `employee`;");
    qry.first();
    set_data(ui->E_salaries, qry.value(0).toString());

    qry.exec("select sum(`Amount`)  from `Salary` where month(`Date`) = "+month+" and year(`Date`) = "+year+";");
    qry.first();
    set_data(ui->E_clear_salary, qry.value(0).toString());
}
void Accounting::calculate_orders(){
    QString month, year;
    month = english.toString(ui->Acc_date->date(), ("M"));
    year = english.toString(ui->Acc_date->date(), "yyyy");
    QSqlQuery qry;
    qry.exec("select count(`Order-num`) from `Order` where month(`Order-time`) = "+month+" and year(`Order-time`) = "+year+";");
    qry.first();
    set_data(ui->opnums, qry.value(0).toString());

    qry.exec("select count(`Order-num`) from `Order` where month(`Delvtime`) = "+month+" and year(`Delvtime`) = "+year+" and `Done` = '1';");
    qry.first();
    set_data(ui->opnums_done, qry.value(0).toString());

    qry.exec("select count(`Order-num`) from `Order` where month(`Delvtime`) = "+month+" and year(`Delvtime`) = "+year+" and `Done` = '0';");
    qry.first();
    set_data(ui->opnums_undone, qry.value(0).toString());

    qry.exec("select count(`Order-num`) from `Order` where month(`Order-time`) = "+month+" and year(`Order-time`) = "+year+" and `Bouns` = '1';");
    qry.first();
    set_data(ui->opnums_bouns, qry.value(0).toString());

    qry.exec("select sum(`M-Pay`), sum(`M-Remain`) from `Order` where month(`Order-time`) = "+month+" and year(`Order-time`) = "+year+" ;");
    qry.first();
    set_data(ui->op_payed, qry.value(0).toString());
    set_data(ui->op_remain, qry.value(1).toString());

    qry.exec("select sum(`M-Pay`) from `Order` where month(`Order-time`) = "+month+" and year(`Order-time`) = "+year+" and `Done` = '0' ;");
    qry.first();
    qlonglong payed_and_undone = qry.value(0).toLongLong();

    qry.exec("select sum(`Total-price`) from `Order` where month(`Delvtime`) = "+month+" and year(`Delvtime`) = "+year+" and `Done` = '1' ;");
    qry.first();
    qlonglong total_done = qry.value(0).toLongLong();

    set_data(ui->op_income, QString::number(total_done + payed_and_undone));

    qry.exec("select sum(`M-pay`) from `Order` where month(`Order-time`) = "+month+" and year(`Order-time`) = "+year+" and `Bouns` = '1' ;");
    qry.first();
    set_data(ui->op_undone_cost, qry.value(0).toString());
    qlonglong undone_codt = qry.value(0).toLongLong();
    set_data(ui->op_profit, QString::number(total_done + payed_and_undone - undone_codt));
}
void Accounting::calculate_stock(){
    QSqlQuery qry;
    qry.exec("select sum(`Quantity`), sum(`Price`) from `Stock`;");
    qry.first();
    set_data(ui->Ware_quant, qry.value(0).toString());
    set_data(ui->Ware_cost, qry.value(1).toString());
}
void Accounting::calculate_ware(){
    QSqlQuery qry;
    qry.exec("select sum(`Quantity`), sum(`Price`) from `Ware`;");
    qry.first();
    set_data(ui->Ware_quant, qry.value(0).toString());
    set_data(ui->Ware_cost, qry.value(1).toString());
}
void Accounting::calculate_daily(){
    QString month, year;
    month = english.toString(ui->Acc_date->date(), ("M"));
    year = english.toString(ui->Acc_date->date(), "yyyy");
    qlonglong profit = 0, outcome = 0, income = 0;
    QSqlQuery qry;
    qry.exec("select sum(`Amount`) from `Daily` where `Done` = 'y' and  `Income` = 'y' and month(`Date`) = "+month+" and year(`Date`) = "+year+";");
    qry.first();
    income = qry.value(0).toLongLong();
    qry.exec("select sum(`Amount`) from `Daily` where `Done` = 'y' and  `Income` = 'n' and month(`Date`) = "+month+" and year(`Date`) = "+year+";");
    qry.first();
    outcome = qry.value(0).toLongLong();
    profit = income - outcome;
    set_data(ui->Daily_income, QString::number(income));
    set_data(ui->Daily_outcome, QString::number(outcome));
    set_data(ui->Daily_profit, QString::number(profit));
    if(ui->Daily_profit->text()[0] == '-')
        ui->Daily_profit->setStyleSheet("color: rgb(255, 0, 0);");
    else
        ui->Daily_profit->setStyleSheet("color: rgb(0, 255, 0);");
}
void Accounting::calculate_total(){
    qlonglong op_profit, op_outcome, E_salaries = 0, E_income = 0;
    op_profit = ui->op_profit->text().toLongLong();
    op_outcome = ui->op_undone_cost->text().toLongLong();

    E_salaries += ui->E_clear_salary->text().toDouble();
    qDebug() << E_salaries << endl;
    E_salaries += ui->E_bro_amount->text().toLongLong();
    E_salaries += ui->E_hours_bouns->text().toLongLong();
    E_salaries += ui->E_bouns_amount->text().toLongLong();
    E_salaries += ui->Daily_outcome->text().toLongLong();

    E_income += ui->E_diss_attend_amount->text().toLongLong();
    E_income += ui->E_Diss_amount->text().toLongLong();
    E_income += ui->Daily_income->text().toLongLong();

    set_data(ui->Total_income, QString::number(op_profit + E_income));
    set_data(ui->Total_outcome, QString::number(op_outcome + E_salaries));
    set_data(ui->Profit, QString::number((op_profit + E_income) - (op_outcome + E_salaries)));

    if(ui->Profit->text()[0] == '-')
        ui->Profit->setStyleSheet("color: rgb(255, 0, 0);");
    else
        ui->Profit->setStyleSheet("color: rgb(0, 255, 0);");
}
void Accounting::on_Acc_date_editingFinished()
{
    if(ui->comboBox->currentText() == "مخزن")
        calculate_ware();
    else
        calculate_stock();
    calculate_orders();
    calculate_employee();
    calculate_daily();
    calculate_total();
}
void Accounting::on_comboBox_currentTextChanged(const QString &arg1)
{
    if (arg1 == "مخزن")
        calculate_ware();
    else
        calculate_stock();
}
