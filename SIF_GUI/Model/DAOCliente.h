#ifndef DAOCLIENTE_H
#define DAOCLIENTE_H

#include <vector>
#include <QtSql/QSqlQuery>
#include "Cliente.h"


class DAOCliente
{
    private:
        static DAOCliente* INSTANCE;

        DAOCliente();
    public: //methods
        ~DAOCliente();

        static DAOCliente* getInstance();

        bool addCliente(Cliente* c);
        QSqlQuery* getBasicInfoClientes(void);
        Cliente* getCliente(unsigned int id);
        bool setCliente(unsigned int id);
        bool deleteCliente(unsigned int id);
};

#endif // DAOCLIENTE_H
