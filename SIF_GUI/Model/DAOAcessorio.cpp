#include "DAOAcessorio.h"
#define noop (void)0

DAOAcessorio* DAOAcessorio::INSTANCE = NULL;

// private methods

DAOAcessorio::DAOAcessorio()
{
    noop;
}

// public methods

DAOAcessorio::~DAOAcessorio()
{
    noop;
}

DAOAcessorio* DAOAcessorio::getInstance()
{
    if(INSTANCE == NULL)
    {
        INSTANCE = new DAOAcessorio();
    }

    return INSTANCE;
}


bool DAOAcessorio::addAcessorio(Acessorio *a)
{
    QSqlQuery query;

    query.prepare("INSERT INTO `sifDB`.`acessorio` (`acessorio_nome`, `acessorio_preco`, `acessorio_quantidade`, `acessorio_descricao`)"
                  "VALUES (?, ?, ?, ?);");
    query.addBindValue(a->getNome());
    query.addBindValue(a->getPreco());
    query.addBindValue(3);
    query.addBindValue(a->getDescricao());

    query.exec();

    delete a;

    return true;
}



