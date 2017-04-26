#ifndef TELACADASTROACESSORIO_H
#define TELACADASTROACESSORIO_H

#include <QFrame>

namespace Ui {
class TelaCadastroAcessorio;
}

class TelaCadastroAcessorio : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroAcessorio(QWidget *parent = 0);
    ~TelaCadastroAcessorio();

private:
    Ui::TelaCadastroAcessorio *ui;
};

#endif // TELACADASTROACESSORIO_H
