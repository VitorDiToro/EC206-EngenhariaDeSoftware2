#include "ListenerGerente.h"

// CRUD functions

void Gerente_cadastrar(string nome, string cpf, string telefone, string endereco, float salario,
                       string login, string senha, string unidadeQueGerencia)
{
    cout << endl << "Cadastrar Gerente" << endl;
    //Gerente* g = new Gerente();
    if(Gerente::getTotal() == 0)
    {
        Gerente* g = Gerente::getInstance();
        g->setNome(nome);
        g->setCpf(cpf);
        g->setTelefone(telefone);
        g->setEndereco(endereco);
        g->setSalario(salario);
        g->setLogin(login);
        g->setSenha(senha);
        g->setUnidadeQueGerencia(unidadeQueGerencia);

        g->print_details();

        gerentes.push_back(g);
    }
    else
    {
        cout << "Gerente ja cadastrado." << endl;
    }
}

void Gerente_listar()
{
    unsigned int i;

    cout << endl << "Listar Gerentes" << endl;

    cout << gerentes.size() << " gerentes cadastrados" << endl;

    for (i = 0; i < gerentes.size(); ++i)
    {
        cout << endl << "Gerente " << i+1 << endl;
        gerentes[i]->print();
    }
}

void Gerente_consultar()
{
    unsigned int id;

    cout << endl << "Consultar Gerente" << endl;

    cout << "id: ";
    cin >> id;

    if(id < gerentes.size())
    {
        gerentes[id]->print_details();
    }
    else
    {
        cout << "not found" << endl;
    }
}

void Gerente_editar()
{
    cout << "Padrao Singleton implementado nessa classe. Opcao temporariamente inválida" << endl;
    return;

    unsigned int id;

    cout << endl << "Editar Gerente" << endl;

    cout << "id: ";
    cin >> id;

    if(id < gerentes.size())
    {
        //Gerente* g = new Gerente();
        Gerente* g = Gerente::getInstance();

        delete gerentes[id];

        gerentes[id] = g;

        gerentes[id]->setId(id);
    }
    else
    {
        cout << "not found" << endl;
    }
}

void Gerente_remover()
{
    unsigned int id;

    cout << endl << "Remover Gerente" << endl;

    cout << "id: " << endl;
    cin >> id;

    if(id < gerentes.size())
    {
       delete gerentes[id];
       gerentes.erase(gerentes.begin()+id);
       cout << "deleted" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}