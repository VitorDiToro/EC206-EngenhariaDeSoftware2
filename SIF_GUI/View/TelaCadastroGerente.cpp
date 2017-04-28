#include "TelaCadastroGerente.h"
#include "ui_TelaCadastroGerente.h"
#include "Controller/ListenerGerente.h"
#include <QDebug>

TelaCadastroGerente::TelaCadastroGerente(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TelaCadastroGerente)
{
    ui->setupUi(this);
    //ui->pushButton->hide();
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

        Gerente_cadastrar(nome, cpf, telefone, endereco, salario, login, senha, unidadeQueGerencia);


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
