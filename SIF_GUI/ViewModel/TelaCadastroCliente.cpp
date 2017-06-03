#include <iostream>
#include <QDebug>
#include "TelaCadastroCliente.h"
#include "ui_TelaCadastroCliente.h"
#include "Model/Cliente.h"
#include <QStyle>
#include <QDesktopWidget>

using namespace std;

TelaCadastroCliente::TelaCadastroCliente(QWidget *parent) :
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
        qDebug() << "vai" << endl;


        qDebug() << endl << "Cadastrar Cliente" << endl;
        Cliente* c = new Cliente();
        c->setNome(nome);
        c->setCpf(cpf);
        c->setTelefone(telefone);
        c->setEndereco(endereco);

        c->print_details();

        clientes.push_back(c);

        this->close();
        delete this;
    }
    else
    {
        qDebug() << "nop" << endl;
    }
}

void TelaCadastroCliente::on_pushButton_2_clicked()
{
    this->close();
}
