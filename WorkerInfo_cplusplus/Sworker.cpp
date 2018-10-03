#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Sworker.h"
using namespace std;
List Sworker::cList;
Sworker::Sworker()
{
	Load();
}
void Sworker::Save()
{
	FILE *fp = fopen("./student.txp", "wb");
	if (!fp)
	{
		cout << "�����ļ�ʱʧ�ܣ�\n";
		return;
	}
	Node* p = cList.GetHead();
	while (p)
	{
		fwrite(&p->data, 1, sizeof(DATA), fp);
		p = p->pNext;
	}
	fclose(fp);
}


void Sworker::Load()
{
	FILE *fp = fopen("./student.txp", "rb");
	if (!fp)
		return;
	DATA data;
	fseek(fp, 0, SEEK_END);
	int nCount = ftell(fp) / sizeof(DATA);
	rewind(fp);
	Node* p = cList.GetHead();
	int i = -1;
	while (++i < nCount)
	{
		fread(&data, 1, sizeof(DATA), fp);
		if (!p)
		{
			p = cList.AddHead(data);
			continue;
		}
		Node* pNew = new Node;
		pNew->data = data;
		pNew->pNext = p->pNext;
		p->pNext = pNew;
		p = pNew;
		cList.GrowCount();
	}
	fclose(fp);

}

int Sworker::CheckNumb(int nNumb)
{
	if (cList.FindNumb(nNumb))
		return 1;
	return 0;
}

void Sworker::Print()
{
	Node* p = cList.GetHead();
	int sum = 0;
	cout << "ѧ��\t����\t����\n";
	while (p)
	{
		cout << p->data.nNumb << '\t';
		cout << p->data.sName << '\t';
		cout << p->data.fSalary << '\n';
		p = p->pNext;
		++sum;
	}
	cout << "һ����" << sum << "����¼!\n";
	system("pause");

}

void Sworker::Modify()
{
	int nNumb;
	cout << "��������Ҫ�޸ĵĹ��ţ�";
	cin >> nNumb;
	if (!nNumb)
		return;
	if (!CheckNumb(nNumb))
	{
		cout << "������Ĺ���" << nNumb <<"�����ڣ�\n";
		system("pause");
		return;
	}
	cout << "ȷ���޸Ĺ���" << nNumb <<"��y/n��:";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y')
	{
		DATA Data = { nNumb };
		cout << "�������µ������͹��ʣ�";
		cin >> Data.sName;
		cin >> Data.fSalary;
		cList.Modify(nNumb, Data);
		Print();
		Save();
	}

}

void Sworker::Delete()
{
	int nNumb;
	cout << "��������Ҫɾ���Ĺ��ţ�";
	cin >> nNumb;
	if (!nNumb)
		return;
	if (!CheckNumb(nNumb))
	{
		cout << "������Ĺ���" << nNumb << "�����ڣ�\n";
		system("pause");
		return;
	}
	cout << "ȷ��ɾ������" << nNumb << "��y/n��:";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y')
	{
		cList.Delete(nNumb);
		Print();
		Save();
	}
}

void Sworker::Input()
{
	int nNumb;
	cout << "�����빤�ţ�";
	while (1)
	{
		cin >> nNumb;
		if (!nNumb)
			return;
		if (!CheckNumb(nNumb))
			break;
		cout << "����" << nNumb << "�Ѿ����ڣ����������룺";
	}
	DATA Data = { nNumb };
	cout << "�����������͹��ʣ�";
	cin >> Data.sName;
	cin >> Data.fSalary;
	cList.AddTail(Data);
	Print();
	Save();
}

int Sworker::Menu()
{
	system("cls");

	cout << "********************************\n";
	cout << "*       1�����������Ϣ        *\n";
	cout << "*       2�������Ϣ            *\n";
	cout << "*       3��ɾ����Ϣ            *\n";
	cout << "*       4���޸���Ϣ            *\n";
	cout << "*       5��������Ϣ            *\n";
	cout << "*       0���˳�                *\n";
	cout << "********************************\n";
	cout << "��ѡ��";
	int i = 0;
	cin >> i;
	switch (i)
	{
	case 1:
		//Print();
		while (cSort.SortMenu())
			;
		break;
	case 2:
		Input();
		break;
	case 3:
		Delete();
		break;
	case 4:
		Modify();
		break;
	case 5:
		while (cFind.FindMenu())
			;
		break;

	}
	return i;
}
Sworker::~Sworker()
{
}
