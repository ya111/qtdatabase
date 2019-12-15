#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    db()
{
    ui->setupUi(this);
    ui->tableView->setModel(db.tableModel.get());

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    db.deleteValues(6);
    db.deleteValues(5);
    db.deleteValues(4);
    db.deleteValues(3);
    db.select(6);
}




void MainWindow::on_add_org_button_clicked()
{
    myform = new Form();
    connect(ui->add_org_button, SIGNAL(clicked()), myform, SLOT(show()));

    connect(myform, SIGNAL(sendData(QString, QString, QString)), this, SLOT(receiveOrgData(QString,QString ,QString)));

    myform->setAttribute(Qt::WA_DeleteOnClose, true);

}
void MainWindow::receiveOrgData(QString inn, QString name, QString address)
{
    db.addOrganization(inn,name,address);
    ui->tableView->setModel(db.tableModel.get());
    db.select(3);
}


void MainWindow::on_show_org_button_clicked()
{

    ui->tableView->setModel(db.tableModel.get());
    db.select(3);
}

void MainWindow::on_add_employee_button_clicked()
{

    myform2 = new Form2();
    connect(ui->add_employee_button, SIGNAL(clicked()), myform2, SLOT(show()));
    connect(myform2, SIGNAL(sendEmpData(QString, QString, QString, QString)), this, SLOT(receiveEmpData(QString,QString,QString ,QString)));
    myform2->setAttribute(Qt::WA_DeleteOnClose, true);

}

void MainWindow::receiveEmpData(QString id, QString name, QString position, QString org_inn)
{
    db.addEmployee(id, name, position, org_inn);
    ui->tableView->setModel(db.tableModel.get());
    db.select(4);
}



void MainWindow::on_show_employee_button_clicked()
{
    ui->tableView->setModel(db.tableModel.get());
    db.select(4);
}

void MainWindow::on_add_phone_button_clicked()
{
    myform3 = new Form3();
    connect(ui->add_phone_button, SIGNAL(clicked()), myform3, SLOT(show()));
    connect(myform3, SIGNAL(sendPhoneData(QString,  QString)), this, SLOT(receivePhoneData(QString,QString)));
    myform3->setAttribute(Qt::WA_DeleteOnClose, true);

}
void MainWindow::receivePhoneData(QString number, QString emp_id)
{
    db.addPhone(number, emp_id);
    ui->tableView->setModel(db.tableModel.get());
    db.select(5);
}


void MainWindow::on_show_phone_button_clicked()
{
    ui->tableView->setModel(db.tableModel.get());
    db.select(5);
}

void MainWindow::on_add_journal_button_clicked()
{
    myform4 = new Form4();
    connect(ui->add_journal_button, SIGNAL(clicked()), myform4, SLOT(show()));
    connect(myform4, SIGNAL(sendJournalData(QString,QString,QString,QString,QString,QString)), this, SLOT(receiveJournalData(QString,QString,QString,QString,QString,QString)));
    myform4->setAttribute(Qt::WA_DeleteOnClose, true);



}


void MainWindow::receiveJournalData(QString id, QString emp_id, QString service_date, QString service, QString traffic, QString number)
{
    db.addJournal(id, emp_id, service_date, service, traffic, number);
    ui->tableView->setModel(db.tableModel.get());
    db.select(6);
}



void MainWindow::on_show_journal_button_clicked()
{
    ui->tableView->setModel(db.tableModel.get());
    db.select(6);
}



void MainWindow::on_show_choosen_org_button_clicked()
{

    QString XMAX=ui->lineEditShowOrg->text();
   // db.showChoosenOrg(XMAX);
    QSqlQueryModel *model = new QSqlQueryModel;
    if (XMAX=="")
        model->setQuery("SELECT e.name as FIO, e.position, o.name, p.phone_number  "
                        "FROM employee e "
                        "join organization o "
                        "ON o.inn=e.org_inn  "
                       " join phone p "
                        "ON e.id=p.emp_id");
        else
            model->setQuery("SELECT e.name as FIO, e.position, o.name, p.phone_number  "
                            "FROM employee e "
                            "join organization o "
                            "ON o.inn=e.org_inn AND o.name ='"+XMAX+"' "
                           " join phone p "
                            "ON e.id=p.emp_id");
    ui->tableView->setModel(model);
    ui->tableView->show();
}








void MainWindow::on_show_emp_service_clicked()
{
    QString XMAX=ui->lineEditShowOrg->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    if (XMAX=="")
        model->setQuery("select e.name, j.service, j.service_date "
                        "from employee e join journal j "
                        "on j.emp_id=e.id "
                        "order by j.service_date");
        else
    model->setQuery("select e.name, j.service, j.service_date "
                            "from employee e join journal j "
                            "on j.emp_id=e.id AND e.name ='"+XMAX+"' "
                            "order by j.service_date");
    ui->tableView->setModel(model);
    ui->tableView->show();

}

void MainWindow::on_pushButton_clicked()
{
    db.addApp();
}

void MainWindow::on_show_org_service_clicked()
{

    QString XMAX=ui->lineEditShowOrg->text();
    QSqlQueryModel *model = new QSqlQueryModel;
   /* model->setQuery("select o.name, sum(j.traffic) as '"+XMAX+"'"
                        "FROM employee e "
                        "join organization o  "
                        "ON o.inn=e.org_inn"
                        "join journal j"
                        "ON e.id=j.emp_id "
                        "group by o.name");
*/
    if (XMAX=="")
        model->setQuery("select o.name, sum(j.traffic) as 'Full traffic'"
                        "from employee e "

                        "join organization o ON o.inn=e.org_inn  "
                        "join journal j on e.id = j.emp_id "
                        "group by o.name");
    else
    model->setQuery("select o.name, sum(j.traffic) as '"+XMAX+"'"
                    "from employee e "
                    "join organization o ON o.inn=e.org_inn  "
                    "join journal j on e.id = j.emp_id "
                    "where service='"+XMAX+"' "
                    "group by o.name");
    ui->tableView->setModel(model);
    ui->tableView->show();
}

void MainWindow::on_show_emp_service_sum_clicked()
{
    QString XMAX=ui->lineEditShowOrg->text();
    QSqlQueryModel *model = new QSqlQueryModel;

    if (XMAX=="")
        model->setQuery("select e.name, sum(j.traffic) as 'Full traffic'"
                        "from employee e join journal j on e.id = j.emp_id "
                        "group by e.name");
    else
    model->setQuery("select e.name, sum(j.traffic) as '"+XMAX+"'"
                    "from employee e join journal j on e.id = j.emp_id "
                    "where service='"+XMAX+"' "
                    "group by e.name");

    ui->tableView->setModel(model);
    ui->tableView->show();
}
