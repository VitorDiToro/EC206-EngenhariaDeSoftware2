#include "TelaCadastroAcessorio.h"
#include <QMessageBox>

TelaCadastroAcessorio::TelaCadastroAcessorio(QWidget *parent, tenu_windowType enuWindowType, int id) :
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

    MANAGER_WINDOW_STATE = enuWindowType;
    Acessorio* a = NULL;

    qDebug() << "rock n roll: " << MANAGER_WINDOW_STATE;

    switch(MANAGER_WINDOW_STATE)
    {
        case CADASTRO:
            (void)0;
            // nothing to be done
            break;
        case CONSULTA:
            this->setWindowTitle("Consulta de Acessório");

            a = DAOAcessorio::getInstance()->getAcessorio(id);

            ui->lineEdit->setText(a->getNome());
            ui->lineEdit->setDisabled(1);
            ui->lineEdit_2->setText(QString::number(a->getPreco()));
            ui->lineEdit_2->setDisabled(1);
            ui->lineEdit_3->setText(a->getDescricao());
            ui->lineEdit_3->setDisabled(1);
            ui->pushButton->hide();
            break;
        case EDICAO:
            this->setWindowTitle("Edição de Acessório");

            a = DAOAcessorio::getInstance()->getAcessorio(id);

            ui->lineEdit->setText(a->getNome());
            ui->lineEdit_2->setText(QString::number(a->getPreco()));
            ui->lineEdit_3->setText(a->getDescricao());
            break;
        case INVALIDO:
            (void)0;
            //error
            break;
        default:
            (void)0;
            // error
            break;
    }

    if(a)
    {
        delete a;
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
    QString title;
    QString title2;
    bool op;

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
