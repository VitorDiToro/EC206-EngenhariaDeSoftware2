#include <iostream>
#include <QDebug>
#include "TelaCadastroCliente.h"
#include "ui_TelaCadastroCliente.h"
#include "Model/Cliente.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QMessageBox>
#include "Model/DAOCliente.h"
#include "Model/DAOCliente.h"

using namespace std;

TelaCadastroCliente::TelaCadastroCliente(QWidget *parent, tenu_windowType enuWindowType, int id) :
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

    MANAGER_WINDOW_STATE = enuWindowType;
    Cliente* c = NULL;

    qDebug() << "rock n roll: " << MANAGER_WINDOW_STATE;

    switch(MANAGER_WINDOW_STATE)
    {
        case CADASTRO:
            (void)0;
            // nothing to be done
            break;
        case CONSULTA:
            this->setWindowTitle("Consulta de Cliente");

            c = DAOCliente::getInstance()->getCliente(id);

            qDebug() << "rock n roll";
            ui->lineEdit->setText(c->getNome());
            ui->lineEdit->setDisabled(1);
            ui->lineEdit_2->setText(c->getCpf());
            ui->lineEdit_2->setDisabled(1);
            ui->lineEdit_3->setText(c->getTelefone());
            ui->lineEdit_3->setDisabled(1);
            ui->lineEdit_4->setText(c->getEndereco());
            ui->lineEdit_4->setDisabled(1);
            ui->pushButton->hide();
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

TelaCadastroCliente::~TelaCadastroCliente()
{
    delete ui;
}

void TelaCadastroCliente::on_pushButton_clicked()
{
    QString nome = ui->lineEdit->text();
    QString cpf = ui->lineEdit_2->text();
    QString telefone = ui->lineEdit_3->text();
    QString endereco = ui->lineEdit_4->text();

    if(!nome.isEmpty() && !cpf.isEmpty() && !telefone.isEmpty() && !endereco.isEmpty())
    {
        qDebug() << endl << "Cadastrar Cliente" << endl;
        Cliente* c = new Cliente();
        c->setNome(nome);
        c->setCpf(cpf);
        c->setTelefone(telefone);
        c->setEndereco(endereco);

        c->print_details();

        clientes.push_back(c);

        if(DAOCliente::getInstance()->addCliente(c))
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

void TelaCadastroCliente::on_pushButton_2_clicked()
{
    MANAGER_WINDOW_STATE = INVALIDO;
    this->close();
}
