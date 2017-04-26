#include "Funcionario.h"

int Funcionario::total = 0;

Funcionario::Funcionario()
{
//    cout << "login: ";
//    cin >> login;
//    cout << "senha: ";
//    cin >>senha;
//    cout << "salario: ";
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

string Funcionario::getLogin() const
{
    return login;
}

void Funcionario::setLogin(const string &value)
{
    login = value;
}

string Funcionario::getSenha() const
{
    return senha;
}

void Funcionario::setSenha(string value)
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

    cout << "salario: " << salario << endl;
}

