#ifndef TELACADASTROCLIENTE_H
#define TELACADASTROCLIENTE_H

#include <QFrame>

namespace Ui {
class TelaCadastroCliente;
}

class TelaCadastroCliente : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroCliente(QWidget *parent = 0);
    ~TelaCadastroCliente();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TelaCadastroCliente *ui;
};

#endif // TELACADASTROCLIENTE_H
