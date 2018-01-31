#include "mainwindow.h"
#include <QApplication>
#include "password.h"
#include <QString>
#include "thread.h"
#include <QSqlDatabase>
#include <QtSql>
#include <qsqldriver.h>
#include <QDebug>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase mydata= QSqlDatabase::addDatabase("QMYSQL");
   /*
    mydata.setHostName("Eman-PC");
    mydata.setDatabaseName("JeansCar");
    mydata.setUserName("jeanscar");
    mydata.setPassword("ASHnouhcompany");

   */
    mydata.setHostName("127.0.0.1");
    mydata.setDatabaseName("JeansCar");
    mydata.setUserName("root");
    mydata.setPassword("root");
  //  mydata.setPort(8889);
    bool ok = mydata.open();
    if(ok)
    {
        qDebug()<< "ok";

    }
    else
    {
         qDebug()<<mydata.lastError().text();
         QMessageBox::critical(0, QObject::tr("Database Error"),mydata.lastError().text());
    }
    QString name="Admine";
    QString code="";
    QString pass="";
    QString pirorty="";
    MainWindow M(0,&name,&code,&pass,&pirorty,&mydata);
    thread thre(&M);
    thre.start();
    password w(0,&M,&name,&code,&pass,&pirorty,&mydata);
    w.show();
    return a.exec();
}
