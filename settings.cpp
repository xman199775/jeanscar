#include "settings.h"
#include "ui_settings.h"
#include <QtSql>
#include <QMessageBox>
Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    QSqlQuery qry;
    qry.exec("select `Flats`, `Wheels`from `Settings`;");
    qry.first();
    ui->nFlats->setValue(qry.value(0).toInt());
    ui->nWheels->setValue(qry.value(1).toInt());
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_clicked()
{
    QString color = ui->wheel_color->text();
    QSqlQuery qry;
    QMessageBox mb(this);
    bool qryDone = qry.exec("update `Settings` set `Flats` = " + QString::number(ui->nFlats->value()) +", `Wheels` = " + QString::number(ui->nWheels->value()) + " where `id` = 1;");
    bool qryDone2 = 0;
    if (color != "" && color != " "){
        qryDone2 =  qry.exec("insert into `Flat_colors` (`Color`) VALUES ('"+color+"');");
    }
    if(qryDone && qryDone2){
        mb.setWindowTitle("تم");
        mb.setText("تم تعديل الدواسات والطارات");
    }
    else if(qryDone && !qryDone2){
        mb.setWindowTitle("تم");
        mb.setText("تم تعديل عدد الدواسات والطارات ولم يتم إضافه اللون للدواسة!");
    }
    else{
        mb.setWindowTitle("خطأ");
        mb.setText("لم يتم التعديل");
    }
    mb.exec();
}
