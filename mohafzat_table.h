#ifndef MOHAFZAT_TABLE_H
#define MOHAFZAT_TABLE_H

#include <QMainWindow>
#include <QWidget>
#include <QDate>
#include <QDateTime>
#include <QTime>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
namespace Ui {
class mohafzat_table;
}

class mohafzat_table : public QMainWindow
{
    Q_OBJECT

public:
    explicit mohafzat_table(QWidget *parent = 0);
    ~mohafzat_table();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::mohafzat_table *ui;
};

#endif // MOHAFZAT_TABLE_H
