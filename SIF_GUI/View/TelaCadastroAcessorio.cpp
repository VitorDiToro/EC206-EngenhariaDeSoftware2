#include "TelaCadastroAcessorio.h"
#include "ui_TelaCadastroAcessorio.h"

TelaCadastroAcessorio::TelaCadastroAcessorio(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TelaCadastroAcessorio)
{
    ui->setupUi(this);
}

TelaCadastroAcessorio::~TelaCadastroAcessorio()
{
    delete ui;
}