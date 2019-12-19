#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;
int main()
{


	ifstream myfile;
	myfile.open("data.txt");
	float first = 0;
	float second = 0;
	string str;
	int a = 0;
	float result;
	int count = 0;
	while (!myfile.eof())
	{
		myfile >> str;
		first = stof(str);
		myfile >> str;
		second = stof(str);
		_asm
		{
			finit
			fld first;
			fmul second;
			fstp result;
		}
		cout << "Result is:" << result << endl;
		ofstream myfile;
		myfile.open("example.txt");
		myfile << result;
		myfile.close();















	}
	myfile.close();

	return(0);

}