#include "form1.h"
#include "ui_form1.h"
#include <QSqlQuery>
#include <QDate>
#include<QDebug>
#include <iostream>
using namespace std;


Form1::Form1(QWidget *parent,QDate date) :
    QWidget(parent),
    ui(new Ui::Form1)
{//  ui->friday->setStyleSheet("color: rgb(0, 85, 255);");
    ui->setupUi(this);
    date1=date;
    QSqlQuery qry;
    QLocale english(QLocale::English, QLocale::UnitedStates);
    QString sdate = english.toString(date1,"yyyy-MM-dd");
    int x = date.dayOfWeek() - 1;
    short mon , tue , wed , thu , fri , sat;
    mon = tue = wed = thu = fri = sat = 0;
    switch (x){
    case 0:{
        tue = 1;
        wed = 2;
        thu = 3;
        fri = 4;
        sat = 5;
        break;
    }
    case 1:{
        mon = -1;
        wed = 1;
        thu = 2;
        fri = 3;
        sat = 4;
        break;
    }
    case 2:{
        mon = -2;
        tue = -1;
        thu = 1;
        fri = 2;
        sat = 3;
        break;
    }
    case 3:{
        mon = -3;
        tue = -2;
        wed = -1;
        fri = 1;
        sat = 2;
        break;
    }
    case 4:{
        mon = -4;
        tue = -3;
        wed = -2;
        thu = -1;
        sat = 1;
        break;
    }
    case 5:{
        mon = -5;
        tue = -4;
        wed = -3;
        thu = -2;
        fri = -1;
        break;
    }
    default:
        break;
    }
    //monday
    ui->monday->setText(date.addDays(mon).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(mon) , "yyyy-MM-dd");
    qry.exec("select s.`H11` , o.`Car-det`  from `Order` AS o ,  `Sec` AS s where o.`Order-num` = s.`H11`  and s.`Date` = '"+sdate+"';");
    qry.first();
    ui->monday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1)
    {
        ui->monday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1)
    {
        ui->monday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Car-det` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1)
    {
        ui->monday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1)
    {
        ui->monday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1)
    {
        ui->monday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1)
    {
        ui->monday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1)
    {
        ui->monday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1)
    {
        ui->monday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2c` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` , `Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5c` , `Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //tuesday
    ui->tuesday->setText((date.addDays(tue)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(tue) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString());
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString());
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //wedensday
    ui->wednsday->setText((date.addDays(wed)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(wed) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //thursaday
    ui->thursday->setText((date.addDays(thu)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(thu) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //friday
    ui->friday->setText((date.addDays(fri)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(fri) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }


    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //sauterday
    ui->sauterday->setText((date.addDays(sat)).toString("dd-MM-yyyy"));
    sdate =english.toString(date.addDays(sat) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }


    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
}




Form1::~Form1()
{
    delete ui;
}

void Form1::on_pushButton_clicked()//حجز
{
    this->close();
}

void Form1::on_pushButton_2_clicked() //السابق
{
    ui->friday1->setStyleSheet("");
    ui->friday1a->setStyleSheet("");
    ui->friday1b->setStyleSheet("");
    ui->friday1c->setStyleSheet("");
    ui->friday1d->setStyleSheet("");
    ui->friday1e->setStyleSheet("");
    ui->friday2->setStyleSheet("");
    ui->friday2a->setStyleSheet("");
    ui->friday2b->setStyleSheet("");
    ui->friday2c->setStyleSheet("");
    ui->friday2d->setStyleSheet("");
    ui->friday2e->setStyleSheet("");
    ui->friday3->setStyleSheet("");
    ui->friday3a->setStyleSheet("");
    ui->friday3b->setStyleSheet("");
    ui->friday3c->setStyleSheet("");
    ui->friday3d->setStyleSheet("");
    ui->friday3e->setStyleSheet("");
    ui->monday1->setStyleSheet("");
    ui->monday1a->setStyleSheet("");
    ui->monday1b->setStyleSheet("");
    ui->monday1c->setStyleSheet("");
    ui->monday1d->setStyleSheet("");
    ui->monday1e->setStyleSheet("");
    ui->monday2->setStyleSheet("");
    ui->monday2a->setStyleSheet("");
    ui->monday2b->setStyleSheet("");
    ui->monday2c->setStyleSheet("");
    ui->monday2d->setStyleSheet("");
    ui->monday2e->setStyleSheet("");
    ui->monday3->setStyleSheet("");
    ui->monday3a->setStyleSheet("");
    ui->monday3b->setStyleSheet("");
    ui->monday3c->setStyleSheet("");
    ui->monday3d->setStyleSheet("");
    ui->monday3e->setStyleSheet("");
    ui->saturday1->setStyleSheet("");
    ui->saturday1a->setStyleSheet("");
    ui->saturday1b->setStyleSheet("");
    ui->saturday1c->setStyleSheet("");
    ui->saturday1d->setStyleSheet("");
    ui->saturday1e->setStyleSheet("");
    ui->saturday2->setStyleSheet("");
    ui->saturday2a->setStyleSheet("");
    ui->saturday2b->setStyleSheet("");
    ui->saturday2d->setStyleSheet("");
    ui->saturday2c->setStyleSheet("");
    ui->saturday2e->setStyleSheet("");
    ui->saturday3->setStyleSheet("");
    ui->saturday3a->setStyleSheet("");
    ui->saturday3b->setStyleSheet("");
    ui->saturday3c->setStyleSheet("");
    ui->saturday3d->setStyleSheet("");
    ui->saturday3e->setStyleSheet("");
    ui->thursday1->setStyleSheet("");
    ui->thursday1a->setStyleSheet("");
    ui->thursday1b->setStyleSheet("");
    ui->thursday1c->setStyleSheet("");
    ui->thursday1d->setStyleSheet("");
    ui->thursday1e->setStyleSheet("");
    ui->thursday2->setStyleSheet("");
    ui->thursday2a->setStyleSheet("");
    ui->thursday2b->setStyleSheet("");
    ui->thursday2c->setStyleSheet("");
    ui->thursday2d->setStyleSheet("");
    ui->thursday2e->setStyleSheet("");
    ui->thursday3->setStyleSheet("");
    ui->thursday3a->setStyleSheet("");
    ui->thursday3b->setStyleSheet("");
    ui->thursday3c->setStyleSheet("");
    ui->thursday3d->setStyleSheet("");
    ui->thursday3e->setStyleSheet("");
    ui->tuesday1->setStyleSheet("");
    ui->tuesday1a->setStyleSheet("");
    ui->tuesday1b->setStyleSheet("");
    ui->tuesday1c->setStyleSheet("");
    ui->tuesday1d->setStyleSheet("");
    ui->tuesday1e->setStyleSheet("");
    ui->tuesday2->setStyleSheet("");
    ui->tuesday2a->setStyleSheet("");
    ui->tuesday2b->setStyleSheet("");
    ui->tuesday2c->setStyleSheet("");
    ui->tuesday2d->setStyleSheet("");
    ui->tuesday2e->setStyleSheet("");
    ui->tuesday3->setStyleSheet("");
    ui->tuesday3a->setStyleSheet("");
    ui->tuesday3b->setStyleSheet("");
    ui->tuesday3c->setStyleSheet("");
    ui->tuesday3d->setStyleSheet("");
    ui->tuesday3e->setStyleSheet("");
    ui->wdensday1->setStyleSheet("");
    ui->wdensday1a->setStyleSheet("");
    ui->wdensday1b->setStyleSheet("");
    ui->wdensday1c->setStyleSheet("");
    ui->wdensday1d->setStyleSheet("");
    ui->wdensday1e->setStyleSheet("");
    ui->wdensday2->setStyleSheet("");
    ui->wdensday2a->setStyleSheet("");
    ui->wdensday2b->setStyleSheet("");
    ui->wdensday2c->setStyleSheet("");
    ui->wdensday2d->setStyleSheet("");
    ui->wdensday2e->setStyleSheet("");
    ui->wdensday3->setStyleSheet("");
    ui->wdensday3a->setStyleSheet("");
    ui->wdensday3b->setStyleSheet("");
    ui->wdensday3c->setStyleSheet("");
    ui->wdensday3d->setStyleSheet("");
    ui->wdensday3e->setStyleSheet("");
    QSqlQuery qry;
    QLocale english(QLocale::English, QLocale::UnitedStates);
    date1=date1.addDays(-7);
    QDate date=date1;
    QString sdate = english.toString(date1,"yyyy-MM-dd");
    qry.exec("select weekday(`Date`) from `Sec` where `Date` = '"+sdate+"'");
    int x = date.dayOfWeek() - 1;
    short mon , tue , wed , thu , fri , sat;
    mon = tue = wed = thu = fri = sat = 0;
    switch (x){
    case 0:{
        tue = 1;
        wed = 2;
        thu = 3;
        fri = 4;
        sat = 5;
        break;
    }
    case 1:{
        mon = -1;
        wed = 1;
        thu = 2;
        fri = 3;
        sat = 4;
        break;
    }
    case 2:{
        mon = -2;
        tue = -1;
        thu = 1;
        fri = 2;
        sat = 3;
        break;
    }
    case 3:{
        mon = -3;
        tue = -2;
        wed = -1;
        fri = 1;
        sat = 2;
        break;
    }
    case 4:{
        mon = -4;
        tue = -3;
        wed = -2;
        thu = -1;
        sat = 1;
        break;
    }
    case 5:{
        mon = -5;
        tue = -4;
        wed = -3;
        thu = -2;
        fri = -1;
        break;
    }
    default:
        break;
    }
    //monday
    ui->monday->setText(date.addDays(mon).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(mon) , "yyyy-MM-dd");
    qry.exec("select s.`H11` , o.`Car-det`  from `Order` AS o ,  `Sec` AS s where o.`Order-num` = s.`H11`  and s.`Date` = '"+sdate+"';");
    qry.first();
    ui->monday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2c` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` , `Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5c` , `Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //tuesday
    ui->tuesday->setText((date.addDays(tue)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(tue) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString());
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString());
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //wedensday
    ui->wednsday->setText((date.addDays(wed)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(wed) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //thursaday
    ui->thursday->setText((date.addDays(thu)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(thu) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //friday
    ui->friday->setText((date.addDays(fri)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(fri) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }


    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //sauterday
    ui->sauterday->setText((date.addDays(sat)).toString("dd-MM-yyyy"));
    sdate =english.toString(date.addDays(sat) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }


    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
}


void Form1::on_pushButton_3_clicked()//التالي
{
    ui->friday1->setStyleSheet("");
    ui->friday1a->setStyleSheet("");
    ui->friday1b->setStyleSheet("");
    ui->friday1c->setStyleSheet("");
    ui->friday1d->setStyleSheet("");
    ui->friday1e->setStyleSheet("");
    ui->friday2->setStyleSheet("");
    ui->friday2a->setStyleSheet("");
    ui->friday2b->setStyleSheet("");
    ui->friday2c->setStyleSheet("");
    ui->friday2d->setStyleSheet("");
    ui->friday2e->setStyleSheet("");
    ui->friday3->setStyleSheet("");
    ui->friday3a->setStyleSheet("");
    ui->friday3b->setStyleSheet("");
    ui->friday3c->setStyleSheet("");
    ui->friday3d->setStyleSheet("");
    ui->friday3e->setStyleSheet("");
    ui->monday1->setStyleSheet("");
    ui->monday1a->setStyleSheet("");
    ui->monday1b->setStyleSheet("");
    ui->monday1c->setStyleSheet("");
    ui->monday1d->setStyleSheet("");
    ui->monday1e->setStyleSheet("");
    ui->monday2->setStyleSheet("");
    ui->monday2a->setStyleSheet("");
    ui->monday2b->setStyleSheet("");
    ui->monday2c->setStyleSheet("");
    ui->monday2d->setStyleSheet("");
    ui->monday2e->setStyleSheet("");
    ui->monday3->setStyleSheet("");
    ui->monday3a->setStyleSheet("");
    ui->monday3b->setStyleSheet("");
    ui->monday3c->setStyleSheet("");
    ui->monday3d->setStyleSheet("");
    ui->monday3e->setStyleSheet("");
    ui->saturday1->setStyleSheet("");
    ui->saturday1a->setStyleSheet("");
    ui->saturday1b->setStyleSheet("");
    ui->saturday1c->setStyleSheet("");
    ui->saturday1d->setStyleSheet("");
    ui->saturday1e->setStyleSheet("");
    ui->saturday2->setStyleSheet("");
    ui->saturday2a->setStyleSheet("");
    ui->saturday2b->setStyleSheet("");
    ui->saturday2d->setStyleSheet("");
    ui->saturday2c->setStyleSheet("");
    ui->saturday2e->setStyleSheet("");
    ui->saturday3->setStyleSheet("");
    ui->saturday3a->setStyleSheet("");
    ui->saturday3b->setStyleSheet("");
    ui->saturday3c->setStyleSheet("");
    ui->saturday3d->setStyleSheet("");
    ui->saturday3e->setStyleSheet("");
    ui->thursday1->setStyleSheet("");
    ui->thursday1a->setStyleSheet("");
    ui->thursday1b->setStyleSheet("");
    ui->thursday1c->setStyleSheet("");
    ui->thursday1d->setStyleSheet("");
    ui->thursday1e->setStyleSheet("");
    ui->thursday2->setStyleSheet("");
    ui->thursday2a->setStyleSheet("");
    ui->thursday2b->setStyleSheet("");
    ui->thursday2c->setStyleSheet("");
    ui->thursday2d->setStyleSheet("");
    ui->thursday2e->setStyleSheet("");
    ui->thursday3->setStyleSheet("");
    ui->thursday3a->setStyleSheet("");
    ui->thursday3b->setStyleSheet("");
    ui->thursday3c->setStyleSheet("");
    ui->thursday3d->setStyleSheet("");
    ui->thursday3e->setStyleSheet("");
    ui->tuesday1->setStyleSheet("");
    ui->tuesday1a->setStyleSheet("");
    ui->tuesday1b->setStyleSheet("");
    ui->tuesday1c->setStyleSheet("");
    ui->tuesday1d->setStyleSheet("");
    ui->tuesday1e->setStyleSheet("");
    ui->tuesday2->setStyleSheet("");
    ui->tuesday2a->setStyleSheet("");
    ui->tuesday2b->setStyleSheet("");
    ui->tuesday2c->setStyleSheet("");
    ui->tuesday2d->setStyleSheet("");
    ui->tuesday2e->setStyleSheet("");
    ui->tuesday3->setStyleSheet("");
    ui->tuesday3a->setStyleSheet("");
    ui->tuesday3b->setStyleSheet("");
    ui->tuesday3c->setStyleSheet("");
    ui->tuesday3d->setStyleSheet("");
    ui->tuesday3e->setStyleSheet("");
    ui->wdensday1->setStyleSheet("");
    ui->wdensday1a->setStyleSheet("");
    ui->wdensday1b->setStyleSheet("");
    ui->wdensday1c->setStyleSheet("");
    ui->wdensday1d->setStyleSheet("");
    ui->wdensday1e->setStyleSheet("");
    ui->wdensday2->setStyleSheet("");
    ui->wdensday2a->setStyleSheet("");
    ui->wdensday2b->setStyleSheet("");
    ui->wdensday2c->setStyleSheet("");
    ui->wdensday2d->setStyleSheet("");
    ui->wdensday2e->setStyleSheet("");
    ui->wdensday3->setStyleSheet("");
    ui->wdensday3a->setStyleSheet("");
    ui->wdensday3b->setStyleSheet("");
    ui->wdensday3c->setStyleSheet("");
    ui->wdensday3d->setStyleSheet("");
    ui->wdensday3e->setStyleSheet("");
    QSqlQuery qry;
    QLocale english(QLocale::English, QLocale::UnitedStates);
    date1=date1.addDays(7);
    QDate date=date1;
    QString sdate = english.toString(date1,"yyyy-MM-dd");
    qry.exec("select weekday(`Date`) from `Sec` where `Date` = '"+sdate+"'");
    int x = date.dayOfWeek() - 1;
    short mon , tue , wed , thu , fri , sat;
    mon = tue = wed = thu = fri = sat = 0;
    switch (x){
    case 0:{
        tue = 1;
        wed = 2;
        thu = 3;
        fri = 4;
        sat = 5;
        break;
    }
    case 1:{
        mon = -1;
        wed = 1;
        thu = 2;
        fri = 3;
        sat = 4;
        break;
    }
    case 2:{
        mon = -2;
        tue = -1;
        thu = 1;
        fri = 2;
        sat = 3;
        break;
    }
    case 3:{
        mon = -3;
        tue = -2;
        wed = -1;
        fri = 1;
        sat = 2;
        break;
    }
    case 4:{
        mon = -4;
        tue = -3;
        wed = -2;
        thu = -1;
        sat = 1;
        break;
    }
    case 5:{
        mon = -5;
        tue = -4;
        wed = -3;
        thu = -2;
        fri = -1;
        break;
    }
    default:
        break;
    }
    //monday
    ui->monday->setText(date.addDays(mon).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(mon) , "yyyy-MM-dd");
    qry.exec("select s.`H11` , o.`Car-det`  from `Order` AS o ,  `Sec` AS s where o.`Order-num` = s.`H11`  and s.`Date` = '"+sdate+"';");
    qry.first();
    ui->monday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2c` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` , `Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5c` , `Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->monday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //tuesday
    ui->tuesday->setText((date.addDays(tue)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(tue) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString());
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString());
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->tuesday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //wedensday
    ui->wednsday->setText((date.addDays(wed)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(wed) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wdensday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->wdensday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //thursaday
    ui->thursday->setText((date.addDays(thu)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(thu) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thursday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->thursday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //friday
    ui->friday->setText((date.addDays(fri)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(fri) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }


    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det` from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->friday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->friday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    //sauterday
    ui->sauterday->setText((date.addDays(sat)).toString("dd-MM-yyyy"));
    sdate =english.toString(date.addDays(sat) , "yyyy-MM-dd");
    qry.exec("select `H11` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H11c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H11e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday1e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday1e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }


    qry.exec("select `H2` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H2c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H2e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday2e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday2e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5a` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3a->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3a->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5b` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3b->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3b->setStyleSheet("background-color:rgb(208, 255, 0)");
    }

    qry.exec("select `H5c` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3c->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3c->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5d` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3d->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3d->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
    qry.exec("select `H5e` ,`Car-det`  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->saturday3e->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() );
    qry.exec("select `Moagal` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1){
        ui->saturday3e->setStyleSheet("background-color:rgb(208, 255, 0)");
    }
}
