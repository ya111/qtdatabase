#ifndef FORM2_H
#define FORM2_H

#include <QWidget>

namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = nullptr);
    ~Form2();

signals:
    void sendEmpData(QString id, QString inn, QString name, QString address);
private slots:
    void on_pushButton_clicked();



private:
    Ui::Form2 *ui;
};

#endif // FORM_H
