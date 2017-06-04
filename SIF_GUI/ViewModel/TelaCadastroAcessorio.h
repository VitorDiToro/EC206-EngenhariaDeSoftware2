#ifndef TELACADASTROACESSORIO_H
#define TELACADASTROACESSORIO_H

#include <QFrame>
#include "ui_TelaCadastroAcessorio.h"
#include <QStyle>
#include <QDesktopWidget>
#include <iostream>
#include <QDebug>
#include "Model/Acessorio.h"
#include "Model/DAOAcessorio.h"

using namespace std;

namespace Ui {
class TelaCadastroAcessorio;
}

class TelaCadastroAcessorio : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroAcessorio(QWidget *parent = 0);
    ~TelaCadastroAcessorio();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::TelaCadastroAcessorio *ui;
};

#endif // TELACADASTROACESSORIO_H
