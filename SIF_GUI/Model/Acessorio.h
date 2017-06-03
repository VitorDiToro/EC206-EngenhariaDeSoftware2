#ifndef ACESSORIO_H
#define ACESSORIO_H

#include <vector>
#include <QString>
#include <QDebug>

using namespace std;

class Acessorio
{
    private:
        QString nome;
        float preco;
        QString descricao;

        static int total;
        int id;
    public:
        Acessorio();
        ~Acessorio();

        QString getNome() const;
        void setNome(const QString &value);
        float getPreco() const;
        void setPreco(float value);
        QString getDescricao() const;
        void setDescricao(const QString &value);

        static int getTotal();
        int getId() const;
        void setId(int value);

        void print();
        void print_details();
};

extern vector<Acessorio*> stock_acessorios;

#endif // ACESSORIO_H
