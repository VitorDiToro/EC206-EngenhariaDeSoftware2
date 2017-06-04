#include "DAOVeiculo.h"
#define noop (void)0

DAOVeiculo* DAOVeiculo::INSTANCE = NULL;

// private methods

DAOVeiculo::DAOVeiculo()
{
    noop;
}

// public methods

DAOVeiculo::~DAOVeiculo()
{
    noop;
}

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
    bool result;
    QSqlQuery query;

    query.prepare("INSERT INTO `sifDB`.`veiculo` (`veiculo_modelo`, `veiculo_preco`, `veiculo_quantidade`, `veiculo_cor`, `veiculo_ano`, `veiculo_ativo`)"
                  "VALUES (?, ?, ?, ?, ?, ?);");
    query.addBindValue(v->getModelo());
    query.addBindValue(v->getPreco());
    query.addBindValue(3);
    query.addBindValue(v->getCor());
    query.addBindValue(v->getAno());
    query.addBindValue(true);
    result = query.exec();

    delete v;

    return result;
}
