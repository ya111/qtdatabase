#include "form3.h"
#include "ui_form3.h"

Form3::Form3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form3)
{
    ui->setupUi(this);
   // connect(ui->pushButton, SIGNAL(sendData(QString, QString, QString)), this, SLOT(on_pushButton_clicked()));
    // connect (ui->pushButton, SIGNAL(clicked()) ,this,SLOT(on_pushButton_clicked()));
}

Form3::~Form3()
{
    delete ui;
}

void Form3::on_pushButton_clicked()
{

    QString number=ui->lineEdit->text();
    QString emp_id=ui->lineEdit_2->text();
    //db.addOrganization(inn, name, address);
   // emit firstWindow(inn, name, address);
    emit sendPhoneData(number, emp_id);
    this->close();


}

