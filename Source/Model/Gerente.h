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
        string unidadeQueGerencia;

        static int total;

        Gerente();
    public:
        ~Gerente();

        static Gerente* getInstance();

        string getUnidadeQueGerencia() const;
        void setUnidadeQueGerencia(const string &value);

        static int getTotal();

        void print();
        void print_details();
};

extern vector<Gerente*> gerentes;

#endif // GERENTE_H
