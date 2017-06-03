#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H


#include "Pessoa.h"


class Funcionario : public Pessoa
{
    private:
        float salario;
        QString login;
        QString senha;

        static int total;
    public:
        Funcionario();
        ~Funcionario();

        float getSalario() const;
        void setSalario(float value);
        QString getLogin() const;
        void setLogin(const QString &value);
        QString getSenha() const;
        void setSenha(QString value);

        static int getTotal();

        void print();
        void print_details();
};

#endif // FUNCIONARIO_H
