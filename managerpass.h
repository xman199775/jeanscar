#ifndef MANAGERPASS_H
#define MANAGERPASS_H
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QDialog>
#include <QString>
namespace Ui {
class managerpass;
}

class managerpass : public QDialog
{
    Q_OBJECT

public:
    explicit managerpass(QWidget *parent = 0,QString *n=0,QString *c=0,QString *p=0);
    ~managerpass();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::managerpass *ui;
    QString *name ;
    QString *code ;
    QString *pass;

};

#endif // MANAGERPASS_H
