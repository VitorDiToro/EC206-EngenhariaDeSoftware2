#ifndef TELACADASTROCLIENTE_H
#define TELACADASTROCLIENTE_H

#include <QFrame>
#include "helper.h"

namespace Ui {
class TelaCadastroCliente;
}

class TelaCadastroCliente : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroCliente(QWidget *parent = 0, tenu_windowType enuWindowType = INVALIDO);
    ~TelaCadastroCliente();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TelaCadastroCliente *ui;
};

#endif // TELACADASTROCLIENTE_H
