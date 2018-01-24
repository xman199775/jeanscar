#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
#include <QDate>
namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = 0, QDate date=QDate::currentDate());
    ~Form1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Form1 *ui;
    QDate date1;
};

#endif // FORM1_H
