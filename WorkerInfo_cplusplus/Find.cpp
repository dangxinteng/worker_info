#include<iostream>
#include "Find.h"
#include "Sworker.h"
using namespace std;
Find::Find():cList(Sworker::cList)
{
	
}

void Find::FindByNumb()
{
	int nNumb;
	cout << "请输入您要查找的工号：";
	cin >> nNumb;
	if (!nNumb)
		return;
	Node* p = cList.FindNumb(nNumb);
	if (!p)
	{
		cout << "你要查找的工号不存在！\n";
		system("pause");
		return;
	}
	cout << p->data.nNumb << '\t';
	cout << p->data.sName << '\t';
	cout << p->data.fSalary << '\n';
	system("pause");

}
void Find::FindByName()
{
	char sName[20];
	cout << "请输入您要查找的姓名：";
	cin >> sName;
	Node* p = cList.GetHead();
	int sum = 0;
	while (p)
	{
		if (strstr(p->data.sName, sName))
		{
			cout << p->data.nNumb << '\t';
			cout << p->data.sName << '\t';
			cout << p->data.fSalary << '\n';
			++sum;
		}

		p = p->pNext;
	}
	cout << "一共有" << sum << "条数据！\n";
	system("pause");

}
void Find::FindBySalary()
{
	float fMin, fMax;
	cout << "请输入您要查找的最低资和最高工资：";
	cin >> fMin;
	cin >> fMax;
	Node* p = cList.GetHead();
	int sum = 0;
	while (p)
	{
		if (p->data.fSalary >= fMin &&  p->data.fSalary <= fMax)
		{
			cout << p->data.nNumb << '\t';
			cout << p->data.sName << '\t';
			cout << p->data.fSalary << '\n';
			++sum;
		}
		p = p->pNext;
	}
	cout << "一共" << sum << "有条数据！\n";
	system("pause");
}

int Find::FindMenu()
{
	system("cls");
	cout << "********************************\n";
	cout << "*                              *\n";
	cout << "*       1、按工号查找          *\n";
	cout << "*       2、按姓名查找          *\n";
	cout << "*       3、按工资段查找        *\n";
	cout << "*       0、退出                *\n";
	cout << "*                              *\n";
	cout << "********************************\n";
	cout << "请选择：";
	int i = 0;
	cin >> i;
	switch (i)
	{
	case 1:
		FindByNumb();
		break;
	case 2:
		FindByName();
		break;
	case 3:
		FindBySalary();
		break;
	}
	return i;
}

Find::~Find()
{
}
