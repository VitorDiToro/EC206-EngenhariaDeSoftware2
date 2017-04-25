#include "LoginWindow.h"
#include "ui_LoginWindow.h"
#include "TelaPrincipal.h"
#include <iostream>

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
    ui->editPassword->clear();
}

void LoginWindow::on_pushButton_2_clicked()
{
    std::cout<<"MERDA";
    std::cout<<ui->editPassword->toPlainText().toStdString();

    this->close();

    TelaPrincipal* tp = new TelaPrincipal();
    tp->show();
}
