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
    string nome = ui->lineEdit->text().toStdString();
    string cpf = ui->lineEdit_2->text().toStdString();
    string telefone = ui->lineEdit_3->text().toStdString();
    string endereco = ui->lineEdit_4->text().toStdString();
    float salario = ui->lineEdit_5->text().toFloat();
    string login = ui->lineEdit_6->text().toStdString();
    string senha = ui->lineEdit_7->text().toStdString();
    string unidadeQueGerencia = ui->lineEdit_8->text().toStdString();

    if(!nome.empty() && !cpf.empty() && !telefone.empty() && !endereco.empty() && salario>0 && !login.empty() &&
            !senha.empty() && !unidadeQueGerencia.empty())
    {
        qDebug() << "vai" << endl;

        cout << endl << "Cadastrar Gerente" << endl;
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
            cout << "Gerente ja cadastrado." << endl;
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
