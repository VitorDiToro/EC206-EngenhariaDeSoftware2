#ifndef GERENTE_H
#define GERENTE_H

#include <vector>

#include "Funcionario.h"

using namespace std;

class Gerente : public Funcionario
{
    private:
        static Gerente* INSTANCE;
        QString unidadeQueGerencia;

        static int total;

        Gerente();
    public:
        ~Gerente();

        static Gerente* getInstance();

        QString getUnidadeQueGerencia() const;
        void setUnidadeQueGerencia(const QString &value);

        static int getTotal();

        void print();
        void print_details();
};

extern vector<Gerente*> gerentes;

#endif // GERENTE_H
