#include "DAOCliente.h"

#define noop (void)0

DAOCliente* DAOCliente::INSTANCE = NULL;

// private methods

DAOCliente::DAOCliente()
{
    noop;
}

// private methods

DAOCliente::~DAOCliente()
{
    noop;
}

DAOCliente* DAOCliente::getInstance()
{
    if(INSTANCE == NULL)
    {
        INSTANCE = new DAOCliente();
    }

    return INSTANCE;
}

bool DAOCliente::addCliente(Cliente *c)
{
    bool result;
    QSqlQuery query;

    query.prepare("INSERT INTO `sifDB`.`cliente` (`cliente_nome`, `cliente_endereco`, `cliente_cpf`, `cliente_telefone`)"
                  "VALUES (?, ?, ?, ?);");
    query.addBindValue(c->getNome());
    query.addBindValue(c->getEndereco());
    query.addBindValue(c->getCpf());
    query.addBindValue(c->getTelefone());

    result = query.exec();

    delete c;

    return result;
}

QSqlQuery* DAOCliente::getBasicInfoClientes()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT cliente_id, cliente_nome FROM sifDB.cliente;");
    query->exec();

    return query;
}

Cliente* DAOCliente::getCliente(unsigned int id)
{
    QSqlQuery* query = new QSqlQuery();
    Cliente* c = NULL;

    query->prepare("SELECT * FROM sifDB.cliente WHERE cliente_id = ?;");
    query->addBindValue(id);
    if(query->exec())
    {
        qDebug() << "Success";
    }

    while (query->next())
    {
        c = new Cliente();

        c->setId(query->value(0).toInt());
        c->setNome(query->value(1).toString());
        c->setEndereco(query->value(2).toString());
        c->setCpf(query->value(3).toString());
        c->setTelefone(query->value(4).toString());

        c->print_details();
    }

    return c;
}

bool DAOCliente::deleteCliente(unsigned int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM `sifDB`.`cliente` WHERE `cliente_id`=?;");
    query.addBindValue(id);

    return query.exec();
}
