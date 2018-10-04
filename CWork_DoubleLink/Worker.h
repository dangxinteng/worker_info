#pragma once
#include<afxtempl.h>
struct Worker
{
	int nNumb;
	char sName[20];
	float fSalary;
};
typedef Worker DATA;

typedef int(*BYFUN)(DATA &, DATA &);
class CWorker
{
	CList<DATA> m_list;
public:
	CWorker();
	int Menu();
	void Load();
	void Save();
	POSITION FindPos(int nNumb);
	void Print();
	void Modify();
	void Delete();
	void Input();	
	static int SortByNumb(DATA &n, DATA &m);
	static int SortByName(DATA &n, DATA &m);
	static int SortBySalary(DATA &n, DATA &m);
	void SortFun(BYFUN fun);
	int SortMenu();
	void FindByNumb();
	void FindByName();
	void FindBySalary();
	int FindMenu();
	~CWorker();
};

