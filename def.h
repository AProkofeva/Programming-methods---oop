#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
class matr 
{
public:
    static  matr* In(ifstream &ifst);	   
    virtual void Read(ifstream &ifst) = 0;  // ввод
    virtual void Write(ofstream &ofst) = 0;     // вывод
	virtual void Multimethod(matr* mas, ofstream &ofst) = 0;
	virtual void CheckWithUsual(ofstream &ofst) = 0;
	virtual void CheckWithDiagonal(ofstream &ofst) = 0;
};
class dv_massiv: public matr 
{
private:
	int n;
	int **A; 
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
	void Multimethod(matr* mas, ofstream &ofst);
	void CheckWithUsual(ofstream &ofst);
	void CheckWithDiagonal(ofstream &ofst);
	dv_massiv() {};
};
struct diagonal_matr: public matr
{
private:
	int n;
	int *A; 
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
	void Multimethod(matr* mas, ofstream &ofst);
	void CheckWithUsual(ofstream &ofst);
	void CheckWithDiagonal(ofstream &ofst);
	diagonal_matr() {};
 };
class container
{
private:
   //lst *list;
	matr *cont;
   container *next; // указатель на следующий элемент
   container *prev;
   int len;
public:
	void In(ifstream &ifst);     // ввод 
    void Out(ofstream &ofst);    // вывод 
    void Clear();  // очистка контейнера
	void Multimethod(ofstream &ofst);
    container();    // инициализация контейнера
    ~container() {Clear();} // утилизация контейнера
};