#include "Veiculo.h"
#include <string.h>
#include <stdio.h>
#include <sstream>

int Veiculo::total = 0;

vector<Veiculo*> veiculos;

Veiculo::Veiculo()
{
    cout << "Construtor de Veiculo" << endl;

//    cout << "modelo: ";
//    cin >> this->modelo;
//    getchar();
//    cout << "cor: ";
//    cin >> this->cor;
//    getchar();
//    cout << "ano: ";
//    cin >> this->ano;
//    cout << "preco: ";
//    cin >> this->preco;

    id = total++;
}

Veiculo::~Veiculo()
{
    cout << "destructor" << endl;

    modelo = "";
    cor = "";
    ano = 0;
    preco = 0;
    id = 0;

    total--;
}

int Veiculo::getTotal()
{
    return total;
}

string Veiculo::getModelo() const
{
    return modelo;
}

void Veiculo::setModelo(const string &value)
{
    modelo = value;
}

string Veiculo::getCor() const
{
    return cor;
}

void Veiculo::setCor(const string &value)
{
    cor = value;
}

unsigned int Veiculo::getAno() const
{
    return ano;
}

void Veiculo::setAno(unsigned int value)
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
    cout << "modelo: " << this->modelo << endl;
}

void Veiculo::print_details()
{
    cout << "id: " << this->id << endl;
    cout << "modelo: " << this->modelo << endl;
    cout << "cor: " << this->cor << endl;
    cout << "ano: " << this->ano << endl;
    cout << "preco: " << this->preco << endl;
}


