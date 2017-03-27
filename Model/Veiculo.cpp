#include "Veiculo.h"
#include <string.h>
#include <stdio.h>
#include <sstream>

int Veiculo::total = 0;

vector<Veiculo*> veiculos;

Veiculo::Veiculo()
{
    cout << "Cadastro de Veiculo" << endl;

    cout << "nome: ";
    cin >> this->nome;
    getchar();
    cout << "cor: ";
    cin >> this->cor;
    getchar();
    cout << "ano: ";
    cin >> this->ano;
    cout << "preco: ";
    cin >> this->preco;

    acessorios.clear();

    id = total++;
}

Veiculo::~Veiculo()
{
    cout << "destructor" << endl;

    nome = "";
    cor = "";
    ano = 0;
    preco = 0;
    id = 0;

    acessorios.clear();

    total--;
}

int Veiculo::getTotal()
{
    return total;
}

string Veiculo::getNome() const
{
    return nome;
}

void Veiculo::setNome(const string &value)
{
    nome = value;
}

string Veiculo::getCor() const
{
    return cor;
}

void Veiculo::setCor(const string &value)
{
    cor = value;
}

int Veiculo::getAno() const
{
    return ano;
}

void Veiculo::setAno(int value)
{
    ano = value;
}

float Veiculo::getPreco() const
{
    return preco;
}

void Veiculo::setPreco(float value)
{
    preco = value;
}


int Veiculo::getId() const
{
    return id;
}

void Veiculo::setId(int value)
{
    id = value;
}

void Veiculo::print()
{
    cout << "id: " << this->id << endl;
    cout << "nome: " << this->nome << endl;
}

void Veiculo::print_details()
{
    cout << "id: " << this->id << endl;
    cout << "nome: " << this->nome << endl;
    cout << "cor: " << this->cor << endl;
    cout << "ano: " << this->ano << endl;
    cout << "preco: " << this->preco << endl;
}


