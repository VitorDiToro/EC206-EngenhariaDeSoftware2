#include "TelaLogin.h"
#include "ui_TelaLogin.h"
#include "TelaPrincipal.h"
#include "TelaCadastroGerente.h"
#include <iostream>
#include <QDebug>
#include <QStyle>
#include <QDesktopWidget>

using namespace std;

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
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

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    ui->lineEdit_usuario->clear();
    ui->lineEdit_senha->clear();
}



void LoginWindow::on_pushButton_2_clicked()
{
    string password = "1019";

    //qDebug() << "a" + ui->editPassword->toPlainText() << endl;



    if(ui->lineEdit_senha->text().toStdString() == password)
    {
        TelaPrincipal* tp = new TelaPrincipal();
        tp->show();

        this->close();
        delete this;
    }
    else
    {
        TelaCadastroGerente* tcg = new TelaCadastroGerente();
        tcg->show();
    }
}

void LoginWindow::on_editPassword_selectionChanged()
{
    //ui->lineEdit_senha->clear();
}

void LoginWindow::on_lineEdit_senha_returnPressed()
{
    string password = "1019";

    //qDebug() << "a" + ui->editPassword->toPlainText() << endl;



    if(ui->lineEdit_senha->text().toStdString() == password)
    {
        TelaPrincipal* tp = new TelaPrincipal();
        tp->show();

        this->close();
        delete this;
    }
    else
    {
        TelaCadastroGerente* tcg = new TelaCadastroGerente();
        tcg->show();
    }
}

void LoginWindow::on_lineEdit_senha_selectionChanged()
{
    if(ui->lineEdit_senha->text()=="Senha")
    {
        ui->lineEdit_senha->clear();
    }
}
