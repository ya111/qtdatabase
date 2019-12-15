#ifndef FORM3_H
#define FORM3_H

#include <QWidget>

namespace Ui {
class Form3;
}

class Form3 : public QWidget
{
    Q_OBJECT

public:
    explicit Form3(QWidget *parent = nullptr);
    ~Form3();

signals:
    void sendPhoneData(QString number, QString emp_id);
private slots:
    void on_pushButton_clicked();



private:
    Ui::Form3 *ui;
};

#endif // FORM_H
