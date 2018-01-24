#include "report.h"
#include "ui_report.h"

report::report(QWidget *parent,QString e) :
    QWidget(parent),
    ui(new Ui::report)
{
    ui->setupUi(this);
    ecode=e;
    table=new QSqlTableModel();
    table->setTable("Employee");
    table->setFilter("`Ecode` = '"+ecode+"'");
    table->select();
    ui->tableView->setModel(table);
    QSqlQuery qry;
    qry.exec("SELECT `Employee`.`Weakly` FROM `Employee` WHERE `Ecode` = '"+ecode+"'");
    qry.first();
    week=qry.value(0).toString();
    qry.exec("SELECT `Employee`.`Insurance` FROM `Employee` WHERE `Ecode` = '"+ecode+"'");
    qry.first();
    mo2mn=qry.value(0).toString();

  if(week=="y")
  {
      ui->checkBox->setChecked(true);
  }
  else
  {
        ui->checkBox->setChecked(false);
  }
  if(mo2mn=="y")
  {
      ui->checkBox_2->setChecked(true);
  }
  else
  {
        ui->checkBox_2->setChecked(false);
  }
}

report::~report()
{
    delete ui;
}

void report::on_pushButton_clicked()
{
    QSqlQuery qry;
    if(ui->checkBox->isChecked())
    {
     qry.exec("update  `Employee` set `Weakly` = 'y' where `Ecode` = '"+ecode+"' ");
    }
    else
    {
     qry.exec("update  `Employee` set `Weakly` = 'n' where `Ecode` = '"+ecode+"' ");
    }
    if(ui->checkBox_2->isChecked())
    {
       qry.exec("update  `Employee` set `Insurance` = 'y' where `Ecode` = '"+ecode+"'");
    }
    else
    {
        qry.exec("update  `Employee` set `Insurance` = 'n' where `Ecode` = '"+ecode+"'");
    }
    this->close();
}

void report::on_pushButton_2_clicked()
{
    table=new QSqlTableModel();
    table->setTable("Employee");
    table->select();
    ui->tableView->setModel(table);
}

void report::on_pushButton_3_clicked()//بحث بالاسم
{
    QString name=ui->lineEdit->text();
    QSqlQueryModel *model;
    model=new QSqlQueryModel;
    model->setQuery("SELECT `Employee`.`Ecode` as 'كود الموظف', `Employee`.`Name` as 'اسم الموظف',`Employee`.`Nation-id` as 'الرقم القومي',`Employee`.`Social-status` as 'الحاله الاجتماعية',`Employee`.`BirthDate` as 'تاريخ الميلاد',`Employee`.`Number` as 'الموبايل',`Employee`.`Home_Num` as 'تيلفون المنزل',`Employee`.`Add-nid` as 'عنوان البطاقة',`Employee`.`Add-ano` as 'عنوان حالي',`Employee`.`Clear-salary` as 'مرتب اساسي',`Employee`.`Last_salaray` as 'اخر مرتب',`Employee`.`Hours` as 'عدد ساعات العمل',`Employee`.`Arrive-time` as 'وقت الوصول',`Employee`.`Leave-time` as 'وقت الانصراف',`Employee`.`Major` as 'القسم',`Employee`.`Certifcate` as 'المؤهل',`Employee`.`Year_grad` as 'تاريخ التخرج',`Employee`.`Year_of_job` as 'تاريخ التوظيف',`Employee`.`Curr_job` as 'الوظيفة الحالية',`Employee`.`N_of_work_in_years` as 'عدد سنوات العمل',`Employee`.`Another_exper` as 'خبرات اخري',`Employee`.`Insurance` as 'مؤمن عليه',`Employee`.`Weakly` as 'اسبوعي',`Employee`.`Note` as 'ملاحظات'  FROM `JeansCar`.`Employee` where `Name` like '%"+name+"%'");
    ui->tableView->setModel(model);
}
