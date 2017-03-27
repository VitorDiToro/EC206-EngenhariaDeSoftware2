#ifndef GERENTE_H
#define GERENTE_H

#include <iostream>
#include <vector>

#include "Funcionario.h"

using namespace std;

class Gerente : public Funcionario
{
    public:
        vector<string> unidades;

        static int total;
    public:
        Gerente();
        ~Gerente();

        vector<string> getUnidades() const;
        void setUnidades(const vector<string> &value);

        static int getTotal();

        void print();
        void print_details();
};

extern vector<Gerente*> gerentes;

#endif // GERENTE_H
