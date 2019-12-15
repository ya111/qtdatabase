#include "database.h"
#include <QDebug>
#include <QSqlQueryModel>
#include <string>
Database::Database(const QString pathToFile)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(pathToFile);
    if (!QFile(pathToFile).exists() & db.open())
    {

        db.exec ( "create table Organization  "
                  "( "
                  "inn integer PRIMARY KEY,"
                  "name varchar(40) NOT NULL,"
                  "address varchar(60) NOT NULL "
                  ")"
                  );
        db.exec (
                    "create table employee "
                   " ( id int primary key, "
                   " name varchar(100), "
                   " position varchar(50), "
                   " org_inn integer "
                   ")"
                   );
        db.exec (
                   " create table phone "
                   "(phone_number TEXT NOT NULL, "
                   "emp_id TEXT NOT NULL "
                   ")"
                   );
        db.exec(       " create table journal "
                       " (id int, "
                        "emp_id int,"
                        "service_date date, "
                        "service varchar(10), "
                        "traffic number, "
                        "client_phone_number integer "
                        ")"
                    );

    }
    tableModel = std::make_unique<QSqlTableModel>(nullptr, db);
}

void Database::addApp()
{

    db.exec("insert into organization values"
                   " (205306407, 'OOO Romashka', 'g. SPb, ul. Petrova, d.3')");
    db.exec("insert into organization values "
            "(205306440, 'OOO Siren', 'g. Moskva, ul. Pushkina, d. Kolot')");
    db.exec("insert into organization values "
            "(333080822, 'ZAO Gvozdika', 'g.SPb, ul. Makarova, d.6, of.5')");
    db.exec("insert into organization values (324867198, 'OAO Petrushka', ' g. Samara, ul.ORPMvjuegcn, 8') ");
    db.exec("insert into employee values "
           " (1, 'Kolotushkina Aleksandra Viktorovna', 'Menedzher', '205306407')");
    db.exec("insert into employee values  (1, 'Kolotushkina Aleksandra Viktorovna', 'Menedzher', '205306407')");

    db.exec("insert into employee values  (2, 'Petrov Aleksej Ioannovich', 'Uborshchik', '205306407')");
    db.exec("insert into employee values  (3, 'Sedyh Mark Alekseevich', 'Stazhyor-pevec', '205306407')");
    db.exec("insert into employee values  (4, 'Andreeva Olga Pavlovna', 'Direktor', '205306440')");
    db.exec("insert into employee values  (5, 'Zubov Andrej Viktorovich', 'Zamestitel direktora', '205306440')");
    db.exec("insert into employee values  (6, 'Sorokin Petr Glebovich', 'Pochtalion', '205306440')");
    db.exec("insert into employee values  (7, 'Myasnikov Ruslan Evgenevich', 'Konsultant', '333080822')");
    db.exec("insert into employee values  (8, 'Kalinina Galina YUrevna', 'Prodavec', '333080822')");
    db.exec("insert into phone values ( 89501202111, 1)");
    db.exec("insert into phone values  (669032, 1)");
    db.exec("insert into phone values (88005553535, 2)");
    db.exec("insert into phone values    (01,3)");
    db.exec("insert into phone values  (02,4)");
    db.exec("insert into phone values (666000,5)");
    db.exec("insert into phone values (77002,6)");
    db.exec("insert into phone values (8800300,7)");
    db.exec("insert into journal values (2, 1, '05-apr-2019', 'Zvonok', '533', 88005553535)");
    db.exec("insert into journal values (3, 2, '27-oct-2019', 'SMS', '150', 666888)");
    db.exec("insert into journal values (4, 2, '26-oct-2019', 'SMS', '203', 333213)");
    db.exec("insert into journal values (5, 4, '25-aug-2019', 'SMS', '55', 8800555)");




}

void Database::select(int i)
{


    if (i == 3)
        tableModel->setTable("organization");
    if (i == 4)
        tableModel->setTable("employee");
    if (i == 5)
        tableModel->setTable("phone");
    if (i == 6)
        tableModel->setTable("journal");
  // d0b.exec("SELECT * FROM main");
  // db.exec("SELECT Application FROM main");
    tableModel->select();
  // model->setHeaderData(1, Qt::Horizontal, QObject::tr("Salary"));

}

void Database::deleteValues(int i)
{
    if (i == 1)
        db.exec("DELETE FROM main");
    if (i == 2)
        db.exec("DELETE FROM main2");
    if (i == 3)
        db.exec("DELETE FROM organization");
    if (i == 4)
        db.exec("DELETE FROM employee");
    if (i == 5)
        db.exec("DELETE FROM phone");
    if (i == 6)
        db.exec("DELETE FROM journal");
}


void Database::addOrganization(QString inn, QString name, QString address)
{
    db.exec("INSERT INTO organization VALUES("+inn+",'"+name+"','"+address+"')");
}
void Database::addEmployee(QString id, QString name, QString position, QString org_inn)
{
    db.exec("INSERT INTO employee VALUES('"+id+"','"+name+"','"+position+"','"+org_inn+"')");
}
void Database::addPhone(QString number, QString emp_id)
{
    db.exec("INSERT INTO phone VALUES('"+number+"','"+emp_id+"')");
}
void Database::addJournal(QString id, QString emp_id, QString service_date, QString service, QString traffic, QString number)
{
    db.exec("INSERT INTO journal VALUES ('"+id+"','"+emp_id+"','"+service_date+"','"+service+"','"+traffic+"','"+number+"')");
}

