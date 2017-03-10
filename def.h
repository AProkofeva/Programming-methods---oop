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
	void WriteFirst(ofstream &ofst);
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
	void WriteFirst(ofstream &ofst);
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
	void OutFirst(ofstream &ofst);  
    void Clear();  // ������� ���������� �� �����
    container();    // ������������� ����������
    ~container() {Clear();} // ���������� ����������
};