#include <iostream>
#include <QDebug>
#include "TelaCadastroCliente.h"
#include "ui_TelaCadastroCliente.h"
#include "Controller/ListenerCliente.h"
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
    string nome = ui->lineEdit->text().toStdString();
    string cpf = ui->lineEdit_2->text().toStdString();
    string telefone = ui->lineEdit_3->text().toStdString();
    string endereco = ui->lineEdit_4->text().toStdString();

    if(!nome.empty() && !cpf.empty() && !telefone.empty() && !endereco.empty())
    {
        qDebug() << "vai" << endl;

        Cliente_cadastrar(nome, cpf, telefone, endereco);

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
