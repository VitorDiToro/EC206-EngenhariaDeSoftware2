#include "DAOVendedor.h"

#define noop (void)0

DAOVendedor* DAOVendedor::INSTANCE = NULL;

// private methods

DAOVendedor::DAOVendedor()
{
    noop;
}

// private methods

DAOVendedor::~DAOVendedor()
{
    noop;
}

DAOVendedor* DAOVendedor::getInstance()
{
    if(INSTANCE == NULL)
    {
        INSTANCE = new DAOVendedor();
    }

    return INSTANCE;
}

bool DAOVendedor::addVendedor(Vendedor *v)
{
    bool result;
    QSqlQuery query;

    query.prepare("INSERT INTO `sifDB`.`vendedor` (`vendedor_comissao`, `vendedor_unidade`, `vendedor_nome`, `vendedor_cpf`, `vendedor_telefone`, `vendedor_endereco`, `vendedor_ativo`)"
                  "VALUES (?, ?, ?, ?, ?, ?, ?);");
    query.addBindValue(v->getComissao());
    query.addBindValue(v->getUnidadeDeTrabalho());
    query.addBindValue(v->getNome());
    query.addBindValue(v->getCpf());
    query.addBindValue(v->getTelefone());
    query.addBindValue(v->getEndereco());
    query.addBindValue(true);
    result = query.exec();

    if(result)
    {
        query.exec("SELECT MAX(vendedor_id) FROM sifDB.vendedor;");
        if(query.next())
        {
            int id = query.value(0).toInt();
            qDebug() << "id returned from database: " << id;

            query.prepare("INSERT INTO sifDB.funcionario (vendedor_vendedor_id)"
                          "VALUES (?);");
            query.addBindValue(id);
            result = query.exec();
        }
    }

    delete v;

    return result;
}

QSqlQuery* DAOVendedor::getBasicInfoVendedores()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT vendedor_id, vendedor_nome FROM sifDB.vendedor;");
    query->exec();

    return query;
}

Vendedor* DAOVendedor::getVendedor(unsigned int id)
{
    QSqlQuery* query = new QSqlQuery();
    Vendedor* v = NULL;

    query->prepare("SELECT * FROM sifDB.vendedor WHERE vendedor_id = ?;");
    query->addBindValue(id);
    if(query->exec())
    {
        qDebug() << "Success";
    }

    while (query->next())
    {
        v = new Vendedor();

        v->setId(query->value(0).toInt());
        v->setComissao(query->value(1).toFloat());
        v->setUnidadeDeTrabalho(query->value(2).toString());
        v->setNome(query->value(3).toString());
        v->setCpf(query->value(4).toString());
        v->setTelefone(query->value(5).toString());
        v->setEndereco(query->value(6).toString());

        v->print_details();
    }

    return v;
}

bool DAOVendedor::deleteVendedor(unsigned int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM sifDB.vendedor WHERE vendedor_id = ?;");
    query.addBindValue(id);

    return query.exec();
}

bool DAOVendedor::login(QString username, QString password)
{
    bool result = false;

    return result;
}
