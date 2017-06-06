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
        vector<Vendedor*> getVendedor(vector<unsigned int> ids);
        bool setVendedor(unsigned int id);
        bool deleteVendedor(unsigned int id);
        bool login(QString username, QString password);
};

#endif // DAOVENDEDOR_H
