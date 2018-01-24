#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLocale>
namespace Ui {
class Accounting;
}

class Accounting : public QMainWindow
{
    Q_OBJECT

public:
    explicit Accounting(QWidget *parent = 0);
    ~Accounting();

private slots:
    void on_Acc_date_editingFinished();


    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::Accounting *ui;
    void calculate_employee();
    void calculate_orders();
    void calculate_ware();
    void calculate_stock();
    void calculate_total();
    void calculate_daily();
    void set_data(QLineEdit *l, QString s);
    QLocale english;
};

#endif // ACCOUNTING_H
