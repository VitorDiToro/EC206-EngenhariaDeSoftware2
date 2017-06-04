#include "TelaListagem.h"
#include "ui_TelaListagem.h"
#include "QDebug"
#include <iostream>
#include <QStyle>
#include <QDesktopWidget>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql>
#include "Model/DAOCliente.h"
#include "Model/DAOVeiculo.h"

using namespace std;

TelaListagem::TelaListagem(QWidget *parent, tenu_objType enuObjType) :
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

    QSqlQueryModel* model = new QSqlQueryModel;

    QSqlQuery* query = DAOVeiculo::getInstance()->getBasicInfoVeiculos();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Modelo");

    ui->tableView->setModel(model);
    ui->tableView->show();

    delete query;
    //delete model;
}

TelaListagem::~TelaListagem()
{
    delete ui;
}
