#include "Find.h"

CFind::CFind(CList<DATA> &cArray):m_array(cArray)
{
}

CFind::~CFind()
{
}
CList<DATA>::iterator CFind::FindNumb(int nNumb) const
{
	CList<DATA>::iterator itData = m_array.begin();
	while(itData != m_array.end())
	{
		if (itData->nNumb == nNumb)
			break;
		itData++;
	}
	return itData;
}
void CFind::FindByNumb() const
{
	int nNumb;
	cout << "请输入您要查找的工号：";
	cin >> nNumb;
	if (!nNumb)
		return;
	CList<DATA>::iterator itData= FindNumb(nNumb);
	if (itData == m_array.end())
	{
		cout << "你要查找的工号不存在！" << endl;
		system("pause");
		return;
	}
	cout << itData->nNumb << '\t';
	cout << itData->sName << '\t';
	cout << itData->fSalary << endl;
	system("pause");
}

void CFind::FindByName() const
{
	char sName[20]; int sum = 0;
	cout << "请输入您要查找的姓名：";
	cin >> sName;
	CList<DATA>::iterator itData = m_array.begin();
	while (itData != m_array.end())
	{
		if (strstr(itData->sName, sName))
		{
			cout << itData->nNumb << '\t';
			cout << itData->sName << '\t';
			cout << itData->fSalary  << endl;
			++sum;
		}
		++itData;
	}
	cout << "一共有" << sum << "条数据！" << endl;
	system("pause");
}

void CFind::FindBySalary() const
{
	float fMin, fMax; int sum = 0;
	cout << "请输入您要查找的最低资和最高工资：";
	cin >> fMin;
	cin >> fMax;
	CList<DATA>::iterator itData = m_array.begin();
	while (itData != m_array.end())
	{
		if (itData->fSalary >= fMin &&  itData->fSalary <= fMax)
		{
			cout << itData->nNumb << '\t';
			cout << itData->sName << '\t';
			cout << itData->fSalary << endl;
			++sum;
		}
		++itData;
	}
	cout << "一共" << sum << "有条数据！" << endl;
	system("pause");
}

int CFind::FindMenu() const
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
