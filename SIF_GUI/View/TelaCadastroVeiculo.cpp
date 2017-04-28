#include <iostream>
#include <QDebug>

#include "TelaCadastroVeiculo.h"
#include "ui_TelaCadastroVeiculo.h"
#include "Controller/ListenerVeiculo.h"
#include <QStyle>
#include <QDesktopWidget>

using namespace std;

TelaCadastroVeiculo::TelaCadastroVeiculo(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TelaCadastroVeiculo)
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

TelaCadastroVeiculo::~TelaCadastroVeiculo()
{
    delete ui;
}

void TelaCadastroVeiculo::on_pushButton_clicked()
{
    string modelo = ui->lineEdit->text().toStdString();
    string cor = ui->lineEdit_2->text().toStdString();
    unsigned int ano = ui->lineEdit_3->text().toUInt();
    float preco = ui->lineEdit_4->text().toFloat();

    if(!modelo.empty() && !cor.empty() && ano > 1700 && ano < 2200 && preco >= 0)
    {
        qDebug() << "vai" << endl;

        Veiculo_cadastrar(modelo, cor, ano, preco);


        this->close();
        delete this;
    }
    else
    {
        qDebug() << "nop" << endl;
    }
}

void TelaCadastroVeiculo::on_pushButton_2_clicked()
{
    this->close();
}
