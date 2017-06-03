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
    QSqlQuery query;
    query.prepare("INSERT INTO `sifDB`.`veiculo` (`veiculo_modelo`, `veiculo_preco`, `veiculo_quantidade`, `veiculo_cor`, `veiculo_ano`, `veiculo_ativo`)"
                  "VALUES (?, ?, ?, ?, ?, ?);");
    query.addBindValue(v->getModelo());
    query.addBindValue(v->getPreco());
    query.addBindValue(3);
    query.addBindValue(v->getCor());
    query.addBindValue(v->getAno());
    query.addBindValue(true);
    query.exec();

    delete v;

    return true;
}
