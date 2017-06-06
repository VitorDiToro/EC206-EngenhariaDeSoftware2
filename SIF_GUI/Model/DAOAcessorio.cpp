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
    bool result;
    QSqlQuery query;

    query.prepare("INSERT INTO `sifDB`.`acessorio` (`acessorio_nome`, `acessorio_preco`, `acessorio_quantidade`, `acessorio_descricao`)"
                  "VALUES (?, ?, ?, ?);");
    query.addBindValue(a->getNome());
    query.addBindValue(a->getPreco());
    query.addBindValue(3);
    query.addBindValue(a->getDescricao());

    result = query.exec();

    delete a;

    return result;
}

QSqlQuery* DAOAcessorio::getBasicInfoAcessorios()
{
    QSqlQuery* query = new QSqlQuery();

    query->prepare("SELECT acessorio_id, acessorio_nome FROM sifDB.acessorio;");
    query->exec();

    return query;
}

Acessorio* DAOAcessorio::getAcessorio(unsigned int id)
{
    QSqlQuery* query = new QSqlQuery();
    Acessorio* a = NULL;

    query->prepare("SELECT * FROM sifDB.acessorio WHERE acessorio_id = ?;");
    query->addBindValue(id);
    if(query->exec())
    {
        qDebug() << "Success";
    }

    while (query->next())
    {
        a = new Acessorio();
        a->setId(query->value(0).toInt());
        a->setNome(query->value(1).toString());
        a->setPreco(query->value(2).toFloat());
        // set qtd
        a->setDescricao(query->value(4).toString());

        a->print_details();
    }

    return a;
}

bool DAOAcessorio::deleteAcessorio(unsigned int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM `sifDB`.`acessorio` WHERE `acessorio_id`=?;");
    query.addBindValue(id);

    return query.exec();
}

