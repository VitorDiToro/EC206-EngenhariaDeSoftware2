#include "TelaCadastroVeiculo.h"
#include "ui_TelaCadastroVeiculo.h"

TelaCadastroVeiculo::TelaCadastroVeiculo(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TelaCadastroVeiculo)
{
    ui->setupUi(this);
}

TelaCadastroVeiculo::~TelaCadastroVeiculo()
{
    delete ui;
}
