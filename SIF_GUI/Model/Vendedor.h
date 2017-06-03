#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <iostream>
#include <vector>

#include "Funcionario.h"

using namespace std;

class Vendedor : public Funcionario
{
    public:
        QString unidadeDeTrabalho;
        float comissao;

        static int total;
    public:
        Vendedor();
        ~Vendedor();

        QString getUnidadeDeTrabalho() const;
        void setUnidadeDeTrabalho(const QString &value);
        float getComissao() const;
        void setComissao(float value);

        static int getTotal();

        void print();
        void print_details();
};

extern vector<Vendedor*> vendedores;

#endif // VENDEDOR_H
