#include "TelaCadastroGerente.h"
#include "ui_TelaCadastroGerente.h"
#include "Model/Gerente.h"
#include <QDebug>
#include <QStyle>
#include <QDesktopWidget>
#include <iostream>

using namespace std;

TelaCadastroGerente::TelaCadastroGerente(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TelaCadastroGerente)
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

TelaCadastroGerente::~TelaCadastroGerente()
{
    delete ui;
}

void TelaCadastroGerente::on_pushButton_clicked()
{
    QString nome = ui->lineEdit->text();
    QString cpf = ui->lineEdit_2->text();
    QString telefone = ui->lineEdit_3->text();
    QString endereco = ui->lineEdit_4->text();
    float salario = ui->lineEdit_5->text().toFloat();
    QString login = ui->lineEdit_6->text();
    QString senha = ui->lineEdit_7->text();
    QString unidadeQueGerencia = ui->lineEdit_8->text();

    if(!nome.isEmpty() && !cpf.isEmpty() && !telefone.isEmpty() && !endereco.isEmpty() && salario>0 && !login.isEmpty() &&
            !senha.isEmpty() && !unidadeQueGerencia.isEmpty())
    {
        qDebug() << "vai" << endl;

        qDebug() << endl << "Cadastrar Gerente" << endl;
        //Gerente* g = new Gerente();
        if(Gerente::getTotal() == 0)
        {
            Gerente* g = Gerente::getInstance();
            g->setNome(nome);
            g->setCpf(cpf);
            g->setTelefone(telefone);
            g->setEndereco(endereco);
            g->setSalario(salario);
            g->setLogin(login);
            g->setSenha(senha);
            g->setUnidadeQueGerencia(unidadeQueGerencia);

            g->print_details();

            gerentes.push_back(g);
        }
        else
        {
            qDebug() << "Gerente ja cadastrado." << endl;
        }

        this->close();
        delete this;
    }
    else
    {
        qDebug() << "nop" << endl;
    }
}

void TelaCadastroGerente::on_pushButton_2_clicked()
{
    this->close();
}
