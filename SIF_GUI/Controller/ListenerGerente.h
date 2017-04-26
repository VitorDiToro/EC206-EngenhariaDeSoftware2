#ifndef MANAGEGERENTE_H
#define MANAGEGERENTE_H

#include <vector>
#include <iostream>
#include "Model/Gerente.h"

using namespace std;

void Gerente_cadastrar(string nome, string cpf, string telefone, string endereco, float salario,
                       string login, string senha, string unidadeQueGerencia);
void Gerente_listar();
void Gerente_consultar();
void Gerente_editar();
void Gerente_remover();

#endif // MANAGEGERENTE_H
