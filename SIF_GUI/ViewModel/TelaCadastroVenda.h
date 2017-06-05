#ifndef TELACADASTROVENDA_H
#define TELACADASTROVENDA_H

#include <QFrame>
#include "helper.h"

namespace Ui {
class TelaCadastroVenda;
}

class TelaCadastroVenda : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroVenda(QWidget *parent = 0, tenu_windowType enuWindowType = INVALIDO);
    ~TelaCadastroVenda();

private:
    Ui::TelaCadastroVenda *ui;
};

#endif // TELACADASTROVENDA_H
