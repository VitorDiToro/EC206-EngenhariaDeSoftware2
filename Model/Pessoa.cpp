#include "Pessoa.h"
#include <stdio.h>

int Pessoa::total = 0;

Pessoa::Pessoa()
{
    //cout << "pessoa" << endl;
    cout << "nome: ";
    cin >> nome;
    getchar();
    cout << "data de nascimento: ";
    cin >> dataDeNascimento;
    getchar();
    cout << "cpf: ";
    cin >> cpf;
    cout << "telefone: ";
    cin >> telefone;
    cout << "endereco: ";
    cin >> endereco;
    cout << "email: ";
    cin >> email;
    id = total++;
};

Pessoa::~Pessoa()
{
    //cout << "Pessoa destructor" << endl;
    nome = "";
    dataDeNascimento = "";
    cpf = "";
    telefone = "";
    endereco = "";
    email = "";
};

Pessoa::Pessoa(string n, string d, string c, string t, string e, string em)
{
    nome = n;
    dataDeNascimento = d;
    cpf = c;
    telefone = t;
    endereco = e;
    email = em;
};

string Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(const string &value)
{
    nome = value;
}

string Pessoa::getDataDeNascimento() const
{
    return dataDeNascimento;
}

void Pessoa::setDataDeNascimento(const string &value)
{
    dataDeNascimento = value;
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

string Pessoa::getEmail() const
{
    return email;
}

void Pessoa::setEmail(const string &value)
{
    email = value;
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
    cout << "data de nascimento: " << this->getDataDeNascimento() << endl;
    cout << "cpf: " << this->getCpf() << endl;
    cout << "telefone: " << this->getTelefone() << endl;
    cout << "endereco: " << this->getEndereco() << endl;
    cout << "email: " << this->getEmail() << endl;
}
