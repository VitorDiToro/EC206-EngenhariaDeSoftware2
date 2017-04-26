#include "TelaCadastroVenda.h"
#include "ui_TelaCadastroVenda.h"

TelaCadastroVenda::TelaCadastroVenda(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TelaCadastroVenda)
{
    ui->setupUi(this);
}

TelaCadastroVenda::~TelaCadastroVenda()
{
    delete ui;
}
