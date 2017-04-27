#ifndef DAOVENDEDOR_H
#define DAOVENDEDOR_H

#include <vector>
#include "Vendedor.h"


class DAOVendedor
{
    public: //methods
        DAOVendedor();

        bool addVendedor(Vendedor* v);
        vector<Vendedor*> getVendedor(vector<unsigned int> ids);
        bool setVendedor(unsigned int id);
        bool deleteVendedor(unsigned int id);
};

#endif // DAOVENDEDOR_H
