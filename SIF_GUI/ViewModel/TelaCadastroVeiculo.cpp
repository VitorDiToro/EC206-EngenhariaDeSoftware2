#include <iostream>
#include <QDebug>

#include "TelaCadastroVeiculo.h"
#include "ui_TelaCadastroVeiculo.h"
#include "Model/Veiculo.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QtSql/QSqlQuery>

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
    QString modelo = ui->lineEdit->text();
    QString cor = ui->lineEdit_2->text();
    unsigned int ano = ui->lineEdit_3->text().toUInt();
    float preco = ui->lineEdit_4->text().toFloat();

    if(!modelo.isEmpty() && !cor.isEmpty() && ano > 1700 && ano < 2200 && preco >= 0)
    {
        qDebug() << "vai" << endl;

        cout << endl << "Cadastrar veiculo" << endl;
        Veiculo* v = new Veiculo();
        v->setModelo(modelo.toStdString());
        v->setCor(cor.toStdString());
        v->setAno(ano);
        v->setPreco(preco);

        v->print_details();

        veiculos.push_back(v);

        QSqlQuery query;
        query.prepare("INSERT INTO `sifDB`.`veiculo` (`veiculo_modelo`, `veiculo_preco`, `veiculo_quantidade`, `veiculo_cor`, `veiculo_ano`, `veiculo_ativo`)"
                      "VALUES (?, ?, ?, ?, ?, ?);");
        query.addBindValue(modelo);
        query.addBindValue(preco);
        query.addBindValue(3);
        query.addBindValue(cor);
        query.addBindValue(ano);
        query.addBindValue(true);
        query.exec();

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
