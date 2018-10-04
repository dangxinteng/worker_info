#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Worker.h"
using namespace std;
CWorker::CWorker()
{
	Load();
}

void CWorker::Load()
{
	
	FILE *fp = fopen("./worker.txp", "rb");
	if (!fp)
	{
		cout << "打开数据文件失败！\n";
		return;
	}		
	DATA data;	
	while (fread(&data, 1, sizeof(DATA), fp)== sizeof(DATA))
	{
		m_list.AddTail(data);
	}
	fclose(fp);
}

void CWorker::Save()
{
	FILE *fp = fopen("./worker.txp", "wb");
	if (!fp)
	{
		cout << "保存文件时失败！\n";
		return ;
	}
	POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		DATA &data = m_list.GetAt(pos);
		fwrite(&data, 1, sizeof(DATA), fp);
		m_list.GetNext(pos);
	}
	fclose(fp);
}

POSITION CWorker::FindPos(int nNumb)
{
	POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		DATA &data = m_list.GetAt(pos);
		if (data.nNumb == nNumb)
			return pos;
		m_list.GetNext(pos);
	}
	return NULL;
}

void CWorker::Print()
{
	int sum = 0;
	cout << "学号\t姓名\t工资\n";
	POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		DATA &data = m_list.GetAt(pos);
		cout << data.nNumb << '\t';
		cout << data.sName << '\t';
		cout << data.fSalary << '\n';
		++sum;
		m_list.GetNext(pos);
	}	
	cout << "一共有" << sum << "条记录!\n";
	system("pause");
}

void CWorker::Modify()
{
	int nNumb;
	cout << "请输入您要修改的工号：";
	cin >> nNumb;
	if (!nNumb)
		return ;
	POSITION pos = FindPos(nNumb);
	if (!pos)
	{
		cout << "您输入的工号" << nNumb << "不存在！\n";
		system("pause");
		return ;
	}
	cout << "确定修改工号" << nNumb << "【y/n】:";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y')
	{
		
		DATA &Data = m_list.GetAt(pos);
		cout << "请输入新的姓名和工资：";
		cin >> Data.sName;
		cin >> Data.fSalary;
		Print();
		Save();
	}
}

void CWorker::Delete()
{
	int nNumb;
	cout << "请输入您要删除的工号：";
	cin >> nNumb;
	if (!nNumb)
		return ;
	POSITION pos = FindPos(nNumb);
	if (!pos)
	{
		cout << "您输入的工号" << nNumb << "不存在！\n";
		system("pause");
		return ;
	}
	cout << "确定删除工号" << nNumb << "【y/n】:";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y')
	{
		m_list.RemoveAt(pos);
		Print();
		Save();
	}
}

void CWorker::Input()
{
	int nNumb;
	cout << "请输入工号：";
	while (true)
	{
		cin >> nNumb;
		if (!nNumb)
			return ;
		if (!FindPos(nNumb))
			break;
		cout << "工号" << nNumb << "已经存在，请重新输入：";
	}
	DATA Data = { nNumb };
	cout << "请输入姓名和工资：";
	cin >> Data.sName;
	cin >> Data.fSalary;
	m_list.AddTail(Data);
	Print();
	Save();
}

int CWorker::Menu()
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
		while (SortMenu())
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
		while (FindMenu())
			;
		break;

	}
	return i;
}

int CWorker::SortByNumb(DATA &n, DATA &m)
{
	return n.nNumb < m.nNumb;
}

int CWorker::SortByName(DATA &n, DATA &m)
{
	return strcmp(n.sName, m.sName) < 0;
}

int CWorker::SortBySalary(DATA &n, DATA &m)
{
	return n.fSalary < m.fSalary;
}

void CWorker::SortFun(BYFUN pFun)
{
	int nCount = m_list.GetCount();
	POSITION* _pp = new POSITION[nCount];
	POSITION*  pp = _pp;
	int i = -1;
	while (++i < nCount)
	{
		*pp = m_list.FindIndex(i);
		pp++;
	}
	i = -1; pp = _pp;
	while (++i < nCount)
	{
		int j = i, m = i;
		while (++j < nCount)
		{
			DATA &data1 = m_list.GetAt(pp[j]);
			DATA &data2 = m_list.GetAt(pp[m]);
			if (pFun(data1, data2))
			{
				m = j;
			}
		}
		if (m != i)
		{
			POSITION t = pp[i];
			pp[i] = pp[m];
			pp[m] = t;
		}
	}
	pp = _pp;
	cout << "学号\t姓名\t工资\n";
	i = -1;
	while (++i < nCount)
	{
		DATA &data = m_list.GetAt(pp[i]);
		cout << data.nNumb << '\t';
		cout << data.sName << '\t';
		cout << data.fSalary << '\n';
	}
	cout << "一共有" << i << "条记录!\n";	
	system("pause");
	delete _pp;
}

int CWorker::SortMenu()
{
	system("cls");
	cout << "********************************\n";
	cout << "*                              *\n";
	cout << "*      1、按工号排序浏览       *\n";
	cout << "*      2、按姓名排序浏览       *\n";
	cout << "*      3、按工资排序浏览       *\n";
	cout << "*      0、退出                 *\n";
	cout << "*                              *\n";
	cout << "********************************\n";
	cout << "请选择：";
	int i = 0;
	cin >> i;
	BYFUN ByFun[] = { SortByNumb,SortByName,SortBySalary };
	if (i > 0 && i < 4)
		SortFun(ByFun[i - 1]);
	return i;
}

void CWorker::FindByNumb()
{
	int nNumb;
	cout << "请输入您要查找的工号：";
	cin >> nNumb;
	if (!nNumb)
		return ;
	POSITION pos = FindPos(nNumb);
	if (!pos)
	{
		cout << "你要查找的工号不存在！\n";
		system("pause");
		return ;
	}
	DATA &data = m_list.GetAt(pos);
	cout << data.nNumb << '\t';
	cout << data.sName << '\t';
	cout << data.fSalary << '\n';
	system("pause");
}

void CWorker::FindByName()
{
	char sName[20];
	cout << "请输入您要查找的姓名：";
	cin >> sName;
	int sum = 0;
	POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		DATA &data = m_list.GetAt(pos);
		if (strstr(data.sName, sName))
		{
			cout << data.nNumb << '\t';
			cout << data.sName << '\t';
			cout << data.fSalary << '\n';
			++sum;
		}
		m_list.GetNext(pos);
	}
	cout << "一共有" << sum << "条数据！\n";
	system("pause");
}

void CWorker::FindBySalary()
{
	float fMin, fMax;
	cout << "请输入您要查找的最低资和最高工资：";
	cin >> fMin;
	cin >> fMax;
	int sum = 0;
	POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		DATA &data = m_list.GetAt(pos);
		if (data.fSalary >= fMin &&  data.fSalary <= fMax)
		{
			cout << data.nNumb << '\t';
			cout << data.sName << '\t';
			cout << data.fSalary << '\n';
			++sum;
		}
		m_list.GetNext(pos);
	}
	cout << "一共" << sum << "有条数据！\n";
	system("pause");
}

int CWorker::FindMenu()
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


CWorker::~CWorker()
{
}
