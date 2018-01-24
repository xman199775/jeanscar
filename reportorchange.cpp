#include "reportorchange.h"
#include "ui_reportorchange.h"

reportorchange::reportorchange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reportorchange)
{
    ui->setupUi(this);
}

reportorchange::~reportorchange()
{
    delete ui;
}

void reportorchange::on_pushButton_clicked()
{

}
