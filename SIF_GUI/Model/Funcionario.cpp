#include "Funcionario.h"

int Funcionario::total = 0;

Funcionario::Funcionario()
{
//    qDebug() << "login: ";
//    cin >> login;
//    qDebug() << "senha: ";
//    cin >>senha;
//    qDebug() << "salario: ";
//    cin >> salario;
    setId(total++);
}

Funcionario::~Funcionario()
{
    salario = 0;

    total--;
}

float Funcionario::getSalario() const
{
    return salario;
}

void Funcionario::setSalario(float value)
{
    salario = value;
}

QString Funcionario::getLogin() const
{
    return login;
}

void Funcionario::setLogin(const QString &value)
{
    login = value;
}

QString Funcionario::getSenha() const
{
    return senha;
}

void Funcionario::setSenha(QString value)
{
    senha = value;
}

int Funcionario::getTotal()
{
    return total;
}

void Funcionario::print()
{
    Pessoa::print();
}

void Funcionario::print_details()
{
    Pessoa::print_details();

    qDebug() << "salario: " << salario << endl;
}

