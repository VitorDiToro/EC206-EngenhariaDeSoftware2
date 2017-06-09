#include "Acessorio.h"

int Acessorio::total = 0;

vector<Acessorio*> stock_acessorios;

Acessorio::Acessorio()
{
    //    qDebug() << "nome: ";
    //    cin >> this->nome;
    //    qDebug() << "preco: ";
    //    cin >> this->preco;
    //    qDebug() << "descricao: ";
//    cin >> this->descricao;
    id = total++;
}

Acessorio::~Acessorio()
{
    this->nome = "";
    this->descricao = "";

    total--;
}

QString Acessorio::getNome() const
{
    return nome;
}

void Acessorio::setNome(const QString &value)
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

QString Acessorio::getDescricao() const
{
    return descricao;
}

void Acessorio::setDescricao(const QString &value)
{
    descricao = value;
}

unsigned int Acessorio::getQuantidade() const
{
    return quantidade;
}

void Acessorio::setQuantidade(unsigned int value)
{
    quantidade = value;
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
    qDebug() << "id: " << id;
    qDebug() << "nome: " << nome;
}

void Acessorio::print_details()
{
    print();

    qDebug() << "preco: " << preco;
    qDebug() << "descricao: " << descricao;
}
