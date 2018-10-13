#pragma once
#include"list.h"
#include"Sort.h"
#include"Find.h"
#include"User.h"
class CWorker
{
	CList<DATA> m_arry;
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

