#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;

class Venda;

class Cliente : public Pessoa
{
    private:
        vector<Venda*> vendas;

        static int total;
    public:
        Cliente();
        ~Cliente();

        vector<Venda*> getVendas() const;
        void setVendas(const vector<Venda *> &value);

        static int getTotal();

        void print();
        void print_details();
};

extern vector<Cliente*> clientes;

#endif // CLIENTE_H
