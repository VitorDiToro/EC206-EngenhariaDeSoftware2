#ifndef TELACADASTROVENDEDOR_H
#define TELACADASTROVENDEDOR_H

#include <QFrame>
#include "helper.h"

namespace Ui {
class TelaCadastroVendedor;
}

class TelaCadastroVendedor : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroVendedor(QWidget *parent = 0, tenu_objType enuObjType = INVALID);
    ~TelaCadastroVendedor();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::TelaCadastroVendedor *ui;
};

#endif // TELACADASTROVENDEDOR_H
