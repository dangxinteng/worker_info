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
		cout << "保存文件时失败！\n";
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
	cout << "学号\t姓名\t工资\n";
	while (p)
	{
		cout << p->data.nNumb << '\t';
		cout << p->data.sName << '\t';
		cout << p->data.fSalary << '\n';
		p = p->pNext;
		++sum;
	}
	cout << "一共有" << sum << "条记录!\n";
	system("pause");

}

void Sworker::Modify()
{
	int nNumb;
	cout << "请输入您要修改的工号：";
	cin >> nNumb;
	if (!nNumb)
		return;
	if (!CheckNumb(nNumb))
	{
		cout << "您输入的工号" << nNumb <<"不存在！\n";
		system("pause");
		return;
	}
	cout << "确定修改工号" << nNumb <<"【y/n】:";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y')
	{
		DATA Data = { nNumb };
		cout << "请输入新的姓名和工资：";
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
	cout << "请输入您要删除的工号：";
	cin >> nNumb;
	if (!nNumb)
		return;
	if (!CheckNumb(nNumb))
	{
		cout << "您输入的工号" << nNumb << "不存在！\n";
		system("pause");
		return;
	}
	cout << "确定删除工号" << nNumb << "【y/n】:";
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
	cout << "请输入工号：";
	while (1)
	{
		cin >> nNumb;
		if (!nNumb)
			return;
		if (!CheckNumb(nNumb))
			break;
		cout << "工号" << nNumb << "已经存在，请重新输入：";
	}
	DATA Data = { nNumb };
	cout << "请输入姓名和工资：";
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
	cout << "*       1、浏览所有信息        *\n";
	cout << "*       2、添加信息            *\n";
	cout << "*       3、删除信息            *\n";
	cout << "*       4、修改信息            *\n";
	cout << "*       5、查找信息            *\n";
	cout << "*       0、退出                *\n";
	cout << "********************************\n";
	cout << "请选择：";
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
