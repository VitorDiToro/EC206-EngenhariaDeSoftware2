#include <QApplication>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <typeinfo>
#include <QDebug>
#include <iostream>

//#include <QtSql/QSql>
//#include <QtSql/QSqlDatabase>
//#include <QtSql/QSqlDriver>
//#include <QtSql/QSqlQuery>
#include <QtSql>

using namespace std;

#include "ViewModel/TelaLogin.h"

bool createConnection();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!createConnection())
    {
        qDebug() << "Not connected!";
        return 1;
    }
    else
    {
        qDebug() << "Connected!";

        QSqlQuery query;
        query.exec("INSERT INTO `sys`.`newTable` (`name`) VALUES ('foo');");

        while (query.next())
        {
            QString name = query.value(0).toString();
            qDebug() << "name:" << name;
        }

        return 0;
    }


    LoginWindow* lw = new LoginWindow();
    lw->show();

    qDebug() << "aarrumamalae";

    return a.exec();

    return 0;
}

bool createConnection(){
    //QString serverName = "localhost\\SIFBD

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("sys");
    db.setUserName("root");
    db.setPassword("root");
    if (!db.open()) {
        qDebug() << "Database error occurred";
        return false;
    }
    return true;
}
