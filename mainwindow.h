#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <database.h>
#include <form.h>
#include <form2.h>
#include <form3.h>
#include <form4.h>
#include <thread>
#include <chrono>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QStackedLayout>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void receiveOrgData(QString inn, QString name, QString address);
    void receiveEmpData(QString id, QString name, QString position, QString org_inn);
    void receivePhoneData(QString number, QString num);
    void receiveJournalData(QString id, QString emp_id, QString service_date, QString service, QString traffic, QString number);
private slots:

    void on_pushButton_2_clicked();




    void on_add_org_button_clicked();

    void on_show_org_button_clicked();

    void on_add_employee_button_clicked();

    void on_show_employee_button_clicked();

    void on_add_phone_button_clicked();

    void on_show_phone_button_clicked();

    void on_add_journal_button_clicked();

    void on_show_journal_button_clicked();


    void on_show_choosen_org_button_clicked();

    void on_show_emp_service_clicked();

    void on_pushButton_clicked();

    void on_show_org_service_clicked();

    void on_show_emp_service_sum_clicked();

private:
    Form  ad;
    Form *myform;
    Form2 *myform2;
    Form3 *myform3;
    Form4 *myform4;
    Ui::MainWindow *ui;
    Database            db;
};

#endif // MAINWINDOW_H
