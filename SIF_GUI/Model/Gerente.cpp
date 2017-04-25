#include "Gerente.h"
#include <stdio.h>

int Gerente::total = 0;
Gerente* Gerente::INSTANCE = NULL;

vector<Gerente*> gerentes;

Gerente::Gerente()
{
    cout << "unidade que gerencia: ";
    cin >> unidadeQueGerencia;

    setId(total++);
}

Gerente::~Gerente()
{
    total--;
}

Gerente* Gerente::getInstance()
{
    if(INSTANCE == NULL)
    {
        INSTANCE = new Gerente();
    }

    return INSTANCE;
}

string Gerente::getUnidadeQueGerencia() const
{
    return unidadeQueGerencia;
}

void Gerente::setUnidadeQueGerencia(const string &value)
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

    cout << "unidade que gerencia: " << unidadeQueGerencia << endl;
}
