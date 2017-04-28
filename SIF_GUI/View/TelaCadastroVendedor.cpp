#include "TelaCadastroVendedor.h"
#include "ui_TelaCadastroVendedor.h"
#include "Controller/ListenerVendedor.h"
#include <QDebug>

TelaCadastroVendedor::TelaCadastroVendedor(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TelaCadastroVendedor)
{
    ui->setupUi(this);
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

        Vendedor_cadastrar(nome, cpf, telefone, endereco, salario, login, senha, unidadeDeTrabalho, comissao);

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
