#pragma once
#include"DList.h"
class CSort
{
	DList &m_list;
	typedef int(*BYFUN)(DATA&, DATA&);
public:
	CSort(DList &list);
	~CSort();
	int SortMenu();
	static int SortByNumb(DATA &n, DATA &m);
	static int SortByName(DATA &n, DATA &m);
	static int SortBySalary(DATA &n, DATA &m);
	void SortFun(BYFUN fun);
};

