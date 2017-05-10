#include "TelaPrincipal.h"
#include "ui_TelaPrincipal.h"
#include "ViewModel/TelaCadastroGerente.h"
#include "ViewModel/TelaCadastroVendedor.h"
#include "ViewModel/TelaCadastroCliente.h"
#include "ViewModel/TelaCadastroVeiculo.h"
#include "ViewModel/TelaCadastroAcessorio.h"
#include "ViewModel/TelaCadastroVenda.h"
#include "ViewModel/TelaListagem.h"
#include "Controller/ListenerVeiculo.h"
#include "Controller/ListenerAcessorio.h"
#include "Controller/ListenerGerente.h"
#include "Controller/ListenerVendedor.h"
#include "Controller/ListenerCliente.h"
#include "Controller/ListenerVenda.h"

#include "Controller/ListenerGerente.h"
#include "Controller/ListenerVendedor.h"
#include <QStyle>
#include <QDesktopWidget>

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
    Venda_listar();
}

void TelaPrincipal::on_actionListar_2_triggered()
{
    TelaListagem* tl = new TelaListagem();
    tl->show();
    tl->activateWindow();

    Veiculo_listar();
}

void TelaPrincipal::on_actionListar_3_triggered()
{
    Acessorio_listar();
}

void TelaPrincipal::on_actionListar_4_triggered()
{
    Cliente_listar();
}

void TelaPrincipal::on_actionListar_5_triggered()
{
    Vendedor_listar();
}

void TelaPrincipal::on_actionListar_6_triggered()
{
    Gerente_listar();
}
