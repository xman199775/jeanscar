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
    table->setHeaderData(0,  Qt::Horizontal, tr("كود الموظف"));
    table->setHeaderData(1,  Qt::Horizontal, tr("الإسم"));
    table->setHeaderData(2,  Qt::Horizontal, tr("الرقم القومي"));
    table->setHeaderData(3,  Qt::Horizontal, tr("الحالة الإجتماعيه"));
    table->setHeaderData(4,  Qt::Horizontal, tr("تاريخ الميلاد"));
    table->setHeaderData(5,  Qt::Horizontal, tr("رقم التليفون"));
    table->setHeaderData(6,  Qt::Horizontal, tr("هاتف المنزل"));
    table->setHeaderData(7,  Qt::Horizontal, tr("عنوان البطاقه"));
    table->setHeaderData(8,  Qt::Horizontal, tr("عنوان آخر"));
    table->setHeaderData(9,  Qt::Horizontal, tr("الراتب الاساسي"));
    table->setHeaderData(10, Qt::Horizontal, tr("آخر راتب حصل عليه"));
    table->setHeaderData(11, Qt::Horizontal, tr("عدد ساعات العمل"));
    table->setHeaderData(12, Qt::Horizontal, tr("وقت الحضور"));
    table->setHeaderData(13, Qt::Horizontal, tr("وقت الانصراف"));
    table->setHeaderData(14, Qt::Horizontal, tr("القسم"));
    table->setHeaderData(15, Qt::Horizontal, tr("آخر شهاده تم الحصول عليها"));
    table->setHeaderData(16, Qt::Horizontal, tr("تاريخ التخرج"));
    table->setHeaderData(17, Qt::Horizontal, tr("تاريخ الحصول على المهنه"));
    table->setHeaderData(18, Qt::Horizontal, tr("الوظيفه الحاليه"));
    table->setHeaderData(19, Qt::Horizontal, tr("عدد سنوات ممارسه المهنه"));
    table->setHeaderData(20, Qt::Horizontal, tr("خبرات آخرى"));
    table->setHeaderData(21, Qt::Horizontal, tr("مؤمن عليه"));
    table->setHeaderData(22, Qt::Horizontal, tr("اسبوعي"));
    table->setHeaderData(23, Qt::Horizontal, tr("ملاحظات خاصه"));
    table->setHeaderData(24, Qt::Horizontal, tr("حد ادنى للمرتب"));
    table->setHeaderData(25, Qt::Horizontal, tr("ثمن الساعه الاضافيه"));
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
