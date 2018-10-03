#include<iostream>
#include"Sworker.h"
using namespace std;
void main()
{
	Sworker cSworker;
	cout << "********************************\n";
	cout << "*                              *\n";
	cout << "*                              *\n";
	cout << "*         员工管理系统         *\n";
	cout << "*           2018.09            *\n";
	cout << "*                              *\n";
	cout << "*                              *\n";
	cout << "********************************\n";
	system("pause");
	while (cSworker.Menu())
		;
}