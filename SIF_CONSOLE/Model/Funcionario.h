#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.h"


class Funcionario : public Pessoa
{
    private:
        float salario;
        string login;
        long int senha;

        static int total;
    public:
        Funcionario();
        ~Funcionario();

        float getSalario() const;
        void setSalario(float value);
        string getLogin() const;
        void setLogin(const string &value);
        long getSenha() const;
        void setSenha(long value);

        static int getTotal();

        void print();
        void print_details();
};

#endif // FUNCIONARIO_H
