#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <vector>
#include "Acessorio.h"

using namespace std;

class Veiculo
{
    private:
        string nome;
        string cor;
        int ano;
        float preco;
        vector<Acessorio*> acessorios;

        static int total;
        int id;
    public:
        Veiculo();
        ~Veiculo();

        string getNome() const;
        void setNome(const string &value);
        string getCor() const;
        void setCor(const string &value);
        int getAno() const;
        void setAno(int value);
        float getPreco() const;
        void setPreco(float value);

        static int getTotal();
        int getId() const;
        void setId(int value);

        void print();
        void print_details();
};

extern vector<Veiculo*> veiculos;

#endif // VEICULO_H
