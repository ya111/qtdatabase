#include "form4.h"
#include "ui_form4.h"

Form4::Form4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form4)
{
    ui->setupUi(this);
   // connect(ui->pushButton, SIGNAL(sendData(QString, QString, QString)), this, SLOT(on_pushButton_clicked()));
    // connect (ui->pushButton, SIGNAL(clicked()) ,this,SLOT(on_pushButton_clicked()));
}

Form4::~Form4()
{
    delete ui;
}

void Form4::on_pushButton_clicked()
{

    QString id=ui->lineEdit->text();
    QString emp_id=ui->lineEdit_2->text();
    QString service_date=ui->lineEdit_3->text();
    QString service=ui->lineEdit_4->text();
    QString traffic=ui->lineEdit_5->text();
    QString number=ui->lineEdit_6->text();
    //db.addOrganization(inn, name, address);
   // emit firstWindow(inn, name, address);
    emit sendJournalData(id, emp_id, service_date, service, traffic, number);
    this->close();


}

