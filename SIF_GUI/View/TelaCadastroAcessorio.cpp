#include "TelaCadastroAcessorio.h"
#include "ui_TelaCadastroAcessorio.h"
#include <QStyle>
#include <QDesktopWidget>

TelaCadastroAcessorio::TelaCadastroAcessorio(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TelaCadastroAcessorio)
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

TelaCadastroAcessorio::~TelaCadastroAcessorio()
{
    delete ui;
}

void TelaCadastroAcessorio::on_pushButton_2_clicked()
{
    this->close();
}
