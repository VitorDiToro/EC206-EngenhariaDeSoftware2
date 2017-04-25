#include "ListenerVendedor.h"

// CRUD functions

void Vendedor_cadastrar()
{
    cout << endl << "Cadastrar Vendedor" << endl;
    Vendedor* g = new Vendedor();

    vendedores.push_back(g);
}

void Vendedor_listar()
{
    unsigned int i;

    cout << endl << "Listar Vendedor" << endl;
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
