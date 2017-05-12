#include <QString>
#include <QtTest>

class Sif_testeTest : public QObject
{
    Q_OBJECT

public:
    Sif_testeTest();

private Q_SLOTS:
    void testCase1();
};

Sif_testeTest::Sif_testeTest()
{
}

void Sif_testeTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Sif_testeTest)

#include "tst_sif_testetest.moc"
