#include "TelaLogin.h"
#include "ui_TelaLogin.h"
#include "TelaPrincipal.h"
#include <iostream>

using namespace std;

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    ui->editUser->clear();
    ui->editPassword->clear();
}

void LoginWindow::on_editUser_selectionChanged()
{
    ui->editUser->clear();
}

void LoginWindow::on_pushButton_2_clicked()
{
    string password = "1019";

    if(ui->editPassword->toPlainText().toStdString() == password)
    {
        this->close();

        delete this;

        TelaPrincipal* tp = new TelaPrincipal();
        tp->show();
    }
}

void LoginWindow::on_editPassword_selectionChanged()
{
    ui->editPassword->clear();
}
