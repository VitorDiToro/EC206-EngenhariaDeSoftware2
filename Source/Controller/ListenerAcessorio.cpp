#include "ListenerAcessorio.h"

// CRUD functions

void Acessorio_cadastrar()
{
    cout << endl << "Cadastrar Acessorio" << endl;
    Acessorio* g = new Acessorio();

    acessorios.push_back(g);
}

void Acessorio_listar()
{
    unsigned int i;

    cout << endl << "Listar Acessorios" << endl;
    for (i = 0; i < acessorios.size(); ++i)
    {
        cout << endl << "Acessorio " << i+1 << endl;
        acessorios[i]->print();
    }
}

void Acessorio_consultar()
{
    unsigned int id;

    cout << endl << "Consultar Acessorio" << endl;

    cout << "id: ";
    cin >> id;

    if(id < acessorios.size())
    {
        acessorios[id]->print_details();
    }
    else
    {
        cout << "not found" << endl;
    }
}

void Acessorio_editar()
{
    unsigned int id;

    cout << endl << "Editar Acessorio" << endl;

    cout << "id: ";
    cin >> id;

    if(id < acessorios.size())
    {
        Acessorio* a = new Acessorio();

        delete acessorios[id];

        acessorios[id] = a;

        acessorios[id]->setId(id);
    }
    else
    {
        cout << "not found" << endl;
    }
}

void Acessorio_remover()
{
    unsigned int id;

    cout << endl << "Remover Acessorio" << endl;

    cout << "id: " << endl;
    cin >> id;

    if(id < acessorios.size())
    {
       delete acessorios[id];
       acessorios.erase(acessorios.begin()+id);
       cout << "deleted" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

