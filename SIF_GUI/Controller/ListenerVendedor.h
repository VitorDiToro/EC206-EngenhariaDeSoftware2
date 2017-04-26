#ifndef MANAGEVENDEDOR_H
#define MANAGEVENDEDOR_H

#include <vector>
#include <iostream>
#include "Model/Vendedor.h"

using namespace std;

void Vendedor_cadastrar(string nome, string cpf, string telefone, string endereco, float salario,
                        string login, string senha, string unidadeDeTrabalho, float comissao);
void Vendedor_listar();
void Vendedor_consultar();
void Vendedor_editar();
void Vendedor_remover();

#endif // MANAGEVENDEDOR_H
