#include "Vendedor.h"
#include <stdio.h>
#include <vector>

int Vendedor::total = 0;

vector<Vendedor*> vendedores;

Vendedor::Vendedor()
{
    cout << "unidade de trabalho: ";
    cin >> unidadeDeTrabalho;
    getchar();
    bonificacao = 0;

    setId(total++);
}

Vendedor::~Vendedor()
{
    unidadeDeTrabalho = "";
    bonificacao = 0;

    total--;
}

string Vendedor::getUnidadeDeTrabalho() const
{
    return unidadeDeTrabalho;
}

void Vendedor::setUnidadeDeTrabalho(const string &value)
{
    unidadeDeTrabalho = value;
}

float Vendedor::getBonificacao() const
{
    return bonificacao;
}

void Vendedor::setBonificacao(float value)
{
    bonificacao = value;
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

    cout << "unidade de trabalho: " << unidadeDeTrabalho << endl;
    cout << "bonificacao: " << bonificacao << endl;
}
