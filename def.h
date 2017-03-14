#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
enum output {LINE_BY_LINE, BY_COLUMN, ONE_MASSIV};
class matr 
{
public:
	output outm;
    static  matr* In(ifstream &ifst);	   
    virtual void Read(ifstream &ifst) = 0;  // ввод
    virtual void Write(ofstream &ofst) = 0;     // вывод
};
class dv_massiv: public matr 
{
private:
	int n;
	int **A; 
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
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
    void Clear();  // очистка контейнера от фигур
    container();    // инициализация контейнера
    ~container() {Clear();} // утилизация контейнера
};