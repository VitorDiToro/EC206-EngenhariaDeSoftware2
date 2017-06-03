#include "Vendedor.h"
#include <stdio.h>
#include <vector>

int Vendedor::total = 0;

vector<Vendedor*> vendedores;

Vendedor::Vendedor()
{
//    qDebug() << "unidade de trabalho: ";
//    cin >> unidadeDeTrabalho;
//    getchar();
//    comissao = 0;

    setId(total++);
}

Vendedor::~Vendedor()
{
    unidadeDeTrabalho = "";
    comissao = 0;

    total--;
}

QString Vendedor::getUnidadeDeTrabalho() const
{
    return unidadeDeTrabalho;
}

void Vendedor::setUnidadeDeTrabalho(const QString &value)
{
    unidadeDeTrabalho = value;
}

float Vendedor::getComissao() const
{
    return comissao;
}

void Vendedor::setComissao(float value)
{
    comissao = value;
}

int Vendedor::getTotal()
{
    return total;
}

void Vendedor::print()
{
    Funcionario::print();
}

void Vendedor::print_details()
{
    Funcionario::print_details();

    qDebug() << "unidade de trabalho: " << unidadeDeTrabalho << endl;
    qDebug() << "comissao: " << comissao << endl;
}
