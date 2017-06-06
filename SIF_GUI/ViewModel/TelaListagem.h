#ifndef TELALISTAGEM_H
#define TELALISTAGEM_H

#include <QFrame>
#include "manager.h"

namespace Ui {
class TelaListagem;
}

class TelaListagem : public QFrame
{
    Q_OBJECT

public:
    explicit TelaListagem(QWidget *parent = 0, tenu_objType enuObjType = INVALID);
    ~TelaListagem();

private slots:
    void on_pushButton_3_clicked();

    void on_editarButton_clicked();

    void on_consultarButton_clicked();

    void on_excluirButton_clicked();



private:
    Ui::TelaListagem *ui;

    int getIDinDB();
    bool updateTableView(tenu_objType enuObjType);
};

#endif // TELALISTAGEM_H
