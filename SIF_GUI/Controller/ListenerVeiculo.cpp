#include "ListenerVeiculo.h"
#include <QDebug>

// CRUD functions

void Veiculo_cadastrar(string modelo, string cor, unsigned int ano, float preco)
{
    cout << endl << "Cadastrar veiculo" << endl;
    Veiculo* v = new Veiculo();
    v->setModelo(modelo);
    v->setCor(cor);
    v->setAno(ano);
    v->setPreco(preco);

    v->print_details();

    veiculos.push_back(v);
}

void Veiculo_listar()
{
    unsigned int i;

    cout << endl << "Listar Veiculo" << endl;

    cout << veiculos.size() << " veiculos cadastrados" << endl;

    for (i = 0; i < veiculos.size(); ++i)
    {
        cout << endl << "Veiculo " << i+1 << endl;
        veiculos[i]->print();
    }
}

void Veiculo_consultar()
{
    unsigned int id;

    cout << endl << "Consultar" << endl;

    cout << "id: ";
    cin >> id;

    if(id < veiculos.size())
    {
        veiculos[id]->print_details();
    }
    else
    {
        cout << "not found" << endl;
    }
}

void Veiculo_editar()
{
    unsigned int id;

    cout << endl << "Editar Veiculo" << endl;

    cout << "id: ";
    cin >> id;

    if(id < veiculos.size())
    {
        Veiculo* v = new Veiculo();

        delete veiculos[id];

        veiculos[id] = v;

        veiculos[id]->setId(id);
    }
    else
    {
        cout << "not found" << endl;
    }
}

void Veiculo_remover()
{
    unsigned int id;

    cout << endl << "Consultar";

    cout << "id: " << endl;
    cin >> id;

    if(id < veiculos.size())
    {
       delete veiculos[id];
       veiculos.erase(veiculos.begin()+id);
       cout << "deleted" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}
