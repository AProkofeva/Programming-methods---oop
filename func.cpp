//#include "stdafx.h"
#include "def.h"

void CheckIn(ifstream &inFile)
{
	if(!inFile)
	{
		cout << "No input file found!" << endl;
		exit(1);
	}
}
void CheckOut(ofstream &outFile)
{
	if(!outFile)
	{
		cout << "No output file found!" << endl;
		exit(1);
	}
}
int CheckNumber(ifstream &inFile, int number)
{
	inFile >> number;
	if (inFile.fail())
    {
        cout << "Wrong input! Your file must contain only numbers!" << endl;
        exit(1);
    }
	if (( number < -1000 ) || (number > 1000))
	{
		 cout << "Wrong input! Your file contain large numbers!" << endl;
		 exit(1);
	}
	return number;
}
void CheckType(int number)
{
	int begin = 1;
	int end = 3;
	if (( number < begin ) || (number > end))
    {
        cout << "Wrong type!!! 1 - diagonal, 2 - square (usual), 3 - triangle matrix" << endl;
		cout << "OR  1 - line by line, 2 - by column, 3 - like one-dimensional way output of matrix" << endl;
        exit(1);
    }
}
void CheckSize(int size)
{
	if ((size < 2) || (size > 100))
    {
        cout << "Wrong size of matrix!!!" << endl;
        exit(1);
    }
}
void CheckTriangleSize(int size)
{
	float sq = sqrt(float(1 + 8 * size));
	if ((sq - int(sq)) == 0)
	{
		float n = ( -1 + sq)/2;
		if ((n - int(n)) == 0)
		{
			return ;
		}
		else
		{
			cout << "Wrong size of triangle matrix!!!" << endl;
			exit(1);
		}
	}
	else
	{
		cout << "Wrong size of triangle matrix!!!" << endl;
		exit(1);
	}
}
// значения ключей для каждой из матриц
void _usualMatr ::Read(ifstream &inFile)
{
	n = CheckNumber(inFile, n);
	CheckSize(n);
	A = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = new int[n];
	}
	for( int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			inFile >> A[i][j];
		}
	}
} 
void _diagonalMatr :: Read(ifstream &inFile)
{
	n = CheckNumber(inFile, n);
	CheckSize(n);
	A = new int [n];
	for( int i = 0; i < n; i++)
	{
		inFile >> A[i];
	}
}
void _triangleMatr :: Read(ifstream &inFile)
{
	n = CheckNumber(inFile, n);
	CheckSize(n);
	CheckTriangleSize(n);
	A = new int [n];
	for( int i = 0; i < n; i++)
	{
		inFile >> A[i];
	}
}
void _usualMatr :: Write(ofstream &outFile)
{
	outFile << "It is a usual square matrix! Number of rows (columns) = " << n << endl << "Matrix:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			outFile << A[i][j] << '\t';
		}
		outFile << endl;
	}
}
void _usualMatr ::WriteFirst(ofstream &outFile)
{
	Write(outFile);
}
void _diagonalMatr ::WriteFirst(ofstream &outFile)
{
}
void _triangleMatr ::WriteFirst(ofstream &outFile)
{
}
void _diagonalMatr :: Write (ofstream &outFile)
{
	outFile << "It is diagonal matrix! Number of rows (columns) = " << n << endl << "Matrix:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				outFile << A[i] << '\t';
			}
			else
			{
				outFile << "0\t";
			}
		}
		outFile << endl;
	}
}
int _usualMatr :: Sum()
{
	int sum = 0;
	for( int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum = sum + A[i][j];
		}
	}
	return sum;
}
int _diagonalMatr :: Sum ()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + A[i];
	}
	return sum;
}
int _triangleMatr :: Sum ()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + A[i];
	}
	return sum;
}
void _triangleMatr :: Write (ofstream &outFile)
{
	int len = ( -1 + sqrt(float( 1 + 8 * n)))/2;
	outFile << "It is low triangle matrix! Number of rows (columns) = " << len << endl << "Matrix:" << endl;
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i >= j)
			{
				outFile << A[k] << '\t';
				k++;
			}
			else
			{
				outFile << "0\t";
			}
		}
		outFile << endl;
	}
}
_matr* _matr::In(ifstream& inFile)
{
	_matr *matrix;
	int key = 0;
	key = CheckNumber(inFile, key);
	CheckType(key);
	int outm = 0;
	outm = CheckNumber(inFile, outm);
	CheckType(outm);
	switch (key)
	{
		case 1:
		{
			matrix = new _diagonalMatr;
			switch(outm)
			{
				case 1:
				{
					matrix->outm = LINE_BY_LINE;
					break;
				}
				case 2:
				{
					matrix->outm = BY_COLUMN;
					break;
				}
				case 3:
				{
					matrix->outm = ONE_MASSIV;
					break;
				}
			}
			break;
		}
		
		case 2:
		{
			matrix = new _usualMatr;
			switch(outm)
			{
				case 1:
				{
					matrix->outm = LINE_BY_LINE;
					break;
				}
				case 2:
				{
					matrix->outm = BY_COLUMN;
					break;
				}
				case 3:
				{
					matrix->outm = ONE_MASSIV;
					break;
				}
			}
			break;
		}
		case 3:
		{
			matrix = new _triangleMatr;
			switch(outm)
			{
				case 1:
				{
					matrix->outm = LINE_BY_LINE;
					break;
				}
				case 2:
				{
					matrix->outm = BY_COLUMN;
					break;
				}
				case 3:
				{
					matrix->outm = ONE_MASSIV;
					break;
				}
			}
			break;
		}
		default:
		{
			return 0;
		}
	}
	matrix->Read(inFile);
	return matrix;
}
_container::_container()
{
	cont = NULL;
    next = NULL; // указатель на следующий узел
    prev = NULL; // указатель на предыдущий узел 
	len = 0;
}

 //  Очистка контейнера от элементов (освобождение памяти)
void _container:: Clear()
{
	_container *cur = this;
	cur = cur->next;
	while (cur != NULL) //Пока по адресу на начало списка что-то есть
    {
		_container *temp = cur->prev ;
		temp->next = cur->next;
		delete cur; // освобождаем память удаляемого элемента
		cur = temp;
    }
	len = 0;
	cont = NULL;
    next = NULL; // указатель на следующий узел
    prev = NULL; // указатель на предыдущий узел 
}
void _container::In(ifstream &inFile)
{
	len = CheckNumber(inFile, len);
	if (len < 0)
    {
        cout << "Wrong count of elements ( must be > 0)!!!" << endl;
        exit(1);
    }
	_container *cur = this;
	for(int i = 0; i < len; i++)
	{
		_matr *matrix;
		if((matrix = _matr::In(inFile))!=0)
		{
			_container *temp, *p;
			temp = new _container;
			p = cur->next; // сохранение указателя на следующий узел
			cur->next = temp; // предыдущий узел указывает на создаваемый
			temp->cont = matrix;
			temp->next = p; // созданный узел указывает на следующий узел
			temp->prev = cur; // созданный узел указывает на предыдущий узел
			if (p != NULL)
				p->prev = temp;
			cur = temp;
		}
	}
	this->cont = cur->cont;
	this->next = cur->next;
	this->prev = cur->prev;
}
void _container::Out(ofstream &outFile)
{
	outFile << "Container contains " << len << " elements." << endl;
	_container *p = this;
	for( int i = 0; i < len-1; i++)
			p = p ->prev;
	int schet = 1;
	while((p != NULL)&&(len!=0))
	{
		outFile << schet << ": " <<endl;
		switch(p->cont->outm)
		{
			case LINE_BY_LINE:
			{
				outFile << "It is line by line method of output" << endl;
				break;
			}
			case BY_COLUMN:
			{
				outFile << "It is method of output by columns" << endl;
				break;
			}
			case ONE_MASSIV:
			{
				outFile << "It is method of output in shape of one-dimensional massiv" << endl;
				break;
			}
			default:
			{
				outFile << "It is incorrect way of output matrix!" <<endl;
				break;
			}
		}
		p->cont->Write(outFile); // вывод значения элемента p
		int sum = p->cont->Sum ();
		outFile << "Sum of elements = " << sum << endl;
		p = p->next; // переход к следующему узлу
		schet++; 
	} 
}
bool _matr::Compare(_matr *next)
{
	int s = Sum();
	int sk = next->Sum();
	return (s > sk);
}
void _container :: Sort()
{
	_container *p= this;
	bool flag;
	do
	{
		flag = false;
		for( int i = 0; i < len-1; i++)
		{
			p = p ->prev;
		}
		while (p->next != NULL)
		{
			_matr *one;
			one = p->cont;
			p = p->next;
			_matr *two;
			two = p->cont;
			bool k = one->Compare(two);
			if (k == true)
			{
				p->cont = one;
				p = p->prev;
				p->cont = two;
				flag = true;
			}
			else
			{
				p = p->prev;
			}
			p = p->next; // переход к следующему узлу
		}
	} while (flag);
}
void _container::OutFirst(ofstream &outFile)
{
	_container *p = this;
	for( int i = 0; i < len-1; i++)
	{
		p = p ->prev;
	}
	int schet = 0;
	while((p != NULL) && (len != 0))
	{
		p->cont->WriteFirst(outFile); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
		schet++;
	} 
}
void _matr ::WriteFirst(ofstream &outFile)
{
	outFile << endl;  // пустая строка
}
