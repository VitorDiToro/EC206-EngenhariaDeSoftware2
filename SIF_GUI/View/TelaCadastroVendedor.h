#ifndef TELACADASTROVENDEDOR_H
#define TELACADASTROVENDEDOR_H

#include <QFrame>

namespace Ui {
class TelaCadastroVendedor;
}

class TelaCadastroVendedor : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroVendedor(QWidget *parent = 0);
    ~TelaCadastroVendedor();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::TelaCadastroVendedor *ui;
};

#endif // TELACADASTROVENDEDOR_H
