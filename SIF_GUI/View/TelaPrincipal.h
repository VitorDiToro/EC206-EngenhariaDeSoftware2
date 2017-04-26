#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class TelaPrincipal;
}

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaPrincipal(QWidget *parent = 0);
    ~TelaPrincipal();

private slots:
    void on_actionCadastrar_triggered();

    void on_actionCadastrar_6_triggered();

    void on_actionCadastrar_5_triggered();

    void on_actionCadastrar_4_triggered();

    void on_actionCadastrar_3_triggered();

    void on_actionCadastrar_2_triggered();

    void on_actionListar_triggered();

    void on_actionListar_2_triggered();

    void on_actionListar_3_triggered();

    void on_actionListar_4_triggered();

    void on_actionListar_5_triggered();

    void on_actionListar_6_triggered();

private:
    Ui::TelaPrincipal *ui;
};

#endif // TELAPRINCIPAL_H
