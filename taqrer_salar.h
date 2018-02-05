#ifndef TAQRER_SALAR_H
#define TAQRER_SALAR_H

#include <QMainWindow>
namespace Ui {
class Taqrer_salar;
}

class Taqrer_salar : public QMainWindow
{
    Q_OBJECT

public:
    explicit Taqrer_salar(QWidget *parent = 0, QString ecode = "", QString month = "", QString year = "");
    ~Taqrer_salar();

private slots:
    void on_taqretype_currentIndexChanged(const QString &arg1);

    void on_taqrerdate_editingFinished();

    void on_pushButton_2_clicked();

    void setValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage);

private:
    Ui::Taqrer_salar *ui;
    QString ecode, month, year;
    void setModel5asm();
    void setModelSolfa();
    void setModelZyada();
    void setModelGyab();
    void setModelNotes();
    void setModelTa5eer();
    void setRest();
};

#endif // TAQRER_SALAR_H
