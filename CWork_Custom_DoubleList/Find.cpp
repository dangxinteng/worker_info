#include "Find.h"

CFind::CFind(DList &list):m_list(list)
{
}

CFind::~CFind()
{
}
POSITION CFind::FindPos(int nNumb)
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
void CFind::FindByNumb()
{
	int nNumb;
	cout << "请输入您要查找的工号：";
	cin >> nNumb;
	if (!nNumb)
		return;
	POSITION pos = FindPos(nNumb);
	if (!pos)
	{
		cout << "你要查找的工号不存在！" << endl;
		system("pause");
		return;
	}
	DATA &data = m_list.GetAt(pos);
	cout << data.nNumb << '\t';
	cout << data.sName << '\t';
	cout << data.fSalary << endl;
	system("pause");
}

void CFind::FindByName()
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
			cout << data.fSalary  << endl;
			++sum;
		}
		m_list.GetNext(pos);
	}
	cout << "一共有" << sum << "条数据！" << endl;
	system("pause");
}

void CFind::FindBySalary()
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
			cout << data.fSalary << endl;
			++sum;
		}
		m_list.GetNext(pos);
	}
	cout << "一共" << sum << "有条数据！" << endl;
	system("pause");
}

int CFind::FindMenu()
{
	system("cls");
	cout << "********************************" << endl;
	cout << "*                              *" << endl;
	cout << "*       1、按工号查找          *" << endl;
	cout << "*       2、按姓名查找          *" << endl;
	cout << "*       3、按工资段查找        *" << endl;
	cout << "*       0、退出                *" << endl;
	cout << "*                              *" << endl;
	cout << "********************************" << endl;
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
