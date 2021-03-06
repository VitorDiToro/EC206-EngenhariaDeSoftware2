#include "DAOGerente.h"

#define noop (void)0

DAOGerente* DAOGerente::INSTANCE = NULL;

// private methods

DAOGerente::DAOGerente()
{
    noop;
}

// private methods

DAOGerente::~DAOGerente()
{
    noop;
}

DAOGerente* DAOGerente::getInstance()
{
    if(INSTANCE == NULL)
    {
        INSTANCE = new DAOGerente();
    }

    return INSTANCE;
}

bool DAOGerente::addGerente(Gerente *g)
{
    bool result;
    QSqlQuery query;

    query.prepare("INSERT INTO `sifDB`.`gerente` (`gerente_nome`, `gerente_cpf`, `gerente_endereco`, `gerente_telefone`, `gerente_unidade`, `gerente_ativo`, `gerente_salario`, `gerente_senha`, `gerente_login`)"
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);");
    query.addBindValue(g->getNome());
    query.addBindValue(g->getCpf());
    query.addBindValue(g->getEndereco());
    query.addBindValue(g->getTelefone());
    query.addBindValue(g->getUnidadeQueGerencia());
    query.addBindValue(true);
    query.addBindValue(g->getSalario());
    query.addBindValue(g->getSenha());
    query.addBindValue(g->getLogin());
    result = query.exec();

    if(result)
    {
        query.exec("SELECT MAX(gerente_id) FROM sifDB.gerente;");
        if(query.next())
        {
            int id = query.value(0).toInt();
            qDebug() << "id returned from database: " << id;

            query.prepare("INSERT INTO sifDB.funcionario (gerente_gerente_id)"
                          "VALUES (?);");
            query.addBindValue(id);
            result = query.exec();
        }
    }

    delete g;

    return result;
}

QSqlQuery* DAOGerente::getBasicInfoGerentes()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT gerente_id, gerente_nome FROM sifDB.gerente;");
    query->exec();

    return query;
}

Gerente* DAOGerente::getGerente(unsigned int id)
{
    QSqlQuery* query = new QSqlQuery();
    Gerente* g = NULL;

    query->prepare("SELECT * FROM sifDB.gerente WHERE gerente_id = ?;");
    query->addBindValue(id);
    if(query->exec())
    {
        qDebug() << "Success";
    }

    while (query->next())
    {
        g = new Gerente();

        g->setId(query->value(0).toInt());
        g->setNome(query->value(1).toString());
        g->setCpf(query->value(2).toString());
        g->setEndereco(query->value(3).toString());
        g->setTelefone(query->value(4).toString());
        g->setUnidadeQueGerencia(query->value(5).toString());
        g->setSalario(query->value(7).toFloat());
        g->setSenha(query->value(8).toString());
        g->setLogin(query->value(9).toString());

        g->print_details();
    }

    return g;
}

bool DAOGerente::deleteGerente(unsigned int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM `sifDB`.`gerente` WHERE `gerente_id`=?;");
    query.addBindValue(id);

    return query.exec();
}

