#ifndef VENDA_H
#define VENDA_H

#include "Veiculo.h"
#include "Cliente.h"
#include "Vendedor.h"

class Venda
{
    private:
        Veiculo* veiculo;
        Cliente* cliente;
        Vendedor* vendedor;
        float preco;

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
        float getPreco() const;
        void setPreco(float value);

        static int getTotal();
        int getId() const;
        void setId(int value);

        void print();
        void print_details();
};

extern vector<Venda*> vendas;

#endif // VENDA_H
