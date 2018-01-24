#ifndef PRINT_H
#define PRINT_H

#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
namespace Ui {
class Print;
}

class Print : public QDialog
{
    Q_OBJECT

public:
    explicit Print(QString myHTML = "",  QWidget *parent = 0);
    ~Print();

private slots:
    void on_print_clicked();

    void on_cancel_clicked();

private:
    Ui::Print *ui;
    QPrinter *printer;
    QPrintDialog *pd;
    QString html;

};

#endif // PRINT_H
