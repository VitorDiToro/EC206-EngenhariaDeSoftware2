QT += core
QT -= gui

TARGET = SIF_console
CONFIG += console
CONFIG -= app_bundle
#CONFIG += -std=c++11
CONFIG += -std=gnu++11

TEMPLATE = app

SOURCES += main.cpp \
    Veiculo.cpp \
    Venda.cpp \
    Cliente.cpp \
    Acessorio.cpp \
    Pessoa.cpp \
    Funcionario.cpp \
    Vendedor.cpp \
    Gerente.cpp \
    Manage/ManageAcessorio.cpp \
    Manage/ManageCliente.cpp \
    Manage/ManageGerente.cpp \
    Manage/ManageVeiculo.cpp \
    Manage/ManageVenda.cpp \
    Manage/ManageVendedor.cpp

HEADERS += \
    Veiculo.h \
    Venda.h \
    Cliente.h \
    Acessorio.h \
    Pessoa.h \
    Funcionario.h \
    Vendedor.h \
    Gerente.h \
    Manage/ManageAcessorio.h \
    Manage/ManageCliente.h \
    Manage/ManageGerente.h \
    Manage/ManageVeiculo.h \
    Manage/ManageVenda.h \
    Manage/ManageVendedor.h

