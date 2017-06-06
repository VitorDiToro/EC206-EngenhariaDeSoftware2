#ifndef MANAGER_H
#define MANAGER_H

typedef enum enu_objType
{
    INVALID,
    VENDA,
    VEICULO,
    ACESSORIO,
    CLIENTE,
    VENDEDOR,
    GERENTE
}tenu_objType;

typedef enum enu_windowState
{
    INVALIDO,
    CADASTRO,
    CONSULTA,
    EDICAO,
}tenu_windowType;

static tenu_objType MANAGER_OBJECT_TYPE;
static tenu_windowType MANAGER_WINDOW_STATE = INVALIDO;

#endif // MANAGER_H
