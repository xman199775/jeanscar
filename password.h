#ifndef PASSWORD_H
#define PASSWORD_H
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QDialog>
#include <mainwindow.h>
namespace Ui {
class password;
}

class password : public QDialog
{
    Q_OBJECT

public:
    explicit password(QWidget *parent = 0, MainWindow *x=0, QString *n=0, QString *c=0,QString *p=0 ,QString *pir=0 ,QSqlDatabase *m=0);
    ~password();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::password *ui;
    MainWindow *mainw;
    QString *name;
    QString *code;
    QString *pass;
    QString *pirorty;
    QSqlDatabase *mydata;
};

#endif // PASSWORD_H
