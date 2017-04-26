#include <iostream>
#include <fstream>
#include "def.h"

//using namespace std;

int main(int argc, char *argv[])
{
	if(argc !=3)
	{
		cout << "Error! Incorrect command line! "
		"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream inFile(argv[1]);
	//FILE *fp = fopen("in.txt","r");
	//ifstream inFile(fp);
	//FILE *fn = fopen("out.txt","w");
	//ofstream outFile(fn);
	CheckIn(inFile);
    ofstream outFile(argv[2]);
	CheckOut(outFile);
	cout << "Start"<< endl;
	_container cont; //= new _container;
	cont.In(inFile);
	outFile << "Filled container. " << endl;
	cont.Out(outFile);
	outFile << "Sorted container. " << endl;
	cont.Sort();
	cont.Out(outFile);
	outFile << "Only usual matrix. " << endl;
	cont.OutFirst(outFile);
	outFile << "Multimethod " << endl;
	cont.Multimethod(outFile);
	cont.Clear();
	outFile << "Empty container. " << endl;
	cont.Out(outFile);
    inFile.close();
    outFile.close();
	cout << "Stop"<< endl;
	return 0;
}
