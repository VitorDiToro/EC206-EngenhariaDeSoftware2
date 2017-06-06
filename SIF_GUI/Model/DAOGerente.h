#ifndef DAOGERENTE_H
#define DAOGERENTE_H

#include <vector>
#include "Gerente.h"
#include <QtSql/QSqlQuery>

class DAOGerente
{
    private:
        static DAOGerente* INSTANCE;

        DAOGerente();
    public: //methods
        ~DAOGerente();

        static DAOGerente* getInstance();

        bool addGerente(Gerente* g);
        QSqlQuery* getBasicInfoGerentes();
        Gerente* getGerente(unsigned int id);
        bool setGerente(unsigned int id);
        bool deleteGerente(unsigned int id);
};

#endif // DAOGERENTE_H



#ifndef DAOVENDEDOR_H
#define DAOVENDEDOR_H

#include <vector>
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
        vector<Vendedor*> getVendedor(vector<unsigned int> ids);
        bool setVendedor(unsigned int id);
        bool deleteVendedor(unsigned int id);
};

#endif // DAOVENDEDOR_H

