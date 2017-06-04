#ifndef PESSOA_H
#define PESSOA_H

#include <QString>
#include <QDebug>

class Pessoa
{
    private:
        QString nome;
        QString cpf;
        QString telefone;
        QString endereco;

        static int total;
        int id;
    public:
        Pessoa();
        Pessoa(QString n, QString c, QString t, QString e);
        ~Pessoa();

        QString getNome() const;
        void setNome(const QString &value);
        QString getCpf() const;
        void setCpf(const QString &value);
        QString getTelefone() const;
        void setTelefone(const QString &value);
        QString getEndereco() const;
        void setEndereco(const QString &value);

        static int getTotal();
        int getId() const;
        void setId(int value);

        void print();
        void print_details();
};

#endif // PESSOA_H
