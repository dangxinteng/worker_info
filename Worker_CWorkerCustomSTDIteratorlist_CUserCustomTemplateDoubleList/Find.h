#pragma once
#include"list.h"
class CFind
{
	CList<DATA> &m_array;
	void FindByNumb() const;
	void FindByName() const;
	void FindBySalary() const;
public:
	CFind(CList<DATA> &cArray);
	~CFind();
	CList<DATA>::iterator FindNumb(int nNumb) const;
	int FindMenu() const;

};

