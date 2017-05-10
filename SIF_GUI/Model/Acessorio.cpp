#include "Acessorio.h"

int Acessorio::total = 0;

vector<Acessorio*> stock_acessorios;

Acessorio::Acessorio()
{
//    cout << "nome: ";
//    cin >> this->nome;
//    cout << "preco: ";
//    cin >> this->preco;
//    cout << "descricao: ";
//    cin >> this->descricao;
    id = total++;
}

Acessorio::~Acessorio()
{
    this->nome = "";
    this->descricao = "";

    total--;
}

string Acessorio::getNome() const
{
    return nome;
}

void Acessorio::setNome(const string &value)
{
    nome = value;
}

float Acessorio::getPreco() const
{
    return preco;
}

void Acessorio::setPreco(float value)
{
    preco = value;
}

string Acessorio::getDescricao() const
{
    return descricao;
}

void Acessorio::setDescricao(const string &value)
{
    descricao = value;
}

int Acessorio::getTotal()
{
    return total;
}

int Acessorio::getId() const
{
    return id;
}

void Acessorio::setId(int value)
{
    id = value;
}

void Acessorio::print()
{
    cout << "id: " << id << endl;
    cout << "nome: " << nome << endl;
}

void Acessorio::print_details()
{
    print();

    cout << "preco: " << preco << endl;
    cout << "descricao: " << descricao << endl;
}
