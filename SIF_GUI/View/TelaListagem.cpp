#include "TelaListagem.h"
#include "ui_TelaListagem.h"

TelaListagem::TelaListagem(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TelaListagem)
{
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
