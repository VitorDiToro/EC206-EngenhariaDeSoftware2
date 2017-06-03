#include "TelaListagem.h"
#include "ui_TelaListagem.h"
#include "QDebug"
#include <iostream>
#include <QStyle>
#include <QDesktopWidget>

using namespace std;

TelaListagem::TelaListagem(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TelaListagem)
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

    QStringList titulos;

    titulos.append("id");
    titulos.append("nome");
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(titulos);

    //ui->tableView->addScrollBarWidget();
}

TelaListagem::~TelaListagem()
{
    delete ui;
}
