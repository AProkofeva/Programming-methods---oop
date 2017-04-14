//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
enum output {LINE_BY_LINE, BY_COLUMN, ONE_MASSIV};
class _matr
{
	public:
		output outm;
		static  _matr* In(ifstream &inFile);
		virtual void Read(ifstream &inFile) = 0;  // ввод
		virtual void Write(ofstream &outFile) = 0;     // вывод
		virtual int Sum() = 0;
		bool Compare (_matr *next);
		virtual void WriteFirst(ofstream &outFile) = 0;
};
class _usualMatr: public _matr
{
	private:
		int n;
		int **A;
	public:
		void Read(ifstream &inFile);
		void Write(ofstream &outFile);
		int Sum ();
		void WriteFirst(ofstream &outFile);
		_usualMatr() {};
};
class _diagonalMatr: public _matr
{
	private:
		int n;
		int *A;
	public:
		void Read(ifstream &inFile);
		void Write(ofstream &outFile);
		int Sum ();
		void WriteFirst(ofstream &outFile);
		_diagonalMatr() {};
 };
class _triangleMatr: public _matr
{
	private:
		int n;
		int *A;
	public:
		void Read(ifstream &inFile);
		void Write(ofstream &outFile);
		int Sum ();
		void WriteFirst(ofstream &outFile);
		_triangleMatr() {};
 };
class _container
{
	private:
		_matr *cont;
		_container *next; // указатель на следующий элемент
		_container *prev;
		int len;
	public:
		void In(ifstream &inFile);     // ввод
		void Out(ofstream &outFile);    // вывод
		void Sort();
		void OutFirst(ofstream &outFile);
		void Clear();  // очистка контейнера от фигур
		_container();    // инициализация контейнера
		~_container() {Clear();} // утилизация контейнера
};
void CheckIn(ifstream &inFile);
void CheckOut(ofstream &outFile);
int CheckNumber(ifstream &inFile, int number);
void CheckType(int number);
void CheckSize(int size);
void CheckTriangleSize(int size);
