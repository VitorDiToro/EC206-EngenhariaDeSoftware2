#ifndef TELACADASTROVEICULO_H
#define TELACADASTROVEICULO_H

#include <QFrame>

namespace Ui {
class TelaCadastroVeiculo;
}

class TelaCadastroVeiculo : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroVeiculo(QWidget *parent = 0);
    ~TelaCadastroVeiculo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TelaCadastroVeiculo *ui;
};

#endif // TELACADASTROVEICULO_H
