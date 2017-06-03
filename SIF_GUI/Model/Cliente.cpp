#include "Cliente.h"

int Cliente::total = 0;

vector<Cliente*> clientes;

Cliente::Cliente()
{
    //qDebug() << "cliente" << endl;
    vendas.clear();
    qtdVendas = 0;
    
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
    qtdVendas = 0;

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

unsigned int Cliente::getQtdVendas() const
{
    return qtdVendas;
}

void Cliente::incQtdVendas()
{
    qtdVendas++;
}

void Cliente::decQtdVendas()
{
    qtdVendas--;
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
