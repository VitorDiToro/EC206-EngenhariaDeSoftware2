#include "DAOVeiculo.h"

DAOVeiculo* DAOVeiculo::INSTANCE = NULL;

DAOVeiculo::DAOVeiculo()
{
    // pass
}

// public methods

DAOVeiculo* DAOVeiculo::getInstance()
{
    if(INSTANCE == NULL)
    {
        INSTANCE = new DAOVeiculo();
    }

    return INSTANCE;
}

bool DAOVeiculo::addVeiculo(Veiculo *v)
{
    return true;
}


//DAOVeiculo::getInstance()->insert(v);
