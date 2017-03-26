#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Acessorio.h"
#include "Cliente.h"
#include "Funcionario.h"
#include "Gerente.h"
#include "Pessoa.h"
#include "Veiculo.h"
#include "Venda.h"
#include "Vendedor.h"

#include "Manage/ManageAcessorio.h"
#include "Manage/ManageCliente.h"
#include "Manage/ManageGerente.h"
#include "Manage/ManageVenda.h"
#include "Manage/ManageVeiculo.h"
#include "Manage/ManageVendedor.h"


void mainMenu(void);
void genericMenu(void);


int main(void)
{
    int c;
    int crud;

    Acessorio *acessorio = new Acessorio();
    Cliente *cliente = new Cliente();
    Funcionario *funcionario = new Funcionario();
    Gerente *gerente = new Gerente();
    Pessoa *pessoa = new Pessoa();
    Veiculo *veiculo = new Veiculo();
    Venda *venda = new Venda();
    Vendedor *vendedor = new Vendedor();
    
    for(;;)
    {
        mainMenu();
        
        c = getchar();
        getchar();
        
        switch(c)
        {
            case('1'):
                genericMenu();
                crud = getchar();
                getchar();
                
                switch(crud)
                {
                    case('1'):
                        Gerente_cadastrar();
                    break;
                        
                    case('2'):
                        Gerente_listar();
                    break;
                        
                    case('3'):
                        Gerente_consultar();
                    break;
                        
                    case('4'):
                        Gerente_editar();
                    break;
                        
                    case('5'):
                        Gerente_editar();                      
                    break;    
                    
                    case('0'):
                        printf("\n");
                    break;
                        
                    default:
                        printf("Opecao invalida\n");
                }
            break;
            
            case('2'):
                genericMenu();
                crud = getchar();
                getchar();
                
                switch(crud)
                {
                    case('1'):
                        Vendedor_cadastrar();
                    break;
                        
                    case('2'):
                        Vendedor_listar();
                    break;
                        
                    case('3'):
                        Vendedor_consultar();
                    break;
                        
                    case('4'):
                        Vendedor_editar();
                    break;
                        
                    case('5'):
                        Vendedor_editar();                      
                    break;    
                    
                    case('0'):
                        printf("\n");
                    break;
                        
                    default:
                        printf("Opecao invalida\n");
                }
            break;
            
            case('3'):
                genericMenu();
                crud = getchar();
                getchar();
                
                switch(crud)
                {
                    case('1'):
                        Cliente_cadastrar();
                    break;
                        
                    case('2'):
                        Cliente_listar();
                    break;
                        
                    case('3'):
                        Cliente_consultar();
                    break;
                        
                    case('4'):
                        Cliente_editar();
                    break;
                        
                    case('5'):
                        Cliente_editar();                      
                    break;    
                    
                    case('0'):
                        printf("\n");
                    break;
                        
                    default:
                        printf("Opecao invalida\n");
                }
            break;

            case('4'):
                genericMenu();
                crud = getchar();
                getchar();
                
                switch(crud)
                {
                    case('1'):
                        Veiculo_cadastrar();
                    break;
                        
                    case('2'):
                        Veiculo_listar();
                    break;
                        
                    case('3'):
                        Veiculo_consultar();
                    break;
                        
                    case('4'):
                        Veiculo_editar();
                    break;
                        
                    case('5'):
                        Veiculo_editar();                      
                    break;    
                    
                    case('0'):
                        printf("\n");
                    break;
                        
                    default:
                        printf("Opecao invalida\n");
                }
            break;
            
            case('5'):
                genericMenu();
                crud = getchar();
                getchar();
                
                switch(crud)
                {
                    case('1'):
                        Acessorio_cadastrar();
                    break;
                        
                    case('2'):
                        Acessorio_listar();
                    break;
                        
                    case('3'):
                        Acessorio_consultar();
                    break;
                        
                    case('4'):
                        Acessorio_editar();
                    break;
                        
                    case('5'):
                        Acessorio_editar();                      
                    break;    
                    
                    case('0'):
                        printf("\n");
                    break;
                        
                    default:
                        printf("Opecao invalida\n");
                }
            break;
            
            case('6'):
                genericMenu();
                crud = getchar();
                getchar();
                
                switch(crud)
                {
                    case('1'):
                        Venda_cadastrar();
                    break;
                        
                    case('2'):
                        Venda_listar();
                    break;
                        
                    case('3'):
                        Venda_consultar();
                    break;
                        
                    case('4'):
                        Venda_editar();
                    break;
                        
                    case('5'):
                        Venda_editar();                      
                    break;    
                    
                    case('0'):
                        printf("\n");
                    break;
                        
                    default:
                        printf("Opecao invalida\n");
                }
            break;
        
            case('0'):
                printf("Tchau!!!\n");
                goto stop;
            break;
            
            default:
                printf("Opecao invalida\n");
        }
    }
    stop:   //Sim, estou usando GOTO \,,/
    
    return 0;
}


void mainMenu(void)
{
    printf("1 - Gerentes\n");
    printf("2 - Vendedores\n");
    printf("3 - Clientes\n");
    printf("4 - Carros\n");
    printf("5 - Acessorios\n");
    printf("6 - Vendas\n");
    printf("0 - Sair\n");
    printf("\n");
    
    return;
}

void genericMenu(void)
{
    
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Consultar\n");
    printf("4 - Editar\n");
    printf("5 - Excluir\n");
    printf("0 - Voltar\n");
    printf("\n");
    return;
}
