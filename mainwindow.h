#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDate>
#include <QDateTime>
#include <QTime>
#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include"report.h"
#include <QPrintDialog>
#include <QPrinter>
#include <todoornottodo.h>
#include <mohafzat_table.h>
#include "taqrer_salar.h"
#include "priority.h"
#include "accounting.h"
#include <print.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, QString *n=0, QString *c=0,QString *pa=0,QString *pir=0,QSqlDatabase *m=0);
    ~MainWindow();
    void refresh();
    void updatedate();
    void setPriorty(QString s);
private slots:

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_3_clicked();

    void on_ecodesolfa_editingFinished();

    void on_pushButton_20_clicked();

    void on_salarys0lfa_editingFinished();
    
    void on_pushButton_2_clicked();

    void on_pushButton_17_clicked();
    
    void on_pushButton_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_solfadate_editingFinished();

    void on_pushButton_11_clicked();

    void on_price1_editingFinished();

    void on_price2_editingFinished();

    void on_price3_editingFinished();

    void on_recived_editingFinished();

    void on_pushButton_25_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();


    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_34_clicked();


    void on_delevercode_2_editingFinished();

    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_38_clicked();

    void on_f511_doubleClicked(const QModelIndex &index);

    void on_f82_doubleClicked(const QModelIndex &index);

    void on_f115_doubleClicked(const QModelIndex &index);

    void on_pushButton_39_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_89_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_49_clicked();

    void on_delverlist_doubleClicked(const QModelIndex &index);


    void on_pushButton_50_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_53_clicked();

    void on_editgoodcode_cursorPositionChanged(int arg1, int arg2);

    void on_editgoodcolor_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_54_clicked();

    void on_pushButton_55_clicked();

    void on_edit_scode_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_56_clicked();

    void on_salaryReportPrint_clicked();

    void on_salaryReportTable_doubleClicked(const QModelIndex &index);

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_Accounting_clicked();

    void on_customertable_doubleClicked(const QModelIndex &index);

    void on_actionSettings_triggered();

    void on_print_op_clicked();


    void on_delete_cus_clicked();

    void on_cphone_edit_cursorPositionChanged(int arg1, int arg2);

    QString generate_html_delevers(QString date);

private:
    Ui::MainWindow *ui;
    QString *name;
    QString *code;
    QString *pass;
    QTime *curtime;
    QString timestr;
    QDate *curdate;
    QString datestr;
    QSqlDatabase *mydata;
    QLocale english ;
    report *re;
    QPrintDialog *pd;
    QPrinter *p;
    todoornottodo *todo;
    Taqrer_salar *reportSalary;
    QString* priority_check;
    Priority *pri;
    Accounting *a;
    Print *print;
    QString generate_html_op(QString opcode);
    QString generate_html_all_salary(QString month, QString year);
    void update_flat_color();
    void update_op_code();
};

#endif // MAINWINDOW_H
