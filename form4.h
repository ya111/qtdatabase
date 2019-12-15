#ifndef FORM4_H
#define FORM4_H

#include <QWidget>

namespace Ui {
class Form4;
}

class Form4 : public QWidget
{
    Q_OBJECT

public:
    explicit Form4(QWidget *parent = nullptr);
    ~Form4();

signals:
    void sendJournalData(QString id, QString emp_id, QString service_date, QString service, QString traffic, QString number);
private slots:
    void on_pushButton_clicked();



private:
    Ui::Form4 *ui;
};

#endif // FORM_H
