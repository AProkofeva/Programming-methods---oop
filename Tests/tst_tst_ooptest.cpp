#include <QString>
#include <QtTest>
#include "def.h"
class Tst_oopTest : public QObject
{
    Q_OBJECT

public:
    Tst_oopTest();

private Q_SLOTS:
    void testMas_data();
    void testMas();
    void testDiagonal_data();
    void testDiagonal();
    void testTriangle_data();
    void testTriangle();
    void testCompare_data();
    void testCompare();
    void testInit();
    void testIn();
    void testOut();
    void testOne();
    void testEmpty();
    void sortEmpty();
    void sortOne();
    void sortList();
    void sortAssorted();
    void sortSort();
    void testClear();
};

Tst_oopTest::Tst_oopTest()
{
}

void Tst_oopTest::testMas_data()
{
    QTest::addColumn<int>("size");
    QTest::addColumn<int>("first");
    QTest::addColumn<int>("expected");

    QTest::newRow("compare01") << 0 << 0 << 0;
    QTest::newRow("compare02") << 1 << 10 << 10;
    QTest::newRow("compare03") << 3 << 15 << 171;
    QTest::newRow("compare04") << 5 << 10 << 550;
    QTest::newRow("compare05") << 10 << 1 << 5050;
}

void Tst_oopTest::testMas()
{
    QVERIFY2(true, "Failure");
    QFETCH(int, size);
    QFETCH(int, first);
    QFETCH(int, expected);
    //matr *m;
    //m = new matr;
    dv_massiv *mas;
    mas = new dv_massiv;
    //mas->key =USUAL;
    mas->n = size;
    mas->A = new int*[mas->n];
    for (int i = 0; i <mas->n; ++i)
    {
        mas->A[i]=new int[mas->n];
    }
   /* int mas2[6][6]={{1,2,3,4,5,6},
                    {2,2,2,2,2,2},
                    {6,6,4,4,2,2},
                    {2,2,3,3,0,4},
                    {6,2,4,1,4,3},
                    {1,2,2,1,1,2}};*/
    int k = 0;
    for (int i = 0; i <mas->n; ++i)
    {
        for(int j = 0; j<mas->n; ++j)
        {
            mas->A[i][j]= first + k;//mas2[i][j];
            k++;
        }
    }
    //m = (matr*)mas;
    //int actual =Sum(m);
    int actual = mas->Sum();
    QCOMPARE(actual, expected);
}
//Тест на сумму диагональной матрицы
void Tst_oopTest::testDiagonal_data()
{
    QTest::addColumn<int>("size");
    QTest::addColumn<int>("first");
    QTest::addColumn<int>("expected");

    QTest::newRow("compare01") << 0 << 0 << 0;
    QTest::newRow("compare02") << 1 << 10 << 10;
    QTest::newRow("compare03") << 3 << 15 << 48;
    QTest::newRow("compare04") << 10 << 10 << 145;
    QTest::newRow("compare05") << 100 << 1 << 5050;
}
void Tst_oopTest::testDiagonal()
{
    QVERIFY2(true, "Failure");
    QFETCH(int, size);
    QFETCH(int, first);
    QFETCH(int, expected);
   // matr *m;
   // m = new matr;
    diagonal_matr *mas;
    mas = new diagonal_matr;
   // mas->key = DIAGONAL;
    mas->n = size;
    mas->A = new int[mas->n];
    int k = 0;
    for (int i = 0; i <mas->n; ++i)
    {
        mas->A[i] = first + k;//mas2[i][j];
        k++;
    }
    //m = (matr*)mas;
    //int actual =Sum(m);
    int actual = mas->Sum();
    QCOMPARE(actual, expected);
}
//Тест на сумму двумерного массива
void Tst_oopTest::testTriangle_data()
{
    QTest::addColumn<int>("size");
    QTest::addColumn<int>("first");
    QTest::addColumn<int>("expected");

    QTest::newRow("compare01") << 0 << 0 << 0;
    QTest::newRow("compare02") << 1 << 10 << 10;
    QTest::newRow("compare03") << 7 << -2 << 7;
    QTest::newRow("compare04") << 10 << 10 << 145;
    QTest::newRow("compare05") << 100 << 1 << 5050;
}
void Tst_oopTest::testTriangle()
{
    QVERIFY2(true, "Failure");
    QFETCH(int, size);
    QFETCH(int, first);
    QFETCH(int, expected);
    //matr *m;
    //m = new matr;
    triangle_matr *mas;
    mas = new triangle_matr;
    //mas->key = TRIANGLE;
    mas->n = size;
    mas->A = new int[mas->n];
    int k = 0;
    for (int i = 0; i <mas->n; ++i)
    {
        mas->A[i] = first + k;//mas2[i][j];
        k++;
    }
    //m = (matr*)mas;
    //int actual =Sum(m);
    int actual = mas->Sum();
    QCOMPARE(actual, expected);
}
void Tst_oopTest::testCompare_data()
{
    QTest::addColumn<int>("size_usual");
    QTest::addColumn<int>("size_diagonal");
    QTest::addColumn<int>("size_triangle");
    QTest::addColumn<bool>("expected");
    QTest::newRow("compare01") << 0 << 0 << 0 << false;
    QTest::newRow("compare02") << 1 << 1 << 1 << false;
    QTest::newRow("compare03") << 3 << 3 << 3 << true;
    QTest::newRow("compare04") << 20 << 20 << 20 << true;
}
void Tst_oopTest::testCompare()
{
    QVERIFY2(true, "Failure");
    QFETCH(int, size_usual);
    QFETCH(int, size_diagonal);
    QFETCH(int, size_triangle);
    QFETCH(bool, expected);
    matr * matrM;
    matr * matrT;
    matr * matrD;
    dv_massiv *square;
    square = new dv_massiv;
    diagonal_matr *diag;
    diag = new diagonal_matr;
    triangle_matr *tri;
    tri = new triangle_matr;

    square->n = size_usual;
    square->A = new int*[square->n];
    for (int i = 0; i <square->n; ++i)
    {
        square->A[i]=new int[square->n];
    }
    for (int i = 0; i <square->n; ++i)
    {
        for (int j = 0; j <square->n; ++j)
        {
            square->A[i][j] = 1;
        }
    }
    tri->n = size_triangle;
    tri->A = new int [tri->n];
    for (int i = 0; i <tri->n; ++i)
    {
        tri->A[i] = 1;
    }
    diag->n = size_diagonal;
    diag->A = new int [diag->n];
    for (int i = 0; i <diag->n; ++i)
    {
        diag->A[i] = 1;
    }
    matrM = (matr*)square;
    matrT = (matr*)tri;
    matrD = (matr*)diag;
    bool actual =  matrM->Compare(matrT);
    QCOMPARE(actual, expected);
    bool actual2 =  matrM->Compare(matrM);
    bool expected2 = false;
    QCOMPARE(actual2, expected2);
    bool actual3 =  matrD->Compare(matrT);
    bool expected3 = false;
    QCOMPARE(actual3, expected3);
}
void Tst_oopTest::testInit()
{
    QVERIFY2(true, "Failure");
    container c;
    int actualLen = c.len;
    int expectedLen = 0;
    QCOMPARE(actualLen, expectedLen);
    matr* actual = c.cont;
    matr* expected = NULL;
    QCOMPARE(actual, expected);
    container* actual1 = c.prev;
    container* expected1 = NULL;
    QCOMPARE(actual1, expected1);
    container* actual2 = c.next;
    container* expected2 = NULL;
    QCOMPARE(actual2, expected2);
}
void Tst_oopTest::testIn()
{
    container c;
    FILE *fp = fopen("in.txt","r");
    ifstream ifst(fp);
    c.In(ifst);
    int actuallen = c.len;
    int expectedlen = 6;
    QCOMPARE(actuallen, expectedlen);
    matr* actualHead = c.cont;
    matr *expectedHead;
    diagonal_matr *mas;
    mas = new diagonal_matr;
    mas->outm = ONE_MASSIV;
    mas->n = 3;
    mas->A = new int[mas->n];

    /*int mas2[6][6]={{1,2,3,4,5,6},
                    {2,2,2,2,2,2},
                    {6,6,4,4,2,2},
                    {2,2,3,3,0,4},
                    {6,2,4,1,4,3},
                    {1,2,2,1,1,2}};*/
    int mas2[3] = {4, 3, 5};
    for (int i = 0; i <mas->n; ++i)
    {
        mas->A[i]= mas2[i];
    }
    expectedHead = (matr*)mas;
    QCOMPARE(actualHead, expectedHead);
}
void Tst_oopTest::testOut()
{
    QVERIFY2(true, "Failure");
    container c;
    FILE *fp = fopen("in.txt","r");
    ifstream ifst(fp);
    FILE *fn = fopen("out.txt","w");
    ofstream ofst(fn);
    c.In(ifst);
    int actuallen = c.len;
    c.Out(ofst);
    fclose(fn);
    fclose(fp);
    FILE *fd = fopen("out.txt","r");
    ifstream actual(fd);
    FILE *fk = fopen("outexp.txt","r");
    ifstream expected(fk);
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    fclose(fd);
    fclose(fk);
}
void Tst_oopTest::testOne()
{
    QVERIFY2(true, "Failure");
    container c;
    FILE *fp = fopen("in_one.txt","r");
    ifstream ifst(fp);
    FILE *fn = fopen("out1.txt","w");
    ofstream ofst(fn);
    c.In(ifst);
    int actuallen = c.len;
    c.Out(ofst);
    fclose(fn);
    fclose(fp);
    FILE *fd = fopen("out1.txt","r");
    ifstream actual(fd);
    FILE *fk = fopen("out_one.txt","r");
    ifstream expected(fk);
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    fclose(fd);
    fclose(fk);
}
void Tst_oopTest::testEmpty()
{
    QVERIFY2(true, "Failure");
    container c;
    FILE *fp = fopen("in_empty.txt","r");
    ifstream ifst(fp);
    FILE *fn = fopen("outemp.txt","w");
    ofstream ofst(fn);
    c.In(ifst);
    int actuallen = c.len;
    c.Out(ofst);
    fclose(fn);
    fclose(fp);
    FILE *fd = fopen("outemp.txt","r");
    ifstream actual(fd);
    FILE *fk = fopen("out_empty.txt","r");
    ifstream expected(fk);
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    fclose(fd);
    fclose(fk);
}
void Tst_oopTest::sortEmpty()
{
    QVERIFY2(true, "Failure");
    container c;
    FILE *fp = fopen("in_empty.txt","r");
    ifstream ifst(fp);
    FILE *fn = fopen("sortemp.txt","w");
    ofstream ofst(fn);
    c.In(ifst);
    c.Sort();
    c.Out(ofst);
    fclose(fn);
    fclose(fp);
    FILE *fd = fopen("sortemp.txt","r");
    ifstream actual(fd);
    FILE *fk = fopen("exp_sort_empty.txt","r");
    ifstream expected(fk);
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    fclose(fd);
    fclose(fk);
}
void Tst_oopTest::sortOne()
{
    QVERIFY2(true, "Failure");
    container c;
    FILE *fp = fopen("in_one.txt","r");
    ifstream ifst(fp);
    FILE *fn = fopen("sortone.txt","w");
    ofstream ofst(fn);
    c.In(ifst);
    c.Sort();
    c.Out(ofst);
    fclose(fn);
    fclose(fp);
    FILE *fd = fopen("sortone.txt","r");
    ifstream actual(fd);
    FILE *fk = fopen("exp_sort_one.txt","r");
    ifstream expected(fk);
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    fclose(fd);
    fclose(fk);
}
void Tst_oopTest::sortList()
{
    QVERIFY2(true, "Failure");
    container c;
    FILE *fp = fopen("in.txt","r");
    ifstream ifst(fp);
    FILE *fn = fopen("sort_usual.txt","w");
    ofstream ofst(fn);
    c.In(ifst);
    c.Sort();
    c.Out(ofst);
    fclose(fn);
    fclose(fp);
    FILE *fd = fopen("sort_usual.txt","r");
    ifstream actual(fd);
    FILE *fk = fopen("exp_sort_usual.txt","r");
    ifstream expected(fk);
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    fclose(fd);
    fclose(fk);
}
void Tst_oopTest::sortAssorted()
{
    QVERIFY2(true, "Failure");
    container c;
    FILE *fp = fopen("in_assort.txt","r");
    ifstream ifst(fp);
    FILE *fn = fopen("sort_assort.txt","w");
    ofstream ofst(fn);
    c.In(ifst);
    c.Sort();
    c.Out(ofst);
    fclose(fn);
    fclose(fp);
    FILE *fd = fopen("sort_assort.txt","r");
    ifstream actual(fd);
    FILE *fk = fopen("exp_sort_assort.txt","r");
    ifstream expected(fk);
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    fclose(fd);
    fclose(fk);
}
void Tst_oopTest::sortSort()
{
    QVERIFY2(true, "Failure");
    container c;
    FILE *fp = fopen("in2.txt","r");
    ifstream ifst(fp);
    FILE *fn = fopen("sort_sort.txt","w");
    ofstream ofst(fn);
    c.In(ifst);
    c.Sort();
    c.Out(ofst);
    fclose(fn);
    fclose(fp);
    FILE *fd = fopen("sort_sort.txt","r");
    ifstream actual(fd);
    FILE *fk = fopen("exp_sort_sort.txt","r");
    ifstream expected(fk);
    char act;
    char exp;
    while(!actual.eof())
    {
        actual >> act;
        expected >> exp;
        QCOMPARE(act, exp);
    }
    fclose(fd);
    fclose(fk);
}
void Tst_oopTest::testClear()
{
    QVERIFY2(true, "Failure");
    container c;
    FILE *fp = fopen("in2.txt","r");
    ifstream ifst(fp);
    c.In(ifst);
    c.Clear();
    int actualLen = c.len;
    int expectedLen = 0;
    QCOMPARE(actualLen, expectedLen);
    matr* actual = c.cont;
    matr* expected = NULL;
    QCOMPARE(actual, expected);
    container* actual1 = c.prev;
    container* expected1 = NULL;
    QCOMPARE(actual1, expected1);
    container* actual2 = c.next;
    container* expected2 = NULL;
    QCOMPARE(actual2, expected2);
}
QTEST_APPLESS_MAIN(Tst_oopTest)

#include "tst_tst_ooptest.moc"
