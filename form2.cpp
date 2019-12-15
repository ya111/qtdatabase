#include "form2.h"
#include "ui_form2.h"

Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
   // connect(ui->pushButton, SIGNAL(sendData(QString, QString, QString)), this, SLOT(on_pushButton_clicked()));
    // connect (ui->pushButton, SIGNAL(clicked()) ,this,SLOT(on_pushButton_clicked()));
}

Form2::~Form2()
{
    delete ui;
}

void Form2::on_pushButton_clicked()
{
    QString name=ui->lineEdit->text();
    QString position=ui->lineEdit_2->text();
    QString org_inn=ui->lineEdit_3->text();
    QString id=ui->lineEdit_4->text();
    //db.addOrganization(inn, name, address);
   // emit firstWindow(inn, name, address);
    emit sendEmpData(id, name, position, org_inn);
    this->close();


}

