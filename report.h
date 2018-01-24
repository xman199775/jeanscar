#ifndef REPORT_H
#define REPORT_H

#include <QWidget>
#include <QSqlDatabase>
#include <QtSql>
#include <QString>
namespace Ui {
class report;
}

class report : public QWidget
{
    Q_OBJECT

public:
    explicit report(QWidget *parent = 0, QString e="");
    ~report();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::report *ui;
    QSqlTableModel *table;
    QString ecode, week,mo2mn;
};

#endif // REPORT_H
