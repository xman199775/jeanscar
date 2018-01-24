#ifndef TODOORNOTTODO_H
#define TODOORNOTTODO_H

#include <QWidget>
#include <QDate>
#include <QDateTime>
#include <QTime>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
namespace Ui {
class todoornottodo;
}

class todoornottodo : public QWidget
{
    Q_OBJECT

public:
    explicit todoornottodo(QString m,QWidget *parent = 0);
    ~todoornottodo();
    QString ecode, opcode;
    int Case;

private slots:
    void on_doIt_clicked();

    void on_cancel_clicked();

private:
    Ui::todoornottodo *ui;
};

#endif // TODOORNOTTODO_H
