// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#INCLUDE C : \\Irvine\Irvine32.inc


#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include <string>
#include<fstream>
using namespace std;
int main()
{
	ifstream file;
	file.open("data.txt");
	float i = 0;
	float j = 0;
	string str;
	int a = 0;
	float result, garbage;
	int count = 0;
	while (!file.eof())
	{
		file >> str;
		i = stof(str);
		file >> str;
		j = stof(str);
		_asm {
			finit
			fld i;
			fld j;
			fmul ST(0), ST(1); multiply
				fstp result;
			fstp garbage;

		}
		cout << "Result is:"s << result << endl;

		//cout << "value of i:" << i << endl;
		//cout << "Read Integar:" << integer << endl;
		//cout << i;
		//cout << line << endl;
	}
	file.close();
	//result = array1[j];

	return(0);

}