#include "Pessoa.h"
#include <stdio.h>

int Pessoa::total = 0;

Pessoa::Pessoa()
{
    //cout << "pessoa" << endl;
    cout << "nome: ";
    cin >> nome;
    getchar();
    cout << "cpf: ";
    cin >> cpf;
    cout << "telefone: ";
    cin >> telefone;
    cout << "endereco: ";
    cin >> endereco;
    id = total++;
};

Pessoa::~Pessoa()
{
    //cout << "Pessoa destructor" << endl;
    nome = "";
    cpf = "";
    telefone = "";
    endereco = "";
};

Pessoa::Pessoa(string n, string c, string t, string e)
{
    nome = n;
    cpf = c;
    telefone = t;
    endereco = e;
};

string Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(const string &value)
{
    nome = value;
}

string Pessoa::getCpf() const
{
    return cpf;
}

void Pessoa::setCpf(const string &value)
{
    cpf = value;
}

string Pessoa::getTelefone() const
{
    return telefone;
}

void Pessoa::setTelefone(const string &value)
{
    telefone = value;
}

string Pessoa::getEndereco() const
{
    return endereco;
}

void Pessoa::setEndereco(const string &value)
{
    endereco = value;
}

int Pessoa::getTotal()
{
    return total;
}

int Pessoa::getId() const
{
    return id;
}

void Pessoa::setId(int value)
{
    id = value;
}

void Pessoa::print()
{
    cout << "id: " << this->id << endl;
    cout << "nome: " << this->nome << endl;
}

void Pessoa::print_details()
{
    cout << "id: " << this->id << endl;
    cout << "nome: " << this->getNome() << endl;
    cout << "cpf: " << this->getCpf() << endl;
    cout << "telefone: " << this->getTelefone() << endl;
    cout << "endereco: " << this->getEndereco() << endl;
}
