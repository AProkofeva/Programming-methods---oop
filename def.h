#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
class matr 
{
public:
    static  matr* In(ifstream &ifst);	   
    virtual void Read(ifstream &ifst) = 0;  // ����
    virtual void Write(ofstream &ofst) = 0;     // �����
	virtual int Sum() = 0;
	bool Compare (matr *next);
};
class dv_massiv: public matr 
{
private:
	int n;
	int **A; 
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
	int Sum ();
	dv_massiv() {};
};
class diagonal_matr: public matr
{
private:
	int n;
	int *A; 
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
	int Sum ();
	diagonal_matr() {};
 };
class container
{
private:
   //lst *list;
	matr *cont;
   container *next; // ��������� �� ��������� �������
   container *prev;
   int len;
public:
	void In(ifstream &ifst);     // ���� 
    void Out(ofstream &ofst);    // ����� 
	void Sort();
    void Clear();  // ������� ���������� �� �����
    container();    // ������������� ����������
    ~container() {Clear();} // ���������� ����������
};
