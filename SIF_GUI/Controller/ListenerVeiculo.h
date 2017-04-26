#ifndef MANAGEVEICULO_H
#define MANAGEVEICULO_H

#include <vector>
#include <iostream>
#include "Model/Veiculo.h"

using namespace std;

void Veiculo_cadastrar(string modelo, string cor, unsigned int ano, float preco);
void Veiculo_listar();
void Veiculo_consultar();
void Veiculo_editar();
void Veiculo_remover();

#endif // MANAGEVEICULO_H
