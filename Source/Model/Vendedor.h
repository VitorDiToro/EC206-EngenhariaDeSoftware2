#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <iostream>
#include <vector>

#include "Funcionario.h"

using namespace std;

class Vendedor : public Funcionario
{
    public:
        string unidadeDeTrabalho;
        float bonificacao;

        static int total;
    public:
        Vendedor();
        ~Vendedor();

        string getUnidadeDeTrabalho() const;
        void setUnidadeDeTrabalho(const string &value);
        float getBonificacao() const;
        void setBonificacao(float value);

        static int getTotal();

        void print();
        void print_details();
};

extern vector<Vendedor*> vendedores;

#endif // VENDEDOR_H
