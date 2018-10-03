#include<iostream>
#include "Sort.h"
#include "Sworker.h"
using namespace std;
Sort::Sort():cList(Sworker::cList)
{
	
}
int Sort::ByNumb(void* n, void* m)
{
	return ((DATA*)n)->nNumb < ((DATA*)m)->nNumb;
}
int Sort::ByName(void* n, void* m)
{
	return strcmp(((DATA*)n)->sName, ((DATA*)m)->sName) < 0;
}
int Sort::BySalary(void* n, void* m)
{
	return ((DATA*)n)->fSalary < ((DATA*)m)->fSalary;
}
void Sort::SortFun(BYFUN fun)
{
	Node* p = cList.GetHead();
	int nCount = cList.GetCount();
	DATA** _pp = new DATA*[nCount];
	DATA** pp = _pp;
	while (--nCount > -1)
	{
		*pp = (DATA*)p;
		pp++, p = p->pNext;
	}
	int i = -1; pp = _pp; nCount = cList.GetCount();
	while (++i < nCount)
	{
		int j = i, m = i;
		while (++j < nCount)
		{
			if (fun(pp[j], pp[m]))
			{
				m = j;
			}
		}
		if (m != i)
		{
			DATA* t = pp[i];
			pp[i] = pp[m];
			pp[m] = t;
		}
	}
	pp = _pp;
	cout << "ѧ��\t����\t����\n";
	i = -1;
	while (++i < nCount)
	{
		cout << pp[i]->nNumb << '\t';
		cout << pp[i]->sName << '\t';
		cout << pp[i]->fSalary << '\n';
	}		
	cout << "һ����" << i << "����¼!\n";
	delete _pp;
	system("pause");
}


int Sort::SortMenu()
{
	system("cls");
	cout << "********************************\n";
	cout << "*                              *\n";
	cout << "*      1���������������       *\n";
	cout << "*      2���������������       *\n";
	cout << "*      3���������������       *\n";
	cout << "*      0���˳�                 *\n";
	cout << "*                              *\n";
	cout << "********************************\n";
	cout << "��ѡ��";
	int i = 0;
	cin >> i;
	BYFUN ByFun[] = { ByNumb,ByName,BySalary };
	if (i > 0 && i < 4)
		SortFun(ByFun[i - 1]);
	return i;
}

Sort::~Sort()
{
}
