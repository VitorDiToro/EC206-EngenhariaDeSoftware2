#ifndef TELACADASTROVENDA_H
#define TELACADASTROVENDA_H

#include <QFrame>

namespace Ui {
class TelaCadastroVenda;
}

class TelaCadastroVenda : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroVenda(QWidget *parent = 0);
    ~TelaCadastroVenda();

private:
    Ui::TelaCadastroVenda *ui;
};

#endif // TELACADASTROVENDA_H
