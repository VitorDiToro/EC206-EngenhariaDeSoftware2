#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.h"


class Funcionario : public Pessoa
{
    private:
        float salario;
        string login;
        string senha;

        static int total;
    public:
        Funcionario();
        ~Funcionario();

        float getSalario() const;
        void setSalario(float value);
        string getLogin() const;
        void setLogin(const string &value);
        string getSenha() const;
        void setSenha(string value);

        static int getTotal();

        void print();
        void print_details();
};

#endif // FUNCIONARIO_H
