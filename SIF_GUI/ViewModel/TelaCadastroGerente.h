#ifndef TELACADASTROGERENTE_H
#define TELACADASTROGERENTE_H

#include <QFrame>
#include "helper.h"

namespace Ui {
class TelaCadastroGerente;
}

class TelaCadastroGerente : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroGerente(QWidget *parent = 0, tenu_windowType enuWindowType = INVALIDO);
    ~TelaCadastroGerente();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TelaCadastroGerente *ui;
};

#endif // TELACADASTROGERENTE_H
