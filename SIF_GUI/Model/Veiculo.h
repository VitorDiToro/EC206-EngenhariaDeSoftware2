#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <vector>
#include "Acessorio.h"

using namespace std;

class Veiculo
{
    private:
        string modelo;
        string cor;
        unsigned int ano;
        float preco;

        static int total;
        int id;

    public:
        Veiculo();
        ~Veiculo();

        string getModelo() const;
        void setModelo(const string &value);
        string getCor() const;
        void setCor(const string &value);
        unsigned int getAno() const;
        void setAno(unsigned int value);
        float getPreco() const;
        void setPreco(float value);

        //static int getTotal();
        int getId() const;
        void setId(int value); // Utilizado apenas para testes.
                               // O 'id' é definido automaticamente pleo bando.
        //Métodos para debug
        void print();
        void print_details();
};

extern vector<Veiculo*> veiculos;

#endif // VEICULO_H
