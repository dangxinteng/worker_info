#pragma once
#include"DList.h"
#include"Sort.h"
#include"Find.h"
class CWorker
{
	DList m_list;
	CSort m_sort;
	CFind m_find;
public:
	CWorker();
	bool Start();
	int Menu();
	void Load();
	void Save();	
	void Print();
	void Modify();
	void Delete();
	void Input();

	~CWorker();
};

