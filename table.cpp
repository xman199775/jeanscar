#include "table.h"
#include "ui_table.h"
#include <QTextBrowser>
#include <QLayout>
#include <QSqlQuery>

//background-color: rgb(255, 128, 0);

void table::clear_all(){
    ui->fri1->setStyleSheet("");
    ui->fri2->setStyleSheet("");
    ui->fri3->setStyleSheet("");
    ui->fri4->setStyleSheet("");
    ui->fri5->setStyleSheet("");
    ui->fri6->setStyleSheet("");
    ui->monday1->setStyleSheet("");
    ui->monday2->setStyleSheet("");
    ui->monday3->setStyleSheet("");
    ui->monday4->setStyleSheet("");
    ui->monday5->setStyleSheet("");
    ui->monday6->setStyleSheet("");
    ui->sat1->setStyleSheet("");
    ui->sat2->setStyleSheet("");
    ui->sat3->setStyleSheet("");
    ui->sat4->setStyleSheet("");
    ui->sat5->setStyleSheet("");
    ui->sat6->setStyleSheet("");
    ui->thu1->setStyleSheet("");
    ui->thu2->setStyleSheet("");
    ui->thu3->setStyleSheet("");
    ui->thu4->setStyleSheet("");
    ui->thu5->setStyleSheet("");
    ui->thu6->setStyleSheet("");
    ui->tuesday1->setStyleSheet("");
    ui->tuesday2->setStyleSheet("");
    ui->tuesday3->setStyleSheet("");
    ui->tuesday4->setStyleSheet("");
    ui->tuesday5->setStyleSheet("");
    ui->tuesday6->setStyleSheet("");
    ui->wed1->setStyleSheet("");
    ui->wed2->setStyleSheet("");
    ui->wed3->setStyleSheet("");
    ui->wed4->setStyleSheet("");
    ui->wed5->setStyleSheet("");
    ui->wed6->setStyleSheet("");

    ui->monday->setStyleSheet("");
    ui->monday_2->setStyleSheet("");
    ui->tuesday->setStyleSheet("");
    ui->tuesday_2->setStyleSheet("");
    ui->wedensday->setStyleSheet("");
    ui->wedensday_2->setStyleSheet("");
    ui->thursday->setStyleSheet("");
    ui->thursday_2->setStyleSheet("");
    ui->friday->setStyleSheet("");
    ui->friday_2->setStyleSheet("");
    ui->saturday->setStyleSheet("");
    ui->saturday_2->setStyleSheet("");

}

void table::set_curr(QDate date1){
    QLocale english(QLocale::English, QLocale::UnitedStates);
    QString cur = english.toString(date1,"dd-MM-yyyy");
    QString mon, tue, wed, thu, fri, sat;
    mon = ui->monday->text();
    tue = ui->tuesday->text();
    wed = ui->wedensday->text();
    thu = ui->thursday->text();
    fri = ui->friday->text();
    sat = ui->saturday->text();
    if (cur == mon){
        ui->monday->setStyleSheet("background-color: rgb(255, 128, 0);");
        ui->monday_2->setStyleSheet("background-color: rgb(255, 128, 0);");
    }
    else if (cur == tue){
        ui->tuesday->setStyleSheet("background-color: rgb(255, 128, 0);");
        ui->tuesday_2->setStyleSheet("background-color: rgb(255, 128, 0);");
    }
    else if (cur == wed) {
        ui->wedensday->setStyleSheet("background-color: rgb(255, 128, 0);");
        ui->wedensday_2->setStyleSheet("background-color: rgb(255, 128, 0);");
    }
    else if (cur == thu) {
        ui->thursday->setStyleSheet("background-color: rgb(255, 128, 0);");
        ui->thursday_2->setStyleSheet("background-color: rgb(255, 128, 0);");
    }
    else if (cur == fri) {
        ui->friday->setStyleSheet("background-color: rgb(255, 128, 0);");
        ui->friday_2->setStyleSheet("background-color: rgb(255, 128, 0);");
    }
    else if (cur == sat) {
        ui->saturday->setStyleSheet("background-color: rgb(255, 128, 0);");
        ui->saturday_2->setStyleSheet("background-color: rgb(255, 128, 0);");
    }
}

void table::set11to5(QDate date){
    QSqlQuery qry;
    QLocale english(QLocale::English, QLocale::UnitedStates);
    QString sdate = english.toString(date,"yyyy-MM-dd");
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
    ui->monday->setText(date.addDays(mon).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(mon) , "yyyy-MM-dd");
    count(date.addDays(mon), ui->monday_flat);
    qry.exec("select s.`H11` , o.`Car-det`,IF(o.`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(o.`flat` = '1' ,CONCAT('أرضيه:', o.`flat_color`), 'أرضيه : لا يوجد')  from `Order` AS o ,  `Sec` AS s where o.`Order-num` = s.`H11`  and s.`Date` = '"+sdate+"';");
    qry.first();
    ui->monday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a")
    {
        ui->monday1->setStyleSheet("background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->monday1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->monday1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a")
    {
        ui->monday2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->monday2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->monday2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->monday3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->monday3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->monday3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a")
    {
        ui->monday4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->monday4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->monday4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a")
    {
        ui->monday5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->monday5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->monday5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a")
    {
        ui->monday6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->monday6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->monday6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //tuesday

    ui->tuesday->setText((date.addDays(tue)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(tue) , "yyyy-MM-dd");
    count(date.addDays(tue), ui->tue_flat);
    qry.exec("select `H11` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->tuesday1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->tuesday1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->tuesday1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->tuesday2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->tuesday2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->tuesday2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->tuesday3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->tuesday3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->tuesday3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->tuesday4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->tuesday4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->tuesday4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->tuesday5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->tuesday5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->tuesday5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->tuesday6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->tuesday6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->tuesday6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //wedensday

    ui->wedensday->setText((date.addDays(wed)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(wed) , "yyyy-MM-dd");
    count(date.addDays(wed), ui->wed_flat);
    qry.exec("select `H11` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->wed1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->wed1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->wed1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->wed2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->wed2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->wed2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->wed3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->wed3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->wed3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->wed4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->wed4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->wed4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->wed5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->wed5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->wed5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->wed6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->wed6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->wed6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //thuresday
    ui->thursday->setText((date.addDays(thu)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(thu) , "yyyy-MM-dd");
    count(date.addDays(thu), ui->thu_flat);
    qry.exec("select `H11` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->thu1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->thu1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->thu1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->thu2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->thu2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->thu2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->thu3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->thu3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->thu3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->thu4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->thu4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->thu4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->thu5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->thu5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->thu5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->thu6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->thu6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->thu6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //friday
    ui->friday->setText((date.addDays(fri)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(fri) , "yyyy-MM-dd");
    count(date.addDays(fri), ui->friday_flat);
    qry.exec("select `H11` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->fri1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->fri1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->fri1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->fri2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->fri2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->fri2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->fri3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->fri3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->fri3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->fri4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->fri4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->fri4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->fri5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->fri5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->fri5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->fri6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->fri6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->fri6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //saturday
    ui->saturday->setText((date.addDays(sat)).toString("dd-MM-yyyy"));
    sdate =english.toString(date.addDays(sat) , "yyyy-MM-dd");
    count(date.addDays(sat), ui->sat_flat);
    qry.exec("select `H11` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11` and `H11` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->sat1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->sat1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->sat1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11a` and `H11a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->sat2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->sat2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->sat2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11b` and `H11b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->sat3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->sat3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->sat3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11c` and `H11c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->sat4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->sat4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->sat4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11d` and `H11d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->sat5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->sat5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->sat5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H11e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H11e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H11e` and `H11e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->sat6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "a")){
        ui->sat6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "a"){
        ui->sat6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
}

void table::set2to8(QDate date){
    QSqlQuery qry;
    QLocale english(QLocale::English, QLocale::UnitedStates);
    QString sdate = english.toString(date,"yyyy-MM-dd");
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
    ui->monday->setText(date.addDays(mon).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(mon) , "yyyy-MM-dd");
    count(date.addDays(mon), ui->monday_flat);
    qry.exec("select s.`H2` , o.`Car-det`,IF(o.`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(o.`flat` = '1' ,CONCAT('أرضيه:', o.`flat_color`), 'أرضيه : لا يوجد')  from `Order` AS o ,  `Sec` AS s where o.`Order-num` = s.`H2`  and s.`Date` = '"+sdate+"';");
    qry.first();
    ui->monday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b")
    {
        ui->monday1->setStyleSheet("background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->monday1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->monday1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b")
    {
        ui->monday2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->monday2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->monday2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->monday3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->monday3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->monday3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b")
    {
        ui->monday4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->monday4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->monday4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b")
    {
        ui->monday5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->monday5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->monday5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b")
    {
        ui->monday6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->monday6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->monday6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //tuesday

    ui->tuesday->setText((date.addDays(tue)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(tue) , "yyyy-MM-dd");
    count(date.addDays(tue), ui->tue_flat);
    qry.exec("select `H2` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->tuesday1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->tuesday1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->tuesday1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->tuesday2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->tuesday2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->tuesday2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->tuesday3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->tuesday3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->tuesday3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->tuesday4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->tuesday4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->tuesday4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->tuesday5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->tuesday5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->tuesday5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->tuesday6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->tuesday6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->tuesday6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //wedensday

    ui->wedensday->setText((date.addDays(wed)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(wed) , "yyyy-MM-dd");
    count(date.addDays(wed), ui->wed_flat);
    qry.exec("select `H2` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->wed1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->wed1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->wed1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->wed2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->wed2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->wed2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->wed3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->wed3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->wed3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->wed4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->wed4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->wed4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->wed5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->wed5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->wed5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->wed6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->wed6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->wed6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //thuresday
    ui->thursday->setText((date.addDays(thu)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(thu) , "yyyy-MM-dd");
    count(date.addDays(thu), ui->thu_flat);
    qry.exec("select `H2` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->thu1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->thu1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->thu1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->thu2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->thu2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->thu2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->thu3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->thu3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->thu3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->thu4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->thu4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->thu4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->thu5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->thu5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->thu5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->thu6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->thu6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->thu6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //friday
    ui->friday->setText((date.addDays(fri)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(fri) , "yyyy-MM-dd");
    count(date.addDays(fri), ui->friday_flat);
    qry.exec("select `H2` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->fri1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->fri1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->fri1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->fri2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->fri2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->fri2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->fri3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->fri3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->fri3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->fri4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->fri4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->fri4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->fri5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->fri5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->fri5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->fri6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->fri6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->fri6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //saturday
    ui->saturday->setText((date.addDays(sat)).toString("dd-MM-yyyy"));
    sdate =english.toString(date.addDays(sat) , "yyyy-MM-dd");
    count(date.addDays(sat), ui->sat_flat);
    qry.exec("select `H2` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2` and `H2` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->sat1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->sat1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->sat1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2a` and `H2a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->sat2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->sat2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->sat2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2b` and `H2b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->sat3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->sat3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->sat3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2c` and `H2c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->sat4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->sat4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->sat4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2d` and `H2d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->sat5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->sat5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->sat5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H2e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H2e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H2e` and `H2e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->sat6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "b")){
        ui->sat6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "b"){
        ui->sat6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
}

void table::set5to11(QDate date){
    QSqlQuery qry;
    QLocale english(QLocale::English, QLocale::UnitedStates);
    QString sdate = english.toString(date,"yyyy-MM-dd");
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
    ui->monday->setText(date.addDays(mon).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(mon) , "yyyy-MM-dd");
    count(date.addDays(mon), ui->monday_flat);
    qry.exec("select s.`H5` , o.`Car-det`,IF(o.`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(o.`flat` = '1' ,CONCAT('أرضيه:', o.`flat_color`), 'أرضيه : لا يوجد')  from `Order` AS o ,  `Sec` AS s where o.`Order-num` = s.`H5`  and s.`Date` = '"+sdate+"';");
    qry.first();
    ui->monday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c")
    {
        ui->monday1->setStyleSheet("background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->monday1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->monday1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c")
    {
        ui->monday2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->monday2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->monday2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->monday3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->monday3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->monday3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c")
    {
        ui->monday4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->monday4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->monday4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c")
    {
        ui->monday5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->monday5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->monday5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->monday6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c")
    {
        ui->monday6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->monday6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->monday6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->monday6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //tuesday

    ui->tuesday->setText((date.addDays(tue)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(tue) , "yyyy-MM-dd");
    count(date.addDays(tue), ui->tue_flat);
    qry.exec("select `H5` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->tuesday1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->tuesday1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->tuesday1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->tuesday2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->tuesday2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->tuesday2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->tuesday3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->tuesday3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->tuesday3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->tuesday4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->tuesday4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->tuesday4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->tuesday5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->tuesday5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->tuesday5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->tuesday6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->tuesday6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->tuesday6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->tuesday6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->tuesday6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //wedensday

    ui->wedensday->setText((date.addDays(wed)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(wed) , "yyyy-MM-dd");
    count(date.addDays(wed), ui->wed_flat);
    qry.exec("select `H5` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->wed1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->wed1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->wed1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->wed2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->wed2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->wed2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->wed3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->wed3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->wed3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->wed4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->wed4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->wed4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->wed5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->wed5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->wed5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->wed6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->wed6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->wed6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->wed6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->wed6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //thuresday
    ui->thursday->setText((date.addDays(thu)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(thu) , "yyyy-MM-dd");
    count(date.addDays(thu), ui->thu_flat);
    qry.exec("select `H5` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->thu1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->thu1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->thu1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->thu2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->thu2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->thu2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->thu3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->thu3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->thu3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->thu4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->thu4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->thu4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->thu5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->thu5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->thu5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد') from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->thu6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->thu6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->thu6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->thu6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->thu6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //friday
    ui->friday->setText((date.addDays(fri)).toString("dd-MM-yyyy"));
    sdate = english.toString(date.addDays(fri) , "yyyy-MM-dd");
    count(date.addDays(fri), ui->friday_flat);
    qry.exec("select `H5` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->fri1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->fri1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->fri1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->fri2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->fri2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->fri2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->fri3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->fri3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->fri3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->fri4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->fri4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->fri4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->fri5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->fri5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->fri5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->fri6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->fri6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->fri6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->fri6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->fri6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    //saturday
    ui->saturday->setText((date.addDays(sat)).toString("dd-MM-yyyy"));
    sdate =english.toString(date.addDays(sat) , "yyyy-MM-dd");
    qry.exec("select `H5` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat1->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5` and `H5` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->sat1->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->sat1->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat1->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->sat1->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5a` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5a` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat2->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5a` and `H5a` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->sat2->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->sat2->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat2->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->sat2->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5b` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5b` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat3->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5b` and `H5b` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->sat3->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->sat3->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat3->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->sat3->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5c` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5c` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat4->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5c` and `H5c` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->sat4->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->sat4->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat4->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->sat4->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5d` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5d` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat5->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5d` and `H5d` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->sat5->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->sat5->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat5->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->sat5->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
    qry.exec("select `H5e` ,`Car-det`,IF(`wheel` = '1', 'طاره : نعم', 'طاره : لا يوجد'), if(`flat` = '1' ,CONCAT('أرضيه:', `flat_color`), 'أرضيه : لا يوجد')  from `Order` , `Customer` , `Sec` where `Order-num` = `H5e` and `C-code` = `Cnum`  and `Date` = '"+sdate+"';");
    qry.first();
    ui->sat6->setText(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" +  qry.value(2).toString() + "\n"  + qry.value(3).toString() );
    qry.exec("select `Moagal`, `Done`,`Bouns` , `Delvtime`, `time` from `Order` , `Sec` where `Order-num` = `H5e` and `H5e` = "+qry.value(0).toString()+"");
    qry.first();
    if (qry.value(0).toInt() == 1 && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->sat6->setStyleSheet("﻿background-color: rgb(0, 205, 21);");
    }
    else if (qry.value(0).toInt() == 1 && (qry.value(3).toString() != sdate || qry.value(4).toString() != "c")){
        ui->sat6->setStyleSheet("background-color: rgb(0, 195, 246);");
    }
    if (qry.value(2).toString() == "1" ){
        ui->sat6->setStyleSheet("background-color: rgb(255, 50, 0);");
    }
    if(qry.value(1).toString() == "1" && qry.value(3).toString() == sdate && qry.value(4).toString() == "c"){
        ui->sat6->setStyleSheet("background-color: rgb(255, 253, 0);");
    }
}

void table::count(QDate date, QLabel* label){
    QSqlQuery qry;
    QLocale english(QLocale::English, QLocale::UnitedStates);
    qry.exec("select sum(`flat`), sum(`wheel`) from `Order` where `Delvtime` = '" + english.toString(date,"yyyy-MM-dd") +"';");
    qry.first();
    label->setText(" عدد الدواسات : "  + qry.value(0).toString() + " \n" + " عدد الطارات : " + qry.value(1).toString());

}
table::table(QWidget *parent, QDate date1) :
    QMainWindow(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);
    cur = date1;
    date = date1;
    set11to5(date);
    ui->change_date->setDate(QDate::currentDate());
    set_curr(date1);
}

table::~table()
{
    delete ui;
}

void table::on_comboBox_currentIndexChanged(const QString &arg1)
{
    clear_all();
    if (arg1 == "11:5"){
        set11to5(date);
    }
    else if(arg1 == "2:8") {
        set2to8(date);
    }
    else{
        set5to11(date);
    }
    set_curr(date);
}

void table::on_pushButton_clicked()//prev
{
    clear_all();
    QSqlQuery qry;
    QLocale english(QLocale::English, QLocale::UnitedStates);
    date = date.addDays(-7);
    QDate date1 = date;
    if(ui->comboBox->currentText() == "11:5")
        set11to5(date1);
    else if (ui->comboBox->currentText() == "2:8")
        set2to8(date1);
    else
        set5to11(date1);
    set_curr(cur);
}

void table::on_pushButton_2_clicked()//next
{
    clear_all();
    QSqlQuery qry;
    QLocale english(QLocale::English, QLocale::UnitedStates);
    date = date.addDays(7);
    QDate date1 = date;
    if(ui->comboBox->currentText() == "11:5"){
        set11to5(date1);
    }
    else if (ui->comboBox->currentText() == "2:8")
        set2to8(date1);
    else
        set5to11(date1);
    set_curr(cur);
}

void table::on_pushButton_3_clicked()
{
    this->close();
}

void table::on_change_date_editingFinished()
{
    clear_all();
    QSqlQuery qry;
    QLocale english(QLocale::English, QLocale::UnitedStates);
    date = ui->change_date->date();
    QDate date1 = date;
    cur = date;
    if(ui->comboBox->currentText() == "11:5")
        set11to5(date1);
    else if (ui->comboBox->currentText() == "2:8")
        set2to8(date1);
    else
        set5to11(date1);
    set_curr(cur);
}
