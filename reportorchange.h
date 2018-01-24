#ifndef REPORTORCHANGE_H
#define REPORTORCHANGE_H

#include <QWidget>

namespace Ui {
class reportorchange;
}

class reportorchange : public QWidget
{
    Q_OBJECT

public:
    explicit reportorchange(QWidget *parent = 0);
    ~reportorchange();

private slots:
    void on_pushButton_clicked();

private:
    Ui::reportorchange *ui;
};

#endif // REPORTORCHANGE_H
