#include "ListenerVendedor.h"
//#include "/Model/DAOVendedor.h"
#include <QDebug>

// CRUD functions

void Vendedor_cadastrar(string nome, string cpf, string telefone, string endereco, float salario,
                        string login, string senha, string unidadeDeTrabalho, float comissao)
{
    qDebug() << endl << "Cadastrar Vendedor" << endl;
    Vendedor* v = new Vendedor();
    v->setNome(nome);
    v->setCpf(cpf);
    v->setTelefone(telefone);
    v->setEndereco(endereco);
    v->setSalario(salario);
    v->setLogin(login);
    v->setSenha(senha);
    v->setUnidadeDeTrabalho(unidadeDeTrabalho);
    v->setComissao(comissao);

    v->print_details();

    vendedores.push_back(v);
}

void Vendedor_listar()
{
    unsigned int i;

    cout << endl << "Listar Vendedor" << endl;

    cout << vendedores.size() << " vendedores cadastrados" << endl;

    for (i = 0; i < vendedores.size(); ++i)
    {
        cout << endl << "Vendedor " << i+1 << endl;
        vendedores[i]->print();
    }
}

void Vendedor_consultar()
{
    unsigned int id;

    cout << endl << "Consultar Vendedor" << endl;

    cout << "id: ";
    cin >> id;

    if(id < vendedores.size())
    {
        vendedores[id]->print_details();
    }
    else
    {
        cout << "not found" << endl;
    }
}

void Vendedor_editar()
{
    unsigned int id;

    cout << endl << "Editar Vendedor" << endl;

    cout << "id: ";
    cin >> id;

    if(id < vendedores.size())
    {
        Vendedor* v = new Vendedor();

        delete vendedores[id];

        vendedores[id] = v;

        vendedores[id]->setId(id);
    }
    else
    {
        cout << "not found" << endl;
    }
}

void Vendedor_remover()
{
    unsigned int id;

    cout << endl << "Remover Vendedor" << endl;

    cout << "id: " << endl;
    cin >> id;

    if(id < vendedores.size())
    {
       delete vendedores[id];
       vendedores.erase(vendedores.begin()+id);
       cout << "deleted" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}
