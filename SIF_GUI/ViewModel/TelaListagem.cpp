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
#include "TelaCadastroAcessorio.h"
#include "TelaCadastroCliente.h"
#include "TelaCadastroVeiculo.h"
#include "TelaCadastroVendedor.h"
#include "TelaCadastroVenda.h"
#include "TelaCadastroGerente.h"
#include "TelaCadastroVeiculo.h"
#include <QMessageBox>
#include "manager.h"

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

    MANAGER_OBJECT_TYPE = enuObjType;

    updateTableView(enuObjType);
}

bool TelaListagem::updateTableView(tenu_objType enuObjType)
{
    QSqlQuery* query = NULL;
    QString SecondColumn = "Nome";
    QString windowTitle;

    switch(enuObjType)
    {
        case VENDA:
            //query = DAOVenda::getInstance()->getBasicInfoVendas();
            SecondColumn = "Valor";
            windowTitle = "Venda";
            break;
        case VEICULO:
            query = DAOVeiculo::getInstance()->getBasicInfoVeiculos();
            SecondColumn = "Modelo";
            windowTitle = "Veículos";
            break;
        case ACESSORIO:
            query = DAOAcessorio::getInstance()->getBasicInfoAcessorios();
            windowTitle = "Acessórios";
            break;
        case CLIENTE:
            query = DAOCliente::getInstance()->getBasicInfoClientes();
            windowTitle = "Clientes";
            break;
        case VENDEDOR:
            query = DAOVendedor::getInstance()->getBasicInfoVendedores();
            windowTitle = "Vendedores";
            break;
        case GERENTE:
            query = DAOGerente::getInstance()->getBasicInfoGerentes();
            windowTitle = "Gerentes";
            break;
        case INVALID:
            // error
            return false;
            break;
        default:
            // error
            return false;
            break;
    }

    if(query == NULL)
    {
        return false;
    }

    this->setWindowTitle("Listagem de " + windowTitle);

    QSqlQueryModel* model = new QSqlQueryModel;

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, SecondColumn);

    ui->tableView->setModel(model);
    ui->tableView->show();

    delete query;
    //delete model;

    return true;
}

TelaListagem::~TelaListagem()
{
    qDebug() << "God will let me be executed";
    delete ui;
}

void TelaListagem::on_editarButton_clicked()
{
    MANAGER_WINDOW_STATE = EDICAO;
}

void TelaListagem::on_consultarButton_clicked()
{
    MANAGER_WINDOW_STATE = CONSULTA;
    TelaCadastroAcessorio* tca = NULL;
    TelaCadastroCliente* tcc = NULL;
    TelaCadastroGerente* tcg = NULL;
    TelaCadastroVendedor* tcv = NULL;
    TelaCadastroVeiculo* tcvei = NULL;

    int id = getIDinDB();

    qDebug() << "tipo de obj " << MANAGER_OBJECT_TYPE;

    switch(MANAGER_OBJECT_TYPE)
    {
        case VENDA:
            //
            break;
        case VEICULO:
            tcvei = new TelaCadastroVeiculo(0,CONSULTA,id);
            tcvei->show();
            tcvei->activateWindow();
            break;
        case ACESSORIO:
            tca = new TelaCadastroAcessorio(0,CONSULTA,id);
            tca->show();
            tca->activateWindow();
            break;
        case CLIENTE:
            tcc = new TelaCadastroCliente(0,CONSULTA,id);
            tcc->show();
            tcc->activateWindow();
            break;
        case VENDEDOR:
            tcv = new TelaCadastroVendedor(0,CONSULTA,id);
            tcv->show();
            tcv->activateWindow();
            break;
        case GERENTE:
            tcg = new TelaCadastroGerente(0,CONSULTA,id);
            tcg->show();
            tcg->activateWindow();

            break;
        case INVALID:
            // error
            return;
            break;
        default:
            // error
            return;
            break;
    }

    MANAGER_OBJECT_TYPE = ACESSORIO;

}

void TelaListagem::on_excluirButton_clicked()
{
    int id = getIDinDB();
    bool result;

    if(id > 0)
    {
        qDebug() << MANAGER_OBJECT_TYPE;
        switch(MANAGER_OBJECT_TYPE)
        {
            case VENDA:
                //result = DAOAcessorio::getInstance()->deleteAcessorio(id);
                break;
            case VEICULO:
                result = DAOVeiculo::getInstance()->deleteVeiculo(id);
                break;
            case ACESSORIO:
                qDebug() << "AcessorioExcluir";
                result = DAOAcessorio::getInstance()->deleteAcessorio(id);
                break;
            case CLIENTE:
                result = DAOCliente::getInstance()->deleteCliente(id);
                break;
            case VENDEDOR:
                result = DAOVendedor::getInstance()->deleteVendedor(id);
                break;
            case GERENTE:
                result = DAOGerente::getInstance()->deleteGerente(id);
                break;
            case INVALID:
                // error
                return;
                break;
            default:
                // error
                return;
                break;
        }

        if(result)
        {
            QMessageBox::information(this,tr("Remoção"),tr("Remoção  realizada com sucesso!"));
        }
        else
        {
            QMessageBox::critical(this,tr("Remoção"),tr("Remoção  não realizada!"));
        }
    }
    else
    {
        QMessageBox::critical(this,tr("Remoção"),tr("Linha não selecionada!"));
    }

    updateTableView(MANAGER_OBJECT_TYPE);
}

int TelaListagem::getIDinDB()
{
    int i = ui->tableView->currentIndex().row();
    qDebug() << "Selected " << i;

    QAbstractItemModel *model = ui->tableView->model();
    QModelIndex index = model->index(i, 0);
    i = index.data().toInt();

    qDebug() << "solved " << i;
    return i;
}
