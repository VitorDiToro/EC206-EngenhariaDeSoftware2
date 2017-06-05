#include "TelaCadastroVendedor.h"
#include "ui_TelaCadastroVendedor.h"
#include "Model/Vendedor.h"
#include <QDebug>
#include <QStyle>
#include <QDesktopWidget>
#include <iostream>
#include <Model/DAOVendedor.h>
#include <QMessageBox>
//

using namespace std;

TelaCadastroVendedor::TelaCadastroVendedor(QWidget *parent, tenu_windowType enuWindowType) :
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
    QString nome = ui->lineEdit->text();
    QString cpf = ui->lineEdit_2->text();
    QString telefone = ui->lineEdit_3->text();
    QString endereco = ui->lineEdit_4->text();
    float salario = ui->lineEdit_5->text().toFloat();
    QString login = ui->lineEdit_6->text();
    QString senha = ui->lineEdit_7->text();
    QString unidadeDeTrabalho = ui->lineEdit_8->text();
    float comissao = ui->lineEdit_9->text().toFloat();

    if(!nome.isEmpty() && !cpf.isEmpty() && !telefone.isEmpty() && !endereco.isEmpty() && salario>0 && !login.isEmpty() &&
            !senha.isEmpty() && !unidadeDeTrabalho.isEmpty() && comissao > 0)
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

        if(DAOVendedor::getInstance()->addVendedor(v))
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
}

void TelaCadastroVendedor::on_pushButton_4_clicked()
{
    this->close();
}
