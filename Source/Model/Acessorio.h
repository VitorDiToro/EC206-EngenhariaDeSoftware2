#ifndef ACESSORIO_H
#define ACESSORIO_H

#include<iostream>
#include <vector>

using namespace std;

class Acessorio
{
    private:
        string nome;
        float preco;
        string descricao;

        static int total;
        int id;
    public:
        Acessorio();
        ~Acessorio();

        string getNome() const;
        void setNome(const string &value);
        float getPreco() const;
        void setPreco(float value);
        string getDescricao() const;
        void setDescricao(const string &value);

        static int getTotal();
        int getId() const;
        void setId(int value);

        void print();
        void print_details();
};

extern vector<Acessorio*> stock_acessorios;

#endif // ACESSORIO_H
