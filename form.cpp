#include "form.h"
#include "ui_form.h"
#include <QMessageBox>
#include <QSqlQuery>
Form::Form(QWidget *parent, QString o) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    opcode=o;
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{


}
