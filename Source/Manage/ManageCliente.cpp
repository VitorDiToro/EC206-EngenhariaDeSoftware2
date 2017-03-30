#include "ManageCliente.h"

// CRUD functions

void Cliente_cadastrar()
{
    cout << endl << "Cadastrar Cliente" << endl;
    Cliente* g = new Cliente();

    clientes.push_back(g);
}

void Cliente_listar()
{
    unsigned int i;

    cout << endl << "Listar Clientes" << endl;
    for (i = 0; i < clientes.size(); ++i)
    {
        cout << endl << "Cliente " << i+1 << endl;
        clientes[i]->print();
    }
}

void Cliente_consultar()
{
    unsigned int id;

    cout << endl << "Consultar Cliente" << endl;

    cout << "id: ";
    cin >> id;

    if(id < clientes.size())
    {
        clientes[id]->print_details();
    }
    else
    {
        cout << "not found" << endl;
    }
}

void Cliente_editar()
{
    unsigned int id;

    cout << endl << "Editar Cliente" << endl;

    cout << "id: ";
    cin >> id;

    if(id < clientes.size())
    {
        Cliente* c = new Cliente();

        delete clientes[id];

        clientes[id] = c;

        clientes[id]->setId(id);
    }
    else
    {
        cout << "not found" << endl;
    }
}

void Cliente_remover()
{
    unsigned int id;

    cout << endl << "Remover Cliente" << endl;

    cout << "id: " << endl;
    cin >> id;

    if(id < clientes.size())
    {
       delete clientes[id];
       clientes.erase(clientes.begin()+id);
       cout << "deleted" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}
