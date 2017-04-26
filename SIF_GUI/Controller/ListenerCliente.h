#ifndef MANAGECLIENTE_H
#define MANAGECLIENTE_H

#include <vector>
#include <iostream>
#include "Model/Cliente.h"

using namespace std;

void Cliente_cadastrar(string nome, string cpf, string telefone, string endereco);
void Cliente_listar();
void Cliente_consultar();
void Cliente_editar();
void Cliente_remover();

#endif // MANAGECLIENTE_H
