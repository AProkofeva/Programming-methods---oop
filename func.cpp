#include "stdafx.h"
#include "def.h"
// �������� ������ ��� ������ �� ������
void dv_massiv ::Read(ifstream &ifst) 
{
	ifst >> n;
	A = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		A[i]=new int[n];
	}
	for( int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ifst >> A[i][j];
		}
	}
} 
void diagonal_matr :: Read(ifstream &ifst) 
{
	ifst >> n;
	A = new int [n];
	for( int i = 0; i < n; i++)
	{
		ifst >> A[i];
	}
}
void triangle_matr :: Read(ifstream &ifst) 
{
	ifst >> n;
	A = new int [n];
	for( int i = 0; i < n; i++)
	{
		ifst >> A[i];
	}
}
void dv_massiv :: Write(ofstream &ofst)
{
	ofst << "It is a usual square matrix! Number of rows (columns) = " << n << endl << "Matrix:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			ofst << A[i][j] << '\t';
		ofst << endl;
	}
}
void diagonal_matr :: Write (ofstream &ofst)
{
	ofst << "It is diagonal matrix! Number of rows (columns) = " << n << endl << "Matrix:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (i == j)
				ofst << A[i] << '\t';
			else
				ofst << "0\t";
		ofst << endl;
	}
}
void triangle_matr :: Write (ofstream &ofst)
{
	int len = (-1+ sqrt(float(1+8*n)))/2;
	ofst << "It is low triangle matrix! Number of rows (columns) = " << len << endl << "Matrix:" << endl;
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
			if (i >= j)
			{
				ofst << A[k] << '\t';
				k++;
			}
			else
				ofst << "0\t";
		ofst << endl;
	}
}
matr* matr::In(ifstream& ifst)
{
	matr *matrix;
	int key;
	ifst >> key;
	switch (key)
	{
		case 1:
		{
			matrix = new diagonal_matr;
			break;
		}
		
		case 2:
		{
			matrix = new dv_massiv;
			break;
		}
		case 3:
		{
			matrix = new triangle_matr;
			break;
		}
		default:
			return 0;
	}
	matrix->Read(ifst);
	return matrix;
}
container::container() 
{
	cont = NULL;
    next = NULL; // ��������� �� ��������� ����
    prev = NULL; // ��������� �� ���������� ���� 
	len = 0;
}

 //  ������� ���������� �� ��������� (������������ ������)
void container:: Clear() 
{
	container *cur = this;
	cur = cur->next;
	while (cur!=NULL) //���� �� ������ �� ������ ������ ���-�� ����
    {
		container *temp = cur->next ;
		temp->prev = cur->prev;
		delete cur; // ����������� ������ ���������� ��������
		cur = temp;
    }
	len = 0;
	cont = NULL;
    next = NULL; // ��������� �� ��������� ����
    prev = NULL; // ��������� �� ���������� ���� 
}
void container::In(ifstream &ifst)
{
	ifst >> len;
	container *cur = this;
	for(int i = 0; i <len; i++)
	{
		matr *matrix;
		if((matrix = matr::In(ifst))!=0)
		{
			container *temp, *p;
			temp = new container;
			p = cur->next; // ���������� ��������� �� ��������� ����
			cur->next = temp; // ���������� ���� ��������� �� �����������
			temp->cont = matrix;
			temp->next = p; // ��������� ���� ��������� �� ��������� ����
			temp->prev = cur; // ��������� ���� ��������� �� ���������� ����
			if (p != NULL)
				p->prev = temp;
			cur = temp;
		}
	}
	this->cont = cur->cont;
	this->next = cur->next;
	this->prev = cur->prev;
}
void container::Out(ofstream &ofst)
{
	ofst << "Container contains " << len << " elements." << endl;
	container *p = this;
	for( int i = 0; i < len-1; i++)
			p = p ->prev;
	int schet = 1;
	while((p != NULL)&&(len!=0))
	{
		ofst << schet << ": ";
		p->cont->Write(ofst); // ����� �������� �������� p
		p = p->next; // ������� � ���������� ����
	} 
}