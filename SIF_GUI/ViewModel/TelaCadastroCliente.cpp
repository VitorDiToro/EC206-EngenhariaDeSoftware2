#include <iostream>
#include <QDebug>
#include "TelaCadastroCliente.h"
#include "ui_TelaCadastroCliente.h"
#include "Model/Cliente.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QMessageBox>
#include "Model/DAOCliente.h"

using namespace std;

TelaCadastroCliente::TelaCadastroCliente(QWidget *parent, tenu_windowType enuWindowType) :
    QFrame(parent),
    ui(new Ui::TelaCadastroCliente)
{
    ui->setupUi(this);
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    switch(MANAGER_WINDOW_STATE)
    {
        case CADASTRO:

            break;
        case CONSULTA:

            break;
        case EDICAO:

            break;
        case INVALIDO:
            //error
            break;
        default:
            // error
            break;
    }
}

TelaCadastroCliente::~TelaCadastroCliente()
{
    delete ui;
}

void TelaCadastroCliente::on_pushButton_clicked()
{
    QString nome = ui->lineEdit->text();
    QString cpf = ui->lineEdit_2->text();
    QString telefone = ui->lineEdit_3->text();
    QString endereco = ui->lineEdit_4->text();

    if(!nome.isEmpty() && !cpf.isEmpty() && !telefone.isEmpty() && !endereco.isEmpty())
    {
        qDebug() << endl << "Cadastrar Cliente" << endl;
        Cliente* c = new Cliente();
        c->setNome(nome);
        c->setCpf(cpf);
        c->setTelefone(telefone);
        c->setEndereco(endereco);

        c->print_details();

        clientes.push_back(c);

        if(DAOCliente::getInstance()->addCliente(c))
        {
            QMessageBox::information(this,tr("Cadastro"),tr("Cadastro realizado com sucesso!"));
        }
        else
        {
            QMessageBox::critical(this,tr("Cadastro"),tr("Cadastro não realizado!"));
        }

        this->close();
        delete this;
    }
    else
    {
        qDebug() << "nop" << endl;
        QMessageBox::critical(this,tr("Cadastro"),tr("Dados inconsistentes."));
    }

    MANAGER_WINDOW_STATE = INVALIDO;
}

void TelaCadastroCliente::on_pushButton_2_clicked()
{
    MANAGER_WINDOW_STATE = INVALIDO;
    this->close();
}
