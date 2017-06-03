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
    string nome = ui->lineEdit->text().toStdString();
    float preco = ui->lineEdit_2->text().toFloat();
    string descricao = ui->lineEdit_3->text().toStdString();

    cout << preco << endl;

    if(!nome.empty() && preco >= 0 && !descricao.empty())
    {
        qDebug() << "vai" << endl;

        cout << endl << "Cadastrar Acessorio" << endl;
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
