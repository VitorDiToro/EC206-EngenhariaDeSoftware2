#ifndef DAOACESSORIO_H
#define DAOACESSORIO_H

#include <vector>
#include "Acessorio.h"


class DAOAcessorio
{
    public:
        DAOAcessorio();

        bool addAcessorio(Acessorio* a);
        vector<Acessorio*> getAcessorio(vector<unsigned int> ids);
        bool setAcessorio(unsigned int id);
        bool deleteAcessorio(unsigned int id);
};

#endif // DAOACESSORIO_H
