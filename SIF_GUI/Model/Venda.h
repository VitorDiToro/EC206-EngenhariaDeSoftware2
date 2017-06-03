#ifndef VENDA_H
#define VENDA_H

#include <QString>
#include "Veiculo.h"
#include "Cliente.h"
#include "Vendedor.h"

class Venda
{
    private:
        Veiculo* veiculo;
        Cliente* cliente;
        Vendedor* vendedor;
        vector<Acessorio*> acessorios;
        float valor;
        QString data;

        static int total;
        int id;
    public:
        Venda();
        ~Venda();

        Veiculo *getVeiculo() const;
        void setVeiculo(Veiculo *value);
        Cliente *getCliente() const;
        void setCliente(Cliente *value);
        Vendedor *getVendedor() const;
        void setVendedor(Vendedor *value);
        float getValor() const;
        void setValor(float value);
        QString getData() const;
        void setData(const QString &value);

        static int getTotal();
        int getId() const;
        void setId(int value);

        void print();
        void print_details();
};

extern vector<Venda*> vendas;

#endif // VENDA_H
