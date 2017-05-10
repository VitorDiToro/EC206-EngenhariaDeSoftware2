#include <QApplication>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <typeinfo>
#include <QDebug>
#include <iostream>

using namespace std;

#include "ViewModel/TelaLogin.h"

void mainMenu(void);
void genericMenu(void);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow* lw = new LoginWindow();
    lw->show();

    qDebug() << "aarrumamalae";

    return a.exec();

    return 0;
}
