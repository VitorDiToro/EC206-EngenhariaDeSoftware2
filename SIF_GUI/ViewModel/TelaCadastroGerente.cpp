#include "TelaCadastroGerente.h"
#include "ui_TelaCadastroGerente.h"
#include "Model/Gerente.h"
#include <QDebug>
#include <QStyle>
#include <QDesktopWidget>
#include <iostream>
#include "Model/DAOGerente.h"
#include <QMessageBox>
#include "Model/DAOGerente.h"

using namespace std;

TelaCadastroGerente::TelaCadastroGerente(QWidget *parent, tenu_windowType enuWindowType, int id) :
    QFrame(parent),
    ui(new Ui::TelaCadastroGerente)
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
    Gerente* g = NULL;

    qDebug() << "rock n roll: " << MANAGER_WINDOW_STATE;

    switch(MANAGER_WINDOW_STATE)
    {
        case CADASTRO:
            (void)0;
            // nothing to be done
            break;
        case CONSULTA:
            this->setWindowTitle("Consulta de Gerente");

            g = DAOGerente::getInstance()->getGerente(id);

            qDebug() << "rock n roll";
            ui->lineEdit->setText(g->getNome());
            ui->lineEdit->setDisabled(1);
            ui->lineEdit_2->setText(g->getCpf());
            ui->lineEdit_2->setDisabled(1);
            ui->lineEdit_3->setText(g->getTelefone());
            ui->lineEdit_3->setDisabled(1);
            ui->lineEdit_4->setText(g->getEndereco());
            ui->lineEdit_4->setDisabled(1);
            ui->lineEdit_5->setText(QString::number(g->getSalario()));
            ui->lineEdit_5->setDisabled(1);
            ui->lineEdit_6->setText(g->getLogin());
            ui->lineEdit_6->setDisabled(1);
            ui->lineEdit_7->setText(g->getSenha());
            ui->lineEdit_7->setDisabled(1);
            ui->lineEdit_8->setText(g->getUnidadeQueGerencia());
            ui->lineEdit_8->setDisabled(1);
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

TelaCadastroGerente::~TelaCadastroGerente()
{
    delete ui;
}

void TelaCadastroGerente::on_pushButton_clicked()
{
    QString nome = ui->lineEdit->text();
    QString cpf = ui->lineEdit_2->text();
    QString telefone = ui->lineEdit_3->text();
    QString endereco = ui->lineEdit_4->text();
    float salario = ui->lineEdit_5->text().toFloat();
    QString login = ui->lineEdit_6->text();
    QString senha = ui->lineEdit_7->text();
    QString unidadeQueGerencia = ui->lineEdit_8->text();

    if(!nome.isEmpty() && !cpf.isEmpty() && !telefone.isEmpty() && !endereco.isEmpty() && salario>0 && !login.isEmpty() &&
            !senha.isEmpty() && !unidadeQueGerencia.isEmpty())
    {
        qDebug() << "vai" << endl;

        qDebug() << endl << "Cadastrar Gerente" << endl;
        //Gerente* g = new Gerente();
        if(Gerente::getTotal() == 0)
        {
            Gerente* g = new Gerente();
            g->setNome(nome);
            g->setCpf(cpf);
            g->setTelefone(telefone);
            g->setEndereco(endereco);
            g->setSalario(salario);
            g->setLogin(login);
            g->setSenha(senha);
            g->setUnidadeQueGerencia(unidadeQueGerencia);

            g->print_details();

            gerentes.push_back(g);

            if(DAOGerente::getInstance()->addGerente(g))
            {
                QMessageBox::information(this,tr("Cadastro"),tr("Cadastro realizado com sucesso!"));
            }
            else
            {
                QMessageBox::critical(this,tr("Cadastro"),tr("Cadastro não realizado!"));
            }
        }
        else
        {
            qDebug() << "Gerente ja cadastrado." << endl;
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

void TelaCadastroGerente::on_pushButton_2_clicked()
{
    MANAGER_WINDOW_STATE = INVALIDO;
    this->close();
}
