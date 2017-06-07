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

TelaCadastroVeiculo::TelaCadastroVeiculo(QWidget *parent, tenu_windowType enuWindowType, int id) :
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

    ID = id;

    MANAGER_WINDOW_STATE = enuWindowType;
    Veiculo* v = NULL;

    switch(MANAGER_WINDOW_STATE)
    {
        case CADASTRO:
            (void)0;
            // nothing to be done
            break;
        case CONSULTA:
            this->setWindowTitle("Consulta de Veículo");

            v = DAOVeiculo::getInstance()->getVeiculo(id);

            qDebug() << "rock n roll";
            ui->lineEdit->setText(v->getModelo());
            ui->lineEdit->setDisabled(1);
            ui->lineEdit_2->setText(v->getCor());
            ui->lineEdit_2->setDisabled(1);
            ui->lineEdit_3->setText(QString::number(v->getAno()));
            ui->lineEdit_3->setDisabled(1);
            ui->lineEdit_4->setText(QString::number(v->getPreco()));
            ui->lineEdit_4->setDisabled(1);

            ui->pushButton->hide();
            break;
        case EDICAO:
            this->setWindowTitle("Edição de Veículo");

            v = DAOVeiculo::getInstance()->getVeiculo(id);

            ui->lineEdit->setText(v->getModelo());
            ui->lineEdit_2->setText(v->getCor());
            ui->lineEdit_3->setText(QString::number(v->getAno()));
            ui->lineEdit_4->setText(QString::number(v->getPreco()));

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

    if(v)
    {
        delete v;
    }
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
    QString title;
    QString title2;
    bool op;

    if(!modelo.isEmpty() && !cor.isEmpty() && ano > 1700 && ano < 2200 && preco > 0)
    {
        qDebug() << "vai" << endl;

        qDebug() << endl << "Cadastrar veiculo" << endl;
        Veiculo* v = new Veiculo();
        v->setModelo(modelo);
        v->setCor(cor);
        v->setAno(ano);
        v->setPreco(preco);
        v->setId(ID);

        v->print_details();

        veiculos.push_back(v);

        qDebug() << "WINDOW STATE " <<  MANAGER_WINDOW_STATE;

        if(MANAGER_WINDOW_STATE == CADASTRO)
        {
            op = DAOVeiculo::getInstance()->addVeiculo(v);
            title = "Cadastro";
            title2 = " realizado";
        }
        else if(MANAGER_WINDOW_STATE == EDICAO)
        {
            //op = DAOVeiculo::getInstance()->addVeiculo(v);
            op = DAOVeiculo::getInstance()->updateVeiculo(v);
            title = "Edição";
            title2 = " realizada";
        }

        if(v)
        {
            delete v;
        }

        if(op)
        {
            QMessageBox::information(this,title,title + title2 +" com sucesso!");
        }
        else
        {
            QMessageBox::critical(this,title, title + " não" + title2 + "!");
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
    MANAGER_WINDOW_STATE = INVALIDO;
    this->close();
}
