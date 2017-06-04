#ifndef DAOACESSORIO_H
#define DAOACESSORIO_H

#include <vector>
#include <QtSql/QSqlQuery>

#include "Acessorio.h"


class DAOAcessorio
{
    private:
        static DAOAcessorio* INSTANCE;

        DAOAcessorio();
    public:
        ~DAOAcessorio();

        static DAOAcessorio* getInstance();

        bool addAcessorio(Acessorio* a);
        QSqlQuery* getBasicInfoAcessorios();
        vector<Acessorio*> getAcessorio(vector<unsigned int> ids);
        bool setAcessorio(unsigned int id);
        bool deleteAcessorio(unsigned int id);
};

#endif // DAOACESSORIO_H
