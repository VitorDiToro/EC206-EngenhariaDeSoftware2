#include "TelaLogin.h"
#include "ui_TelaLogin.h"
#include "TelaPrincipal.h"
#include "TelaCadastroGerente.h"
#include <iostream>
#include <QDebug>
#include <QStyle>
#include <QDesktopWidget>
#include <QMessageBox>

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

    if(ui->lineEdit_senha->text().toStdString() == password)
    {
        TelaPrincipal* tp = new TelaPrincipal();
        tp->show();

        this->close();
    }
    else
    {
       QMessageBox::critical(this,tr("Login não autorizado!"),tr("Login não atorizado!\nPorfavor, verifique seu usuário e senha."));
    }

    delete this;
}

void LoginWindow::on_lineEdit_senha_returnPressed()
{
    QString password = "1019";

    if(ui->lineEdit_senha->text() == password)
    {
        TelaPrincipal* tp = new TelaPrincipal();
        tp->show();

        this->close();

    }
    else
    {
       QMessageBox::critical(this,tr("Login não autorizado!"),tr("Login não autorizado!\nPor favor, verifique seu usuário e senha."));
    }
}

void LoginWindow::on_lineEdit_senha_selectionChanged()
{
    if(ui->lineEdit_senha->text()=="Senha")
    {
        ui->lineEdit_senha->clear();
    }
}
