#include<iostream>
#include"Worker.h"
using namespace std;
int main()
{
	CWorker cw;
	cout << "********************************\n";
	cout << "*                              *\n";
	cout << "*                              *\n";
	cout << "*         员工管理系统         *\n";
	cout << "*           2018.09            *\n";
	cout << "*                              *\n";
	cout << "*                              *\n";
	cout << "********************************\n";
	system("pause");
	while (cw.Menu())
		;
}