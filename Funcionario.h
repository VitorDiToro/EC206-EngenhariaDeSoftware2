#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.h"


class Funcionario : public Pessoa
{
    private:
        float salario;

        static int total;
    public:
        Funcionario();
        ~Funcionario();

        float getSalario() const;
        void setSalario(float value);

        static int getTotal();

        void print();
        void print_details();
};

#endif // FUNCIONARIO_H
