#include "TelaCadastroVendedor.h"
#include "ui_TelaCadastroVendedor.h"
#include "Model/Vendedor.h"
#include <QDebug>
#include <QStyle>
#include <QDesktopWidget>
#include <iostream>

using namespace std;

TelaCadastroVendedor::TelaCadastroVendedor(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TelaCadastroVendedor)
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

TelaCadastroVendedor::~TelaCadastroVendedor()
{
    delete ui;
}

void TelaCadastroVendedor::on_pushButton_3_clicked()
{
    string nome = ui->lineEdit->text().toStdString();
    string cpf = ui->lineEdit_2->text().toStdString();
    string telefone = ui->lineEdit_3->text().toStdString();
    string endereco = ui->lineEdit_4->text().toStdString();
    float salario = ui->lineEdit_5->text().toFloat();
    string login = ui->lineEdit_6->text().toStdString();
    string senha = ui->lineEdit_7->text().toStdString();
    string unidadeDeTrabalho = ui->lineEdit_8->text().toStdString();
    float comissao = ui->lineEdit_9->text().toFloat();

    if(!nome.empty() && !cpf.empty() && !telefone.empty() && !endereco.empty() && salario>0 && !login.empty() &&
            !senha.empty() && !unidadeDeTrabalho.empty() && comissao > 0)
    {
        qDebug() << "vai" << endl;

        qDebug() << endl << "Cadastrar Vendedor" << endl;
        Vendedor* v = new Vendedor();
        v->setNome(nome);
        v->setCpf(cpf);
        v->setTelefone(telefone);
        v->setEndereco(endereco);
        v->setSalario(salario);
        v->setLogin(login);
        v->setSenha(senha);
        v->setUnidadeDeTrabalho(unidadeDeTrabalho);
        v->setComissao(comissao);

        v->print_details();

        vendedores.push_back(v);

        this->close();
        delete this;
    }
    else
    {
        qDebug() << "nop" << endl;
    }
}

void TelaCadastroVendedor::on_pushButton_4_clicked()
{
    this->close();
}
