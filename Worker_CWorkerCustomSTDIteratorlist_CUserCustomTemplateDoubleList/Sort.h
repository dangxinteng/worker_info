#pragma once
#include"list.h"
class CSort
{
	CList<DATA> &m_arry;
	typedef int(*BYFUN)(const DATA&, const DATA&);
	static int SortByNumb(const DATA &, const DATA &);
	static int SortByName(const DATA &, const DATA &);
	static int SortBySalary(const DATA &, const DATA &);
	void Print(const DATA** pp) const;
	void SortFun(BYFUN fun) const;
public:
	CSort(CList<DATA> &cArray);
	~CSort();
	int SortMenu() const;
};

