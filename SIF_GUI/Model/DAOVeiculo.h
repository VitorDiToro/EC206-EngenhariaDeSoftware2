#ifndef DAOVEICULO_H
#define DAOVEICULO_H

#include <vector>
#include "Veiculo.h"


class DAOVeiculo
{
    public:
        DAOVeiculo();

        bool addVeiculo(Veiculo* v);
        vector<Veiculo*> getVeiculo(vector<unsigned int> ids);
        bool setVeiculo(unsigned int id);
        bool deleteVeiculo(unsigned int id);
};

#endif // DAOVEICULO_H
