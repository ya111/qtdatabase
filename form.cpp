#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
   // connect(ui->pushButton, SIGNAL(sendData(QString, QString, QString)), this, SLOT(on_pushButton_clicked()));
    // connect (ui->pushButton, SIGNAL(clicked()) ,this,SLOT(on_pushButton_clicked()));
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{

    QString inn=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    QString address=ui->lineEdit_3->text();
    //db.addOrganization(inn, name, address);
   // emit firstWindow(inn, name, address);
    emit sendData(inn, name, address);
    this->close();


}

