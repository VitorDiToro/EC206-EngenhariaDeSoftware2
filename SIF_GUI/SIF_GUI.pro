#-------------------------------------------------
#
# Project created by QtCreator 2017-04-24T22:56:13
#
#-------------------------------------------------

QT += core gui
QT += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SIF_GUI
TEMPLATE = app

SOURCES += main.cpp\
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
    View/TelaPrincipal.cpp \
    View/TelaRemocao.cpp \
    View/TelaLogin.cpp \
    View/TelaCadastroGerente.cpp \
    View/TelaCadastroVendedor.cpp \
    View/TelaCadastroCliente.cpp \
    View/TelaCadastroVeiculo.cpp \
    View/TelaCadastroAcessorio.cpp \
    View/TelaCadastroVenda.cpp

HEADERS  += \
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
    View/TelaPrincipal.h \
    View/TelaRemocao.h \
    View/TelaLogin.h \
    View/TelaCadastroGerente.h \
    View/TelaCadastroVendedor.h \
    View/TelaCadastroCliente.h \
    View/TelaCadastroVeiculo.h \
    View/TelaCadastroAcessorio.h \
    View/TelaCadastroVenda.h

FORMS    += \
    View/TelaPrincipal.ui \
    View/TelaLogin.ui \
    View/TelaCadastroGerente.ui \
    View/TelaCadastroVendedor.ui \
    View/TelaCadastroCliente.ui \
    View/TelaCadastroVeiculo.ui \
    View/TelaCadastroAcessorio.ui \
    View/TelaCadastroVenda.ui
