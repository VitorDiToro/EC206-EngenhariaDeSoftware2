#ifndef TELACADASTROVEICULO_H
#define TELACADASTROVEICULO_H

#include <QFrame>
#include "manager.h"

namespace Ui {
class TelaCadastroVeiculo;
}

class TelaCadastroVeiculo : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroVeiculo(QWidget *parent = 0, tenu_windowType enuWindowType = INVALIDO);
    ~TelaCadastroVeiculo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TelaCadastroVeiculo *ui;
};

#endif // TELACADASTROVEICULO_H
