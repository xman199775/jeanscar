#include "print.h"
#include "ui_print.h"
#include <QMessageBox>
Print::Print(QString myHTML, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Print)
{
    ui->setupUi(this);
    html = myHTML;
    ui->pdf->setHtml(html);
    printer = new QPrinter;
    pd = new QPrintDialog(printer, this);
}

Print::~Print()
{
    delete ui;
}

void Print::on_print_clicked()
{
    if (pd->exec() == QPrintDialog::Accepted){
        ui->pdf->print(printer);
        this->close();
    }
    else{
        QMessageBox mb(this);
        mb.setWindowTitle("خطأ");
        mb.setText("لم تتم الطباعه");
        mb.exec();
    }
}

void Print::on_cancel_clicked()
{
    this->close();
}
