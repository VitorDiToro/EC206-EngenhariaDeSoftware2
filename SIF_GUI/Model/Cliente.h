#ifndef CLIENTE_H
#define CLIENTE_H

#include <vector>
#include "Pessoa.h"

using namespace std;

class Venda;

class Cliente : public Pessoa
{
    private:
        vector<Venda*> vendas;
        unsigned int qtdVendas;

        static int total;
    public:
        Cliente();
        ~Cliente();

        vector<Venda*> getVendas() const;
        void setVendas(const vector<Venda *> &value);
        unsigned int getQtdVendas() const;
        void incQtdVendas(void);
        void decQtdVendas(void);

        static int getTotal();

        void print();
        void print_details();
};

extern vector<Cliente*> clientes;

#endif // CLIENTE_H
