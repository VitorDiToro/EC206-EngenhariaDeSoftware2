#include "ListenerVenda.h"

// CRUD functions

void Venda_cadastrar()
{
    cout << endl << "Cadastrar Venda" << endl;
    try
    {
        Venda* v = new Venda();
        vendas.push_back(v);
    }
    catch(int a)
    {
        cout << "fail" << endl;
    }
}

void Venda_listar()
{
    unsigned int i;

    cout << endl << "Listar vendas" << endl;

    cout << vendas.size() << " vendas cadastradas" << endl;

    for (i = 0; i < vendas.size(); ++i)
    {
        cout << endl << "Venda " << i+1 << endl;
        vendas[i]->print();
    }
}

void Venda_consultar()
{
    unsigned int id;

    cout << endl << "Consultar Venda" << endl;

    cout << "id: ";
    cin >> id;

    if(id < vendas.size())
    {
        vendas[id]->print_details();
    }
    else
    {
        cout << "not found" << endl;
    }
}

void Venda_editar()
{
    unsigned int id;

    cout << endl << "Editar Venda" << endl;

    cout << "id: ";
    cin >> id;

    if(id < vendas.size())
    {
        Venda* v = new Venda();

        delete vendas[id];

        vendas[id] = v;

        vendas[id]->setId(id);
    }
    else
    {
        cout << "not found" << endl;
    }
}

void Venda_remover()
{
    unsigned int id;

    cout << endl << "Remover Venda" << endl;

    cout << "id: ";
    cin >> id;

    if(id < vendas.size())
    {
       delete vendas[id];
       vendas.erase(vendas.begin()+id);
       cout << "deleted" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}
