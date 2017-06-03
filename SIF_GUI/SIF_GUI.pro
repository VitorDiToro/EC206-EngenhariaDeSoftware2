QT += core gui
QT += core
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QTPLUGIN += QMYSQL
TARGET = SIF_GUI
TEMPLATE = app

FORMS += \
    View/TelaCadastroAcessorio.ui \
    View/TelaCadastroCliente.ui \
    View/TelaCadastroGerente.ui \
    View/TelaCadastroVeiculo.ui \
    View/TelaCadastroVenda.ui \
    View/TelaCadastroVendedor.ui \
    View/TelaListagem.ui \
    View/TelaLogin.ui \
    View/TelaPrincipal.ui

HEADERS += \
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
    ViewModel/TelaCadastro.h \
    ViewModel/TelaCadastroAcessorio.h \
    ViewModel/TelaCadastroCliente.h \
    ViewModel/TelaCadastroGerente.h \
    ViewModel/TelaCadastroVeiculo.h \
    ViewModel/TelaCadastroVenda.h \
    ViewModel/TelaCadastroVendedor.h \
    ViewModel/TelaConsulta.h \
    ViewModel/TelaEdicao.h \
    ViewModel/TelaListagem.h \
    ViewModel/TelaLogin.h \
    ViewModel/TelaPrincipal.h \
    ViewModel/TelaRemocao.h

SOURCES += \
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
    ViewModel/TelaCadastro.cpp \
    ViewModel/TelaCadastroAcessorio.cpp \
    ViewModel/TelaCadastroCliente.cpp \
    ViewModel/TelaCadastroGerente.cpp \
    ViewModel/TelaCadastroVeiculo.cpp \
    ViewModel/TelaCadastroVenda.cpp \
    ViewModel/TelaCadastroVendedor.cpp \
    ViewModel/TelaConsulta.cpp \
    ViewModel/TelaEdicao.cpp \
    ViewModel/TelaListagem.cpp \
    ViewModel/TelaLogin.cpp \
    ViewModel/TelaPrincipal.cpp \
    ViewModel/TelaRemocao.cpp \
    main.cpp
