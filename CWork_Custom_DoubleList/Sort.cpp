#include "Sort.h"

CSort::CSort(DList &list):m_list(list)
{
}
CSort::~CSort()
{
}

int CSort::SortByNumb(DATA &n, DATA &m)
{
	return n.nNumb < m.nNumb;
}

int CSort::SortByName(DATA &n, DATA &m)
{
	return strcmp(n.sName, m.sName) < 0;
}

int CSort::SortBySalary(DATA &n, DATA &m)
{
	return n.fSalary < m.fSalary;
}

void CSort::SortFun(BYFUN pFun)
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
	cout << "学号\t姓名\t工资" << endl;
	i = -1;
	while (++i < nCount)
	{
		DATA &data = m_list.GetAt(pp[i]);
		cout << data.nNumb << '\t';
		cout << data.sName << '\t';
		cout << data.fSalary << endl;
	}
	cout << "一共有" << i << "条记录!" << endl;
	system("pause");
	delete[] _pp;
}

int CSort::SortMenu()
{
	system("cls");
	cout << "********************************" << endl;
	cout << "*                              *" << endl;
	cout << "*      1、按工号排序浏览       *" << endl;
	cout << "*      2、按姓名排序浏览       *" << endl;
	cout << "*      3、按工资排序浏览       *" << endl;
	cout << "*      0、退出                 *" << endl;
	cout << "*                              *" << endl;
	cout << "********************************" << endl;
	cout << "请选择：";
	int i = 0;
	cin >> i;
	BYFUN ByFun[] = { SortByNumb,SortByName,SortBySalary };
	if (i > 0 && i < 4)
		SortFun(ByFun[i - 1]);
	return i;
}