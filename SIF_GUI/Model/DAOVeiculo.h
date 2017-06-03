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
        vector<Veiculo*> getVeiculo(vector<unsigned int> ids);
        bool setVeiculo(unsigned int id);
        bool deleteVeiculo(unsigned int id);
};

#endif // DAOVEICULO_H
