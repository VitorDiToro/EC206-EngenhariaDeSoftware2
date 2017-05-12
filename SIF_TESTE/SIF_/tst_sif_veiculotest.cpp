#include <QString>
#include <QtTest>
#include "./../../SIF_GUI/Model/Veiculo.h"

class SIF_VeiculoTest : public QObject
{
    Q_OBJECT

public:
    SIF_VeiculoTest();

private Q_SLOTS:

    void testCase_setModelo();
    void testCase_getModelo();

    void testCase_setCor();
    void testCase_getCor();

    void testCase_setAno();
    void testCase_getAno();

    void testCase_setPreco();
    void testCase_getPreco();

    void testCase_setId();
    void testCase_getId();
};

SIF_VeiculoTest::SIF_VeiculoTest()
{
}


// Modelo
void SIF_VeiculoTest::testCase_setModelo()
{
    Veiculo* v = new Veiculo();

    try
    {
        v->setModelo("model");
        QVERIFY(true);
    }
    catch (int e)
    {
        QVERIFY(false);
    }
}

void SIF_VeiculoTest::testCase_getModelo()
{
    Veiculo* v = new Veiculo();
    v->setModelo("model");
    QVERIFY(v->getModelo()=="model");
}



// Cor
void SIF_VeiculoTest::testCase_setCor()
{
    Veiculo* v = new Veiculo();

    try
    {
        v->setCor("color");
        QVERIFY(true);
    }
    catch (int e)
    {
        QVERIFY(false);
    }
}

void SIF_VeiculoTest::testCase_getCor()
{
    Veiculo* v = new Veiculo();
    v->setCor("color");
    QVERIFY(v->getCor()=="color");
}



// Ano
void SIF_VeiculoTest::testCase_setAno()
{
    Veiculo* v = new Veiculo();

    try
    {
        v->setAno(2017);
        QVERIFY(true);
    }
    catch (int e)
    {
        QVERIFY(false);
    }
}

void SIF_VeiculoTest::testCase_getAno()
{
    Veiculo* v = new Veiculo();
    v->setAno(2017);
    QVERIFY(v->getAno() == 2017);
}



// Preço
void SIF_VeiculoTest::testCase_setPreco()
{
    Veiculo* v = new Veiculo();

    try
    {
        v->setPreco(20000);
        QVERIFY(true);
    }
    catch (int e)
    {
        QVERIFY(false);
    }
}

void SIF_VeiculoTest::testCase_getPreco()
{
    Veiculo* v = new Veiculo();
    v->setPreco(20000);
    QVERIFY(v->getPreco() == 20000);
}



// ID
void SIF_VeiculoTest::testCase_setId()
{
    Veiculo* v = new Veiculo();

    try
    {
        v->setId(42);
        QVERIFY(true);
    }
    catch (int e)
    {
        QVERIFY(false);
    }
}

void SIF_VeiculoTest::testCase_getId()
{
    Veiculo* v = new Veiculo();
    v->setId(42);
    QVERIFY(v->getId() == 42);
}


QTEST_APPLESS_MAIN(SIF_VeiculoTest)

#include "tst_sif_veiculotest.moc"
