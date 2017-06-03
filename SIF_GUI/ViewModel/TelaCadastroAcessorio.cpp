#include "TelaCadastroAcessorio.h"
#include "ui_TelaCadastroAcessorio.h"
#include <QStyle>
#include <QDesktopWidget>
#include <iostream>
#include <QDebug>
#include "Model/Acessorio.h"

using namespace std;

TelaCadastroAcessorio::TelaCadastroAcessorio(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TelaCadastroAcessorio)
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

TelaCadastroAcessorio::~TelaCadastroAcessorio()
{
    delete ui;
}

void TelaCadastroAcessorio::on_pushButton_2_clicked()
{
    this->close();
}

void TelaCadastroAcessorio::on_pushButton_clicked()
{
    QString nome = ui->lineEdit->text();
    float preco = ui->lineEdit_2->text().toFloat();
    QString descricao = ui->lineEdit_3->text();

    qDebug() << preco << endl;

    if(!nome.isEmpty() && preco >= 0 && !descricao.isEmpty())
    {
        qDebug() << "vai" << endl;

        qDebug() << endl << "Cadastrar Acessorio" << endl;
        Acessorio* a = new Acessorio();
        a->setNome(nome);
        a->setPreco(preco);
        a->setDescricao(descricao);

        a->print_details();

        stock_acessorios.push_back(a);

        this->close();
        delete this;
    }
    else
    {
        qDebug() << "nop" << endl;
    }
}
