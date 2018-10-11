#pragma once
#include"common.h"
class CFind
{
	CArray<DATA> &m_array;
	void FindByNumb() const;
	void FindByName() const;
	void FindBySalary() const;
public:
	CFind(CArray<DATA> &cArray);
	~CFind();
	int FindNumb(int nNumb) const;
	int FindMenu() const;

};

