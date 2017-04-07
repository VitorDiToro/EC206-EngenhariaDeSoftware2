#ifndef GERENTE_H
#define GERENTE_H

#include <iostream>
#include <vector>

#include "Funcionario.h"

using namespace std;

class Gerente : public Funcionario
{
    private:
        static Gerente* INSTANCE;
        vector<string> unidades;

        static int total;

        Gerente();
    public:
        ~Gerente();

        static Gerente* getInstance();

        vector<string> getUnidades() const;
        void setUnidades(const vector<string> &value);

        static int getTotal();

        void print();
        void print_details();
};

extern vector<Gerente*> gerentes;

#endif // GERENTE_H
