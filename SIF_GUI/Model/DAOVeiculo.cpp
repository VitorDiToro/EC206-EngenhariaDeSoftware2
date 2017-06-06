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

QSqlQuery* DAOVeiculo::getBasicInfoVeiculos()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT veiculo_id, veiculo_modelo FROM sifDB.veiculo;");
    query->exec();

    return query;
}

Veiculo* DAOVeiculo::getVeiculo(unsigned int id)
{
    QSqlQuery* query = new QSqlQuery();
    Veiculo* v = NULL;

    query->prepare("SELECT * FROM sifDB.veiculo WHERE veiculo_id = ?;");
    query->addBindValue(id);
    if(query->exec())
    {
        qDebug() << "Success";
    }

    while (query->next())
    {
        v = new Veiculo();

        v->setId(query->value(0).toInt());
        v->setModelo(query->value(1).toString());
        v->setPreco(query->value(2).toFloat());
        v->setQuantidade(query->value(3).toInt());
        v->setCor(query->value(4).toString());
        v->setAno(query->value(5).toInt());

        v->print_details();
    }

    return v;
}

bool DAOVeiculo::deleteVeiculo(unsigned int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM `sifDB`.`veiculo` WHERE `veiculo_id`=?;");
    query.addBindValue(id);

    return query.exec();
}
