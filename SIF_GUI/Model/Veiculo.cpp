#include "Veiculo.h"
#include <stdio.h>
#include <sstream>
#include <QDebug>

int Veiculo::total = 0;

vector<Veiculo*> veiculos;

Veiculo::Veiculo()
{
    //    cout << "Construtor de Veiculo" << endl;

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
//  cout << "destructor" << endl;

    modelo = "";
    cor = "";
    ano = 0;
    preco = 0;
    id = 0;

    total--;
}

/* ======== XXX ========
 Samuel, por que existe este método?
 A ideia era utiliza-lo p/ o que exatamente?
========================*/
//int Veiculo::getTotal()
//{
//    return total;
//}

QString Veiculo::getModelo() const
{
    return modelo;
}

void Veiculo::setModelo(const QString &value)
{
    modelo = value;
}

QString Veiculo::getCor() const
{
    return cor;
}

void Veiculo::setCor(const QString &value)
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

unsigned int Veiculo::getQuantidade() const
{
    return quantidade;
}

void Veiculo::setQuantidade(unsigned int value)
{
    quantidade = value;
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
    qDebug() << "id: " << this->id << endl;
    qDebug() << "modelo: " << this->modelo << endl;
}

void Veiculo::print_details()
{
    qDebug() << "id: " << this->id << endl;
    qDebug() << "modelo: " << this->modelo << endl;
    qDebug() << "cor: " << this->cor << endl;
    qDebug() << "ano: " << this->ano << endl;
    qDebug() << "preco: " << this->preco << endl;
}


