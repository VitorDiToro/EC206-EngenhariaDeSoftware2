#include "TelaPrincipal.h"
#include "ui_TelaPrincipal.h"
#include "ViewModel/TelaCadastroGerente.h"
#include "ViewModel/TelaCadastroVendedor.h"
#include "ViewModel/TelaCadastroCliente.h"
#include "ViewModel/TelaCadastroVeiculo.h"
#include "ViewModel/TelaCadastroAcessorio.h"
#include "ViewModel/TelaCadastroVenda.h"
#include "ViewModel/TelaListagem.h"
#include "Model/Acessorio.h"
#include "Model/Cliente.h"
#include "Model/Gerente.h"
#include "Model/Veiculo.h"
#include "Model/Venda.h"
#include "Model/Vendedor.h"

#include <QStyle>
#include <QDesktopWidget>
#include <iostream>

using namespace std;

TelaPrincipal::TelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPrincipal)
{

    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            qApp->desktop()->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    ui->setupUi(this);
}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}

void TelaPrincipal::on_actionCadastrar_6_triggered()
{
    TelaCadastroGerente* tcg = new TelaCadastroGerente();
    tcg->show();
}

void TelaPrincipal::on_actionCadastrar_5_triggered()
{
    TelaCadastroVendedor* tcv = new TelaCadastroVendedor();
    tcv->show();
}

void TelaPrincipal::on_actionCadastrar_4_triggered()
{
    TelaCadastroCliente* tcc = new TelaCadastroCliente();
    tcc->show();
}

void TelaPrincipal::on_actionCadastrar_3_triggered()
{
    TelaCadastroAcessorio* tca = new TelaCadastroAcessorio();
    tca->show();
}

void TelaPrincipal::on_actionCadastrar_2_triggered()
{
    TelaCadastroVeiculo* tcv = new TelaCadastroVeiculo();
    tcv->show();
}

void TelaPrincipal::on_actionCadastrar_triggered()
{
    TelaCadastroVenda* tcv = new TelaCadastroVenda();
    tcv->show();
}

void TelaPrincipal::on_actionListar_triggered()
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

void TelaPrincipal::on_actionListar_2_triggered()
{
    TelaListagem* tl = new TelaListagem();
    tl->show();
    tl->activateWindow();

    unsigned int i;

    cout << endl << "Listar Veiculo" << endl;

    cout << veiculos.size() << " veiculos cadastrados" << endl;

    for (i = 0; i < veiculos.size(); ++i)
    {
        cout << endl << "Veiculo " << i+1 << endl;
        veiculos[i]->print();
    }
}

void TelaPrincipal::on_actionListar_3_triggered()
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

void TelaPrincipal::on_actionListar_4_triggered()
{
    unsigned int i;

    cout << endl << "Listar Clientes" << endl;

    cout << clientes.size() << " clientes cadastrados" << endl;

    for (i = 0; i < clientes.size(); ++i)
    {
        cout << endl << "Cliente " << i+1 << endl;
        clientes[i]->print();
    }
}

void TelaPrincipal::on_actionListar_5_triggered()
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

void TelaPrincipal::on_actionListar_6_triggered()
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
