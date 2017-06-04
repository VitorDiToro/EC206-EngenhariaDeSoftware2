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
#include "Model/DAOVenda.h"
#include "Model/DAOAcessorio.h"
#include "Model/DAOVendedor.h"
#include "Model/DAOGerente.h"

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

    QSqlQuery* query = NULL;
    QString SecondColumn = "Nome";

    switch(enuObjType)
    {
        case VENDA:
            //query = DAOVenda::getInstance()->getBasicInfoVendas();
            SecondColumn = "Valor";
            break;
        case VEICULO:
            query = DAOVeiculo::getInstance()->getBasicInfoVeiculos();
            SecondColumn = "Modelo";
            break;
        case ACESSORIO:
            query = DAOAcessorio::getInstance()->getBasicInfoAcessorios();
            break;
        case CLIENTE:
            query = DAOCliente::getInstance()->getBasicInfoClientes();
            break;
        case VENDEDOR:
            query = DAOVendedor::getInstance()->getBasicInfoVendedores();
            break;
        case GERENTE:
            query = DAOGerente::getInstance()->getBasicInfoGerentes();
            break;
        case INVALID:
            // error
            break;
        default:
            // error
            break;
    }

    if(query == NULL)
    {
        return;
    }

    QSqlQueryModel* model = new QSqlQueryModel;

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, SecondColumn);

    ui->tableView->setModel(model);
    ui->tableView->show();

    delete query;
    //delete model;
}

TelaListagem::~TelaListagem()
{
    qDebug() << "God will let me be executed";
    delete ui;
}
