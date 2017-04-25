QT += core
QT -= gui

TARGET = SIF
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Controller/ListenerAcessorio.cpp \
    Controller/ListenerCliente.cpp \
    Controller/ListenerGerente.cpp \
    Controller/ListenerLogin.cpp \
    Controller/ListenerVeiculo.cpp \
    Controller/ListenerVenda.cpp \
    Controller/ListenerVendedor.cpp \
    Model/Acessorio.cpp \
    Model/Cliente.cpp \
    Model/DAOAcessorio.cpp \
    Model/DAOCliente.cpp \
    Model/DAOGerente.cpp \
    Model/DAOVeiculo.cpp \
    Model/DAOVenda.cpp \
    Model/DAOVendedor.cpp \
    Model/Funcionario.cpp \
    Model/Gerente.cpp \
    Model/Pessoa.cpp \
    Model/Veiculo.cpp \
    Model/Venda.cpp \
    Model/Vendedor.cpp \
    View/TelaCadastro.cpp \
    View/TelaConsulta.cpp \
    View/TelaEdicao.cpp \
    View/TelaListagem.cpp \
    View/TelaLogin.cpp \
    View/TelaPrincipal.cpp \
    View/TelaRemocao.cpp

HEADERS += \
    Controller/ListenerAcessorio.h \
    Controller/ListenerCliente.h \
    Controller/ListenerGerente.h \
    Controller/ListenerLogin.h \
    Controller/ListenerVeiculo.h \
    Controller/ListenerVenda.h \
    Controller/ListenerVendedor.h \
    Model/Acessorio.h \
    Model/Cliente.h \
    Model/DAOAcessorio.h \
    Model/DAOCliente.h \
    Model/DAOGerente.h \
    Model/DAOVeiculo.h \
    Model/DAOVenda.h \
    Model/DAOVendedor.h \
    Model/Funcionario.h \
    Model/Gerente.h \
    Model/Pessoa.h \
    Model/Veiculo.h \
    Model/Venda.h \
    Model/Vendedor.h \
    View/TelaCadastro.h \
    View/TelaConsulta.h \
    View/TelaEdicao.h \
    View/TelaListagem.h \
    View/TelaLogin.h \
    View/TelaPrincipal.h \
    View/TelaRemocao.h

FORMS +=

