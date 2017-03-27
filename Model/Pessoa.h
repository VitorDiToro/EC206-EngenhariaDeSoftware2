#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>

using namespace std;

class Pessoa
{
    private:
        string nome;
        string dataDeNascimento;
        string cpf;
        string telefone;
        string endereco;
        string email;

        static int total;
        int id;
    public:
        Pessoa();
        Pessoa(string n, string d, string c, string t, string e, string em);
        ~Pessoa();

        string getNome() const;
        void setNome(const string &value);
        string getDataDeNascimento() const;
        void setDataDeNascimento(const string &value);
        string getCpf() const;
        void setCpf(const string &value);
        string getTelefone() const;
        void setTelefone(const string &value);
        string getEndereco() const;
        void setEndereco(const string &value);
        string getEmail() const;
        void setEmail(const string &value);

        static int getTotal();
        int getId() const;
        void setId(int value);

        void print();
        void print_details();
};

#endif // PESSOA_H
