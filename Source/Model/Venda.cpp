#include "Venda.h"

#define FAIL 0

int Venda::total = 0;

vector<Venda*> vendas;

Venda::Venda()
{
    int id;
    
    cout << "id cliente: ";
    cin >> id;
    
//    if((unsigned int)id < clientes.size())
//    {
//        cliente = clientes[id];
//        cliente->incQtdVendas();

//        cout << "ok cliente" << endl;
//    }
//    else
//    {
//        throw FAIL;
//    }

//    cout << "id vendedor: ";
//    cin >> id;

//    if((unsigned int)id < vendedores.size())
//    {
//        vendedor = vendedores[id];
//        cout << "ok vendedor" << endl;
//    }
//    else
//    {
//        cliente = NULL;
//        throw FAIL;
//    }

//    cout << "id veiculo: ";
//    cin >> id;

//    if((unsigned int)id < veiculos.size())
//    {
//        veiculo = veiculos[id];
//        //veiculos.erase(veiculos.begin() + id);
//        valor = veiculo->getPreco();
//        cout << "ok veiculo" << endl;
//    }
//    else
//    {
//        cliente = NULL;
//        vendedor = NULL;
//        valor = 0;
//        throw FAIL;
//    }
    cout << "data: ";

    acessorios.clear();

    do
    {
        cout << "id acessorio (-1 para sair): ";
        cin >> id;

        if(id < Acessorio::getTotal() && id >= 0)
        {
            cout << "eh menor que o total." << endl;
            this->acessorios.push_back(stock_acessorios[id]);
            valor += acessorios[id]->getPreco();
            cout << "ok acessorio" << endl;
        }
    } while(id != -1);

    total++;
}

Venda::~Venda()
{
    if(cliente)
    {
        cliente->decQtdVendas();
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

    valor = 0;

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

float Venda::getValor() const
{
    return valor;
}

void Venda::setValor(float value)
{
    valor = value;
}

string Venda::getData() const
{
    return data;
}

void Venda::setData(const string &value)
{
    data = value;
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

    cout << endl << "valor: " << valor << endl;
    cout << endl << "data: " << data << endl;
    cout << "######################################" << endl;
}

void Venda::print_details()
{
    unsigned int i;

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

    for(i = 0; i < this->acessorios.size(); i++)
    {
        cout << "acessorio 1:" << endl;
        acessorios[i]->print_details();
    }

    cout << endl << "valor: " << valor << endl;
    cout << endl << "data: " << data << endl;
    cout << "######################################" << endl;
}
