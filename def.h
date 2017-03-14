#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
enum output {LINE_BY_LINE, BY_COLUMN, ONE_MASSIV};
class matr 
{
public:
	output outm;
    static  matr* In(ifstream &ifst);	   
    virtual void Read(ifstream &ifst) = 0;  // ����
    virtual void Write(ofstream &ofst) = 0;     // �����
	virtual int Sum() = 0;
	bool Compare (matr *next);
	virtual void WriteFirst(ofstream &ofst) = 0;
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
	void WriteFirst(ofstream &ofst);
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
	void WriteFirst(ofstream &ofst);
	diagonal_matr() {};
 };
class triangle_matr: public matr
{
private:
	int n;
	int *A; 
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
	int Sum ();
	void WriteFirst(ofstream &ofst);
	triangle_matr() {};
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
	void OutFirst(ofstream &ofst);  
    void Clear();  // ������� ���������� �� �����
    container();    // ������������� ����������
    ~container() {Clear();} // ���������� ����������
};
