#ifndef TELACADASTROGERENTE_H
#define TELACADASTROGERENTE_H

#include <QFrame>

namespace Ui {
class TelaCadastroGerente;
}

class TelaCadastroGerente : public QFrame
{
    Q_OBJECT

public:
    explicit TelaCadastroGerente(QWidget *parent = 0);
    ~TelaCadastroGerente();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TelaCadastroGerente *ui;
};

#endif // TELACADASTROGERENTE_H
