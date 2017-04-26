#include "TelaPrincipal.h"
#include "ui_TelaPrincipal.h"
#include "View/TelaCadastroGerente.h"
#include "View/TelaCadastroVendedor.h"
#include "View/TelaCadastroCliente.h"
#include "View/TelaCadastroVeiculo.h"
#include "View/TelaCadastroAcessorio.h"

#include "Controller/ListenerGerente.h"
#include "Controller/ListenerVendedor.h"

TelaPrincipal::TelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPrincipal)
{
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
    //Gerente_cadastrar();
}

void TelaPrincipal::on_actionCadastrar_5_triggered()
{
    TelaCadastroVendedor* tcv = new TelaCadastroVendedor();
    tcv->show();
    //Vendedor_cadastrar();
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

}
