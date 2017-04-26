#include "ListenerAcessorio.h"

// CRUD functions

void Acessorio_cadastrar()
{
    cout << endl << "Cadastrar Acessorio" << endl;
    Acessorio* g = new Acessorio();

    stock_acessorios.push_back(g);
}

void Acessorio_listar()
{
    unsigned int i;

    cout << endl << "Listar Acessorios" << endl;

    cout << stock_acessorios.size() << " acessorios cadastrados" << endl;

    for (i = 0; i < stock_acessorios.size(); ++i)
    {
        cout << endl << "Acessorio " << i+1 << endl;
        stock_acessorios[i]->print();
    }
}

void Acessorio_consultar()
{
    unsigned int id;

    cout << endl << "Consultar Acessorio" << endl;

    cout << "id: ";
    cin >> id;

    if(id < stock_acessorios.size())
    {
        stock_acessorios[id]->print_details();
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

    if(id < stock_acessorios.size())
    {
        Acessorio* a = new Acessorio();

        delete stock_acessorios[id];

        stock_acessorios[id] = a;

        stock_acessorios[id]->setId(id);
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

    if(id < stock_acessorios.size())
    {
       delete stock_acessorios[id];
       stock_acessorios.erase(stock_acessorios.begin()+id);
       cout << "deleted" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

