#include "TelaCadastroVendedor.h"
#include "ui_TelaCadastroVendedor.h"
#include "Model/Vendedor.h"
#include <QDebug>
#include <QStyle>
#include <QDesktopWidget>
#include <iostream>
#include <Model/DAOVendedor.h>
#include <QMessageBox>
//

using namespace std;

TelaCadastroVendedor::TelaCadastroVendedor(QWidget *parent, tenu_windowType enuWindowType, int id) :
    QFrame(parent),
    ui(new Ui::TelaCadastroVendedor)
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

    MANAGER_WINDOW_STATE = enuWindowType;
    Vendedor* v = NULL;

    qDebug() << "rock n roll: " << MANAGER_WINDOW_STATE;

    switch(MANAGER_WINDOW_STATE)
    {
        case CADASTRO:
            (void)0;
            // nothing to be done
            break;
        case CONSULTA:
            this->setWindowTitle("Consulta de Acessório");

            v = DAOVendedor::getInstance()->getVendedor(id);

            qDebug() << "rock n roll";
            ui->lineEdit->setText(v->getNome());
            ui->lineEdit->setDisabled(1);
            ui->lineEdit_2->setText(v->getCpf());
            ui->lineEdit_2->setDisabled(1);
            ui->lineEdit_3->setText(v->getTelefone());
            ui->lineEdit_3->setDisabled(1);
            ui->lineEdit_4->setText(v->getEndereco());
            ui->lineEdit_4->setDisabled(1);
            ui->lineEdit_5->setText(QString::number(v->getSalario()));
            ui->lineEdit_5->setDisabled(1);
            ui->lineEdit_6->setText(v->getLogin());
            ui->lineEdit_6->setDisabled(1);
            ui->lineEdit_7->setText(v->getSenha());
            ui->lineEdit_7->setDisabled(1);
            ui->lineEdit_8->setText(v->getUnidadeDeTrabalho());
            ui->lineEdit_8->setDisabled(1);
            ui->lineEdit_9->setText(QString::number(v->getComissao()));
            ui->lineEdit_9->setDisabled(1);


            ui->pushButton_3->hide();
            break;
        case EDICAO:
            (void)0;
            break;
        case INVALIDO:
            (void)0;
            //error
            break;
        default:
            (void)0;
            // error
            break;
    }
}

TelaCadastroVendedor::~TelaCadastroVendedor()
{
    delete ui;
}

void TelaCadastroVendedor::on_pushButton_3_clicked()
{
    QString nome = ui->lineEdit->text();
    QString cpf = ui->lineEdit_2->text();
    QString telefone = ui->lineEdit_3->text();
    QString endereco = ui->lineEdit_4->text();
    float salario = ui->lineEdit_5->text().toFloat();
    QString login = ui->lineEdit_6->text();
    QString senha = ui->lineEdit_7->text();
    QString unidadeDeTrabalho = ui->lineEdit_8->text();
    float comissao = ui->lineEdit_9->text().toFloat();

    if(!nome.isEmpty() && !cpf.isEmpty() && !telefone.isEmpty() && !endereco.isEmpty() && salario>0 && !login.isEmpty() &&
            !senha.isEmpty() && !unidadeDeTrabalho.isEmpty() && comissao > 0)
    {
        qDebug() << "vai" << endl;

        qDebug() << endl << "Cadastrar Vendedor" << endl;
        Vendedor* v = new Vendedor();
        v->setNome(nome);
        v->setCpf(cpf);
        v->setTelefone(telefone);
        v->setEndereco(endereco);
        v->setSalario(salario);
        v->setLogin(login);
        v->setSenha(senha);
        v->setUnidadeDeTrabalho(unidadeDeTrabalho);
        v->setComissao(comissao);

        v->print_details();

        vendedores.push_back(v);

        if(DAOVendedor::getInstance()->addVendedor(v))
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

    MANAGER_WINDOW_STATE = INVALIDO;
}

void TelaCadastroVendedor::on_pushButton_4_clicked()
{
    MANAGER_WINDOW_STATE = INVALIDO;
    this->close();
}
