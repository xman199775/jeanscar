#ifndef CHOOSE_EMPLOYEE_H
#define CHOOSE_EMPLOYEE_H

#include <QDialog>
#include <QLineEdit>
#include <QSql>
#include <QtCore>
#include <QSqlDatabase>
namespace Ui {
class choose_employee;
}

class choose_employee : public QDialog
{
    Q_OBJECT

public:
    explicit choose_employee(QWidget *parent = 0, QLineEdit *l = 0);
    ~choose_employee();

private slots:
    void on_employees_doubleClicked(const QModelIndex &index);

private:
    Ui::choose_employee *ui;
    QLineEdit *my_label;
};

#endif // CHOOSE_EMPLOYEE_H
