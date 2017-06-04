#include "DAOGerente.h"
#include <QtSql/QSqlQuery>

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

    query.prepare("INSERT INTO `sifDB`.`gerente` (`gerente_nome`, `gerente_cpf`, `gerente_endereco`, `gerente_telefone`, `gerente_unidade`, `gerente_ativo`)"
                  "VALUES (?, ?, ?, ?, ?, ?);");
    query.addBindValue(g->getNome());
    query.addBindValue(g->getCpf());
    query.addBindValue(g->getEndereco());
    query.addBindValue(g->getTelefone());
    query.addBindValue(g->getUnidadeQueGerencia());
    query.addBindValue(true);
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

