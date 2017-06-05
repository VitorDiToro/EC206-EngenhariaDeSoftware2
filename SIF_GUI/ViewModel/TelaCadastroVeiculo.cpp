#include <iostream>
#include <QDebug>


#include <QStyle>
#include <QDesktopWidget>
#include <QMessageBox>

#include "TelaCadastroVeiculo.h"
#include "ui_TelaCadastroVeiculo.h"
#include "Model/Veiculo.h"
#include "Model/DAOVeiculo.h"

using namespace std;

TelaCadastroVeiculo::TelaCadastroVeiculo(QWidget *parent, tenu_objType enuObjType) :
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
    QString modelo = ui->lineEdit->text();
    QString cor = ui->lineEdit_2->text();
    unsigned int ano = ui->lineEdit_3->text().toUInt();
    float preco = ui->lineEdit_4->text().toFloat();

    if(!modelo.isEmpty() && !cor.isEmpty() && ano > 1700 && ano < 2200 && preco > 0)
    {
        qDebug() << "vai" << endl;

        qDebug() << endl << "Cadastrar veiculo" << endl;
        Veiculo* v = new Veiculo();
        v->setModelo(modelo);
        v->setCor(cor);
        v->setAno(ano);
        v->setPreco(preco);

        v->print_details();

        veiculos.push_back(v);

        if(DAOVeiculo::getInstance()->addVeiculo(v))
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

void TelaCadastroVeiculo::on_pushButton_2_clicked()
{
    this->close();
}
