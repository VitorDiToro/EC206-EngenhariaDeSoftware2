#include "Gerente.h"
#include <stdio.h>

int Gerente::total = 0;

vector<Gerente*> gerentes;

Gerente::Gerente()
{
    //qDebug() << "unidade que gerencia: ";
    //cin >> unidadeQueGerencia;

    setId(total++);
}

Gerente::~Gerente()
{
    total--;
}

QString Gerente::getUnidadeQueGerencia() const
{
    return unidadeQueGerencia;
}

void Gerente::setUnidadeQueGerencia(const QString &value)
{
    unidadeQueGerencia = value;
}

int Gerente::getTotal()
{
    return total;
}

void Gerente::print()
{
    Funcionario::print();
}

void Gerente::print_details()
{
    Funcionario::print_details();

    qDebug() << "unidade que gerencia: " << unidadeQueGerencia << endl;
}
