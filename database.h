#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QFile>

class Database
{
private:
    QSqlDatabase                      db;
public:
    std::unique_ptr<QSqlTableModel>   tableModel;

    explicit Database(const QString pathToFile = "database.db");

    void addApp();
    void select(int i);
    void deleteValues(int i);
    void addOrganization(QString inn, QString name, QString address);
    void addEmployee(QString id, QString name, QString position, QString org_inn);
    void addPhone(QString number, QString emp_id);
    void addJournal(QString id, QString emp_id, QString service_date, QString service, QString traffic, QString number);
    void showOrganization();
    void showEmployee();
    void showPhone();
    void ShowJournal();
};

#endif // DATABASE_H

