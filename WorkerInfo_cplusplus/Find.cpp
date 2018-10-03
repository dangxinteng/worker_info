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
	cout << "��������Ҫ���ҵĹ��ţ�";
	cin >> nNumb;
	if (!nNumb)
		return;
	Node* p = cList.FindNumb(nNumb);
	if (!p)
	{
		cout << "��Ҫ���ҵĹ��Ų����ڣ�\n";
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
	cout << "��������Ҫ���ҵ�������";
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
	cout << "һ����" << sum << "�����ݣ�\n";
	system("pause");

}
void Find::FindBySalary()
{
	float fMin, fMax;
	cout << "��������Ҫ���ҵ�����ʺ���߹��ʣ�";
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
	cout << "һ��" << sum << "�������ݣ�\n";
	system("pause");
}

int Find::FindMenu()
{
	system("cls");
	cout << "********************************\n";
	cout << "*                              *\n";
	cout << "*       1�������Ų���          *\n";
	cout << "*       2������������          *\n";
	cout << "*       3�������ʶβ���        *\n";
	cout << "*       0���˳�                *\n";
	cout << "*                              *\n";
	cout << "********************************\n";
	cout << "��ѡ��";
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
