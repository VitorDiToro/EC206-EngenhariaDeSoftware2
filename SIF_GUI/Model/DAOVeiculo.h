#ifndef DAOVEICULO_H
#define DAOVEICULO_H

#include <vector>
#include <QtSql/QSqlQuery>

#include "Veiculo.h"


class DAOVeiculo
{
    private:
        static DAOVeiculo* INSTANCE;

        DAOVeiculo();
    public:
        ~DAOVeiculo();

        static DAOVeiculo* getInstance();

        bool addVeiculo(Veiculo* v);
        QSqlQuery* getBasicInfoVeiculos();
        Veiculo* getVeiculo(unsigned int id);
        bool updateVeiculo(Veiculo* v);
        bool deleteVeiculo(unsigned int id);
};

#endif // DAOVEICULO_H
