#ifndef PRODUCT_H
#define PRODUCT_H

#include <QWidget>

namespace Ui {
class product;
}

class product : public QWidget
{
    Q_OBJECT

public:
    explicit product(QWidget *parent = 0, QString o=0);
    ~product();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::product *ui;
    QString opnum;
};

#endif // PRODUCT_H
