#include "Pessoa.h"
#include <stdio.h>

int Pessoa::total = 0;

Pessoa::Pessoa()
{
//    qDebug() << "pessoa" << endl;
//    qDebug() << "nome: ";
//    cin >> nome;
//    getchar();
//    qDebug() << "cpf: ";
//    cin >> cpf;
//    qDebug() << "telefone: ";
//    cin >> telefone;
//    qDebug() << "endereco: ";
//    cin >> endereco;
    id = total++;
}

Pessoa::~Pessoa()
{
    //qDebug() << "Pessoa destructor" << endl;
    nome = "";
    cpf = "";
    telefone = "";
    endereco = "";
}

Pessoa::Pessoa(QString n, QString c, QString t, QString e)
{
    nome = n;
    cpf = c;
    telefone = t;
    endereco = e;
}

QString Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(const QString &value)
{
    nome = value;
}

QString Pessoa::getCpf() const
{
    return cpf;
}

void Pessoa::setCpf(const QString &value)
{
    cpf = value;
}

QString Pessoa::getTelefone() const
{
    return telefone;
}

void Pessoa::setTelefone(const QString &value)
{
    telefone = value;
}

QString Pessoa::getEndereco() const
{
    return endereco;
}

void Pessoa::setEndereco(const QString &value)
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
    qDebug() << "id: " << this->id << endl;
    qDebug() << "nome: " << this->nome << endl;
}

void Pessoa::print_details()
{
    qDebug() << "id: " << this->id;
    qDebug() << "nome: " << this->getNome();
    qDebug() << "cpf: " << this->getCpf();
    qDebug() << "telefone: " << this->getTelefone();
    qDebug() << "endereco: " << this->getEndereco();
}
