#pragma once
#include"DList.h"
class CFind
{
	DList &m_list;
public:
	CFind(DList &list);
	~CFind();
	void FindByNumb();
	void FindByName();
	void FindBySalary();
	int FindMenu();
	POSITION FindPos(int nNumb);
};

