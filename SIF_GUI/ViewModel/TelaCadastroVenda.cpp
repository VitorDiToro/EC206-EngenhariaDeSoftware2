#include "TelaCadastroVenda.h"
#include "ui_TelaCadastroVenda.h"
#include <QStyle>
#include <QDesktopWidget>

TelaCadastroVenda::TelaCadastroVenda(QWidget *parent, tenu_windowType enuWindowType) :
    QFrame(parent),
    ui(new Ui::TelaCadastroVenda)
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

    switch(MANAGER_WINDOW_STATE)
    {
        case CADASTRO:

            break;
        case CONSULTA:

            break;
        case EDICAO:

            break;
        case INVALIDO:
            //error
            break;
        default:
            // error
            break;
    }


}

TelaCadastroVenda::~TelaCadastroVenda()
{
    delete ui;
}
