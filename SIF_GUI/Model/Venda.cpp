#include "Venda.h"

#define FAIL 0

int Venda::total = 0;

vector<Venda*> vendas;

Venda::Venda()
{
    int id;
    
    qDebug() << "id cliente: ";
    cin >> id;
    
//    if((unsigned int)id < clientes.size())
//    {
//        cliente = clientes[id];
//        cliente->incQtdVendas();

//        qDebug() << "ok cliente" << endl;
//    }
//    else
//    {
//        throw FAIL;
//    }

//    qDebug() << "id vendedor: ";
//    cin >> id;

//    if((unsigned int)id < vendedores.size())
//    {
//        vendedor = vendedores[id];
//        qDebug() << "ok vendedor" << endl;
//    }
//    else
//    {
//        cliente = NULL;
//        throw FAIL;
//    }

//    qDebug() << "id veiculo: ";
//    cin >> id;

//    if((unsigned int)id < veiculos.size())
//    {
//        veiculo = veiculos[id];
//        //veiculos.erase(veiculos.begin() + id);
//        valor = veiculo->getPreco();
//        qDebug() << "ok veiculo" << endl;
//    }
//    else
//    {
//        cliente = NULL;
//        vendedor = NULL;
//        valor = 0;
//        throw FAIL;
//    }
    qDebug() << "data: ";

    acessorios.clear();

    do
    {
        qDebug() << "id acessorio (-1 para sair): ";
        cin >> id;

        if(id < Acessorio::getTotal() && id >= 0)
        {
            qDebug() << "eh menor que o total." << endl;
            this->acessorios.push_back(stock_acessorios[id]);
            valor += acessorios[id]->getPreco();
            qDebug() << "ok acessorio" << endl;
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

QString Venda::getData() const
{
    return data;
}

void Venda::setData(const QString &value)
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
    qDebug() << "######################################" << endl;
    qDebug() << "id: " << id << endl;

    if(veiculo)
    {
        qDebug() << endl << "veiculo:" << endl;
        veiculo->print();
    }

    if(cliente)
    {
        qDebug() << endl << "cliente:" << endl;
        cliente->print();
    }

    if(vendedor)
    {
        qDebug() << endl << "vendedor:" << endl;
        vendedor->print();
    }

    qDebug() << endl << "valor: " << valor << endl;
    qDebug() << endl << "data: " << data << endl;
    qDebug() << "######################################" << endl;
}

void Venda::print_details()
{
    unsigned int i;

    qDebug() << "######################################" << endl;
    qDebug() << "id: " << id << endl;

    if(veiculo)
    {
        qDebug() << endl << "veiculo:" << endl;
        veiculo->print_details();
    }

    if(cliente)
    {
        qDebug() << endl << "cliente:" << endl;
        cliente->print_details();
    }

    if(vendedor)
    {
        qDebug() << endl << "vendedor:" << endl;
        vendedor->print_details();
    }

    for(i = 0; i < this->acessorios.size(); i++)
    {
        qDebug() << "acessorio 1:" << endl;
        acessorios[i]->print_details();
    }

    qDebug() << endl << "valor: " << valor << endl;
    qDebug() << endl << "data: " << data << endl;
    qDebug() << "######################################" << endl;
}
