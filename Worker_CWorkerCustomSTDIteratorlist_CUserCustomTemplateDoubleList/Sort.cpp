#include "Sort.h"

CSort::CSort(CList<DATA> &cArray):m_arry(cArray)
{
}
CSort::~CSort()
{
}

int CSort::SortByNumb(const DATA &n, const DATA &m)
{
	return n.nNumb < m.nNumb;
}

int CSort::SortByName(const DATA &n, const DATA &m)
{
	return strcmp(n.sName, m.sName) < 0;
}

int CSort::SortBySalary(const DATA &n, const DATA &m)
{
	return n.fSalary < m.fSalary;
}

void CSort::SortFun(BYFUN pFun) const
{
	int i = -1, nCount = m_arry.size();
	DATA** _pp = new DATA*[nCount];	
	DATA** pp = _pp;
	CList<DATA>::iterator itData = m_arry.begin();
	while (itData != m_arry.end())
	{
		*pp =&(*itData);
		++pp, itData++;
	}
	i = -1;
	pp = _pp;  
	while (++i < nCount)
	{
		int j = i, m = i;
		while (++j < nCount)
		{
			if (pFun(*pp[j], *pp[m]))
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
	Print((const DATA**)_pp);
	delete[] _pp;
}
void CSort::Print(const DATA** pp) const
{
	cout << "ѧ��\t����\t����" << endl;
	int i = -1, nCount = m_arry.size();
	while (++i < nCount)
	{
		cout << (*pp)->nNumb << '\t';
		cout << (*pp)->sName << '\t';
		cout << (*pp)->fSalary << endl;
		++pp;
	}
	cout << "һ����" << nCount << "����¼!" << endl;
	system("pause");
}
int CSort::SortMenu() const
{
	system("cls");
	cout << "********************************" << endl;
	cout << "*                              *" << endl;
	cout << "*      1���������������       *" << endl;
	cout << "*      2���������������       *" << endl;
	cout << "*      3���������������       *" << endl;
	cout << "*      0���˳�                 *" << endl;
	cout << "*                              *" << endl;
	cout << "********************************" << endl;
	cout << "��ѡ��";
	int i = 0;
	cin >> i;
	BYFUN ByFun[] = { SortByNumb,SortByName,SortBySalary };
	if (i > 0 && i < 4)
		SortFun(ByFun[i - 1]);
	return i;
}