#pragma once
#include"Sort.h"
#include"Find.h"
#include"User.h"
class CWorker
{
	CArray<DATA> m_arry;
	CSort m_sort;
	CFind m_find;
	CUser m_user;
	void Load();
	void Modify();
	void Delete();
	void Input();
	int Menu();
	void Save() const;
	void Print() const;
public:
	CWorker();
	~CWorker();
	bool Start();
};

