#include "Venda.h"

#define FAIL 0

int Venda::total = 0;

vector<Venda*> vendas;

Venda::Venda()
{
    unsigned int id;

    cout << "id cliente: ";
    cin >> id;

    if(id < clientes.size())
    {
        cliente = clientes[id];
        cout << "ok cliente" << endl;
    }
    else
    {
        throw FAIL;
    }

    cout << "id vendedor: ";
    cin >> id;

    if(id < vendedores.size())
    {
        vendedor = vendedores[id];
        cout << "ok vendedor" << endl;
    }
    else
    {
        cliente = NULL;
        throw FAIL;
    }

    cout << "id veiculo: ";
    cin >> id;

    if(id < veiculos.size())
    {
        veiculo = veiculos[id];
        veiculos.erase(veiculos.begin() + id);
        preco = veiculo->getPreco();
        cout << "ok veiculo" << endl;
    }
    else
    {
        cliente = NULL;
        vendedor = NULL;
        preco = 0;
        throw FAIL;
    }

    total++;
}

Venda::~Venda()
{
    if(cliente)
    {
        cliente = NULL;
    }

    if(vendedor)
    {
        vendedor = NULL;
    }

    if(veiculo)
    {
        veiculos.push_back(veiculo);
        veiculo = NULL;
    }

    preco = 0;

    total--;
}

Veiculo *Venda::getVeiculo() const
{
    return veiculo;
}

void Venda::setVeiculo(Veiculo *value)
{
    veiculo = value;
}

Cliente *Venda::getCliente() const
{
    return cliente;
}

void Venda::setCliente(Cliente *value)
{
    cliente = value;
}

Vendedor *Venda::getVendedor() const
{
    return vendedor;
}

void Venda::setVendedor(Vendedor *value)
{
    vendedor = value;
}

float Venda::getPreco() const
{
    return preco;
}

void Venda::setPreco(float value)
{
    preco = value;
}

int Venda::getTotal()
{
    return total;
}

int Venda::getId() const
{
    return id;
}

void Venda::setId(int value)
{
    id = value;
}

void Venda::print()
{
    cout << "######################################" << endl;
    cout << "id: " << id << endl;

    if(veiculo)
    {
        cout << endl << "veiculo:" << endl;
        veiculo->print();
    }

    if(cliente)
    {
        cout << endl << "cliente:" << endl;
        cliente->print();
    }

    if(vendedor)
    {
        cout << endl << "vendedor:" << endl;
        vendedor->print();
    }

    cout << endl << "valor: " << preco << endl;
    cout << "######################################" << endl;
}

void Venda::print_details()
{
    cout << "######################################" << endl;
    cout << "id: " << id << endl;

    if(veiculo)
    {
        cout << endl << "veiculo:" << endl;
        veiculo->print_details();
    }

    if(cliente)
    {
        cout << endl << "cliente:" << endl;
        cliente->print_details();
    }

    if(vendedor)
    {
        cout << endl << "vendedor:" << endl;
        vendedor->print_details();
    }

    cout << endl << "valor: " << preco << endl;
    cout << "######################################" << endl;
}

