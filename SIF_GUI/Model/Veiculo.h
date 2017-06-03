#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <vector>
#include "Acessorio.h"

using namespace std;

class Veiculo
{
    private:
        QString modelo;
        QString cor;
        unsigned int ano;
        float preco;
        unsigned int quantidade;

        static int total;
        int id;

    public:
        Veiculo();
        ~Veiculo();

        QString getModelo() const;
        void setModelo(const QString &value);
        QString getCor() const;
        void setCor(const QString &value);
        unsigned int getAno() const;
        void setAno(unsigned int value);
        float getPreco() const;
        void setPreco(float value);
        unsigned int getQuantidade() const;
        void setQuantidade(unsigned int value);

        //static int getTotal();
        int getId() const;
        void setId(int value); // Utilizado apenas para testes.
                               // O 'id' é definido automaticamente pelo banco
        //Métodos para debug
        void print();
        void print_details();
};

extern vector<Veiculo*> veiculos;

#endif // VEICULO_H
