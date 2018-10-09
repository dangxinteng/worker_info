#include "Find.h"

CFind::CFind(CArray<DATA> &cArray):m_array(cArray)
{
}

CFind::~CFind()
{
}
int CFind::FindNumb(int nNumb) const
{
	DATA* pData = m_array.GetData();
	int i = -1, nCount = m_array.GetCount();
	while (++i < nCount)
	{
		if (pData->nNumb == nNumb)
			return i;
		++pData;
	}
	return -1;
}
void CFind::FindByNumb() const
{
	int nNumb;
	cout << "请输入您要查找的工号：";
	cin >> nNumb;
	if (!nNumb)
		return;
	int nIndex = FindNumb(nNumb);
	if (nIndex < -1)
	{
		cout << "你要查找的工号不存在！" << endl;
		system("pause");
		return;
	}
	DATA &data = m_array.GetAt(nIndex);
	cout << data.nNumb << '\t';
	cout << data.sName << '\t';
	cout << data.fSalary << endl;
	system("pause");
}

void CFind::FindByName() const
{
	char sName[20];
	cout << "请输入您要查找的姓名：";
	cin >> sName;
	int sum = 0, i = -1, nCount = m_array.GetCount();
	const DATA* pData = m_array.GetData();
	while (++i < nCount)
	{
		if (strstr(pData->sName, sName))
		{
			cout << pData->nNumb << '\t';
			cout << pData->sName << '\t';
			cout << pData->fSalary  << endl;
			++sum;
		}
		++pData;
	}
	cout << "一共有" << sum << "条数据！" << endl;
	system("pause");
}

void CFind::FindBySalary() const
{
	float fMin, fMax;
	cout << "请输入您要查找的最低资和最高工资：";
	cin >> fMin;
	cin >> fMax;
	int sum = 0, i = -1, nCount = m_array.GetCount();
	while (++i < nCount)
	{
		DATA &data = m_array.GetAt(i);
		if (data.fSalary >= fMin &&  data.fSalary <= fMax)
		{
			cout << data.nNumb << '\t';
			cout << data.sName << '\t';
			cout << data.fSalary << endl;
			++sum;
		}
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
