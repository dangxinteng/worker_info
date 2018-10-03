#pragma once
#include"List.h"
typedef int(*BYFUN)(void*, void*);
class Sort
{
	List& cList;
public:
	Sort();
	static int Sort::ByNumb(void* n, void* m);
	static int Sort::ByName(void* n, void* m);
	static int Sort::BySalary(void* n, void* m);
	void Sort::SortFun(BYFUN fun);
	int Sort::SortMenu();
	~Sort();
};

