#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>
#include <QDate>
#include <QLabel>
namespace Ui {
class table;
}

class table : public QMainWindow
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = 0, QDate date1 = QDate::currentDate());
    ~table();
    QDate date;
private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_change_date_editingFinished();

private:
    Ui::table *ui;
    void set5to11(QDate date);
    void set11to5(QDate date);
    void set2to8(QDate date);
    void clear_all();
    void count(QDate date, QLabel *label);
    void set_curr(QDate date1);
    QDate cur;
};

#endif // TABLE_H
