#include "Gerente.h"
#include <stdio.h>

int Gerente::total = 0;
Gerente* Gerente::INSTANCE = NULL;

vector<Gerente*> gerentes;

Gerente::Gerente()
{
    unsigned int numeroDeUnidades;
    string unidade;
    cout << "numero de unidades: ";
    cin >> numeroDeUnidades;

    for (unsigned int i = 0; i < numeroDeUnidades; i++) {
        cout << "unidade " << i+1 << ": ";
        cin >> unidade;
        unidades.push_back(unidade);
    }

    setId(total++);
}

Gerente::~Gerente()
{
    unidades.clear();

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

vector<string> Gerente::getUnidades() const
{
    return unidades;
}

void Gerente::setUnidades(const vector<string> &value)
{
    unidades = value;
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
    unsigned int i;

    Funcionario::print_details();

    for (i = 0; i < unidades.size(); i++) {
        cout << "unidade " << i << ": " << unidades[i] << endl;
    }
}
