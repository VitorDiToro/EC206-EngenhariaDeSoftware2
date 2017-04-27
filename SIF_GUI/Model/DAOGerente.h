#ifndef DAOGERENTE_H
#define DAOGERENTE_H

#include <vector>
#include "Gerente.h"


class DAOGerente
{
    public:
        DAOGerente();

        bool addGerente(Gerente* g);
        vector<Gerente*> getGerente(vector<unsigned int> ids);
        bool setGerente(unsigned int id);
        bool deleteGerente(unsigned int id);
};

#endif // DAOGERENTE_H
