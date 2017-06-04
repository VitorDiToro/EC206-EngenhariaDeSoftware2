#ifndef TELALISTAGEM_H
#define TELALISTAGEM_H

#include <QFrame>

typedef enum enu_objType
{
    INVALID,
    VENDA,
    VEICULO,
    ACESSORIO,
    CLIENTE,
    VENDEDOR,
    GERENTE
}tenu_objType;

namespace Ui {
class TelaListagem;
}

class TelaListagem : public QFrame
{
    Q_OBJECT

public:
    explicit TelaListagem(QWidget *parent = 0, tenu_objType enuObjType = INVALID);
    ~TelaListagem();

private:
    Ui::TelaListagem *ui;
};

#endif // TELALISTAGEM_H
