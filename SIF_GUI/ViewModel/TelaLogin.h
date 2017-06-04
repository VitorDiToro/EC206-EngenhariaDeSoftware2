#ifndef TELALOGIN_H
#define TELALOGIN_H

#include <QMainWindow>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_senha_returnPressed();

    void on_lineEdit_senha_selectionChanged();

private:
    Ui::LoginWindow *ui;
};

#endif // TELALOGIN_H
