#ifndef DAOVENDA_H
#define DAOVENDA_H

#include <vector>
#include "Venda.h"


class DAOVenda
{
    public:
        DAOVenda();

        bool addVenda(Venda* v);
        vector<Venda*> getVenda(vector<unsigned int> ids);
        bool setVenda(unsigned int id);
        bool deleteVenda(unsigned int id);
};

#endif // DAOVENDA_H
