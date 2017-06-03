#include "TelaCadastroVenda.h"
#include "ui_TelaCadastroVenda.h"
#include <QStyle>
#include <QDesktopWidget>

TelaCadastroVenda::TelaCadastroVenda(QWidget *parent) :
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
}

TelaCadastroVenda::~TelaCadastroVenda()
{
    delete ui;
}
