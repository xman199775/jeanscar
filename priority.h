#ifndef PRIORITY_H
#define PRIORITY_H

#include <QDialog>
#include <QCheckBox>
namespace Ui {
class Priority;
}

class Priority : public QDialog
{
    Q_OBJECT

public:
    explicit Priority(QWidget *parent = 0, QString *s = nullptr);
    ~Priority();
    QString *data;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Priority *ui;
    void add(QCheckBox *b);
};

#endif // PRIORITY_H
