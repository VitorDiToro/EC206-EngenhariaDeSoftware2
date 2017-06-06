#include "TelaCadastroAcessorio.h"
#include <QMessageBox>

TelaCadastroAcessorio::TelaCadastroAcessorio(QWidget *parent, tenu_windowType enuWindowType) :
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

TelaCadastroAcessorio::~TelaCadastroAcessorio()
{
    delete ui;
}

void TelaCadastroAcessorio::on_pushButton_2_clicked()
{
    MANAGER_WINDOW_STATE = INVALIDO;
    this->close();
}

void TelaCadastroAcessorio::on_pushButton_clicked()
{
    QString nome = ui->lineEdit->text();
    float preco = ui->lineEdit_2->text().toFloat();
    QString descricao = ui->lineEdit_3->text();

    qDebug() << preco << endl;

    if(!nome.isEmpty() && preco > 0 && !descricao.isEmpty())
    {
        qDebug() << "vai" << endl;

        qDebug() << endl << "Cadastrar Acessorio" << endl;
        Acessorio* a = new Acessorio();
        a->setNome(nome);
        a->setPreco(preco);
        a->setDescricao(descricao);

        a->print_details();

        stock_acessorios.push_back(a);

        if(DAOAcessorio::getInstance()->addAcessorio(a))
        {
            QMessageBox::information(this,tr("Cadastro"),tr("Cadastro realizado com sucesso!"));
        }
        else
        {
            QMessageBox::critical(this,tr("Cadastro"),tr("Cadastro não realizado!"));
        }

        this->close();
        delete this;
    }
    else
    {
        qDebug() << "nop" << endl;
        QMessageBox::critical(this,tr("Cadastro"),tr("Dados inconsistentes."));
    }

    MANAGER_WINDOW_STATE = INVALIDO;
}
