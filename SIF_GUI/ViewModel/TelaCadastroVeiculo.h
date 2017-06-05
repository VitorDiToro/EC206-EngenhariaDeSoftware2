#ifndef TELACADASTROVEICULO_H
#define TELACADASTROVEICULO_H

#include <QFrame>
#include "helper.h"

namespace Ui {
class TelaCadastroVeiculo;
}

class TelaCadastroVeiculo : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroVeiculo(QWidget *parent = 0, tenu_objType enuObjType = INVALID);
    ~TelaCadastroVeiculo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TelaCadastroVeiculo *ui;
};

#endif // TELACADASTROVEICULO_H
