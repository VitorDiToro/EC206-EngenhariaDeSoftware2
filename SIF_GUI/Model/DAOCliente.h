#ifndef DAOCLIENTE_H
#define DAOCLIENTE_H

#include <vector>
#include "Cliente.h"


class DAOCliente
{
    public:
        DAOCliente();

        bool addCliente(Cliente* c);
        vector<Cliente*> getCliente(vector<unsigned int> ids);
        bool setCliente(unsigned int id);
        bool deleteCliente(unsigned int id);
};

#endif // DAOCLIENTE_H
