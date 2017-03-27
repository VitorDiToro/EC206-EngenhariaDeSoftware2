#include "Cliente.h"

int Cliente::total = 0;

vector<Cliente*> clientes;

Cliente::Cliente()
{
    //cout << "cliente" << endl;
    vendas.clear();

    setId(total++);
}

Cliente::~Cliente()
{
//    for (unsigned int i = 0; i < vendas.size(); i++)
//    {
//        if(vendas[i])
//        {
//            delete vendas[i];
//        }
//    }
    vendas.clear();

    total--;
}

vector<Venda*> Cliente::getVendas() const
{
    return vendas;
}

void Cliente::setVendas(const vector<Venda *> &value)
{
    vendas = value;
}

int Cliente::getTotal()
{
    return total;
}

void Cliente::print()
{
    Pessoa::print();
}

void Cliente::print_details()
{
    Pessoa::print_details();
}
