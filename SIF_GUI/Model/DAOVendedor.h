#ifndef DAOVENDEDOR_H
#define DAOVENDEDOR_H

#include <vector>
#include <QtSql/QSqlQuery>

#include "Vendedor.h"


class DAOVendedor
{
    private:
        static DAOVendedor* INSTANCE;

        DAOVendedor();
    public: //methods
        ~DAOVendedor();

        static DAOVendedor* getInstance();

        bool addVendedor(Vendedor* v);
        QSqlQuery* getBasicInfoVendedores();
        Vendedor* getVendedor(unsigned int id);
        bool setVendedor(unsigned int id);
        bool deleteVendedor(unsigned int id);
        bool login(QString username, QString password);
};

#endif // DAOVENDEDOR_H
